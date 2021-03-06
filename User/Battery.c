#include "../Common/StdInc.h"
#include "Battery.h"

#if USE_BATTERY == ENABLE


void UseThis(BatteryData_t* Battery){
    switch(Battery->ID){
        case 0:
            if(Battery->Percent < 5)
                Battery->Enable = 0;
            else
                Battery->Enable = 1;
            MAIN_BATTERY = Battery->Enable;
            SUB_BATTERY = 0;
            break;
        case 1:
            if(Battery->Percent < 5)
                Battery->Enable = 0;
            else if(Battery->Percent >= 5 && !MAIN_BATTERY)
                Battery->Enable = 1;
            SUB_BATTERY = Battery->Enable;
            break;
    }
}

#endif