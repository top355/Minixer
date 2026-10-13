# -*- coding: utf-8 -*-
"""校验 translations/Minixer_zh_CN.txt 与源码的一致性。

检查项：
  1. 翻译文件可被 JUCE LocalisedStrings 算法正确解析（含 \" 与 \\n 转义）
  2. 源码中所有 TRANS() 字符串均有中文译文（防止新增界面文案漏翻译）
  3. 无空译文、无重复键

用法（仓库根目录）：
    python tools/verify_translations.py

被 .github/workflows/build-windows.yml 的 check-translations 作业调用，
任何导致覆盖率下降的提交都会在 CI 阶段失败。
"""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(REPO, "Source")
TXT = os.path.join(REPO, "translations", "Minixer_zh_CN.txt")

# ---- 与 juce_LocalisedStrings.cpp 完全一致的解析算法 -----------------------

def find_close_quote(text, start_pos):
    """复刻 JUCE 的 findCloseQuote：跳过 \\" 转义后的引号。"""
    last_char = ''
    i = start_pos
    while i < len(text):
        c = text[i]
        if c == '"' and last_char != '\\':
            return i
        last_char = c
        i += 1
    return i


def unescape(s):
    """复刻 JUCE 的 unescapeString。"""
    return (s.replace('\\"', '"').replace("\\'", "'")
             .replace('\\t', '\t').replace('\\r', '\r').replace('\\n', '\n'))


def parse_translation_file(content):
    """复刻 juce_LocalisedStrings::loadFromText。"""
    mappings = {}
    for raw_line in content.split('\n'):
        line = raw_line.strip()
        if line.startswith('"'):
            close_quote = find_close_quote(line, 1)
            original = unescape(line[1:close_quote])
            if original:
                opening_quote = find_close_quote(line, close_quote + 1)
                close_quote = find_close_quote(line, opening_quote + 1)
                new_text = unescape(line[opening_quote + 1:close_quote])
                if new_text:
                    if original in mappings:
                        print('[duplicate key] %r' % original)
                    mappings[original] = new_text
    return mappings


# ---- 源码 TRANS() 字符串提取 ------------------------------------------------

TRANS_RE = re.compile(r'TRANS\s*\(')
STR_RE = re.compile(r'"((?:[^"\\\n]|\\.)*)"')


def unescape_cpp(lit):
    return lit.replace('\\"', '"').replace('\\n', '\n').replace('\\t', '\t')


def find_trans_calls(text):
    results = []
    for m in TRANS_RE.finditer(text):
        start = m.end()
        depth = 1
        i = start
        while i < len(text) and depth > 0:
            c = text[i]
            if c == '(':
                depth += 1
            elif c == ')':
                depth -= 1
                if depth == 0:
                    break
            i += 1
        results.append(text[start:i])
    return results


def extract_literal_groups(content):
    """C++ 相邻字面量编译期拼接；三元表达式中的字面量相互独立。"""
    matches = list(STR_RE.finditer(content))
    groups = []
    i = 0
    while i < len(matches):
        parts = [unescape_cpp(matches[i].group(1))]
        j = i + 1
        while (j < len(matches)
               and content[matches[j - 1].end():matches[j].start()].strip() == ''):
            parts.append(unescape_cpp(matches[j].group(1)))
            j += 1
        groups.append(''.join(parts))
        i = j
    return groups


# 生成的数据文件不是代码，跳过（其 R"LOCDATA( 定界符会干扰扫描）
SKIP_FILES = {'TranslationData_zh_CN.cpp'}

# 有意保留英文的条目（品牌名 / 单位 / 技术标准缩写 / 语言自称）
INTENTIONAL_ENGLISH = {
    'Minixer',
    ' dB',
    'dBFS', 'RMS', 'LUFS-M', 'LUFS-S',
    'English',
}


def collect_source_strings():
    found = set()
    for root, dirs, files in os.walk(SRC):
        for fn in sorted(files):
            if not fn.endswith(('.cpp', '.h')) or fn in SKIP_FILES:
                continue
            with open(os.path.join(root, fn), 'r', encoding='utf-8',
                      errors='replace') as f:
                text = f.read()
            for content in find_trans_calls(text):
                for s in extract_literal_groups(content):
                    found.add(s)
    return found


def main():
    if not os.path.isfile(TXT):
        print('ERROR: translation file not found: %s' % TXT)
        return 1

    with open(TXT, 'r', encoding='utf-8') as f:
        mappings = parse_translation_file(f.read())

    src_strings = collect_source_strings()

    print('translation file: %d mappings' % len(mappings))
    print('source TRANS strings: %d unique' % len(src_strings))

    missing = sorted(s for s in src_strings
                     if s not in mappings and s not in INTENTIONAL_ENGLISH)
    bad = [k for k, v in mappings.items() if not v.strip()]

    if missing:
        print('\nMISSING TRANSLATIONS (%d):' % len(missing))
        for s in missing:
            print('  %r' % s)

    if bad:
        print('\nEMPTY TRANSLATIONS: %r' % bad)

    if not missing and not bad:
        print('OK: all source strings are covered')
        return 0

    print('\nFAILED: update translations/Minixer_zh_CN.txt, '
          'then run: python tools/gen_translation_data.py')
    return 1


if __name__ == '__main__':
    sys.exit(main())
