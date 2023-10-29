/*
 * fsm_manual_run.c
 *
 *  Created on: Oct 28, 2023
 *      Author: HP
 */
#include "fsm_manual.h"
#include "fsm_auto.h"
void redToogle(){
	HAL_GPIO_TogglePin(D1_GPIO_Port, D1_Pin);
	HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
}
void greenToogle(){
	HAL_GPIO_TogglePin(D1_GPIO_Port, D3_Pin);
	HAL_GPIO_TogglePin(D4_GPIO_Port, D6_Pin);
	HAL_GPIO_WritePin(D2_GPIO_Port, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D5_Pin, GPIO_PIN_SET);
}
void amberToogle(){
	HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
	HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
	HAL_GPIO_WritePin(D2_GPIO_Port, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
}
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
void toggle(){
	HAL_GPIO_TogglePin(D1_GPIO_Port, D1_Pin);
	HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
	HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
	HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
	HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
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
		if(isButton1Pressed(2) == 1){
			increaseLEDTime(RED);
		}
		if(isButton1Pressed(3) == 1){
			cntRoad1 = arr[RED];
			cntRoad2 = arr[GREEN];
			led_status1 = RED;
			led_status2 = GREEN;
			status = INIT;
		}
		if(isButton1Pressed(1) == 1){
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
		if(isButton1Pressed(2) == 1){
			increaseLEDTime(GREEN);
		}
		if(isButton1Pressed(3) == 1){
			cntRoad1 = arr[RED];
			cntRoad2 = arr[GREEN];
			led_status1 = RED;
			led_status2 = GREEN;
			status = INIT;
		}
		if(isButton1Pressed(1) == 1){
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
		if(isButton1Pressed(2) == 1){
			increaseLEDTime(AMBER);
		}
		if(isButton1Pressed(3) == 1){
			cntRoad1 = arr[RED];
			cntRoad2 = arr[GREEN];
			led_status1 = RED;
			led_status2 = GREEN;
			status = INIT;
		}
		if(isButton1Pressed(1) == 1){
			status = MAN_RED;
			setTimer1(100);
		}
		break;
	default:
		break;
	}
}
