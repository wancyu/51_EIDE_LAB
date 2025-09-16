# MCU51-Labs

个人 51 单片机实验练习合集，并提供一套可复用的通用函数库。

## 仓库结构
- src/          各实验项目
- lib/          通用函数库（GPIO、UART、Timer 等）
- docs/         函数库使用文档

## 使用说明
1. 克隆仓库：
   git clone https://github.com/wancyu/MCU51-Labs.git
2. 编译实验：
   cd src/LED_Blink
   make
3. 在实验中调用库函数：
   ```c
   #include "../../lib/gpio.h"
   MCU51_GPIO_Init();
