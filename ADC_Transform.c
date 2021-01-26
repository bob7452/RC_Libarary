#include "ADC_Transform.h"

static __IO uint16_t  pu16RegularConvData_Tab[8];
static __IO uint16_t  gu16VDCBus;       //Unit: mV
static __IO int16_t   gi16Position ;    //Unit: deg 
static __IO uint16_t  gu16VDD;          //Unit: mV
static __IO uint16_t  gu16Temperature;  //Unit: C

void ADC_Transfrom_Fnct(Data_From_ADC * ADC_Data,System_Count * Sys_Cnt,System_Flag* Sys_Flag)
{
    uint8_t ADC_Initial_Flag = (Sys_Flag->ADC_State_Flag & Start); 
    uint8_t ADC_Sample_Time_Out_Flag  = (Sys_Cnt-> ADC_Time_Count == 0);

     gu16VDD = (uint16_t)((uint32_t)5079040 / pu16RegularConvData_Tab[5]);   
     gu16VDCBus = (uint16_t)((uint32_t)pu16RegularConvData_Tab[0] * gu16VDD / V_FACTOR);
     gu16Temperature = pu16RegularConvData_Tab[2];
     gi16Position = (int16_t)(((uint32_t)pu16RegularConvData_Tab[1] * ADC_Data->I16_D_Factor) >> 11);
     gi16Position -= ADC_Data->I16_D_Factor;

    #if ADC_Samping_Mode
        if(ADC_Initial_Flag==Start)
        {
            ADC_Data->U16_VDD = (uint16_t)(((uint32_t)ADC_Data->U16_VDD *3 +gu16VDD)>>2);
            ADC_Data->U16_VDCBus = (uint16_t)(((uint32_t)ADC_Data->U16_VDCBus * 3 + gu16VDCBus) >> 2);   
            ADC_Data->U16_Temperature = (uint16_t)(((uint32_t)ADC_Data->U16_Temperature * 3 + gu16Temperature) >> 2);

            #if (Pos_Filter > 1)
                ADC_Data->I16_Position= (int16_t)(((int32_t)ADC_Data->I16_Position * (POS_FILTER - 1)+gi16Position + (POS_FILTER>>1))/POS_FILTER);
            #else
                ADC_Data->I16_Position = gi16Position;
            #endif
        }
        else
        {
            Sys_Flag->ADC_State_Flag |= Start;
            ADC_Data->U16_VDD = gu16VDD;
            ADC_Data->U16_VDCBus = gu16VDCBus;
            ADC_Data->U16_Temperature = gu16Temperature;
            ADC_Data->I16_Position = gi16Position;
        }
    #else
        if(ADC_Sample_Time_Out_Flag==Start)
        {
            Sys_Cnt->ADC_Time_Count = ADC_Sampling_Initial_Time_Count +1;
            if(ADC_Initial_Flag==Start)
            {
                ADC_Data->U16_VDD = (uint16_t)(((uint32_t)ADC_Data->U16_VDD *3 +gu16VDD)>>2);
                ADC_Data->U16_VDCBus = (uint16_t)(((uint32_t)ADC_Data->U16_VDCBus * 3 + gu16VDCBus) >> 2);   
                ADC_Data->U16_Temperature = (uint16_t)(((uint32_t)ADC_Data->U16_Temperature * 3 + gu16Temperature) >> 2);

                #if (Pos_Filter > 1)
                    ADC_Data->I16_Position= (int16_t)(((int32_t)ADC_Data->I16_Position * (POS_FILTER - 1)+ gi16Position + (POS_FILTER>>1))/POS_FILTER);
                #else
                    ADC_Data->I16_Position = gi16Position;
                #endif
            }
            else
            {
                Sys_Flag->ADC_State_Flag |= Start;
                ADC_Data->U16_VDD = gu16VDD;
                ADC_Data->U16_VDCBus = gu16VDCBus;
                ADC_Data->U16_Temperature = gu16Temperature;
                ADC_Data->I16_Position = gi16Position;
            }
        }
    #endif
}
