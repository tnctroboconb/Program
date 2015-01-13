/* 
 * File:   EEPROM.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/29, 17:41
 */

#ifndef EEPROM_H
#define	EEPROM_H

#include "../Common/TypeDef.h"

void InitEEP();
void WriteToEEP(const BYTE);
void ReadFromEEP(const BYTE*);

#endif	/* EEPROM_H */