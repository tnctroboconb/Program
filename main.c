/* 
 * File:   main.c
 * Author: sekiguchikeita
 *
 * Created on 2014/12/17, 16:58
 */

#include "Common/Config.h"
#include "Motor.h"
#include "Device/Serial/I2C.h"
#include "Device/Init.h"
#include "Device/PWM.h"


int main(){
    Address MotorID;
    State NowMotorState,NextMotorState,TargetMotorState;
    Init_Device();
    GetID(&MotorID);
    while(1){
        GetData(&NextMotorState);
        SetToNext(&NowMotorState,&NextMotorState,&TargetMotorState);
    }
    return 0;
}