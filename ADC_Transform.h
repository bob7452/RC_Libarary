#ifndef __ADC_Transform__H
#define __ADC_Transform__H

#include "stm32f0xx.h"
#include "Plane.h"

#define Pos_Filter 32

static __IO uint16_t pu16RegularConvData_Tab[8];
static __IO uint16_t  gu16VDCBus;       //Unit: mV
static __IO int16_t   gi16Position ;    //Unit: deg 
static __IO uint16_t  gu16VDD;          //Unit: mV
static __IO uint16_t  gu16Temperature;  //Unit: C

typedef struct 
{
    uint16_t    U16_VDCBus;
    int16_t     I16_Position;
    uint16_t    U16_VDD;
    uint16_t    U16_Temperature;
    int16_t     I16_D_Factor; // VR ADC_value <-> S16 Form
}Data_From_ADC;

void ADC_Transfrom_Fnct(Data_From_ADC * ADC_Data,System_Count * Sys_Cnt,System_Flag* Sys_Flag)

#endif