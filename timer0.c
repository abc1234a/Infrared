#include <REGX51.H>
/**
  * @brief  定时器0初始化
  * @param  无
  * @retval 无
  */

void Timer0_Init()
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TF0=0;//启动T0
	TR0=0;//定时器0不记时
	TL0 = 0;		//设置定时初值
	TH0 = 0;		//设置定时初值
	
}
/**
  * @brief  定时器0设置计数器值
  * @param  Value，要设置的计数器值，范围：0~65535
  * @retval 无
  */
void Timer0_SetCounter(unsigned int Value)
{
	TH0=Value/256;
	TL0=Value%256;
}
/**
  * @brief  定时器0获取计数器值
  * @param  无
  * @retval 计数器值，范围：0~65535
  */
unsigned int Timer0_GetCounter(void)
{
	return (TH0<<8)|TL0;

}
/**
  * @brief  定时器0启动停止控制
  * @param  Flag 启动停止标志，1为启动，0为停止
  * @retval 无
  */
void Timer0_Run(unsigned char Flag)

{
	TR0=Flag;
}