#include "../../Common/StdInc.h"
#include "I2C.h"

State_t ReceiveData;
extern BYTE SendData;
I2CProtocol I2C;

#if USE_I2C == ENABLE

I2CProtocol* Use_I2C(){
    if(!I2C.Initialized){
        I2C.I2CInit = Init_I2C;
        I2C.I2CStart = Start_I2C;
        I2C.I2CRestart = Restart_I2C;
        I2C.I2CIdle = IdleI2C;
        I2C.IDGet = GetID;
        I2C.Data_Get = Get_Data;
        I2C.DataSend = Send_Data;
    }
    I2C.Initialized = TRUE;
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
    SSP1ADD = ((Addr->ID0L) << 1);
    return TRUE;
}

BOOL IdleI2C(){
    while(SSP1CON2bits.SEN);
    while(SSP1CON2bits.PEN);
    while(SSP1CON2bits.RCEN);
    while(SSP1CON2bits.ACKEN);
    while(SSP1STATbits.R_NOT_W);
    return TRUE;
}

BOOL GetID(Address_t* Addr){
    Addr->ID0L0 = PORTAbits.RA0;
    Addr->ID0L1 = (PORTAbits.RA1 << 1);
    Addr->ID0L2 = (PORTAbits.RA2 << 2);
    Addr->ID0L3 = (PORTAbits.RA3 << 3);
    return TRUE;
}

BOOL Start_I2C(Address_t* Addr){
    return TRUE;
}
BOOL Restart_I2C(){
    SSP1CON1bits.CKP = 1;
    IFS1bits.SSP1IF = 0;
    return TRUE;
}
BOOL Send_Data(Address_t* Addr,BYTE Data){
    return TRUE;
}
BOOL Get_Data(State_t* Addr){
    return TRUE;
}


void __attribute__((interrupt, no_auto_psv)) _MSSP1Interrupt(void){
    int dummy;
    if(!SSP1STATbits.R_W){
        /*****マスタからの書き込み要求*****/
        if(!SSP1STATbits.D_A){
            /*****アドレスを受信した時の対応*****/
            dummy = SSP1BUF;
            IdleI2C();
        }else{
            /*****データを受信した時の対応*****/
            ReceiveData.plusminus = ( SSP1BUF & 0x01);
            ReceiveData.duty      = ((SSP1BUF & 0x3E) >> 1);
            ReceiveData.direction = ((SSP1BUF & 0xC0) >> 6);
        }
        I2C.I2CRestart();
    }else{
        /*****スレーブからの読み出し要求*****/
        if(SSP1STATbits.BF){
            /*****アドレス受信直後の割り込み*****/
            dummy = SSP1BUF;
            while(SSP1CON1bits.CKP | SSP1STATbits.BF);
            SSP1BUF = SendData;
            I2C.I2CRestart();
        }else if(!SSP1CON2bits.ACKSTAT){
            /*****ACKによる割り込み*****/
            while(SSP1CON1bits.CKP | SSP1STATbits.BF);
            SSP1BUF = SendData;
            I2C.I2CRestart();
        }else{
            /*****NACK応答*****/
            I2C.I2CRestart();
        }
    }
}


#endif
#endif