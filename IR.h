#ifndef __IR0_H__
#define __IR0_H__
#define IR_POWER 0X45
#define IR_MODE 0X46
#define IR_MUTE 0X47
#define IR_START_STOP 0X44
#define IR_PREVIOUS 0X40
#define IR_NEXT 0X43
#define IR_EQ 0X07
#define IR_VOL_MTNUS 0X15
#define IR_VOL_ADD 0X09
#define IR_0 0X16
#define IR_RPT 0X19
#define IR_USD 0X0D
#define IR_1 0X0C
#define IR_2 0X18
#define IR_3 0X5E
#define IR_4 0X08
#define IR_5 0X1C
#define IR_6 0X5A
#define IR_7 0X42
#define IR_8 0X52
#define IR_9 0X4A
void IR_Init(void);                   // 初始化
unsigned char IR_GetDataFlag(void);   // 判断是否收到数据帧标志位
unsigned char IR_GetRepeatFlag(void); // 是否收到连发帧标志位
unsigned char IR_GetAddress(void);    // 收到的地址数据
unsigned char IR_GetCommand(void);    // 收到的命令数据
#endif