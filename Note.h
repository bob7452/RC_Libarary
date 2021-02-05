1. Special模式下 -> Period 怎麼跟 PPM對上 
    >> 應該是要等到完全收到一個Signal後才分析
    >> 但共用怎辦?
    >> 建議Special Mode 的頻率需>= 300Hz (3.3ms) 
    >> 以適用於防破碎


2. Dead-Band Code 
    {
        State 1. Pulse_Width 等於 u16CaptureCmdMin -> PPM_Float_Count 為 0 且 PPM這次不更新
        State 2. (Pulse_Width - u16CaptureCmdMin) == 1  && (u16CaptureCmdDOWN == 0) ->  PPM_Float_Count 為 0 且 PPM這次更新;  Down = MIN ; MIN = Pulse_Width
        State 3.                                                                                                                   



    }