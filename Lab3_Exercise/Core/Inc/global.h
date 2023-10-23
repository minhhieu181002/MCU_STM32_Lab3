/*
 * global.h
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "softwareTimer.h"
#include "main.h"
//#include "button.h"
#define INIT 			1
#define AUTO_RED_GREEN	2
#define AUTO_RED_AMBER	3
#define AUTO_GREEN_RED	4
#define AUTO_AMBER_RED	5
#define TIME_FOR_RED_GREEN	1
#define TIME_FOR_RED_AMBER	2
#define TIME_FOR_GREEN_RED	1
#define TIME_FOR_AMBER_RED 	2
#define TIME_FOR_LED_RED_RUN 	1
#define TIME_FOR_LED_GREEN_RUN 	2
#define TIME_FOR_LED_YELLOW_RUN 3

extern int status;
extern int arr[3];


#endif /* INC_GLOBAL_H_ */
