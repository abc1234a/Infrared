#include <REGX51.H>
#include "timer0.h"
#include "Int0.h"
unsigned int IR_time;
unsigned char IR_State;
unsigned char IR_Data[4];
unsigned char IR_PData;
unsigned char IR_DataFlage;
unsigned char IR_RepeatFlag;
unsigned char IR_Address;
unsigned char IR_Command;

void IR_Init(void) // 初始化
{
	  Timer0_Init();
    Int0_Init();
    
}
unsigned char IR_GetDataFlag(void)//判断是否收到数据帧标志位
{
if(IR_DataFlage)
{
    IR_DataFlage=0;
    return 1;//收到
}
return 0;//没收到
}
unsigned char IR_GetRepeatFlag(void)//是否收到连发帧标志位
{
if(IR_RepeatFlag)
{
    IR_RepeatFlag=0;
    return 1;//收到
}
return 0;//没收到
}
unsigned char IR_GetAddress(void)//收到的地址数据
{
return IR_Address;
}
unsigned char IR_GetCommand(void)//收到的命令数据
{
    return IR_Command;
}

void Int0_Routine(void) interrupt 0 // 设置中断号,外部中断0，下降沿触发

{
    if (IR_State == 0) // 状态0 ，处于空闲状态
    {
        Timer0_SetCounter(0); // 计数器初值置0
        Timer0_Run(1);        // 启动计数器
        IR_State = 1;
    }
    else if (IR_State == 1) // 状态1，等待Start信号或Repeat信号
    {
        IR_time = Timer0_GetCounter(); //获取上一次中断到此次中断的时间                     // 获取上一次中断到此次中断的时间
        Timer0_SetCounter(0);  //定时计数器清0                             // 计数器初值置0
        if (IR_time > 12442 - 500 && IR_time < 13500 + 500) // 如果计时为13.5ms，则接收到了Start信号
        {
            IR_State = 2; // 状态2
        }
        else if (IR_time > 10368 - 500 && IR_time < 11250 + 500) // 如果计时为11.25ms，则接收到Repeat信号
        {
            IR_RepeatFlag = 1;
            Timer0_Run(0); // 停止计数器
            IR_State = 0;
        }
        else
        {
            IR_State = 1;
        }
    }
    else if (IR_State == 2)
    {
        IR_time =Timer0_GetCounter(); //获取上一次中断到此次中断的时间
        Timer0_SetCounter(0);     //定时计数器清0
        if (IR_time > 1032 - 500 && IR_time < 1032 + 500) // 如果计时为1120uS，则接收到了Start信号
        {
          IR_Data[IR_PData/8]&=~(0X01<<(IR_PData%8));//数据位置清0
          IR_PData++;//数据位指针叠加
        }
        else if (IR_time > 2074 - 500 && IR_time < 2074 + 500) // 如果计时为2250uS，则接收到Repeat信号
        {
            IR_Data[IR_PData/8]|=(0X01<<(IR_PData%8));//数据位置1
          IR_PData++;//数据位指针叠加
        }
        else					//接收出错
		{
			IR_PData=0;			//数据位置指针清0
			IR_State=1;			//置状态为1
		}
        if(IR_PData>=32)
        {
            IR_PData=0;//数据位置指针清0
            if(IR_Data[0]==~IR_Data[1]&&(IR_Data[2]==~IR_Data[3]))//数据验证
            {
                
                IR_Address=IR_Data[0];//数据转存
                IR_Command=IR_Data[2];//数据转存
                IR_DataFlage=1;//置收到连发帧标志位为1
            }
            Timer0_Run(0);//停止计数器
            IR_State=0;//状态清0
        }
    }
}