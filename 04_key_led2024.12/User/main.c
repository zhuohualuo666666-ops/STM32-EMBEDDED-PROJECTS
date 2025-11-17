#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

uint8_t KeyNum;

int main(void)
{
	LED_init();//调用LED初始化函数
	Key_init();//调用按键初始化函数
	
	while(1)
	{
		KeyNum=Key_GetNum();//调取“按键数字获取”函数，获得返回值，判断按键是否按下
		if(KeyNum==1)//返回值为1，1号按键按下
		{
		LED1_Turn();//调用LED1电平反转函数
		}
		if(KeyNum==2)//返回值为2，11号按键按下
		{
		LED2_Turn();//调用LED2电平反转函数
		}
	}
}
