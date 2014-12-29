#include "../Common/StdInc.h"
#include "Motor.h"
#include "../Device/PWM.h"

void MotorDrive(State_t* NextMotorState){
    
}

void SetToNext(State_t* NowMotorState,State_t *NextMotorState,State_t*TargetMotorState){
    if(TargetMotorState->direction != NowMotorState->direction){
        __delay_us(20);
        NextMotorState->direction = TargetMotorState->direction;
    }
    if(TargetMotorState->duty > NowMotorState->duty)
        NextMotorState->duty ++;
    if(TargetMotorState->duty < NowMotorState->duty)
        NextMotorState->duty --;
    __delay_us(5);
}

void GetData(State_t* NextMotorState){
    NextMotorState->state = SSP1BUF;
}