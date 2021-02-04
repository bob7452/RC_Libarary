#ifndef __TIM_INPUT_CAPTUREG_H
#define __TIM_INPUT_CAPTUREG_H

#include "Plane.h"
#include "Global_System_Variable.h"

#define Period_Ratio_Signal_to_Control CLK_Freq_Mhz/ICP_CLK_MHZ

#define Muti_Mode_Compile	1//(Special_Mode+SSR_Mode)

#define ICP_Period_Finish 2
#define ICP_Pusle_Width_Finish 4

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


#define ICP_CLK_MHZ (uint32_t)(ICP_CLK / 1000000)
#define ICP_PRSC    ((System_Clock / ICP_CLK) - 1)


/*******************************************************************************************/
//                                  Special_Period                                         //
/*******************************************************************************************/
#if (Special_Mode_Hz <= 0)
	#error "Special_Mode_Hz is illegal"
#elif (Special_Mode_Period > 65535)
	#error "Special_Mode_Hz is illegal"
#else
	#define Special_Mode_Period_us ((unsigned long long) (1000000uL/Special_Mode_Hz) * ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  Special_Mode_Pulse_Min                                 //
/*******************************************************************************************/
#if (Special_Mode_Pulse_Min <=0)
    #error "Special_Mode_Period_Min is illegal"
#elif (Special_Mode_Pulse_Min >= Special_Mode_Pulse_Max)
    #error "Special_Mode_Period_Min is illegal"
#elif (Special_Mode_Pulse_Min >= Special_Mode_Pulse_Mid)
    #error "Special_Mode_Period_Min is illegal"
#elif (Special_Mode_Pulse_Min > 65535)
    #error "Special_Mode_Period_Min is illegal"
#else
    #define Special_Mode_Period_Min_us (Special_Mode_Period_Min*ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  Special_Mode_Pulse_Mid                                 //
/*******************************************************************************************/
#if (Special_Mode_Pulse_Mid <=0)
    #error "Special_Mode_Period_Mid is illegal"
#elif (Special_Mode_Pulse_Mid >= Special_Mode_Pulse_Max)
    #error "Special_Mode_Period_Mid is illegal"
#elif (Special_Mode_Pulse_Mid <= Special_Mode_Pulse_Min)
    #error "Special_Mode_Period_Mid is illegal"
#elif (Special_Mode_Pulse_Mid > 65535)
    #error "Special_Mode_Period_Mid is illegal"
#else
    #define Special_Mode_Period_Mid_us (Special_Mode_Period_Mid*ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  Special_Mode_Pulse_Max                                 //
/*******************************************************************************************/
#if (Special_Mode_Pulse_Max <=0)
    #error "Special_Mode_Period_Max is illegal"
#elif (Special_Mode_Pulse_Max <= Special_Mode_Pulse_Mid)
    #error "Special_Mode_Period_Max is illegal"
#elif (Special_Mode_Pulse_Max <= Special_Mode_Pulse_Min)
    #error "Special_Mode_Period_Max is illegal"
#elif (Special_Mode_Pulse_Max > 65535)
    #error "Special_Mode_Period_Max is illegal"
#else
    #define Special_Mode_Period_Max_us (Special_Mode_Period_Max*ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  Special_Signal_Buffer                                  //
/*******************************************************************************************/
#if (Special_Signal_Buffer < 0)
    #error "Special_Signal_Buffer is illegal"
#elif (Special_Signal_Buffer > 50)
    #error "Special_Signal_Buffer is illegal"
#else
    #define Special_Singal_Therehold (Special_Signal_Buffer*ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  SSR_Mode_Pulse_Min                                     //
/*******************************************************************************************/
#if (SSR_Mode_Pulse_Min <0)
    #error "SSR_Mode_Pulse_Min is illegal"
#elif (SSR_Mode_Pulse_Min >= SSR_Mode_Pulse_Max)
    #error "SSR_Mode_Pusle_Min is illegal"
#elif (SSR_Mode_Pulse_Min >= SSR_Mode_Pulse_Mid)
    #error "SSR_Mode_Pusle_Min is illegal"
#else
    #define SSR_Mode_Pulse_Min_us (SSR_Mode_Pulse_Min*ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  SSR_Mode_Pulse_Mid                                     //
/*******************************************************************************************/
#if (SSR_Mode_Pulse_Mid <0)
    #error "SSR_Mode_Pulse_Mid is illegal"
#elif (SSR_Mode_Pulse_Mid >= SSR_Mode_Pulse_Max)
    #error "SSR_Mode_Pusle_Mid is illegal"
#elif  (SSR_Mode_Pulse_Min >= SSR_Mode_Pulse_Mid)
    #error "SSR_Mode_Pusle_Mid is illegal"
#else
    #define SSR_Mode_Pulse_Mid_us (SSR_Mode_Pulse_Mid*ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  SSR_Mode_Pulse_Max                                     //
/*******************************************************************************************/
#if (SSR_Mode_Pulse_Max <0)
    #error "SSR_Mode_Pulse_Max is illegal"
#elif (SSR_Mode_Pulse_Min >= SSR_Mode_Pulse_Max)
    #error "SSR_Mode_Pusle_Max is illegal"
#elif (SSR_Mode_Pulse_Mid >= SSR_Mode_Pulse_Max)
    #error "SSR_Mode_Pusle_Mid is illegal"
#else
    #define SSR_Mode_Pulse_Max_us (SSR_Mode_Pulse_Max*ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  SSR_Signal_Buffer                                      //
/*******************************************************************************************/
#if (SSR_Signal_Buffer < 0)
    #error "SSR_Signal_Buffer is illegal"
#elif (SSR_Signal_Buffer >50)
    #error "SSR_Signal_Buffer is illegal"
#else
    #define SSR_Signal_Therehold (SSR_Signal_Buffer*ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  Normal_Signal_Buffer                                   //
/*******************************************************************************************/
#if (Normal_Signal_Buffer < 0)
    #error "Normal_Signal_Buffer is illegal"
#elif (Normal_Signal_Buffer >50)
    #error "Normal_Signal_Buffer is illegal"
#else
    #define Normal_Signal_Therehold (Normal_Signal_Buffer*ICP_CLK_MHZ)
#endif

/*******************************************************************************************/
//                                  Basic_PPM_Functions                                    //
/*******************************************************************************************/
void TIM_IC_Init(void);
void PPM_Capture_Parameters_Init(sEscParas_t* EscConfig);
void TIM_Input_Capture_Interrupt_Fnct(void);
void PPM_Process_Fnct();

/*******************************************************************************************/
//                                  Muti_Range_Detection                                   //
/*******************************************************************************************/
#if(Muti_Mode_Compile >=1)
    void Muti_Range_Detection (void);
#endif

/*******************************************************************************************/
//                                  PPM_Filter_Fnct                                        //
/*******************************************************************************************/
void PPM_Filter_Fnct();

#endif 
