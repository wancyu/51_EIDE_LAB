/**************************************************************
 * @file    delay.c           
 * @brief   C51 延时函数(8051 单片机)
 * @details 
 * @author  qinglan
 **************************************************************/

 #include <REGX52.H>	/**< 51 单片机寄存器定义头文件 */
 #include <INTRINS.H>	/**< _nop_() 函数所在头文件 */


 /**
  * @brief 延时 500ms
  * @details 12MHz晶振，代码由烧录软件自动生成
  */
 void Delay500ms(void)
{
    unsigned char i, j, k;

    _nop_();
    i = 4;
    j = 205;
    k = 187;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}

/**
 * @brief 延时指定时间，单位ms
 * @details 12MHz晶振，代码由烧录软件自动生成后经循环修改
 * 
 */
void Delayms(unsigned int ms)	
{
    while(ms)
    {
        
        unsigned char data i, j;

        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);

        ms --;
    }
}

