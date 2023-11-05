/*
 * led.h
 *
 *  Created on: Nov 5, 2023
 *      Author: HP
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "global.h"
#include "fsm_auto.h"
#include "fsm_manual.h"



void redToogle();
void greenToogle();
void amberToogle();
void toggle();
void display7SEG(int num);
void updateLedBuffer ();
void update7SEG ( int index );

extern int index_led;
extern int led_buffer[4];
extern const int MAX_LED;
#endif /* INC_LED_H_ */
