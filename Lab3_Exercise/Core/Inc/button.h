/*
 * button.h
 *
 *  Created on: Oct 28, 2023
 *      Author: HP
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
void getKeyInput(); // use for process anti vibration and pressed

int isButton1Pressed();
#endif /* INC_BUTTON_H_ */
