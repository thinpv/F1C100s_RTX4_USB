# F1C100s_RTX4_USB
F1C100s with Keil RTX4 + TinyUSB

## 项目简介
该项目基于洪旭耀编写的 [https://github.com/hongxuyao/F1C100s_with_Keil_RTX4_emWin5](F1C100s_with_Keil_RTX4_emWin5) 项目，将 TinyUSB 库移植过来，并加入了一个串口 Loopback 的 Demo。

TinyUSB 是一个真正方便使用的 USB 框架，拥有大量的 USB Device 实现。

## 编译步骤
首先打开 `f1c100s-spl.uvproj` 并编译，然后打开 `spl-separated.uvproj` 并编译，最后进入 FEL 模式并执行 `output/app-prog.bat` 就可刷入。

## TODO
目前串口的 IN 和 OUT Endpoint 不能用同一个（即不能同时使用 Endpoint 2 作为 TX 和 RX，只能用两个不同的）。如果用同一个，则串口只能发送一次数据，再发送数据就无法接收了。这个不知道是软件的 bug 还是硬件本身不支持。如果有知道的朋友可以告知或修复一下。