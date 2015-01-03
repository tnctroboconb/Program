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


typedef struct myID {
    USIGN    ID:4;
    union{
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
 |方向 |番号 |      50%からの差分      |符号|
 ----------------------------------------
 */
typedef struct MotorData{
    USIGN    state:8;
    union{
        USIGN   plusminus:1;
        USIGN   duty:5;
        USIGN   number:1;
        USIGN   direction:1;
    };
} State_t;

extern State_t ReceiveData[2];

#endif	/* STRUCT_H */