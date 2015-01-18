/* 
 * File:   I2C.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/17, 16:37
 */

#ifndef I2C_H
#define	I2C_H

#include "../../Common/Struct.h"

#define SCL_PIN TRISBbits.TRISB8
#define SDA_PIN TRISBbits.TRISB9
#define KHz 000
#define MASTER (0)
#define SLAVE (1)
#define HI_SPEED (1)
#define SEVEN_BIT (1)
#define INTERRUPT (0)
#define EN (1)
#define GCALL (0)
#define DATA_LATE 400KHz

#if (MASTER == SLAVE)
#error MASTER and SLAVE mode are selected on same time
#endif

#if(HI_SPEED == 0)
#undef BAUD
#define BAUD 100KHz
#endif

#if (HI_SPEED != 1)
#warning I2C is used in low speed mode
#undef HI_SPEED
#define HI_SPEED 0
#undef BAUD
#define BAUD 100KHz
#endif

#if (MASTER == 1)
#define GENERATE ((FCY / (2 * DATA_LATE)) - 1)
#endif

#if ((INTERRUPT != 1) && (INTERRUPT != 0))
#error Double interrupt mode are selected.
#endif

#if MASTER == 1
#define MODE (0b1000)
#elif SLAVE == 1
#if INTERRUPT == 1
#if SEVEN_BIT == 1
#define MODE (0b1110)
#elif SEVEN_BIT == 0
#define MODE (0b1111)
#endif
#elif INTERRUPT == 0
#if SEVEN_BIT == 1
#define MODE (0b0110)
#elif SEVEN_BIT == 0
#define MODE (0b0111)
#endif
#endif
#endif

BOOL Init_I2C(Address_t*);
BOOL Start_I2C(Address_t*);
BOOL Restart_I2C();
BOOL IdleI2C();
BOOL Send_Data(Address_t*,BYTE);
BOOL Get_Data(State_t*);
BOOL GetID(Address_t*);
void __attribute__((interrupt, no_auto_psv)) _MSSP1Interrupt(void);


typedef struct{
    BOOL (*I2CInit)(Address_t*);
    BOOL (*I2CStart)(Address_t*);
    BOOL (*I2CRestart)(void);
    BOOL (*I2CIdle)(void);
    BOOL (*DataSend)(Address_t*,BYTE);
    BOOL (*Data_Get)(State_t*);
    BOOL (*IDGet)(Address_t*);
    BOOL Initialized;
} I2CProtocol;

I2CProtocol* Use_I2C();

#define new(I2CProtocol) Use_I2C();

#endif	/* I2C_H */