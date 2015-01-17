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

int main(){
    Address_t Addr;
    I2CProtocol* I2C = Use_I2C();
    I2C->I2CInit(&Addr);
}