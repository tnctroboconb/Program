/* 
 * File:   Used.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/29, 16:45
 */

/*
 * フォーマット
 * USE_*****
 *
 * 使う機能を1にする
 *
 */

#ifndef USED_H
#define	USED_H

#include "Definition.h"

#define USE_USART       ENABLE
#define USE_I2C         DISABLE
#define USE_SPI         DISABLE
#define USE_PWM         DISABLE
#define USE_ADCONVERT   ENABLE
#define USE_EEPROM      DISABLE
#define USE_MOTOR       DISABLE
#define USE_BATTERY     ENABLE
#define USE_DUALSHOCK2  DISABLE

#include "../Device/Init.h"

#if USE_USART == ENABLE
#include "../Device/Serial/UART.h"
#endif

#if USE_I2C == ENABLE
#include "../Device/Serial/I2C.h"
#endif

#if USE_SPI == ENABLE
#include "../Device/Serial/SPI.h"
#endif

#if USE_PWM == ENABLE
#include "../Device/PWM.h"
#endif

#if USE_ADCONVERT == ENABLE
#include "../Device/Convert/AnaToDigi.h"
#endif

#if USE_EEPROM == ENABLE
#include "../Device/EEPROM.h"
#endif

#if USE_MOTOR == ENABLE
#include "../User/Motor.h"
#endif

#if USE_BATTERY == ENABLE
#include "../User/Battery.h"
#endif

#if USE_DUALSHOCK2 == ENABLE
#include "../User/DUALSHOCK2.h"
#endif

#endif	/* USED_H */

