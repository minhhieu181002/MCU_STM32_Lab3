/*
 * fsm_manual_run.c
 *
 *  Created on: Oct 28, 2023
 *      Author: HP
 */
#include "fsm_manual.h"
#include "fsm_auto.h"
#include "led.h"
void increaseLEDTime(int index){
	if(index == RED){
		arr[RED]++;
		arr[GREEN]++;
		if(arr[RED] >= 99){
			arr[RED] = 0;
		}
	}
	if(index == GREEN){
		arr[GREEN]++;
		arr[RED]++;
		if(arr[GREEN] >= 99){
			arr[GREEN] = 0;
		}
	}
	if(index == AMBER){
		arr[AMBER]++;
		arr[RED]++;
		if(arr[AMBER] >= 99){
			arr[AMBER] = 0;
		}
	}
}

void fsm_manual_run() {
	switch(status){
	case MAN_RED:
		if(timer1_flag == 1){
			redToogle();
			led_status1 = DISPLAY_VALUE_RED;
			led_status2 = MODE_RED;
			setTimer1(100);
		}
		if(isButton1Pressed(BUTTON2) == 1){
			increaseLEDTime(RED);
		}
		if(isButton1Pressed(BUTTON3) == 1){
			cntRoad1 = arr[RED];
			cntRoad2 = arr[GREEN];
			led_status1 = RED;
			led_status2 = GREEN;
			status = INIT;
		}
		if(isButton1Pressed(BUTTON1) == 1){
			status = MAN_GREEN;
			setTimer1(100);
		}
		break;
	case MAN_GREEN:
		if(timer1_flag == 1){
			greenToogle();
			led_status1 = DISPLAY_VALUE_GREEN;
			led_status2 = MODE_GREEN;
			setTimer1(100);
		}
		if(isButton1Pressed(BUTTON2) == 1){
			increaseLEDTime(GREEN);
		}
		if(isButton1Pressed(BUTTON3) == 1){
			cntRoad1 = arr[RED];
			cntRoad2 = arr[GREEN];
			led_status1 = RED;
			led_status2 = GREEN;
			status = INIT;
		}
		if(isButton1Pressed(BUTTON1) == 1){
			status = MAN_YELLOW;
			setTimer1(100);
		}
		break;
	case MAN_YELLOW:
		if(timer1_flag == 1){
			amberToogle();
			led_status1 = DISPLAY_VALUE_AMBER;
			led_status2 = MODE_AMBER;
			setTimer1(100);
		}
		if(isButton1Pressed(BUTTON2) == 1){
			increaseLEDTime(AMBER);
		}
		if(isButton1Pressed(BUTTON3) == 1){
			cntRoad1 = arr[RED];
			cntRoad2 = arr[GREEN];
			led_status1 = RED;
			led_status2 = GREEN;
			status = INIT;
		}
		if(isButton1Pressed(BUTTON1) == 1){
			status = MAN_RED;
			setTimer1(100);
		}
		break;
	default:
		break;
	}
}
