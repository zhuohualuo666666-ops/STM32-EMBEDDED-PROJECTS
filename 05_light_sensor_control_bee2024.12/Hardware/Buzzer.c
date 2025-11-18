#include "stm32f10x.h"                  // Device header
void Buzzer_init(void)
{
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}


void Buzzer_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);//PB12设置为低电平，蜂鸣器工作
}


void Buzzer_OFF(void)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_12);//PB12设置为高电平，蜂鸣器不工作
}



void Buzzer_Turn(void)//LED1电平反转函数
{
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_12)==0)//当PB12输出为低电平时
{
    GPIO_SetBits(GPIOB,GPIO_Pin_12);//PB12引脚置高电平
}
    else
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_12);//当PB12输出为高电平时，PB12引脚置低电平
}
}

