#ifndef __Global_System_Variable__H
#define __Global_System_Variable__H

#include "Plane.h"

/*******************************************************************************************/
//                             System_Clock_Declaration                                    //
/*******************************************************************************************/
// SysTick Parameters
#define ERROR_SAMPLING_TIME 	   		999		//(999 + 1) * 100u = 100ms
#define NO_CMD_TIME 			   		999	    //(4999 + 1) * 100u = 500ms
#define LED_FLICKER_TIME 		 		49999	    //(4999 + 1) * 100u = 5s
#define LED_LIGHT_TIME 			  		5000	    // 5000 * 100u = 500ms
#define LED_LIGHT_OFF_TIME 				(LED_FLICKER_TIME - LED_LIGHT_TIME)
#define PROTECTION_TIME 				999		//(999 + 1) * 100u = 100ms
#define DEBUG_TIME 						19999	//(4999 + 1) * 100u = 5s
#define DEBUG_TIME2 					59999	//(4999 + 1) * 100u = 5s
#define SETPWM_THRESHOLD_TIME  			9
#define ADC_SAMPLING_TIME      			0
#define IBusPROTECTION_TIME 	 		49		//(49 + 1) * 100u = 5ms
#define LOCK_PROTETION_TIME    			9999 //1 sec
#define LOCK_PROTETION_SEC		 		10


/*******************************************************************************************/
//                             System_Variable_Definition                                  //
/*******************************************************************************************/
#define System_Extern_Osi 16000000uL

enum System_State_Machine
{
    Initial =0,
    Start,
    Finish
};

typedef struct 
{
	// Protection
	uint16_t u16OvdOnOff;            // 0:Off, 1:On
	uint16_t u16OvdMaxVolt;          // 0~60
	uint16_t u16OvdRecVolt;          // 0~60
	uint16_t u16LvdOnOff;            // 0:Off, 1:On
	uint16_t u16LvdMinVolt;          // 0~60
	uint16_t u16LvdRecVolt;          // 0~60
	uint16_t u16MaxPwmDuty;          // 50~100%, interval 5%
	uint16_t u16MinPwmDuty;          // 0~100%, interval 1%
	uint16_t u16LockOnOff;           // 0:Off, 1:On
	uint16_t u16LockMaxPwmDuty;      // 0~100%
	uint16_t u16LockContTime;        // 0.5 ~ 600 sec
	uint16_t u16LockDecay;           //// 0 ~ 100 %/sec
	uint16_t u16TempProtOnOff;       // 0:Off, 1:On
	uint16_t u16TempProtStart;       // 60 ~ 95 degree C
	uint16_t u16TempRecovery;        // 70 ~ 105  
	uint16_t u16TempCutoff;	         // 80 ~ 200
	uint16_t u16TempDecay;	         //// 0 ~ 100 %
	uint16_t u16PpmLossTime;         // 0.1 ~ 5.0 sec
	uint16_t u16PpmLossAct;          // 0:free, 1:lock
	uint16_t u16HallFailOnOff;       // 0:Off, 1:On	
	uint16_t u16PtMaxAngle;          //// 0 ~ 360 degree C
	uint16_t u16PtMiddle;            //// 1048 ~ 3048	
}sProtection_t;

typedef struct 
{
	// Driving Basic Design
	uint16_t u16PulseCentralTime;    // 1300~1700us    
	uint16_t u16PulseHigherTime;     // 2100 +/- 200us
	uint16_t u16PulseHigherAng;      // 60 +/- 20 degree
	uint16_t u16PulseLowerTime;      // 900 +/- 200us
	uint16_t u16PulseLowerAng;       // -60 +/- 20 degree
	uint16_t u16DeadBand;            // 1~5
	uint16_t u16MotDrvLogic;         // 0:L, 1:H
	uint16_t u16PtDrvLogic;          // 0:L, 1:H
}sDrvBasic_t;

typedef struct 
{
	// Driving Advanced Design
	uint16_t u16Kp;                  // 0~65535
	uint16_t u16Ki;                  // 0~65535
	uint16_t u16Kd;                  // 0~65535
	uint16_t u16LoopSamplingTime;    // 1~50ms
	uint16_t u16MaxPwmDutyViSat;     // 1~100%
	uint16_t u16SleepMinPwmDutyVdl;  // 0~100%
	uint16_t u16SleepContTime;       // 0~60000ms
	uint16_t u16WakeupMaxPwmDutyVdh; // 0~100%
	uint16_t u16WakeupEmaxDegree;    // 0~360

	uint16_t u16PosiDiv;                     // 0~65535 cnt
	uint16_t u16SpdKpGain;               // 0~65535 cnt
	uint16_t u16MotorFreeErr;            // 0~65535 cnt
	uint16_t u16MotorFreeTime;        // 0~65535 ms

	uint16_t u16SpdKdGain;               // 0~65535 cnt    
	uint16_t u16SpdDiv;                     // 0~65535 cnt    
	uint16_t u16InitialSpeed;               // 0~65535 cnt
	uint16_t u16InitialTimeOut;    // 3~60 s
}sDrvAdvanced_t;

typedef struct 
{
	// Version Control
	uint8_t u8ProjectName[16];
	uint8_t u8FwVer[16];
}sVerCtrl_t;

typedef struct 
{   
	sProtection_t   Protect;
	sDrvBasic_t     DrvBas;
	sDrvAdvanced_t  DrvAdv;
	sVerCtrl_t      VerCtrl;
}sEscParas_t;

/*******************************************************************************************/
//                                         ADC                                             //
/*******************************************************************************************/
#define V_FACTOR (uint16_t)(4096 * R_SHUNT2 / (R_SHUNT1 + R_SHUNT2))

typedef struct 
{
    volatile uint16_t    U16_VDCBus;
    volatile int16_t     I16_Position;
    volatile uint16_t    U16_VDD;
    volatile uint16_t    U16_Temperature;
    volatile int16_t     I16_D_Factor; // VR ADC_value <-> S16 Form
}Data_From_ADC;


/*******************************************************************************************/
//                                         PWM                                             //
/*******************************************************************************************/
enum PWM_Status 
{
    PWM_Brake =0,
    PWM_Run,
    PWM_FreeRun
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

/*******************************************************************************************/
//                                         HALL_State                                      //
/*******************************************************************************************/
typedef enum
{
  SECTOR_0 = 0x00,
  SECTOR_1 = 0x01,
  SECTOR_2 = 0x02,
  SECTOR_3 = 0x03,
  SECTOR_4 = 0x04,
  SECTOR_5 = 0x05,
  SECTOR_6 = 0x06,
  SECTOR_ERR = 0xFF
} SECTOR_VALUE_DEF;

#define GET_HALL_SENSOR_VALUE()        	(((HALL_U_GPIO_PORT->IDR & HALL_U_GPIO_PIN) >> HALL_U_GPIO_SOURCE)| \
	                                    (((HALL_V_GPIO_PORT->IDR & HALL_V_GPIO_PIN) >> HALL_V_GPIO_SOURCE)   << 1) | \
	                                    (((HALL_W_GPIO_PORT->IDR & HALL_W_GPIO_PIN) >> HALL_W_GPIO_SOURCE) << 2))

/*******************************************************************************************/
//                                         FLAG                                            //
/*******************************************************************************************/
typedef struct 
{
   volatile uint8_t ADC_State_Flag;
   volatile uint8_t Input_Capture_Flag;
   volatile uint8_t SSR_FLAG;                        
}System_Flag;

/*******************************************************************************************/
//                                         Count                                           //
/*******************************************************************************************/
typedef struct
{
    volatile uint32_t ADC_Time_Count;
}System_Count;

/*******************************************************************************************/
//                             		Math_Formula_Define                                    //
/*******************************************************************************************/
#define Abs(x) (x ^ (x >> 31)) - (x >> 31)
#define Round_Value(x,y) (x+(y>>1))/y 
#define Round_Value_Nbit(x,N) (x+(1<<(N-1)))>>N
/*******************************************************************************************/
//                             		PID_Loop_Freq                                    	   //
/*******************************************************************************************/
#define PID_Loop_Freq_Mhz 10

/*******************************************************************************************/
//                              	Global_Variable_Define                                 //
/*******************************************************************************************/
extern Data_From_ADC        ADC_Data;
extern System_Flag          Sys_Flag;
extern System_Count         Sys_Cnt;
extern PWM_OutputTypeDef    Pwm_Output;
extern sEscParas_t          EscConfig;
extern sEscParas_t          EscConfig_Write;

#endif