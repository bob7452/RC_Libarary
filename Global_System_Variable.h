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

                             // |bit_7|bit_6|bit_5|bit_4|bit_3|bit_2|bit_1|bit_0|  
typedef struct 
{
   uint8_t ADC_State_Flag;   // |bit_7|bit_6|bit_5|bit_4|bit_3|bit_2|bit_1|ADC_Initial_State|
                            
}System_Flag;

typedef struct
{
    uint32_t ADC_Time_Count;
}System_Count;

extern Data_From_ADC   ADC_Data;
extern System_Flag     Sys_Flag;
extern System_Count    Sys_Cnt;


extern uint8_t Hall_Status;


#endif