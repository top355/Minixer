# -*- coding: utf-8 -*-
"""从 translations/Minixer_zh_CN.txt 生成内嵌翻译数据 C++ 源文件。

用法（在仓库根目录执行）：
    python tools/gen_translation_data.py

生成：Source/Localisation/TranslationData_zh_CN.cpp
内容为 .txt 原文的原始字符串字面量（R"LOCDATA(...)LOCDATA"），JUCE 的
LocalisedStrings 解析器可直接消费，语义与外部 .txt 完全一致。
"""
import io, os, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_TXT = os.path.join(REPO, "translations", "Minixer_zh_CN.txt")
OUT_CPP = os.path.join(REPO, "Source", "Localisation", "TranslationData_zh_CN.cpp")
DELIM = "LOCDATA"  # 原始字符串定界符：R"LOCDATA( ... )LOCDATA"
TERMINATOR = ')' + DELIM + '"'

TEMPLATE = u'''// =============================================================================
// Minixer 简体中文翻译数据（内嵌）
//
// 本文件由 tools/gen_translation_data.py 依据 translations/Minixer_zh_CN.txt
// 自动生成，请勿手工编辑；如需修改文案请改 .txt 后重新生成。
//
// 内容为 JUCE LocalisedStrings 格式的原始字符串（UTF-8），
// 与外部 .txt 文件语义完全一致。
// =============================================================================
#include "TranslationData_zh_CN.h"

namespace minixer
{
namespace TranslationData
{

const char* const zh_CN = R"__DELIM__(
__CONTENT__
)__DELIM__";

} // namespace TranslationData
} // namespace minixer
'''


def main():
    with io.open(SRC_TXT, "r", encoding="utf-8") as f:
        content = f.read()

    if TERMINATOR in content:
        print("ERROR: translation file contains the raw-string terminator "
              + repr(TERMINATOR))
        return 1

    # 统一为 LF，避免不同编辑器引入 CRLF 造成 diff 噪音
    content = content.replace("\r\n", "\n").replace("\r", "\n")

    out_text = (TEMPLATE
                .replace("__DELIM__", DELIM)
                .replace("__CONTENT__", content.rstrip("\n")))

    with io.open(OUT_CPP, "w", encoding="utf-8", newline="\n") as out:
        out.write(out_text)

    print("generated %s" % os.path.relpath(OUT_CPP, REPO))
    return 0


if __name__ == "__main__":
    sys.exit(main())
