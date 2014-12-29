/* 
 * File:   I2C.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/17, 16:37
 */

#ifndef I2C_H
#define	I2C_H


#define SCL_PIN TRISBbits.TRISB8
#define SDA_PIN TRISBbits.TRISB9
#define KHz 000
#define MASTER (0)
#define SLAVE (1)
#define HI_SPEED (1)
#define SEVEN_BIT (1)
#define INTERRUPT (1)
#define ENABLE (1)
#define GCALL (0)
#define BAUD 400KHz

#if (MASTER == SLAVE)
#error MASTER and SLAVE mode are selected on same time
#endif

#if(HI_SPEED == 0)
#undef BAUD
#define BAUD 100KHz
#endif

#if (ENABLE != 1)
#error I2C.h is included. But this module is disabled.
#endif

#if (HI_SPEED != 1)
#warning I2C is used in low speed mode
#undef HI_SPEED
#define HI_SPEED 0
#undef BAUD
#define BAUD 100KHz
#endif

#if ((INTERRUPT != 1) && (INTERRUPT != 0))
#error Double interrupt mode are selected.
#endif

#if MASTER == 1
#define MODE (1000)
#elif SLAVE == 1
#if INTERRUPT == 1
#if SEVEN_BIT == 1
#define MODE (0b1110)
#elif SEVEN_BIT == 0
#define MODE (1111)
#endif
#elif INTERRUPT == 0
#if SEVEN_BIT == 1
#define MODE (0110)
#elif SEVEN_BIT == 0
#define MODE (0111)
#endif
#endif
#endif


typedef struct myID {
    unsigned    ID:4;
    union{
        unsigned    ID0:1;
        unsigned    ID1:1;
        unsigned    ID2:1;
        unsigned    ID3:1;
    };
} Address_t;

//typedef struct myID Address;

void Init_I2C(Address_t*);
void Start_I2C();
void Restart_I2C();
void IdleI2C();
void Send_Data();
void Get_Data();
void GetID(Address_t*);

#endif	/* I2C_H */