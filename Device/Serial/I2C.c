#include "../../Common/StdInc.h"
#include "I2C.h"

State_t ReceiveData;
I2CProtocol I2C;

#if USE_I2C == ENABLE


I2CProtocol* Use_I2C(){
    I2C.I2CInit = Init_I2C;
    I2C.I2CStart = Start_I2C;
    I2C.I2CRestart = Restart_I2C;
    I2C.I2CIdle = IdleI2C;
    I2C.IDGet = GetID;
    I2C.Data_Get = Get_Data;
    I2C.DataSend = Send_Data;

    return &I2C;
}


#if MASTER == 1

#endif

#if SLAVE == 1
BOOL Init_I2C(Address_t* Addr){
    //SSP1CON1 Initialization
    SSP1CON1bits.WCOL = 0;
    SSP1CON1bits.SSPOV = 0;
    SSP1CON1bits.SSPEN = USE_I2C;
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

    IFS1bits.SSP1IF = 0;
    IFS1bits.BCL1IF = 0;
    IEC1bits.SSP1IE = 1;
    IEC1bits.BCL1IE = 0;

    //MotorDriverAddress
    GetID(Addr);
    SSP1ADD = ((Addr->ID) << 1);
}

BOOL IdleI2C(){
    while(SSP1CON2bits.SEN);
    while(SSP1CON2bits.PEN);
    while(SSP1CON2bits.RCEN);
    while(SSP1CON2bits.ACKEN);
    while(SSP1STATbits.R_NOT_W);
}

BOOL GetID(Address_t* Addr){
    Addr->ID0 = PORTAbits.RA0;
    Addr->ID1 = (PORTAbits.RA1 << 1);
    Addr->ID2 = (PORTAbits.RA2 << 2);
    Addr->ID3 = (PORTAbits.RA3 << 3);
}

BOOL Start_I2C(Address_t* Addr){
    return 0;
}
BOOL Restart_I2C(Address_t* Addr){
    return 0;
}
BOOL Send_Data(Address_t* Addr,BYTE Data){
    return 0;
}
BOOL Get_Data(State_t* Addr){
    return 0;
}

void __attribute__((interrupt, no_auto_psv)) _MSSP1Interrupt(void){
    int dummy;
    IFS1bits.SSP1IF = 0;
    if(!SSP1STATbits.R_W){
        if(!SSP1STATbits.D_A){
            dummy = SSP1BUF;
            IdleI2C();
        }else{
            ReceiveData.plusminus = ( SSP1BUF & 0x01);
            ReceiveData.duty      = ((SSP1BUF & 0x3E) >> 1);
            ReceiveData.direction = ((SSP1BUF & 0xC0) >> 6);
        }
    }
}


#endif
#endif