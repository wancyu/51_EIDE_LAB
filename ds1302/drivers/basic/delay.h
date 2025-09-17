/**
 * @file delay.h
 * @brief 8051 延时函数头文件
 * @details 提供基于 12MHz 晶振的延时函数
 * @author qinglan
 * @note   依赖 REGX52.H
 */

#ifndef __DELAY_H__
#define __DELAY_H__

#include <REGX52.H>

/**
 * @brief 延时 500ms
 * @note  基于 12MHz 晶振
 */
void Delay500ms(void);

/**
 * @brief 延时指定毫秒
 * @param ms 延时时间，单位 ms
 * @note  最大值受 unsigned int 限制
 */
void Delayms(unsigned int ms);

#endif /* __DELAY_H__ */
