/*
 * led.c
 *
 *  Created on: Nov 5, 2023
 *      Author: HP
 */
#include "led.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {0,1, 2, 3};

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
void toggle(){
	HAL_GPIO_TogglePin(D1_GPIO_Port, D1_Pin);
	HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
	HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
	HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
	HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
}

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
	// update led of road 1
	if(led_status1 == RED){
		led_buffer[0] = cntRoad1/10;
		led_buffer[1] = cntRoad1%10;
	}
	if(led_status1 == GREEN){
		led_buffer[0] = cntRoad1/10;
		led_buffer[1] = cntRoad1%10;
	}
	if(led_status1 == AMBER){
		led_buffer[0] = cntRoad1/10;
		led_buffer[1] = cntRoad1%10;
	}
	// update led of road 2
	if(led_status2 == GREEN){
			led_buffer[2] = cntRoad2/10;
			led_buffer[3] = cntRoad2%10;
		}
		if(led_status2 == AMBER){
			led_buffer[2] = cntRoad2/10;
			led_buffer[3] = cntRoad2%10;
		}
		if(led_status2 == RED){
			led_buffer[2] = cntRoad2/10;
			led_buffer[3] = cntRoad2%10;
		}
	if((led_status1 == DISPLAY_VALUE_RED) && (led_status2 == MODE_RED)){
		led_buffer[0] = cntRoad1/10;
		led_buffer[1] = cntRoad1%10;
		led_buffer[2] = cntRoad2/10;
		led_buffer[3] = cntRoad2%10;
	}
	if((led_status1 == DISPLAY_VALUE_GREEN) && (led_status2 == MODE_GREEN)){
		led_buffer[0] = cntRoad1/10;
		led_buffer[1] = cntRoad1%10;
		led_buffer[2] = cntRoad2/10;
		led_buffer[3] = cntRoad2%10;
	}
	if((led_status1 == DISPLAY_VALUE_AMBER) && (led_status2 == MODE_AMBER)){
		led_buffer[0] = cntRoad1/10;
		led_buffer[1] = cntRoad1%10;
		led_buffer[2] = cntRoad2/10;
		led_buffer[3] = cntRoad2%10;
	}

}
void update7SEG ( int index ){
	updateLedBuffer();
	switch ( index ){
		case 0:
			HAL_GPIO_WritePin(GPIOA,EN0_Pin,0);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin,1);
			display7SEG(led_buffer[0]);
			break ;
		case 1:
			HAL_GPIO_WritePin(GPIOA,EN0_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin,0);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin,1);
			display7SEG(led_buffer[1]);
			break ;
		case 2:
			HAL_GPIO_WritePin(GPIOA,EN0_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin,0);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin,1);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA,EN0_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin,1);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin,0);
			display7SEG(led_buffer[3]);
			break;
		default :
			break ;
 	 }
 }
