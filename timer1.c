#include <REGX51.H>
/**
  * @brief  定时器1初始化
  * @param  无
  * @retval 无
  */

void Timer1_Init()
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TF1=0;//启动T0
	TR1=1;//T0溢出标志位清零
	TH1=0XA4;//THi=M=T_定时时间/T_机器周期,	假设定时时间为100微秒
	TL1=0XFF;//TLi=M=T_定时时间/T_机器周期，假设定时时间为100微秒
	ET1=1;//开放T1中断允许
	EA=1;//开放总中断允许
	PT1=0;//设置定时器T1为高优先中断
}