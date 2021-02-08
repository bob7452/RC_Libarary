#include "ADC.h"

static __IO uint16_t  pu16RegularConvData_Tab[8];
static __IO uint16_t  gu16VDCBus;       //Unit: mV
static __IO int16_t   gi16Position ;    //Unit: deg 
static __IO uint16_t  gu16VDD;          //Unit: mV
static __IO uint16_t  gu16Temperature;  //Unit: C
static __IO uint8_t   ADC_Flag ;



void ADC_Initial_Fnct(void)
{
	GPIO_InitTypeDef 	GPIO_InitStructure;
	ADC_InitTypeDef     ADC_InitStructure;
	DMA_InitTypeDef 	DMA_InitStructure;

    #if ADC_Samping_Mode 
	    NVIC_InitTypeDef  NVIC_InitStructure;
    #endif

	unsigned volatile char adc_num_x    = ADC_GPIO_x;
	GPIO_TypeDef* 	pADC_Port[] 		= ADC_GPIO_x_PORT;
	unsigned short 	pADC_Pin[] 			= ADC_GPIO_x_PIN;
	unsigned int 	pADC_Pin_Clk[] 	    = ADC_GPIO_x_CLK;	

	ADC_DeInit(ADC1);

	// Configure ADC Channel11 as analog input
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL;
	while (adc_num_x)
	{ 
	    adc_num_x--;

		// GPIO Periph clock enable
		RCC_AHBPeriphClockCmd(pADC_Pin_Clk[adc_num_x], ENABLE);

		// Configure the ADC pin
		GPIO_InitStructure.GPIO_Pin = pADC_Pin[adc_num_x];
		GPIO_Init(pADC_Port[adc_num_x], &GPIO_InitStructure);
	}

	// ADC1 Periph clock enable
	RCC_APB2PeriphClockCmd(ADC_IP_CLK, ENABLE);

	ADC_StructInit(&ADC_InitStructure);

	ADC_InitStructure.ADC_Resolution 				    = ADC_Resolution_12b; 

	#if ADC_Samping_Mode
        ADC_InitStructure.ADC_ContinuousConvMode 		= DISABLE;
        ADC_InitStructure.ADC_ExternalTrigConvEdge      = ADC_ExternalTrigConvEdge_Rising;
        ADC_InitStructure.ADC_ExternalTrigConv 		    = ADC_ExternalTrigConv_T1_CC4;   
    #else 
        ADC_InitStructure.ADC_ContinuousConvMode 		= ENABLE;
        ADC_InitStructure.ADC_ExternalTrigConvEdge      = ADC_ExternalTrigConvEdge_None;
	#endif

	ADC_InitStructure.ADC_DataAlign 				= ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ScanDirection 			= ADC_ScanDirection_Upward;
	ADC_Init(ADC1, &ADC_InitStructure);
	
    #if ADC_Samping_Mode
        NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&NVIC_InitStructure);	 
    #endif

	// DMA1 clock enable
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

	// DMA1 Channel1 Config
	DMA_DeInit(DMA1_Channel1);

	DMA_InitStructure.DMA_PeripheralBaseAddr		 = (uint32_t)ADC1_DR_Address;
	DMA_InitStructure.DMA_MemoryBaseAddr			 = (uint32_t)pu16RegularConvData_Tab;
	DMA_InitStructure.DMA_DIR 						 = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize				 = DMA_Buffer_Size;//4;//6;
	DMA_InitStructure.DMA_PeripheralInc 			 = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc                  = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize         = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize             = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode                       = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority                   = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M                        = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure); 

	// DMA1 Channel1 enable
	DMA_Cmd(DMA1_Channel1, ENABLE);

	// Enable DMA1 Channel1 Transfer Complete interrupt
	DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);

	ADC_ChannelConfig(ADC_IP, ADC_CHANNEL_ALL, ADC_SampleTime_7_5Cycles);
	ADC_ChannelConfig(ADC_IP, (ADC_Channel_TempSensor | ADC_Channel_Vrefint), ADC_SampleTime_71_5Cycles);

	ADC_TempSensorCmd(ENABLE);
	ADC_VrefintCmd(ENABLE);

	ADC_GetCalibrationFactor(ADC_IP);

	// ADC DMA request in circular mode
	ADC_DMARequestModeConfig(ADC_IP, ADC_DMAMode_Circular);

	// Enable ADC_DMA
	ADC_DMACmd(ADC_IP, ENABLE);

	// Enable the ADC peripheral
	ADC_Cmd(ADC_IP, ENABLE);

	// Wait the ADCEN falg
	while (!ADC_GetFlagStatus(ADC_IP, ADC_FLAG_ADEN)) ;

	// ADC1 regular Software Start Conv
	ADC_StartOfConversion(ADC_IP);
}


void ADC_Transfrom_Fnct(Data_From_ADC * ADC_Data,System_Count * Sys_Cnt)
{
    uint8_t ADC_Initial_Flag = (ADC_Flag & Start); 
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
            ADC_Flag |= Start;
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
                ADC_Flag |= Start;
                ADC_Data->U16_VDD = gu16VDD;
                ADC_Data->U16_VDCBus = gu16VDCBus;
                ADC_Data->U16_Temperature = gu16Temperature;
                ADC_Data->I16_Position = gi16Position;
            }
        }
    #endif
}
