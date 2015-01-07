/* 
 * File:   UART.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/22, 17:35
 */

#ifndef UART_H
#define	UART_H

#include "../../Common/Struct.h"
#include "../../Common/Definition.h"
#include "../../Common/TypeDef.h"

#define NINE_BITS   DISABLE
#define SYNC        DISABLE
#define HISPEED     DISABLE
#define GENERAL     ENABLE
#define BAUD        57600UL
#define TOPC        DISABLE
#define PARITY      DISABLE

void Init_UART();
void putch(CINT8);
INT8 getch();

#endif	/* UART_H */

