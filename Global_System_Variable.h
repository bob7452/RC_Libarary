#ifndef __Global_System_Variable__H
#define __Global_System_Variable__H

#include "Plane.h"

/*******************************************************************************************/
//                             System_Definition                                           //
/*******************************************************************************************/
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
#define V_FACTOR (uint16_t)(4096 * R_SHUNT2 / (R_SHUNT1 + R_SHUNT2))

typedef struct 
{
    uint16_t    U16_VDCBus;
    int16_t     I16_Position;
    uint16_t    U16_VDD;
    uint16_t    U16_Temperature;
    int16_t     I16_D_Factor; // VR ADC_value <-> S16 Form
}Data_From_ADC;


/*******************************************************************************************/
//                                         PWM                                             //
/*******************************************************************************************/
enum PWM_Status 
{
    Brake =0,
    Run,
    FreeRun
};

typedef struct
{
  volatile unsigned short        PWM1;
  volatile unsigned short        PWM2;
  volatile unsigned short        PWM3;
  volatile unsigned short        CCER_Reg;
  volatile unsigned char         Hall_Status;
  volatile unsigned char         PWM_Status;
} PWM_OutputTypeDef;

typedef struct 
{
   uint8_t ADC_State_Flag;   
                            
}System_Flag;

typedef struct
{
    uint32_t ADC_Time_Count;
}System_Count;

extern Data_From_ADC        ADC_Data;
extern System_Flag          Sys_Flag;
extern System_Count         Sys_Cnt;
extern PWM_OutputTypeDef    Pwm_Output;


#endif