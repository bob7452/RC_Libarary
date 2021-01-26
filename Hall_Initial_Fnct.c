#include "Hall_Initial_Fnct.h"


void HALL_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	// GPIO Periph clock enable
	RCC_AHBPeriphClockCmd(HALL_U_GPIO_CLK, ENABLE);
	RCC_AHBPeriphClockCmd(HALL_V_GPIO_CLK, ENABLE);
	RCC_AHBPeriphClockCmd(HALL_W_GPIO_CLK, ENABLE);

	// Configure PA0, PA1, PA2 as Hall sensors input
	GPIO_InitStructure.GPIO_Pin     = (HALL_U_GPIO_PIN | HALL_V_GPIO_PIN | HALL_W_GPIO_PIN);
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_2MHz;//GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
	GPIO_Init(HALL_U_GPIO_PORT, &GPIO_InitStructure);

	// Connect TIM pins to AF2
	GPIO_PinAFConfig(HALL_U_GPIO_PORT, HALL_U_GPIO_SOURCE, HALL_U_GPIO_AF);
	GPIO_PinAFConfig(HALL_V_GPIO_PORT, HALL_V_GPIO_SOURCE, HALL_V_GPIO_AF);
	GPIO_PinAFConfig(HALL_W_GPIO_PORT, HALL_W_GPIO_SOURCE, HALL_W_GPIO_AF);
}

