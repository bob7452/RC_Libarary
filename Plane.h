#ifndef __Plane__H
#define __Plane__H

#include "stm32f0xx.h"
#include "Global_System_Variable.h"


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
#define Disturbance_Protection_Fnct Off

#define Special_Mode    On
#define SSR_Mode        On

#define Special_Mode_Hz 833
#define Special_Mode_Pulse_Min 395 
#define Special_Mode_Pulse_Mid 760
#define Special_Mode_Pulse_Max 1125
#define Special_Signal_Buffer 5

#define SSR_Mode_Pulse_Min 45
#define SSR_Mode_Pulse_Max 555
#define SSR_Signal_Buffer  0

#define Normal_Signal_Buffer 25

#define Signal_Loss_Mode  Back_To_Center       //     Back_to_Center ; Lock_Angle

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
#define Driving_Mode    Mix            //      Mix     Biopolar    Complement
#define Start_Up_Mode   Soft_Start    //      Soft_Start  Quick_Start
#define Stepping_Mode   On