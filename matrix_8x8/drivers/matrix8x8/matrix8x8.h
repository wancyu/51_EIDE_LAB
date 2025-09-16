/**************************************************************
 * @file    matrix8x8.h
 * @brief   8x8 LED 点阵屏驱动头文件
 * @details
 * 本模块基于 74HC595 + 行列扫描方式实现 8×8 LED 点阵屏的显示。
 * 
 * 功能特性：
 * - 通过 74HC595 移位寄存器驱动列数据
 * - 行控制通过 MCU IO 口直连
 * - 支持单列点亮、图案显示
 * - 动态扫描方式，需要在循环或定时器中周期调用
 *
 * 硬件说明：
 * - MCU: STC89C52 / AT89X52 系列
 * - 行口：P0（推挽输出）
 * - 74HC595 控制引脚：
 *   - SER → P3.4
 *   - SCK → P3.6
 *   - RCK → P3.5
 *
 * 使用说明：
 * 1. 调用 Matrix8x8_Init() 完成初始化
 * 2. 在主循环或定时器中调用 Matrix8x8_Showcol()
 * 3. 快速循环扫描 0~7 列，即可显示完整图案
 * 
 * @note
 * - 使用时需周期调用 Matrix8x8_Showcol() 扫描刷新
 * - 可在 main 循环或定时器中断里调用
 * 
 * @author  qinglan
 **************************************************************/

#ifndef __MATRIX8X8_H__
#define __MATRIX8X8_H__

/**
 * @brief 初始化 74HC595 & 点阵屏接口
 */
void Matrix8x8_Init(void);

/**
 * @brief 点阵屏显示一列数据，，然后清除
 * @param col 列号 (0~7, 0 最左边)
 * @param col_data   列数据，高位在上，bit=1 点亮LED
 */
void Matrix8x8_ShowColumn(unsigned char col, unsigned char col_data);

#endif /* __MATRIX8X8_H__ */
