/*
 *
 */

#ifndef UART_H
#define	UART_H

#include "../../Common/Struct.h"
#include "../../Common/TypeDef.h"

#define SYNC        DISABLE
#define HISPEED     DISABLE
#define GENERAL     ENABLE
#define TOPC        DISABLE
#define PARITY      DISABLE
#define ADRESSING   ENABLE
#define USE_IN_IDLE DISABLE
#define USE_IrDA    DISABLE
#define FLOW_CTL    DISABLE
#define BAUD        57600UL

void Init_UART();
void putch(CINT8);
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void);

#endif	/* UART_H */

