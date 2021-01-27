#include "Control.h"

void Intial_Operation(void)
{
	int32_t i32AngelTmp;
	//PPMPT
	// gi16TargetAngle = (int16_t)( ( ( (int32_t)u16CaptureMid - (int32_t)3000 ) * 8192 ) / u16CaptureDiv );
	i32AngelTmp = ((int32_t)u16CaptureMid - (int32_t)u16CaptureMid);
	gi16TargetAngle = (int16_t)(( i32AngelTmp*(int32_t)PPM_FACTOR )/(int32_t)u16CaptureDiv);  
	gi16TargetAngle = i16ST_New + gi16TargetAngle;
	gi16TargetAngle_old = gi16TargetAngle;
	//gi32TargetAngle_Smooth = gi16TargetAngle * 100;
	gi32TargetAngle_Smooth = gi16TargetAngle << 5;
}	