#ifndef __Plane__H
#define __Plane__H

#include "stm32f0xx.h"
#include "ADC_Initial_Fnct.h"
#include "ADC_Transform.h"

typedef struct 
{
   uint8_t ADC_State_Flag;
}System_Flag;

typedef struct
{
    uint32_t ADC_Time_Count;
}System_Count;

