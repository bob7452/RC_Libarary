#ifndef __Plane__H
#define __Plane__H

#include "stm32f0xx.h"
#include "ADC_Initial_Fnct.h"
#include "ADC_Transform.h"

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

#define ADC_Sampling_Initial_Time_Count 999
#define Pos_Filter 32

typedef struct 
{
    uint16_t    U16_VDCBus;
    int16_t     I16_Position;
    uint16_t    U16_VDD;
    uint16_t    U16_Temperature;
    int16_t     I16_D_Factor; // VR ADC_value <-> S16 Form
}Data_From_ADC;

typedef struct 
{
   uint8_t ADC_State_Flag;
}System_Flag;

typedef struct
{
    uint32_t ADC_Time_Count;
}System_Count;

