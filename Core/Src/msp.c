/*
 * msp.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Administrator
 */



#include "main_app.h"


void HAL_MspInit(void)
{
	// low process specift inits

	//	1. configure priority group of processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//	2. enable processor system exceptions (bus fault, mem manage, usage fault, systick)
	SCB->SHCSR |= ( (1 << 18) | ( 1 << 17 ) | ( 1 << 16) ); // usg , mem , bus fault

	//	3. configure priority system exceptions
	HAL_NVIC_SetPriority( MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority( BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority( UsageFault_IRQn, 0, 0);

	//	4. other mpu inits: floating point, sleep mode
}


void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	UARTprintmsg_GPIOInit(huart);

	R9SBUS_GPIOInit(huart);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htimer)
{
	SYSTIMER_GPIOInit(htimer);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	PWM_GPIO_Initialization(htim);
}


void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
	ICM20608g_GPIO_I2C_Initialization(hi2c);
}



