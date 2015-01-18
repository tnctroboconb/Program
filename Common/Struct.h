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

/*
 Address_tのデータ構成
 ------------------------------------------------------------------------------------------------
 |bit15|bit14|bit13|bit12|bit11|bit10|bit09|bit08|bit07|bit06|bit05|bit04|bit03|bit02|bit01|bit00|
 ------------------------------------------------------------------------------------------------
 |                                          8bitアドレス                                          |
 ------------------------------------------------------------------------------------------------
 |                      ID1                      |                      ID0                      |
 ------------------------------------------------------------------------------------------------
 |                                          4bitアドレス                                          |
 ------------------------------------------------------------------------------------------------
 |          ID1H         |          ID1L         |          ID0H         |          ID0L         |
 ------------------------------------------------------------------------------------------------
 |                                          1bitアドレス                                          |
 ------------------------------------------------------------------------------------------------
 |ID1H3|ID1H2|ID1H1|ID1H0|ID1L3|ID1L2|ID1L1|ID1L0|ID0H3|ID0H2|ID0H1|ID0H0|ID0L3|ID0L2|ID0L1|ID0L0|
 ------------------------------------------------------------------------------------------------
*/

typedef union myID{
    struct{
        USIGN   ID0:8;
        USIGN   ID1:8;
    };
    struct{
        USIGN   ID0L:4;
        USIGN   ID0H:4;
        USIGN   ID1L:4;
        USIGN   ID1H:4;
    };
    struct{
        USIGN   ID0L0:1;
        USIGN   ID0L1:1;
        USIGN   ID0L2:1;
        USIGN   ID0L3:1;
        USIGN   ID0H0:1;
        USIGN   ID0H1:1;
        USIGN   ID0H2:1;
        USIGN   ID0H3:1;
        USIGN   ID1L0:1;
        USIGN   ID1L1:1;
        USIGN   ID1L2:1;
        USIGN   ID1L3:1;
        USIGN   ID1H0:1;
        USIGN   ID1H1:1;
        USIGN   ID1H2:1;
        USIGN   ID1H3:1;
    };
} Address_t;

/*
 State_tのデータ構成
 ----------------------------------------
 |bit7|bit6|bit5|bit4|bit3|bit2|bit1|bit0|
 ----------------------------------------
 |　 状態   |      50%からの差分     　|符号|
 ----------------------------------------
 */
typedef union MotorData{
    struct{
        USIGN   plusminus:1;
        USIGN   duty:5;
        USIGN   direction:2;
    };
    struct{
        USIGN   plusminus:1;
        USIGN   duty4:1;
        USIGN   duty3:1;
        USIGN   duty2:1;
        USIGN   duty1:1;
        USIGN   duty0:1;
        USIGN   direction1:1;
        USIGN   direction0:1;
    };
} State_t;

extern State_t ReceiveData;

typedef enum Boolean{TRUE = 1,FALSE = 0}BOOL;
typedef enum Direct{cw = 1,ccw = 0}Direction;
typedef enum Switch{on = 1,off = 0}SW;
typedef enum ENDIS{enable = 1,disable = 0}EN_DIS;

#endif	/* STRUCT_H */