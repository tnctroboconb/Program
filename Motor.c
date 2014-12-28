#include "Motor.h"
#include "Device/PWM.h"


void SetToNext(State* NowMotorState,State *NextMotorState,State*TargetMotorState){
    char cnt;
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

void GetData(State* NextMotorState){
    NextMotorState->state = SSP1BUF;
}