#ifndef __TIM_INPUT_CAPTUREG_H
#define __TIM_INPUT_CAPTUREG_H

#include "Plane.h"
#include "Global_System_Variable.h"

void TIM_IC_Init(void);
void TIM14_Capture_Parameters_Init(sSettingVar_t *tSetting);
void TIM_Input_Capture_Interrupt_Fnct(void);

#endif 
