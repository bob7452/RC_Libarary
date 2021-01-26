#ifndef __Plane__H
#define __Plane__H

#include "stm32f0xx.h"
#include "ADC_Initial_Fnct.h"
#include "ADC_Transform.h"

/*******************************************************************************************/
//                             System_Definition                                           //
/*******************************************************************************************/
#define System_Clock      16000000uL
#define System_Extern_Osi 16000000uL

enum System_State_Machine
{
    Initial =0,
    Start,
    Finish
};

/*******************************************************************************************/
//                                         ADC                                             //
/*******************************************************************************************/
#define R_SHUNT1 75
#define R_SHUNT2 10
#define V_FACTOR (uint16_t)(4096 * VR_SHUNT2 / (R_SHUNT1 + R_SHUNT2))

#define Pos_Filter 32
#define ADC_Sampling_Initial_Time_Count 999


/*******************************************************************************************/
//                                         PWM                                             //
/*******************************************************************************************/
#define PWM_TIM_OUTPUT_PERIOD     (16000)
#define DEADTIME_NS 			   450 //840

