/*
 * UARTprintf.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Administrator
 */
#include "UARTprintf.h"

void UARTprintmsg_Init(void)
{
	hUARTprintmsg.Instance 			= UARTprintmsg_CHANNEL;
	hUARTprintmsg.Init.BaudRate		= UARTprintmsg_BAUDRATE;
	hUARTprintmsg.Init.WordLength 	= UART_WORDLENGTH_8B;
	hUARTprintmsg.Init.StopBits 	= UART_STOPBITS_1;
	hUARTprintmsg.Init.Parity 		= UART_PARITY_NONE;
	hUARTprintmsg.Init.Mode 		= UART_MODE_TX;
	hUARTprintmsg.Init.HwFlowCtl 	= UART_HWCONTROL_NONE;
	hUARTprintmsg.Init.OverSampling = UART_OVERSAMPLING_8;
	if ( HAL_UART_Init(&hUARTprintmsg) != HAL_OK )
	{
		//TODO: remove error handler
		Error_Handler();
	}
}

void UARTprintmsg_GPIOInit(UART_HandleTypeDef *huart)
{
	if(huart->Instance == UARTprintmsg_CHANNEL)
	{
		GPIO_InitTypeDef gpio_uart;

		//	1. enable peripheral clock usartx and gpiox
		__UARTprintmsg_CLK_ENABLE();

		//	2. pin muxing configurations (tx rx pins / 2gpios : alternate func. -> UART)
		gpio_uart.Pin   	= UARTprintmsg_TXPIN;
		gpio_uart.Mode  	= GPIO_MODE_AF_PP;
		gpio_uart.Pull  	= GPIO_PULLUP;
		gpio_uart.Speed 	= GPIO_SPEED_FREQ_VERY_HIGH;
		gpio_uart.Alternate = UARTprintmsg_GPIO_AF;
		HAL_GPIO_Init( UARTprintmsg_GPIO, &gpio_uart);

		//	3. NVIC
//		__UARTprintmsg_NVIC_ENABLE();
	}

}


void UARTprintmsg(char *format,...)
{
	char str[80];
	/*Extract the the argument list using VA apis */
	va_list args;
	va_start(args, format);
	vsprintf(str, format,args);
	HAL_UART_Transmit(&hUARTprintmsg,(uint8_t *)str, strlen(str),HAL_MAX_DELAY);
	va_end(args);
}
