/* 
 * File:   stdhead.h
 * Author: sekiguchikeita
 *
 * Created on 2014/12/17, 16:24
 */

#ifndef MOTOR_H
#define	MOTOR_H

#define FCY 32000000UL

#include <xc.h>
#include <libpic30.h>
#include <p24F08KL200.h>


#define DIRECTION_PIN

struct MotorData{
    unsigned    state:8;
    union{
        unsigned    duty:7;
        unsigned    direction:1;
    };
};

typedef struct MotorData State;

void SetToNext(State*,State*,State*);
void GetData(State*);

#endif	/* MOTOR_H */

