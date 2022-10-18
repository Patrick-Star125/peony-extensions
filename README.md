新增项目文件夹：peony-batch-rename，包括：

* 头文件
  * rename-page.h #定义UI逻辑
  * ui-rename-page.h #定义UI界面
  * batch-rename-plugin.h #定义插件主体
  * peony-batch-rename-plugin_global.h
* 源文件
  * rename-page.cpp #绑定UI控件(按钮)功能
  * batch-rename-plugin.cpp #实现插件逻辑(主要逻辑)

目前主要遇到的问题有两个

1. 翻译文件
   * 可能是因为配置或者什么出错，我不懂如何自动生成翻译文件，所以决定手动添加翻译文件，但是我不清楚.qm文件的用途，能否直接套用其它插件的.qm文件呢？
   * 在我自定义的ui文件`ui-rename-page.h`中无法使用函数`tr()`，要如何在这种文件中使用`tr()`函数来套用ts文件提供的翻译文本？
2. 执行代码
   * 目前程序产生的.so结构能够邮件显示，但是不能触发启动窗口，我看其它项目似乎也没有自定义应用UI的实现，所以没有参考，请问这里要如何设置项目结构才能让UI正常显示？
   * 因为qt creator无法自动编译项目，目前我采用的项目编译方法是手动`qmake-make-移动目标文件到目标目录`，但是这样似乎无法利用qDebug调试代码，请问有没有简单的办法直接在文件管理器中右键点击的时候提示调试信息，例如弹出弹窗之类的？