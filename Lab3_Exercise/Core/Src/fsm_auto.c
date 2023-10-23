/*
 * fsm_auto.c
 *
 *  Created on: Oct 23, 2023
 *      Author: HP
 */
#include "fsm_auto.h"
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};


void display7SEG(int num) {
  switch(num) {
	  case 0 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);
		  break;
	  }

	  case 1 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);
		  break;
	  }

	  case 2 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 1);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);
		  break;
	  }
	  case 3 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);
		  break;
	  }
	  case 4 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);
		  break;
	  }
	  case 5 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);
		  break;
	  }
	  case 6 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);
		  break;
	  }
	  case 7 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);
		  break;
	  }
	  case 8 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);
		  break;
	  }
	  case 9 : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);
		  break;
	  }

	  default : {
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 1);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);
		  break;
	  }
  }
}
void updateLedBuffer (){
	if(status == AUTO_RED_GREEN){
		//display for red led
		led_buffer[0] = 0;
		led_buffer[1] = 5;
		//display for green led
		led_buffer[2] = 0;
		led_buffer[3] = 3;
	}
	if(status == AUTO_RED_AMBER){
		led_buffer[0] = 0;
		led_buffer[1] = 3;
		led_buffer[2] = 0;
		led_buffer[3] = 2;
	}
	if(status == AUTO_GREEN_RED){
		//display for green
		led_buffer[0] = 0;
		led_buffer[1] = 3;
		//display for red
		led_buffer[2] = 0;
		led_buffer[3] = 5;
	}
	if(status == AUTO_AMBER_RED){
		led_buffer[0] = 0;
		led_buffer[1] = 2;
		led_buffer[2] = 0;
		led_buffer[3] = 2;
	}
}
void update7SEG ( int index ){
	switch ( index ){
		case 0:
			// Display the first 7 SEG with led_buffer [0] and led_buffer [1]

			HAL_GPIO_WritePin(GPIOA,EN0_Pin,0);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin,0);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin,1);
			display7SEG(led_buffer[0]);
			display7SEG(led_buffer[1]);
			break ;
		case 1:
			// Display the second 7 SEG with led_buffer [2] and led_buffer [3];
			HAL_GPIO_WritePin(GPIOA,EN0_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin,0);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin,0);
			display7SEG(led_buffer[2]);
			display7SEG(led_buffer[3]);
			break ;
		default :
			break ;
 	 }
 }

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
	updateLedBuffer();
	if(timer3_flag == 1){
		setTimer3(50);
		if (index_led >= 2) index_led = 0;
		update7SEG(index_led++);
	}
}

