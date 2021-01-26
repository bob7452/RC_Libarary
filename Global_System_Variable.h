#ifndef __Global_System_Variable__H
#define __Global_System_Variable__H

#include "Plane.h"

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


#endif