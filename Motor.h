/* 
 * File:   stdhead.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/17, 16:24
 */

#ifndef MOTOR_H
#define	MOTOR_H

#define DIRECTION_PIN

typedef struct MotorData{
    unsigned    state:8;
    union{
        unsigned    duty:7;
        unsigned    direction:1;
    };
} State_t;

//typedef struct MotorData State;

void SetToNext(State_t*,State_t*,State_t*);
void GetData(State_t*);

#endif	/* MOTOR_H */

