#include <xc.h>
#include "I2C.h"

#if SLAVE == 1
void Init_I2C(Address* Addr){
    SSP1CON1bits.WCOL = 0;
    SSP1CON1bits.SSPOV = 0;
    SSP1CON1bits.SSPEN = ENABLE;
    SSP1CON1bits.CKP = 0;
    SSP1CON1bits.SSPM = MODE;
    
    SSP1CON2bits.GCEN = GCALL;
    SSP1CON2bits.SEN = 1;
    
    SSP1CON3bits.PCIE = 1;
    SSP1CON3bits.SCIE = 1;
    SSP1CON3bits.BOEN = 1;
    SSP1CON3bits.SDAHT = 0;
    SSP1CON3bits.SBCDE = 0;
    SSP1CON3bits.AHEN = 0;
    SSP1CON3bits.DHEN = 0;
    
    SSP1ADD = Addr->ID;
}

void IdleI2C(){
    while(SSP1CON2bits.SEN);
    while(SSP1CON2bits.PEN);
    while(SSP1CON2bits.RCEN);
    while(SSP1CON2bits.ACKEN);
    while(SSP1STATbits.R_NOT_W);
}

void GetID(Address* Addr){
    Addr->ID0 = PORTAbits.RA0;
    Addr->ID1 = (PORTAbits.RA1 << 1);
    Addr->ID2 = (PORTAbits.RA2 << 2);
    Addr->ID3 = (PORTAbits.RA3 << 3);
}
#endif