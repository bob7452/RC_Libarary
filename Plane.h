#ifndef __Plane__H
#define __Plane__H

#include "stm32f0xx.h"

enum Mode_Switch
{
    OFF =0,
    ON
};

enum Motor_Driving_Mode
{
    Biopolar =0,
    Complement,
    Mix
};

/*******************************************************************************************/
//                                  System_Definition                                      //
/*******************************************************************************************/
#define System_Clock      16000000uL

/*******************************************************************************************/
//                                         ADC                                             //
/*******************************************************************************************/
#define R_SHUNT1 75
#define R_SHUNT2 10

#define Pos_Filter 32
#define ADC_Sampling_Initial_Time_Count 999

/*******************************************************************************************/
//                                         PWM                                             //
/*******************************************************************************************/
#define PWM_FREQ                  16000
#define DEADTIME_NS 			  450 


/*******************************************************************************************/
//                                         ICP                                             //
/*******************************************************************************************/
#define Disturbance_Protection_Fnct OFF


#define Special_Mode    On
#define SSR_Mode        On
#define Normal          On

#define Special_Mode_Period_us 2400
#define Special_Mode_Min_us 395 
#define Special_Mode_Max_us 1125
#define Special_Mode_Mid_us 760
/*******************************************************************************************/
//                                         PID                                             //
/*******************************************************************************************/
#define PID_Pos_Loop_Time   19   //     (19 + 1) * 100u = 2ms
#define PID_Pos_Unit_Time   2    //     50/(PID_POSITION_SAMPLING_TIME+1)

#define PID_Spd_Loop_Time   9    //     ( 9 + 1) * 100u = 1ms
#define PID_Spd_Unit_Time   1	 //     10/(PID_SPEED_SAMPLING_TIME+1)


/*******************************************************************************************/
//                                     Control Mode                                        //
/*******************************************************************************************/
#define Driving_Mode Mix