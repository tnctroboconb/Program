/* 
 * File:   stdhead.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/17, 16:24
 */

#ifndef MOTOR_H
#define	MOTOR_H

#define DIRECTION_PIN

#include "../Common/Struct.h"

//typedef struct MotorData State;

void MotorDrive(State_t*);
void SetToNext(State_t*,State_t*,State_t*);
void GetData(State_t*);

#endif	/* MOTOR_H */

