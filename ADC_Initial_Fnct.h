#ifndef __ADC_Initial_Fnct__H
#define __ADC_Initial_Fnct__H

#include "Plane.h"

/*******************************************************************************************/
//                                 ADC_Sample_Mode_Setting                                 //
/*******************************************************************************************/
#define ADC_Samping_Mode  0 // 0:Pulling 1:Interrupt


/*******************************************************************************************/
//                                 ADC_Sample_Common_Setting                               //
/*******************************************************************************************/
#define ADC_IP								ADC1
#define ADC_IP_CLK    						RCC_APB2Periph_ADC1
#define ADC1_DR_Address 0x40012440

#define ADC_1_GPIO_PORT   					GPIOA                                                 //TPC
#define ADC_1_PIN         					GPIO_Pin_0
#define ADC_1_GPIO_CLK    					RCC_AHBPeriph_GPIOA
#define ADC_1_CHANNEL						ADC_Channel_0

#define ADC_2_GPIO_PORT   					GPIOA                                                 //VPT
#define ADC_2_PIN         					GPIO_Pin_1
#define ADC_2_GPIO_CLK    					RCC_AHBPeriph_GPIOA
#define ADC_2_CHANNEL						ADC_Channel_1

#define ADC_3_GPIO_PORT   					GPIOA                                                 //
#define ADC_3_PIN         					GPIO_Pin_5
#define ADC_3_GPIO_CLK    					RCC_AHBPeriph_GPIOA
#define ADC_3_CHANNEL						ADC_Channel_5

#define ADC_4_GPIO_PORT   					GPIOA                                                 //
#define ADC_4_PIN         					GPIO_Pin_6
#define ADC_4_GPIO_CLK    					RCC_AHBPeriph_GPIOA
#define ADC_4_CHANNEL						ADC_Channel_6


#define ADC_CHANNEL_ALL			            (ADC_1_CHANNEL | ADC_2_CHANNEL | ADC_3_CHANNEL | ADC_4_CHANNEL)

#define ADC_GPIO_x 					        (4)
#define ADC_GPIO_x_PORT 				    {ADC_1_GPIO_PORT, ADC_2_GPIO_PORT, ADC_3_GPIO_PORT, ADC_4_GPIO_PORT}
#define ADC_GPIO_x_PIN						{ADC_1_PIN, ADC_2_PIN ,ADC_3_PIN,ADC_4_PIN}
#define ADC_GPIO_x_CLK    					{ADC_1_GPIO_CLK, ADC_2_GPIO_CLK, ADC_3_GPIO_CLK, ADC_4_GPIO_CLK}


#define DMA_Buffer_Size 6;    // Data Counts


void ADC_Initial_Fnct(void);

#endif