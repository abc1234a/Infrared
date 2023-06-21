#include <REGX51.H>
 void Int0_Init(void)
 {
  
	IT0 = 1;	// 低电平触发
	IE0 = 0;	// 中断标志位
	EX0 = 1;	// 打开中断
	EA = 1;		// 打开中断
	PX0 = 1;	// 设置中断优先级，1为高优先级
 }


 
 //void Int0_Rountine(void) interrupt 0 // 设置中断号

//{
//}