/* 
 * File:   AnaToDigi.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/29, 11:21
 */

#ifndef ANATODIGI_H
#define	ANATODIGI_H

#include "../../Common/StdInc.h"

#define CONVERT_ENABLE              (1)
#define DISCONVERT_IN_IDLE          (0)
#define CONVERSION_TRIGGER_SOURCE   (0b111)
#define SAMPLE_ENABLE               (1)
#define USE_VREF_POSITIVE           (0)
#define USE_VREF_NEGATIVE           (0)
#define USE_OFFSET                  (0)
#define SCAN_INPUT                  (0)
#define AUTO_CONVERT_SEQUENCES      (1)
#define ALUTERNATE                  (0)
#define AUTO_CONVERT                (1)
#define COLLECT_TO_LEFT             (1)
#define DATA_FORMAT_TYPE            (0b00)
#define CLOCK_USE_INTERNAL_RC       (0)
#define AUTO_SAMPLE_TIME            (0b00001)
#define CHARGE_PUMP_ENABLE          (0)
#define USE_AN0_PIN_TO_ANALOG_INPUT (1)
#define USE_AN1_PIN_TO_ANALOG_INPUT (1)

#define MAIN_BATTERY    PORTAbits.RA0
#define SUB_BATTERY     PORTAbits.RA1

typedef struct Battery{
    float       Voltage;
    float       Percent;
    float       tmp;
    long        Result;
    unsigned    Enable:1;
    unsigned    ID:1;
} BatteryData_t;

void ADInit();
void BeforConvert(const char);
void StartConvert();
void Convert(BatteryData_t*,const char);
void Res_To_Volt(BatteryData_t*);
void Volt_To_Perce(BatteryData_t*);
void UseThis(BatteryData_t*);

#endif	/* ANATODIGI_H */

