/*
 * main_app.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Administrator
 */

#ifndef INC_MAIN_APP_H_
#define INC_MAIN_APP_H_

#include "stdint.h"
#include "stm32f4xx_hal.h"

void Error_Handler(void);
void SystemClock_Config_HSE(uint8_t clock_freq);

#define TRUE 	1
#define FALSE 	0

#define SYS_CLOCK_FREQ_50_MHZ 50
#define SYS_CLOCK_FREQ_84_MHZ 84
#define SYS_CLOCK_FREQ_120_MHZ 120
#define SYS_CLOCK_FREQ_168_MHZ 168


#include "RF.h"
#include "r9sbus.h"
#include "ICM20608g.h"
#include "FCA.h"
#include "PWM.h"
#include "SysTimer.h"
#include "FCA_IO.h"

#endif /* INC_MAIN_APP_H_ */
