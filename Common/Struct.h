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


typedef struct MotorData{
    USIGN    state:8;
    union{
        USIGN    duty:7;
        USIGN    direction:1;
    };
} State_t;

#endif	/* STRUCT_H */