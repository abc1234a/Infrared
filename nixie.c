#include <REGX51.H>
#include "Delay.h"
unsigned int table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void Nixie (unsigned int location,number)//��������ܵ�λ�ú���ʾ������
{
switch(location)
{
	//74HC138�������Ķ���
	case 1:P2_4=1;P2_3=1;P2_2=1;break; //LED1��ӦY0[000]
	case 2:P2_4=1;P2_3=1;P2_2=0;break;//LED2��ӦY1[001]
	case 3:P2_4=1;P2_3=0;P2_2=1;break;//LED3��ӦY2[010]
	case 4:P2_4=1;P2_3=0;P2_2=0;break;//LED4��ӦY3[011]
	case 5:P2_4=0;P2_3=1;P2_2=1;break; //LED5��ӦY4[100]
	case 6:P2_4=0;P2_3=1;P2_2=0;break;//LED6��ӦY5[101]
	case 7:P2_4=0;P2_3=0;P2_2=1;break;//LED7��ӦY6[110]
	case 8:P2_4=0;P2_3=0;P2_2=0;break;//LED8��ӦY7[111]
	}
P0=table[number];
//	Delay(2);
////	P0=0X00;
}