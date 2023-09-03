/*
 * callbacks.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Administrator
 */

#include "main_app.h"

// SYSTIMER Callbakcs
void SYSTIMER_200HzTASK(void)
{
	ICM20608g_GetData();
}

void SYSTIMER_100HzTASK1(void)
{
	RF_SendTelemetryDATA();
}

void SYSTIMER_100HzTASK2(void)
{
	FCA_Set_Inputs();
	FCA_step();
	FCA_Set_Outputs();
}

// Comm Callbacks
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	RF_TxCpltCallback(huart);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	R9SBUS_RxEventCallback( huart, Size);
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	R9SBUS_ErrorCallback(huart);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	SYSTIMER_PeriodElapsedCallback(htim);
}
