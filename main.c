/* 
 * File:   main.c
 * Author: sekiguchikeita
 *
 * Created on 2014/12/17, 16:58
 */

#include "Common/Config.h"
#include "Common/TypeDef.h"
#include "Common/StdInc.h"
#include "Common/Struct.h"
#include "Common/Used.h"

#ifndef CONFIG_H
#error This Device is not configured.
#endif

#ifndef USED_H
#error Used modules are not detected.
#endif

BYTE SendData;

int main(){
    Address_t Addr;
    //I2CProtocol* I2C = Use_I2C();
    I2CProtocol* I2C = new(I2CProtocol);
    I2C->I2CInit(&Addr);
}

/*送信時の例
 * int main(){
 *     Address_t Addr;
 *     Addr.ID0L = 0x03;
 *     I2CProtocol* I2C = new(I2CProtocol);
 *     I2C.InitI2C();
 *     I2C.SendData(0x03,0x2f);
 * }
 */