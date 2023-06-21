#include <REGX51.H>
#include "Delay.h"
unsigned int table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void Nixie (unsigned int location,number)//定义数码管的位置和显示的数字
{
switch(location)
{
	//74HC138译码器的定义
	case 1:P2_4=1;P2_3=1;P2_2=1;break; //LED1对应Y0[000]
	case 2:P2_4=1;P2_3=1;P2_2=0;break;//LED2对应Y1[001]
	case 3:P2_4=1;P2_3=0;P2_2=1;break;//LED3对应Y2[010]
	case 4:P2_4=1;P2_3=0;P2_2=0;break;//LED4对应Y3[011]
	case 5:P2_4=0;P2_3=1;P2_2=1;break; //LED5对应Y4[100]
	case 6:P2_4=0;P2_3=1;P2_2=0;break;//LED6对应Y5[101]
	case 7:P2_4=0;P2_3=0;P2_2=1;break;//LED7对应Y6[110]
	case 8:P2_4=0;P2_3=0;P2_2=0;break;//LED8对应Y7[111]
	}
P0=table[number];
//	Delay(2);
////	P0=0X00;
}