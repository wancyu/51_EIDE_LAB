/**************************************************************
 * @file    matrix8x8.c
 * @brief   8x8 LED 点阵屏驱动实现文件
 * @details
 * 实现了基于 74HC595 的点阵屏列扫描显示功能。
 *
 * 使用说明：
 * - 在主循环或定时器中调用 Matrix8x8_ShowColumn()
 * - 快速循环扫描 0~7 列，即可显示完整图案
 *
 * 示例：
 * @code
 *   while(1)
 *   {
 *       Matrix8x8_ShowColumn(0, 0x3C);
 *       Matrix8x8_ShowColumn(1, 0x42);
 *       Matrix8x8_ShowColumn(2, 0xA9);
 *       Matrix8x8_ShowColumn(3, 0x85);
 *       Matrix8x8_ShowColumn(4, 0x85);
 *       Matrix8x8_ShowColumn(5, 0xA9);
 *       Matrix8x8_ShowColumn(6, 0x42);
 *       Matrix8x8_ShowColumn(7, 0x3C);
 *   }
 * @endcode
 * 
 * 将显示一个“心形”图案。
 *
 * @author  qinglan
 **************************************************************/

#include "matrix8x8.h"
#include <REGX52.H>
#include "delay.h"

/* === 硬件接口定义 === */
sbit MATRIX_RCK = P3^5;   /**< 74HC595 RCLK */
sbit MATRIX_SCK = P3^6;   /**< 74HC595 SRCLK */
sbit MATRIX_SER = P3^4;   /**< 74HC595 SER 输入 */

#define MATRIX_LED_PORT   P0   /**< 行口：P0 */

/**
 * @brief 初始化 74HC595 & 点阵接口
 */
void Matrix8x8_Init(void)
{
    MATRIX_SCK = 0;
    MATRIX_RCK = 0;
}

/**
  * @brief  74HC595写入一个字节
  * @param  byte 要写入的字节
  * @retval 无
  */
void _74HC595_Writebyte(unsigned char byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		MATRIX_SER = byte&(0x80>>i);
		MATRIX_SCK=1;
		MATRIX_SCK=0;
	}
	MATRIX_RCK=1;
	MATRIX_RCK=0;
}

/**
  * @brief  LED点阵屏显示一列数据，然后清除
  * @param  col 要选择的列，范围：0~7，0在最左边
  * @param  col_data 选择列显示的数据，高位在上，1为亮，0为灭
  * @retval 无
  */
void Matrix8x8_ShowColumn(unsigned char col, unsigned char col_data)
{
	_74HC595_Writebyte(col_data);
	MATRIX_LED_PORT=~(0x80>>col);
	Delayms(1);
	MATRIX_LED_PORT=0xFF;
}
