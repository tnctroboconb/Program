/* 
 * File:   Struct.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/29, 14:43
 */

#ifndef STRUCT_H
#define	STRUCT_H

#include "TypeDef.h"


typedef struct Battery{
    float       Voltage;
    float       Percent;
    float       tmp;
    ULONG       Result;
    USIGN       Enable:1;
    USIGN       ID:1;
} BatteryData_t;

typedef struct myID{
    union{
        USIGN    ID:4;
        USIGN    ID0:1;
        USIGN    ID1:1;
        USIGN    ID2:1;
        USIGN    ID3:1; 
    };
} Address_t;

/*
 MotorDataのデータ構成
 ----------------------------------------
 |bit7|bit6|bit5|bit4|bit3|bit2|bit1|bit0|
 ----------------------------------------
 |　　状態  |      50%からの差分       |符号|
 ----------------------------------------
 */
typedef struct MotorData{
        USIGN  plusminus:1;
        USIGN  duty:5;
        USIGN  direction:2;
} State_t;

extern State_t ReceiveData;

#endif	/* STRUCT_H */