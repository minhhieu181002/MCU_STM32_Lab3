/*
 * button.c
 *
 *  Created on: Oct 28, 2023
 *      Author: HP
 */

#include"button.h"


int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;
//button1
int keyReg0 = NORMAL_STATE;
int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;
int keyReg3 = NORMAL_STATE;
//button2
int keyReg4 = NORMAL_STATE;
int keyReg5 = NORMAL_STATE;
int keyReg6 = NORMAL_STATE;
int keyReg7 = NORMAL_STATE;
//button3
int keyReg8 = NORMAL_STATE;
int keyReg9 = NORMAL_STATE;
int keyReg10 = NORMAL_STATE;
int keyReg11 = NORMAL_STATE;

int TimerForKeyPress = 200;

int isButton1Pressed(int index){
	if (index == 1){
		if(button1_flag == 1){
			button1_flag = 0;
			return 1;
		}
	}
	if(index == 2){
		if(button2_flag == 1){
			button2_flag = 0;
			return 1;
		}
	}
	if(index == 3){
		if(button3_flag == 1){
			button3_flag = 0;
			return 1;
		}
	}

	return 0;
}

void subKeyProcess1(){
	//TODO
	button1_flag = 1;
}
void subKeyProcess2(){
	button2_flag = 1;
}
void subKeyProcess3(){
	button3_flag = 1;
}
void getKeyInput(){
	//button 1
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(MODE_GPIO_Port,MODE_Pin);
	if((keyReg0 == keyReg1) && (keyReg1 == keyReg2)){
		if(keyReg3 != keyReg2) {// nhan tha
			keyReg3 = keyReg2;
			if(keyReg2 == PRESSED_STATE){
				//TODO
				subKeyProcess1();
				TimerForKeyPress = 200;
			}
		}
		else{ // nhan de
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				keyReg3 = NORMAL_STATE;
			}
		}
	}

	//button 2
	keyReg4 = keyReg5;
	keyReg5 = keyReg6;
	keyReg6 = HAL_GPIO_ReadPin(ADD_GPIO_Port,ADD_Pin);
	if((keyReg4 == keyReg5) && (keyReg5 == keyReg6)){
		if(keyReg7 != keyReg6) {// nhan tha
			keyReg7 = keyReg6;
			if(keyReg6 == PRESSED_STATE){
				//TODO
				subKeyProcess2();
				TimerForKeyPress = 200;
			}
		}
		else{ // nhan de
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				keyReg7 = NORMAL_STATE;
			}
		}
	}
	//button 3
	keyReg8 = keyReg9;
	keyReg9 = keyReg10;
	keyReg10 = HAL_GPIO_ReadPin(SET_GPIO_Port,SET_Pin);
	if((keyReg8 == keyReg9) && (keyReg9 == keyReg10)){
		if(keyReg11 != keyReg10) {// nhan tha
			keyReg11 = keyReg10;
			if(keyReg10 == PRESSED_STATE){
				//TODO
				subKeyProcess3();
				TimerForKeyPress = 200;
			}
		}
		else{ // nhan de
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				keyReg11 = NORMAL_STATE;
			}
		}
	}
}

