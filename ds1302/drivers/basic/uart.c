#include <REGX52.H>


/**
 * @brief 软件自动生成定时器双八位代码
 * 
 */
// void Uart1_Init(void)	//4800bps@12.000MHz
// {
// 	PCON |= 0x80;		//使能波特率倍速位SMOD
// 	SCON = 0x50;		//8位数据,可变波特率
// 	AUXR &= 0xBF;		//定时器时钟12T模式
// 	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
// 	TMOD &= 0x0F;		//设置定时器模式
// 	TMOD |= 0x20;		//设置定时器模式
// 	TL1 = 0xF3;			//设置定时初始值
// 	TH1 = 0xF3;			//设置定时重载值
// 	ET1 = 0;			//禁止定时器中断
// 	TR1 = 1;			//定时器1开始计时
// }




/**
  * @brief  串口初始化，只发不收4800bps@12.000MHz
  * @param  无
  * @retval 无
  */
void UART_Send_Init()
{
	SCON=0x40;  //0100 0000
	PCON |= 0x80;   //软件计算

    //八位自动重装，精度更高，使用软件自动生成代码
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式

	TL1 = 0xF3;			//设置定时初始值
	TH1 = 0xF3;			//设置定时重载值

	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
}


/**
 * @brief 串口初始化，收发
 * 
 */
 void UART_Init()
{
	SCON=0x50;
	PCON |= 0x80;
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF3;		//设定定时初值
	TH1 = 0xF3;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA=1;		//允许接收
	ES=1;		//使能中断
}






/**
  * @brief  串口发送一个字节数据
  * @param  Byte 要发送的一个字节数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);   //软件复位
	TI=0;
}

/*串口中断函数模板
void UART_Routine() interrupt 4
{
	if(RI==1)	//RI是接收中断
	{
		P2 = SBUF;
		RI=0;
	}
}
*/


