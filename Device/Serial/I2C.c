#include "../../Common/StdInc.h"
#include "I2C.h"

State_t ReceiveData[2];

#if USE_I2C == ENABLE

#if MASTER == 1

#endif

#if SLAVE == 1
void Init_I2C(Address_t* Addr){
    //SSP1CON1 Initialization
    SSP1CON1bits.WCOL = 0;
    SSP1CON1bits.SSPOV = 0;
    SSP1CON1bits.SSPEN = EN;
    SSP1CON1bits.CKP = 0;
    SSP1CON1bits.SSPM = MODE;

    //SSP1CON2 Initialization
    SSP1CON2bits.GCEN = GCALL;
    SSP1CON2bits.SEN = 1;

    //SSP1CON3 Initialization
    SSP1CON3bits.PCIE = 1;
    SSP1CON3bits.SCIE = 1;
    SSP1CON3bits.BOEN = 1;
    SSP1CON3bits.SDAHT = 0;
    SSP1CON3bits.SBCDE = 0;
    SSP1CON3bits.AHEN = 0;
    SSP1CON3bits.DHEN = 0;

    //MotorDriverAddress
    GetID(Addr);
    SSP1ADD = ((Addr->ID) << 1);
}

void IdleI2C(){
    while(SSP1CON2bits.SEN);
    while(SSP1CON2bits.PEN);
    while(SSP1CON2bits.RCEN);
    while(SSP1CON2bits.ACKEN);
    while(SSP1STATbits.R_NOT_W);
}

void GetID(Address_t* Addr){
    Addr->ID0 = PORTAbits.RA0;
    Addr->ID1 = (PORTAbits.RA1 << 1);
    Addr->ID2 = (PORTAbits.RA2 << 2);
    Addr->ID3 = (PORTAbits.RA3 << 3);
}

void __attribute__((interrupt, no_auto_psv)) _MSSP1Interrupt(void){
    int dummy;
    if(!SSP1STATbits.R_W){
        if(!SSP1STATbits.D_A){
            dummy = SSP1BUF;
            IdleI2C();
        }else{
            ReceiveData[((SSP1BUF & 0x40) >> 6)].plusminus = ( SSP1BUF & 0x01);
            ReceiveData[((SSP1BUF & 0x40) >> 6)].duty      = ((SSP1BUF & 0x3E) >> 1);
            ReceiveData[((SSP1BUF & 0x40) >> 6)].number    = ((SSP1BUF & 0x40) >> 6);
            ReceiveData[((SSP1BUF & 0x40) >> 6)].direction = ((SSP1BUF & 0x80) >> 7);
        }
    }
}

#endif
#endif