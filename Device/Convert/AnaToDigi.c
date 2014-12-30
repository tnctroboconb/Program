#include "../../Common/StdInc.h"
#include "AnaToDigi.h"
#include "../../User/Battery.h"

#if CONVERT_ENABLE == 1

void ADInit(){
    //AD1CON1 Initialization
    AD1CON1bits.ADON = CONVERT_ENABLE;
    AD1CON1bits.ADSIDL = DISCONVERT_IN_IDLE;
    AD1CON1bits.FORM = DATA_FORMAT_TYPE;
    AD1CON1bits.SSRC = CONVERSION_TRIGGER_SOURCE;
    AD1CON1bits.ASAM = AUTO_CONVERT;
    AD1CON1bits.SAMP = SAMPLE_ENABLE;
    AD1CON1bits.DONE = 0;
    
    //AD1CON2 Initialization
    AD1CON2bits.VCFG0 = USE_VREF_POSITIVE;
    AD1CON2bits.VCFG1 = USE_VREF_NEGATIVE;
    AD1CON2bits.VCFG2 = 0;
    AD1CON2bits.OFFCAL = USE_OFFSET;
    AD1CON2bits.CSCNA = SCAN_INPUT;
    AD1CON2bits.SMPI = AUTO_CONVERT_SEQUENCES;
    AD1CON2bits.ALTS = ALUTERNATE;

    //AD1CON3 Initialization
    AD1CON3bits.ADRC = CLOCK_USE_INTERNAL_RC;
    AD1CON3bits.SAMC = AUTO_SAMPLE_TIME;
    AD1CON3bits.ADCS = 1;
}

void BeforConvert(CINT8 PIN){
    AD1CHSbits.CH0NB = USE_AN0_PIN_TO_ANALOG_INPUT;
    AD1CHSbits.CH0SB = PIN;
    AD1CHSbits.CH0NA = USE_AN1_PIN_TO_ANALOG_INPUT;
}

void StartConvert(){
    AD1CON1bits.DONE = 1;
    while(AD1CON1bits.DONE);
}

void Convert(BatteryData_t* Battery,CINT8 PIN){
    BeforConvert(PIN);
    StartConvert();
    Battery->Result = ADC1BUF0;
    Res_To_Volt(Battery);
    Volt_To_Perce(Battery);
    UseThis(Battery);
}

void inline Res_To_Volt(BatteryData_t* Battery){
    Battery->tmp = ((4.2 * CELLS) * (Battery->Result / 1024));
}

void inline Volt_To_Perce(BatteryData_t* Battery){
    if(Battery->tmp < Battery->Voltage){
        Battery->Voltage = Battery->tmp;
        Battery->Percent = (((4.2 * CELLS) / Battery->Voltage) * 100);
    }else
        Battery->Voltage = Battery->tmp;
}
#endif