#include <xc.h>
#include "Init.h"

void Init_Device(){
    Init_Frequency();
    Init_IO();
}

void Init_Frequency(){
    OSCCON = 0x1120;
    CLKDIV = 0x0000;
    OSCTUN = 0x0000;
    REFOCON = 0x1000;

}

void Init_IO(){
    TRISA = 0x000F;
    ANSA = 0x0000;
    LATA = 0x0000;
    TRISB = 0x0000;
    ANSB = 0x0000;
    LATB = 0x0000;
}