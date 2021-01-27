#ifndef __TIM1_PWMOUTPUT_H
#define __TIM1_PWMOUTPUT_H

#include "Plane.h"

/*******************************************************************************************/
//                                 PWM_Special_Setting                                     //
/*******************************************************************************************/
#define PWM_Interrupt 0
#define PWM_Preloader 0

/*******************************************************************************************/
//                                 PWM_Common_Setting                                      //
/*******************************************************************************************/
#define PWM_PERIOD                (uint16_t)((System_Clock / (uint32_t)(1 * PWM_FREQ * (PWM_PSC + 1))) - 1)
#define PWM_MAX_DUTY 			         PWM_PERIOD 
#define PWM_MIN_DUTY 			         0

#if (PWM_PERIOD <=0)
  #error "The PWM_Period is illegal"  
#endif

#if (DEADTIME_NS < 3556)
#define DEADTIME    ((unsigned short)((unsigned long long)SystemCoreClock \
                        * (unsigned long long)DEADTIME_NS/1000000000uL)) 
#elif (DEADTIME_NS > 3555 && DEADTIME_NS < 5334)                     
  #define DEADTIME    ((unsigned short)((unsigned long long)(SystemCoreClock )/ 2 \
                        * (unsigned long long)DEADTIME_NS/1000000000uL) - 64 + 128)                       
#elif (DEADTIME_NS > 5333 && DEADTIME_NS < 6223) 
  #define DEADTIME    ((unsigned short)((unsigned long long)(SystemCoreClock) / 8 \
                        * (unsigned long long)DEADTIME_NS /1000000000uL) - 32 + 192)                      
#elif (DEADTIME_NS > 6222  && DEADTIME_NS < 7084)  
  #define DEADTIME    ((unsigned short)((unsigned long long)SystemCoreClock / 16\
                        * (unsigned long long)DEADTIME_NS /1000000000uL) - 32 + 224)                       
#elif (DEADTIME_NS > 7083)
  #error "overflow deadtime can be setting maximum value"                        
#endif
												
#define PWM_TIMx						    TIM1
#define PWM_TIMx_CLK    					RCC_APB2Periph_TIM1
//1  CH1
#define PWM_UH_GPIO_PORT   				    GPIOA 
#define PWM_UH_PIN         				    GPIO_Pin_8                          
#define PWM_UH_PINSOURCE    			    GPIO_PinSource8
#define PWM_UH_GPIO_CLK    				    RCC_AHBPeriph_GPIOA
#define PWM_UH_GPIO_AF_MODE				    GPIO_AF_2
//2 CH2
#define PWM_VH_GPIO_PORT   				    GPIOA 
#define PWM_VH_PIN         				    GPIO_Pin_9             
#define PWM_VH_PINSOURCE    			    GPIO_PinSource9   
#define PWM_VH_GPIO_CLK    				    RCC_AHBPeriph_GPIOA
#define PWM_VH_GPIO_AF_MODE				    GPIO_AF_2
//3  CH3
#define PWM_WH_GPIO_PORT   				    GPIOA
#define PWM_WH_PIN         				    GPIO_Pin_10                                
#define PWM_WH_PINSOURCE   				    GPIO_PinSource10
#define PWM_WH_GPIO_CLK    				    RCC_AHBPeriph_GPIOA
#define PWM_WH_GPIO_AF_MODE				    GPIO_AF_2
//1
#define PWM_UL_GPIO_PORT   				    GPIOA
#define PWM_UL_PIN         				    GPIO_Pin_7                
#define PWM_UL_PINSOURCE    			    GPIO_PinSource7
#define PWM_UL_GPIO_CLK    				    RCC_AHBPeriph_GPIOA
#define PWM_UL_GPIO_AF_MODE				    GPIO_AF_2
//2
#define PWM_VL_GPIO_PORT   				    GPIOB
#define PWM_VL_PIN         				    GPIO_Pin_0                    
#define PWM_VL_PINSOURCE    			    GPIO_PinSource0
#define PWM_VL_GPIO_CLK    				    RCC_AHBPeriph_GPIOB
#define PWM_VL_GPIO_AF_MODE				    GPIO_AF_2
//3
#define PWM_WL_GPIO_PORT   				    GPIOB             
#define PWM_WL_PIN         				    GPIO_Pin_1                      
#define PWM_WL_PINSOURCE   				    GPIO_PinSource1
#define PWM_WL_GPIO_CLK    				    RCC_AHBPeriph_GPIOB
#define PWM_WL_GPIO_AF_MODE				    GPIO_AF_2

#define PWM_GPIO_NUM 						(6)

#define	PWM_GPIO_n_PORT 					{PWM_UH_GPIO_PORT, PWM_VH_GPIO_PORT, PWM_WH_GPIO_PORT,	\
											PWM_UL_GPIO_PORT, PWM_VL_GPIO_PORT, PWM_WL_GPIO_PORT}

#define PWM_GPIO_n_PIN   					{PWM_UH_PIN, PWM_VH_PIN, PWM_WH_PIN,										\
											PWM_UL_PIN, PWM_VL_PIN, PWM_WL_PIN}	

#define	PWM_GPIO_n_CLK						{PWM_UH_GPIO_CLK, PWM_VH_GPIO_CLK, PWM_WH_GPIO_CLK,			\
											PWM_UL_GPIO_CLK, PWM_VL_GPIO_CLK, PWM_WL_GPIO_CLK}

#define	PWM_GPIO_n_SOURCE					{PWM_UH_PINSOURCE, PWM_VH_PINSOURCE, PWM_WH_PINSOURCE,	\
											PWM_UL_PINSOURCE, PWM_VL_PINSOURCE, PWM_WL_PINSOURCE}

#define	PWM_GPIO_n_AF_MODE				    {PWM_UH_GPIO_AF_MODE, PWM_VH_GPIO_AF_MODE, PWM_WH_GPIO_AF_MODE, \
										    PWM_UL_GPIO_AF_MODE, PWM_VL_GPIO_AF_MODE, PWM_WL_GPIO_AF_MODE}

#define PWM_ONOFF(x)         			    TIMx_PWM_ONOFF(PWM_TIMx, x)
															
void TIM_PWM_Init(void);
void TIMx_PWM_ONOFF(TIM_TypeDef* TIXx ,eSwitchState_t eONOFF);

#endif /* __TIM1_PWMOUTPUT_H */
