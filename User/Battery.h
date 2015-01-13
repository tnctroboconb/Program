/* 
 * File:   Battery.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/29, 14:29
 */

#ifndef BATTERY_H
#define	BATTERY_H

#include "../Common/StdInc.h"
#include "../Device/Convert/AnaToDigi.h"



#define MAIN_BATTERY    PORTAbits.RA0
#define SUB_BATTERY     PORTAbits.RA1
#define CELL_DETECT     PORTAbits.RA2
#define CELLS           (3)

void UseThis(BatteryData_t*);

#endif	/* BATTERY_H */

