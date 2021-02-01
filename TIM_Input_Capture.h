#ifndef __TIM_INPUT_CAPTUREG_H
#define __TIM_INPUT_CAPTUREG_H

#include "Plane.h"
#include "Global_System_Variable.h"

#define IC_TIMx						        TIM3
#define IC_TIMx_CLK    					    RCC_APB1Periph_TIM3

#define IC_GPIO_PORT   				        GPIOB 
#define IC_GPIO_PIN         				GPIO_Pin_4                          
#define IC_GPIO_PINSOURCE    			    GPIO_PinSource4
#define IC_GPIO_CLK    				        RCC_AHBPeriph_GPIOB
#define IC_GPIO_AF_MODE				        GPIO_AF_1

#define ICP_CLK                             2000000uL
#define IC_FILTER                           (uint8_t)0x04
#define IC_Interrup                         TIM3_IRQn
#define IC_Channel_Pin                      TIM_Channel_1
#define IC_Channel_IT_Trigger_Source        TIM_IT_CC1

#if (ICP_CLK < System_Clock)
    #define ICP_CLK_MHZ (uint32_t)(ICP_CLK / 1000000)
    #define ICP_PRSC    ((System_Clock / ICP_CLK) - 1)
#else
    #error "ICP_CLK_Mhz is illegal"
#endif

#define Period_Ratio_Signal_to_Control CLK_Freq_Mhz/ICP_CLK_MHZ




void TIM_IC_Init(void);
void PPM_Capture_Parameters_Init(sEscParas_t* EscConfig);
void TIM_Input_Capture_Interrupt_Fnct(void);
void PPM_Process_Fnct();
void PPM_Filter_Fnct();

#endif 
