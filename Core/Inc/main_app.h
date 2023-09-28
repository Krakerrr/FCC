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

void Error_Handler(uint8_t errorcode);
void SystemClock_Config_HSE(uint8_t clock_freq);

#define TRUE 	1
#define FALSE 	0

#define SYS_CLOCK_FREQ_50_MHZ 50
#define SYS_CLOCK_FREQ_84_MHZ 84
#define SYS_CLOCK_FREQ_120_MHZ 120
#define SYS_CLOCK_FREQ_168_MHZ 168


typedef enum
{
	E_RFInit = 0,
	E_RFDMAInit,
	E_PWMInit,
	E_PWMConfigChannel1,
	E_PWMConfigChannel2,
	E_PWMConfigChannel3,
	E_PWMConfigChannel4,
	E_PWMStartCH1,
	E_PWMStartCH2,
	E_PWMStartCH3,
	E_PWMStartCH4,
	E_SysTimerInit,
	E_SysTimerSTART_IT,
	E_I2CInit,
	E_I2CSendByte,
	E_I2CReadByte,
	E_ICMInit,
	E_SBUSInit,
	E_RCCOSCConfig,
	E_RCCClokcConfig
}_config_error;

#include "RF.h"
#include "r9sbus.h"
#include "ICM20608g.h"
#include "FCA.h"
#include "PWM.h"
#include "SysTimer.h"
#include "FCA_IO.h"

#endif /* INC_MAIN_APP_H_ */
