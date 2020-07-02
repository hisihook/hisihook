海思芯片PLT-Hook实现
==================
# 警告及免责声明
请勿将本项目技术或代码应用在恶意软件制作、软件著作权/知识产权盗取或不当牟利等**非法用途**中。实施上述行为或利用本项目对非自己著作权所有的程序进行数据嗅探将涉嫌违反《中华人民共和国刑法》第二百一十七条、第二百八十六条，《中华人民共和国网络安全法》《中华人民共和国计算机软件保护条例》等法律规定。本项目提及的技术仅可用于私人学习测试等合法场景中，任何不当利用该技术所造成的刑事、民事责任均与本项目作者无关。

# 简介
本项目可以实现利用PLT-Hook对海思中一些硬件资源的调用实现Hook操作，从而可以更方便地统一对NNIE、IVE等硬件资源进行调配或调试。利用本项目，能够实现在不修改项目代码的情况下，对海思各类硬件对调用频率，调用数据、调用线程等进行分析，可能可以方便地实现硬件资源的分配。本项目以截获NNIE加载模型过程，并保存所需要加载模型为例，演示海思系列芯片PLT-Hook的流程。

# 注意事项
* 实现Hook需要在程序运行过程中，调用hook()函数注册被Hook的函数。
* 主程序链接时，不能将程序链接至NNIE静态库，应通过动态库方式链接。

# 许可
* PLT-Hook库使用了Kubo的plthook_elf代码，链接：https://github.com/kubo/plthook，该代码遵循代码内提供的许可条件进行分发。
* 海思头文件代码著作权归华为海思所有
* 本项目相关代码归属公有领域