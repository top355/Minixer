#pragma once

#include <JuceHeader.h>
#include <optional>

namespace minixer
{

//==============================================================================
/** 界面语言（本地化）管理。

    Minixer 的所有界面文案均通过 JUCE 的 TRANS() 宏输出，
    本模块负责在启动时选择并加载对应的本地化映射表
    （当前仅内置简体中文；english 表示不加载映射，直接显示英文原文）。

    语言选择优先级：
      1. 命令行参数 --lang=zh / --lang=en / --lang=system
      2. 设置面板中的“语言”选项（AppSettings 持久化）
      3. 操作系统当前显示语言（中文系统自动使用中文）

    注意：各组件在构造时一次性读取文案，因此切换语言后需重启生效。
*/
class Localisation
{
public:
    //==============================================================================
    /** 界面语言。

        枚举值与 AppSettings 中持久化的整数值一一对应，
        新增语言时务必保持三者同步（本枚举 / AppSettings / 设置面板下拉框）。
    */
    enum class Language
    {
        system  = 0,   /**< 跟随系统 */
        chinese = 1,   /**< 简体中文 */
        english = 2    /**< English */
    };

    //==============================================================================
    /** 解析命令行中的 --lang= 参数。

        接受的值：zh / cn / chinese / 中文、en / english、system / auto。
        未指定或无法识别时返回 std::nullopt（交由调用方按设置/系统语言处理）。
    */
    static std::optional<Language> parseCommandLineLanguage (const juce::String& commandLine);

    /** 按设置值加载映射表（传入 AppSettings::getLanguage() 的原始整数值）。 */
    static void applyFromSetting (int settingValue);

    /** 加载指定语言；english 时清除映射（回退为英文原文）。 */
    static void apply (Language language);

private:
    //==============================================================================
    /** 将“跟随系统”解析为具体语言（依据操作系统当前显示语言）。 */
    static Language resolveSystemLanguage();
};

} // namespace minixer
