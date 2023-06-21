#include <REGX51.H>
/**
  * @brief  ��ʱ��0��ʼ��
  * @param  ��
  * @retval ��
  */

void Timer0_Init()
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TF0=0;//����T0
	TR0=0;//��ʱ��0����ʱ
	TL0 = 0;		//���ö�ʱ��ֵ
	TH0 = 0;		//���ö�ʱ��ֵ
	
}
/**
  * @brief  ��ʱ��0���ü�����ֵ
  * @param  Value��Ҫ���õļ�����ֵ����Χ��0~65535
  * @retval ��
  */
void Timer0_SetCounter(unsigned int Value)
{
	TH0=Value/256;
	TL0=Value%256;
}
/**
  * @brief  ��ʱ��0��ȡ������ֵ
  * @param  ��
  * @retval ������ֵ����Χ��0~65535
  */
unsigned int Timer0_GetCounter(void)
{
	return (TH0<<8)|TL0;

}
/**
  * @brief  ��ʱ��0����ֹͣ����
  * @param  Flag ����ֹͣ��־��1Ϊ������0Ϊֹͣ
  * @retval ��
  */
void Timer0_Run(unsigned char Flag)

{
	TR0=Flag;
}