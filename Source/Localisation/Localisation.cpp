#include "Localisation.h"
#include "TranslationData_zh_CN.h"

#if JUCE_WINDOWS
 #include <windows.h>
#endif

namespace minixer
{

//==============================================================================
std::optional<Localisation::Language> Localisation::parseCommandLineLanguage (
    const juce::String& commandLine)
{
    // 逐 token 扫描，允许与其他参数共存；值大小写不敏感。
    juce::StringArray tokens;
    tokens.addTokens (commandLine, " ", "\"");

    for (const auto& token : tokens)
    {
        if (! token.startsWithIgnoreCase ("--lang="))
            continue;

        const auto value = token.substring (7).trim().toLowerCase();

        if (value == "zh" || value == "cn" || value == "chinese" || value == "中文")
            return Language::chinese;

        if (value == "en" || value == "english")
            return Language::english;

        if (value == "system" || value == "auto")
            return Language::system;
    }

    return std::nullopt;
}

//==============================================================================
void Localisation::applyFromSetting (int settingValue)
{
    apply (static_cast<Language> (settingValue));
}

//==============================================================================
void Localisation::apply (Language language)
{
    const auto effective = language == Language::system ? resolveSystemLanguage()
                                                        : language;

    if (effective == Language::chinese)
    {
        // 内嵌的 UTF-8 翻译数据直接交给 JUCE 解析（false = 区分大小写精确匹配）。
        juce::LocalisedStrings::setCurrentMappings (
            new juce::LocalisedStrings (juce::String (juce::CharPointer_UTF8 (TranslationData::zh_CN)),
                                        false));
    }
    else
    {
        // 英文（或未识别的语言）：清除映射，TRANS() 原样返回英文原文。
        juce::LocalisedStrings::setCurrentMappings (nullptr);
    }
}

//==============================================================================
Localisation::Language Localisation::resolveSystemLanguage()
{
   #if JUCE_WINDOWS
    // 优先取用户 UI 语言（随账户变化），失败时退回系统默认 UI 语言。
    // 主语言 ID 为 LANG_CHINESE (0x04) 即视为中文（含简/繁/港/澳地区）。
    LANGID langId = ::GetUserDefaultUILanguage();

    if (langId == 0)
        langId = ::GetSystemDefaultUILanguage();

    if (PRIMARYLANGID (langId) == LANG_CHINESE)
        return Language::chinese;

    return Language::english;
   #else
    // 非 Windows 平台：JUCE 的显示语言字符串形如 "zh-CN" / "en-GB"。
    if (juce::SystemStats::getDisplayLanguage().startsWithIgnoreCase ("zh"))
        return Language::chinese;

    return Language::english;
   #endif
}

} // namespace minixer
