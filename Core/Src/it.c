/*
 * it.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Administrator
 */


#include "main_app.h"

extern I2C_HandleTypeDef 	hICM20608g_I2C;
extern UART_HandleTypeDef 	hR9SBUS;
extern TIM_HandleTypeDef 	hSYSTIMER;

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void I2C1_EV_IRQHandler(void)
{
	HAL_I2C_EV_IRQHandler(&hICM20608g_I2C);
}

void USART1_IRQHandler(void)
{
	HAL_UART_IRQHandler(&hR9SBUS);
}

void TIM6_DAC_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&hSYSTIMER);
}


// syste faults

void NMI_Handler(void)
{
	while (1);
}

void HardFault_Handler(void)
{
	while (1);
}

void MemManage_Handler(void)
{
	while (1);
}

void BusFault_Handler(void)
{
	while (1);
}

void UsageFault_Handler(void)
{
	while (1);
}
