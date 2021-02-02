#ifndef __TIMX_HALL_H
#define __TIMX_HALL_H

#include "Plane.h"
#include "Global_System_Variable.h"

//-------------------------------------------------------------------------------------
#define HALL_GPIO_PORT 						GPIOA
//Hall-1
#define HALL_U_GPIO_PORT 					GPIOA
#define HALL_U_GPIO_PIN         			GPIO_Pin_0
#define HALL_U_GPIO_SOURCE 					GPIO_PinSource0
#define HALL_U_GPIO_CLK    					RCC_AHBPeriph_GPIOA
#define HALL_U_GPIO_AF 						GPIO_AF_2
//Hall-2
#define HALL_V_GPIO_PORT 					GPIOA
#define HALL_V_GPIO_PIN         			GPIO_Pin_2
#define HALL_V_GPIO_SOURCE 		            GPIO_PinSource2
#define HALL_V_GPIO_CLK    					RCC_AHBPeriph_GPIOA
#define HALL_V_GPIO_AF 						GPIO_AF_2
//Hall-3
#define HALL_W_GPIO_PORT 					GPIOA
#define HALL_W_GPIO_PIN     		    	GPIO_Pin_1
#define HALL_W_GPIO_SOURCE                  GPIO_PinSource1
#define HALL_W_GPIO_CLK    					RCC_AHBPeriph_GPIOA
#define HALL_W_GPIO_AF 						GPIO_AF_2


#define HALL_STATE2 						HALL_V_GPIO_PIN
#define HALL_STATE6						  	(HALL_V_GPIO_PIN | HALL_W_GPIO_PIN)
#define HALL_STATE4 					  	HALL_W_GPIO_PIN
#define HALL_STATE5 		    			(HALL_U_GPIO_PIN | HALL_W_GPIO_PIN)
#define HALL_STATE1 				   	    HALL_U_GPIO_PIN
#define HALL_STATE3 					    (HALL_U_GPIO_PIN | HALL_V_GPIO_PIN)

typedef enum
{
  SECTOR_0 = 0x00,
  SECTOR_1 = 0x01,
  SECTOR_2 = 0x02,
  SECTOR_3 = 0x03,
  SECTOR_4 = 0x04,
  SECTOR_5 = 0x05,
  SECTOR_6 = 0x06,
  SECTOR_ERR = 0xFF
} SECTOR_VALUE_DEF;

#define GET_HALL_SENSOR_VALUE()        	(((HALL_U_GPIO_PORT->IDR & HALL_U_GPIO_PIN) >> HALL_U_GPIO_SOURCE)| \
	                                    (((HALL_V_GPIO_PORT->IDR & HALL_V_GPIO_PIN) >> HALL_V_GPIO_SOURCE)   << 1) | \
	                                    (((HALL_W_GPIO_PORT->IDR & HALL_W_GPIO_PIN) >> HALL_W_GPIO_SOURCE) << 2))


void HALL_Init(void);
void HALL_State(PWM_OutputTypeDef* PWM);

#endif /*__TIMX_HALL_H */
