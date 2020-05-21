#include "stm32f4xx.h"                  // Device header

void delay(uint32_t time)
{
	while(time)
		time--;
}



int main()
{
	GPIO_InitTypeDef GPIO_InitStructure; // Defining variable to reach structure
	uint8_t button_input;
	uint8_t counter;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100Mhz;
	GPIO_Init(GPIOD, &GPIO_InitStructure); // D port is going to be output
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStucture); // A port is going to be the output
	while(1)
	{
	button_input= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
		
	if(button_input)
	{
		delay(10000000);
		counter++;
	}
	
	//SetBits = 3.3V & ResetBits = 0V
	
	if( (counter % 8)==0)
	{
		GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 );
	}
		
		
	if( (counter % 8)==1) //Red
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_12);
		GPIO_SetBits(GPIOD,GPIO_Pin_13 | GPIO_Pin_14);
	}
	if( (counter % 8)==2) //Green
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_13);
		GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_14);
	}
	if( (counter % 8)==3) //Blue
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_14);
		GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13);
	
	}
	if( (counter % 8)==4) //Yellow
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13);
		GPIO_SetBits(GPIOD,GPIO_Pin_14);
	}
	if( (counter % 8)==5) //Purple
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_14);
		GPIO_SetBits(GPIOD,GPIO_Pin_13);
	}
	
	if( (counter % 8)== 6) //Cyan
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_13 | GPIO_Pin_14);
		GPIO_SetBits(GPIOD,GPIO_Pin_12);
	}
	if( (counter % 8)==7) //White
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
	}
	
	
	
	
		
	}
	
	
	
	
	



}