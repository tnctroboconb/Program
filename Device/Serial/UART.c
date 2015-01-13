#include "../../Common/StdInc.h"
#include "UART.h"

#if USE_USART == ENABLE

void Init_UART(){
    U1MODEbits.UARTEN = ENABLE;
    U1MODEbits.USIDL = USE_IN_IDLE;
    U1MODEbits.IREN = USE_IrDA;
    U1MODEbits.RTSMD = FLOW_CTL;
}

void putch(CINT8 data){

}

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void){
    
}

#endif