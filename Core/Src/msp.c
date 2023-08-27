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






