/*
 * callbacks.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Administrator
 */

#include "main_app.h"



Struct_ICM20608g ICM20608g;
sR9SBUS_data R9SBUS_data;

ExternalInputs_FCA FCA_U;
ExternalOutputs_FCA FCA_Y;

void SYSTIMER_200HzTASK(void)
{
	ICM20608g_Get6Data( &ICM20608g );
}

void SYSTIMER_100HzTASK1(void)
{


}

void SYSTIMER_100HzTASK2(void)
{
	memcpy(FCA_U.KS_channels, R9SBUS_data.channels, sizeof(FCA_U.KS_channels));
	FCA_step();

	PWM_SET_CHANNEL1(FCA_Y.Servo1CMD);
	PWM_SET_CHANNEL2(FCA_Y.Servo2CMD);

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
