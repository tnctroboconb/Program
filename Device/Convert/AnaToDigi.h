/* 
 * File:   AnaToDigi.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/29, 11:21
 */

#ifndef ANATODIGI_H
#define	ANATODIGI_H

#include "../../Common/StdInc.h"
#include "../../Common/Struct.h"

#define CONVERT_ENABLE              (1)     // A/D変換するか
#define DISCONVERT_IN_IDLE          (0)     // アイドリング中に変換するか
#define CONVERSION_TRIGGER_SOURCE   (0b111) //
#define SAMPLE_ENABLE               (1)
#define USE_VREF_POSITIVE           (0)
#define USE_VREF_NEGATIVE           (0)
#define USE_OFFSET                  (0)
#define SCAN_INPUT                  (0)
#define AUTO_CONVERT_SEQUENCES      (1)
#define ALUTERNATE                  (0)
#define AUTO_CONVERT                (1)
#define DATA_FORMAT_TYPE            (0b00)
#define CLOCK_USE_INTERNAL_RC       (0)
#define AUTO_SAMPLE_TIME            (0b00001)
#define CHARGE_PUMP_ENABLE          (0)
#define USE_AN0_PIN_TO_ANALOG_INPUT (1)
#define USE_AN1_PIN_TO_ANALOG_INPUT (1)


void ADInit();
void BeforConvert(CINT8);
void StartConvert();
void Convert(BatteryData_t*,CINT8);
void inline Res_To_Volt(BatteryData_t*);
void inline Volt_To_Perce(BatteryData_t*);

#endif	/* ANATODIGI_H */

