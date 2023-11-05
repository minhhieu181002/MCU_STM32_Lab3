/*
 * fsm_auto.c
 *
 *  Created on: Oct 23, 2023
 *      Author: HP
 */


#include "fsm_auto.h"
#include "fsm_manual.h"
#include "led.h"

void fsm_automatic_run() {
		switch(status){
		case INIT:
			//todo
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
			status = AUTO_RED_GREEN;
			setTimer1(arr[TIME_FOR_RED_GREEN]*100); //3s
			break;
		case AUTO_RED_GREEN:
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
			if (timer1_flag == 1){
				status = AUTO_RED_AMBER;
				setTimer1(arr[TIME_FOR_RED_AMBER]*100); //2s
			}
			if(isButton1Pressed(BUTTON1) == 1){
				status = MAN_RED;
				setTimer1(100);
			}
			break;
		case AUTO_RED_AMBER:
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
			if (timer1_flag == 1){
				status = AUTO_GREEN_RED;
				setTimer1(arr[TIME_FOR_GREEN_RED]*100); //3s
			}
			break;
		case AUTO_GREEN_RED:
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
			if (timer1_flag == 1){
				status = AUTO_AMBER_RED;
				setTimer1(arr[TIME_FOR_AMBER_RED]*100);
			}
			break;
		case AUTO_AMBER_RED:
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
			if (timer1_flag == 1){
				status = AUTO_RED_GREEN;
				setTimer1(arr[TIME_FOR_RED_GREEN]*100);
			}
			break;

		default:
			break;
		}
		if(timer3_flag == 1){
			setTimer3(100);
			if(led_status1 == RED){
				cntRoad1--;
				if(cntRoad1 <= 0){
					led_status1 = GREEN;
					cntRoad1 = arr[1];
				}
			}
			else if(led_status1 == GREEN){
				cntRoad1--;
				if(cntRoad1 <= 0){
					led_status1 = AMBER;
					cntRoad1 = arr[2];
				}
			}
			else if(led_status1 == AMBER){
				cntRoad1--;
				if(cntRoad1 <= 0){
					led_status1 = RED;
					cntRoad1 = arr[0];
				}
			}

			if(led_status2 == GREEN){
				cntRoad2--;
				if(cntRoad2 <= 0){
					led_status2 = AMBER;
					cntRoad2 = arr[2];
				}
			}
			else if(led_status2 == AMBER){
				cntRoad2--;
				if(cntRoad2 <= 0){
					led_status2 = RED;
					cntRoad2 = arr[0];
				}
			}
			else if(led_status2 == RED){
				cntRoad2--;
				if(cntRoad2 <= 0){
					led_status2 = GREEN;
					cntRoad2 = arr[1];
				}
			}
			if((led_status1 == DISPLAY_VALUE_RED) && (led_status2 == MODE_RED)){
				cntRoad1 = arr[RED];
				cntRoad2 = arrMode[RED];
			}
			else if((led_status1 == DISPLAY_VALUE_GREEN) && (led_status2 == MODE_GREEN)){
				cntRoad1 = arr[GREEN];
				cntRoad2 = arrMode[GREEN];
			}
			else if((led_status1 == DISPLAY_VALUE_AMBER) && (led_status2 == MODE_AMBER)){
				cntRoad1 = arr[AMBER];
				cntRoad2 = arrMode[AMBER];
			}

			updateLedBuffer();
		}
		if(timer4_flag == 1){
			setTimer4(25);
			if (index_led >= 4) index_led = 0;
				update7SEG(index_led++);
		}



}

