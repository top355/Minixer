// =============================================================================
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

const char* const zh_CN = R"LOCDATA(
language: Chinese
countries: cn

# =============================================================================
# Minixer 简体中文（zh_CN）翻译表
#
# 格式（JUCE LocalisedStrings）：
#   "英文原文" = "中文译文"
#   - 字符串内的引号写 \" ，换行写 \n
#   - 每行一条，行首不是引号的行视为注释
#   - 本文件必须保存为 UTF-8 无 BOM 编码
#
# 本文件是翻译的唯一可编辑来源；Source/Localisation/TranslationData_zh_CN.cpp
# 由其自动生成（内嵌进程序，避免运行时依赖外部文件）。
# 修改本文件后请运行：python tools/gen_translation_data.py
#
# 语言选择优先级：命令行 --lang=zh|en > 设置面板“语言” > 系统显示语言
# =============================================================================

# -----------------------------------------------------------------------------
# Source/Main.cpp —— 托盘菜单
# -----------------------------------------------------------------------------
"Hide Minixer" = "隐藏 Minixer"
"Show Minixer" = "显示 Minixer"
"Quit" = "退出"

# -----------------------------------------------------------------------------
# Source/MainComponent.cpp —— 主界面状态栏 / 预设操作
# -----------------------------------------------------------------------------
"Ready" = "就绪"
"MONO INPUT" = "单声道输入"
"Shortcut: bring window to front" = "快捷键：将窗口提到前台"
"All plugins bypassed" = "已旁通全部插件"
"All plugins unbypassed" = "已取消旁通全部插件"
"Slot " = "插槽 "
" bypass: on" = " 旁通：开"
" bypass: off" = " 旁通：关"
"Audio device setup error: " = "音频设备设置错误："
"separated %.0f%%" = "分离 %.0f%%"
"merged %.0f%%" = "合并 %.0f%%"
"off" = "关"
"Input " = "输入 "
" dB | Pan " = " dB | 声像 "
" | Stereo " = " | 立体声 "
" | Output " = " | 输出 "
"Cancelled loading in slot %d" = "已取消插槽 %d 的加载"
" is still unloading" = " 仍在卸载中"
" is still loading" = " 仍在加载中"
" is empty" = " 为空"
"Removing " = "正在卸载 "
"Removing" = "正在卸载"
" from slot " = "，来自插槽 "
"..." = "…"
"Slot %d cleared" = "插槽 %d 已清空"
"Copied " = "已复制："
"Pasted " = "已粘贴 "
" into slot " = " 到插槽 "
"Plugin '" = "插件「"
"' not found in scanned list" = "」不在已扫描列表中"
"No plugin in clipboard" = "剪贴板中没有插件"
"Moved " = "已移动："
" to slot " = " → 插槽 "
"No Plugins" = "无插件"
"No VST3 plugins found. Please scan for plugins in Settings." = "未找到 VST3 插件，请在“设置”中扫描插件。"
"Select Plugin" = "选择插件"
"Loading " = "正在加载 "
"Loading" = "正在加载"
"Failed to load plugin: internal error" = "插件加载失败：内部错误"
"Failed to load bridged plugin: " = "桥接插件加载失败："
"Failed to add plugin to graph" = "将插件添加到音频处理链失败"
"Loaded " = "已加载 "
" in slot " = "，插槽 "
"Plugin in slot " = "插槽 "
" crashed" = " 的插件崩溃了"
"Plugin not found for slot " = "未找到插槽 "
"Saved preset: " = "已保存预设："
"Failed to save preset: " = "保存预设失败："
"Preset not found: " = "未找到预设："
"Loaded preset: " = "已加载预设："
"Failed to parse preset: " = "预设解析失败："
"Deleted preset: " = "已删除预设："
"Failed to delete preset: " = "删除预设失败："

# -----------------------------------------------------------------------------
# Source/Components/AboutComponent —— 关于窗口
# -----------------------------------------------------------------------------
"Version" = "版本"
"A lightweight single-channel standalone audio mixer" = "轻量级单通道独立音频混音台"
"GitHub: github.com/XmengMD/Minixer" = "GitHub 仓库：github.com/XmengMD/Minixer"
"License\n" = "许可证\n"
"-------\n" = "────────\n"
"Minixer is licensed under the GNU Affero General Public License v3.0 (AGPLv3).\n" = "Minixer 基于 GNU Affero 通用公共许可证 v3.0（AGPLv3）发布。\n"
"Source code is available at the GitHub repository above.\n\n" = "源代码见上方的 GitHub 仓库。\n\n"
"Third-Party Notices\n" = "第三方声明\n"
"-------------------\n" = "──────────────\n"
# 注意：以下三条在源码中由多个相邻字面量书写，编译期已拼接为整句，
# 因此键必须是拼接后的完整文本。
"JUCE framework: Copyright Raw Material Software Limited. Dual-licensed under AGPLv3 and the JUCE commercial licence.\n\n" = "JUCE 框架：版权归 Raw Material Software Limited 所有，依据 AGPLv3 与 JUCE 商业许可双重授权。\n\n"
"ASIO: ASIO is a trademark and software of Steinberg Media Technologies GmbH. This application uses the Steinberg ASIO SDK under the terms of the Steinberg ASIO Licensing Agreement. Redistribution of the ASIO SDK is not permitted.\n\n" = "ASIO：ASIO 是 Steinberg Media Technologies GmbH 的商标与软件。本应用依据 Steinberg ASIO 许可协议使用 Steinberg ASIO SDK，且不允许再分发该 SDK。\n\n"
"VST3: VST is a trademark of Steinberg Media Technologies GmbH. This application uses the Steinberg VST3 SDK under the terms of the Steinberg VST3 License or GPLv3.\n\n" = "VST3：VST 是 Steinberg Media Technologies GmbH 的商标。本应用依据 Steinberg VST3 许可协议或 GPLv3 使用 Steinberg VST3 SDK。\n\n"
"This software is provided \"as is\", without warranty of any kind.\n" = "本软件按“原样”提供，不作任何形式的保证。\n"
"Close" = "关闭"

# -----------------------------------------------------------------------------
# Source/Components/AsioAdvancedSettingsComponent —— ASIO 高级设置
# -----------------------------------------------------------------------------
"Input Channels" = "输入声道"
"Output Channels" = "输出声道"
"Input Channel" = "输入声道"
"Output Channel" = "输出声道"
"Mode" = "模式"
"Mono" = "单声道"
"Stereo" = "立体声"
"Input L" = "输入 L"
"Input R" = "输入 R"
"Output L" = "输出 L"
"Output R" = "输出 R"
"OK" = "确定"
"Cancel" = "取消"
"Reset" = "重置"
"No ASIO device is currently open." = "当前没有打开 ASIO 设备。"
"ASIO Channel Routing" = "ASIO 声道分配"

# -----------------------------------------------------------------------------
# Source/Components/ChannelStripComponent —— 通道条旋钮
# -----------------------------------------------------------------------------
"L %.0f%%" = "左 %.0f%%"
"R %.0f%%" = "右 %.0f%%"
"C" = "中"
"Input Trim" = "输入增益"
"Pan" = "声像"
"Output" = "输出"

# -----------------------------------------------------------------------------
# Source/Components/FaderComponent / RotaryKnobComponent / LevelMeterComponent
# -----------------------------------------------------------------------------
"Reset to default" = "恢复默认值"
"Copy value" = "复制数值"
"Paste value" = "粘贴数值"
"-inf dB" = "-∞ dB"
"CLIP" = "过载"
"Reset to Default (dBFS)" = "恢复默认值 (dBFS)"

# -----------------------------------------------------------------------------
# Source/Components/KeyCaptureButton
# -----------------------------------------------------------------------------
"Press a key/MIDI/HID..." = "按下按键 / MIDI / HID..."
"None" = "无"

# -----------------------------------------------------------------------------
# Source/Components/PluginSlotComponent —— 插件槽
# -----------------------------------------------------------------------------
"Bypass this plugin" = "旁通此插件"
"Load or remove this plugin" = "加载或移除此插件"
"Cancel loading" = "取消加载"
"Removing this plugin" = "正在移除此插件"
"Empty" = "空"
"Load plugin" = "加载插件"
"Load plugin..." = "加载插件..."
"Remove this plugin" = "移除此插件"
"Removing plugin..." = "正在移除插件..."
"Open plugin editor" = "打开插件编辑器"
"Replace plugin..." = "替换插件..."
"Unbypass" = "取消旁通"
"Bypass" = "旁通"
"Copy plugin" = "复制插件"
"Paste plugin" = "粘贴插件"
"Move up" = "上移"
"Move down" = "下移"
"Delete" = "删除"

# -----------------------------------------------------------------------------
# Source/Components/PresetBarComponent —— 预设栏
# -----------------------------------------------------------------------------
"--" = "——"
"Rename Preset" = "重命名预设"
"Enter new name:" = "输入新名称："
"New Preset" = "新预设"
"Rename" = "重命名"
"Delete Preset" = "删除预设"
"Please save or load a preset first." = "请先保存或加载一个预设。"
"Are you sure you want to delete \"" = "确定要删除“"
"Save Preset" = "保存预设"
"Overwrite Preset" = "覆盖预设"
"A preset named \"" = "已存在名为“"
"\" already exists. Replace it?" = "”的预设，要替换它吗？"
"Replace" = "替换"
"Load Preset" = "加载预设"
"Save" = "保存"
"Load" = "加载"
"Settings" = "设置"

# -----------------------------------------------------------------------------
# Source/Components/SettingsComponent —— 设置面板
# -----------------------------------------------------------------------------
"Audio" = "音频"
"Driver" = "驱动"
"Input Device" = "输入设备"
"Output Device" = "输出设备"
"Sample Rate" = "采样率"
"Buffer Size" = "缓冲区大小"
"Preferences" = "首选项"
"Launch on startup" = "开机时自动启动"
"Start minimized" = "启动时最小化"
"Minimize to system tray" = "最小化到系统托盘"
"Auto-load preset on startup" = "启动时自动加载预设"
"Preset to load" = "要加载的预设"
"Plugins" = "插件"
"Scanned plugins: 0" = "已扫描插件：0"
"Scanned plugins: " = "已扫描插件："
"Shortcuts" = "快捷键"
"About" = "关于"
"About Minixer" = "关于 Minixer"
"Select Preset to Auto-Load" = "选择启动时自动加载的预设"
"Audio Device Error" = "音频设备错误"
"ASIO Control Panel" = "ASIO 控制面板"
"Open ASIO Control Panel" = "打开 ASIO 控制面板"
"Advanced..." = "高级..."
"Browse" = "浏览..."
"Manage Plugins" = "管理插件"
"Configure Shortcuts..." = "配置快捷键..."
"Configure Shortcuts" = "配置快捷键"
"The current device does not provide a control panel." = "当前设备不提供控制面板。"
"ASIO Device" = "ASIO 设备"
"ASIO Settings" = "ASIO 设置"
"Plugin Manager" = "插件管理器"
"Shortcuts Viewport" = "快捷键列表"
"Language" = "语言"
"System default" = "跟随系统"
"Chinese" = "中文"
"Language changed. Restart Minixer to apply." = "语言已更改，重启 Minixer 后生效。"

# -----------------------------------------------------------------------------
# Source/Components/ShortcutsSettingsComponent —— 快捷键设置
# -----------------------------------------------------------------------------
"MIDI Shortcut Input" = "MIDI 快捷键输入"
"Select a MIDI input device to use its notes/CC as slot shortcuts." = "选择 MIDI 输入设备，将其音符 / CC 作为插槽快捷键使用。"
"Global Shortcuts" = "全局快捷键"
"These shortcuts work across the entire Minixer window." = "这些快捷键在整个 Minixer 窗口内有效。"
"Slot Bypass Shortcuts" = "插槽旁通快捷键"
"Each slot can have its own bypass shortcut. Multiple slots may share the same source." = "每个插槽都可以设置独立的旁通快捷键，多个插槽可以共用同一个触发源。"
"Default bypass" = "默认旁通"
"Cycle toggle" = "点按切换"
"Hold toggle" = "长按切换"
"None (disable MIDI shortcuts)" = "无（禁用 MIDI 快捷键）"
"Clear" = "清除"
"Reset to Defaults" = "恢复默认设置"
"Apply" = "应用"

# -----------------------------------------------------------------------------
# Source/Plugin/PluginEditorWindow
# -----------------------------------------------------------------------------
"Plugin Editor" = "插件编辑器"
"This plugin has no editor." = "此插件没有编辑器界面。"

# -----------------------------------------------------------------------------
# Source/Plugin/PluginManagerComponent —— 插件管理器
# -----------------------------------------------------------------------------
"Add folder..." = "添加文件夹..."
"Remove selected" = "移除所选"
"default" = "默认"
"Add VST3 scan folder" = "添加 VST3 扫描文件夹"
"Options" = "选项"
"Rescan previously failed plugins" = "重新扫描上次失败的插件"
"When checked, plugins that crashed or failed in the last scan will be scanned again." = "勾选后，上次扫描中崩溃或失败的插件将会被重新扫描。"
"Filter:" = "筛选："
"Search plugins..." = "搜索插件..."
"Name" = "名称"
"Manufacturer" = "厂商"
"In/Out" = "输入/输出"
"Enable or disable this plugin" = "启用或禁用此插件"
"Edit scan directories..." = "编辑扫描目录..."
"Scan" = "扫描"
"Fully rescan" = "完全重新扫描"
"Remove selected plug-ins" = "移除所选插件"
"Remove all plug-ins" = "移除全部插件"
"Apply dead-man's pedal" = "启用崩溃防护机制"
"Don't apply dead-man's pedal" = "不启用崩溃防护机制"
"Scan directories" = "扫描目录"
"Disable" = "禁用"
"Enable" = "启用"
"Remove plug-in" = "移除插件"
"Show folder in file manager" = "在文件管理器中显示所在文件夹"
"Scanning" = "正在扫描"
"Scan completed" = "扫描完成"
"Total files scanned" = "扫描文件总数"
"Successful" = "成功"
"New plugins" = "新增插件"
"Updated plugins" = "有更新的插件"
"Skipped (unchanged)" = "已跳过（未变化）"
"Skipped (blacklisted)" = "已跳过（黑名单）"
"Failed" = "失败"
"Failed files" = "失败的文件"
"and" = "以及另外"
"more" = " 个"
"Blacklisted plugins skipped" = "已跳过黑名单中的插件"
"Check \"Rescan previously failed plugins\" to retry them." = "勾选“重新扫描上次失败的插件”即可重试这些插件。"
"Plugin Scan Report" = "插件扫描报告"

# -----------------------------------------------------------------------------
# Source/Plugin/PluginRegistry —— 扫描器状态与错误
# -----------------------------------------------------------------------------
"Plugin scan raised a structured exception" = "插件扫描引发了结构化异常"
"Plugin scan threw a C++ exception" = "插件扫描抛出了 C++ 异常"
"Failed to load module" = "模块加载失败"
"No plugin descriptions found" = "未找到插件描述信息"
"No loadable .vst3 library found in bundle" = "插件包中未找到可加载的 .vst3 库"
"Enumerating plugin directories" = "正在枚举插件目录"
"File does not exist" = "文件不存在"
"No previous scan metadata" = "没有上次扫描的元数据"
"Last scan failed" = "上次扫描失败"
"File modification time or size changed" = "文件的修改时间或大小已变化"
"Unable to compute file hash" = "无法计算文件哈希"
"File hash changed" = "文件哈希已变化"
"Unknown error" = "未知错误"

# -----------------------------------------------------------------------------
# Source/Plugin/PluginSelectorComponent —— 插件选择器
# -----------------------------------------------------------------------------
"Category" = "类别"
"All" = "全部"
"Choose which fields the search text should match." = "选择搜索文本需要匹配的字段。"
"Clear search" = "清除搜索"
"No matching plugins" = "没有匹配的插件"

# -----------------------------------------------------------------------------
# Source/Settings/KeyboardShortcut —— 全局快捷键动作名与说明
# -----------------------------------------------------------------------------
"Bring window to front" = "将窗口提到前台"
"Toggle all plugins bypass" = "切换全部插件的旁通状态"
"Toggle settings panel" = "打开 / 关闭设置面板"
"Delete focused slot" = "删除当前聚焦的插槽"
"Unknown" = "未知"
"Show and focus the main Minixer window." = "显示并聚焦 Minixer 主窗口。"
"Bypass or unbypass all loaded plugins at once." = "一次性旁通或取消旁通所有已加载的插件。"
"Open or close the settings panel." = "打开或关闭设置面板。"
"Remove the plugin in the currently focused slot." = "移除当前聚焦插槽中的插件。"

# -----------------------------------------------------------------------------
# JUCE 框架自身的界面字符串（对话框按钮、文本编辑器右键菜单等）。
# TRANS() 宏同样作用于 JUCE 内部文本，故一并翻译。
# -----------------------------------------------------------------------------
"Yes" = "是"
"No" = "否"
"Cut" = "剪切"
"Copy" = "复制"
"Paste" = "粘贴"
"Select All" = "全选"
"Undo" = "撤销"
"Redo" = "重做"
"Open" = "打开"
"New Folder" = "新建文件夹"
"Create Folder" = "创建文件夹"
"File already exists" = "文件已存在"
"There's already a file called: FLNM" = "已存在同名文件：FLNM"
"Are you sure you want to overwrite it?" = "确定要覆盖它吗？"
"Overwrite" = "覆盖"
"Please enter the name for the folder" = "请输入文件夹名称"
"Couldn't create the folder!" = "无法创建文件夹！"
)LOCDATA";

} // namespace TranslationData
} // namespace minixer
