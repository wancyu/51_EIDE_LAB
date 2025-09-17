/**
 * @file tim.c
 * @author chenyu
 * @brief 定时器函数

 */
#include "tim.h"




void Timer0_Init()
{
    //TMOD = 0x01;    //0000 0001
    TMOD &= 0xF0;		//低四位清零，高四位不变，设置定时器模式
	TMOD |= 0x01;		//低四位设置，高四位不变，设置定时器模式
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
    TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
    //TH0 = 64535/256;    //起始数高八位
    //TL0 = 64535 % 256;  //起始数第八位
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}

/*定时器中断函数模板
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		
	}
}
*/



//  /**
//   * @brief led按键流水灯中断处理
//   * 
//   */
//  void Timer0_Routine() interrupt 1
// {
//     static unsigned int T0Count = 0;
//     /* 继续把起始数置于 64535 */
//     TL0 = 0x18;		//设置定时初值
// 	TH0 = 0xFC;		//设置定时初值
//     T0Count++;
//     if(T0Count >=1000){
//         T0Count = 0;
// 		if(LEDMode==0)			//模式判断
// 			P2=_crol_(P2,1);	//LED输出
// 		if(LEDMode==1)
// 			P2=_cror_(P2,1);
//     }
    
// }