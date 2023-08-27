/*
 * UARTprintf.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Administrator
 */
#include "UARTprintf.h"

void UARTprintmsg_Init(void)
{
	hUARTprintmsg.Instance 			= USART1;
	hUARTprintmsg.Init.BaudRate		= 115200;
	hUARTprintmsg.Init.WordLength 	= UART_WORDLENGTH_8B;
	hUARTprintmsg.Init.StopBits 	= UART_STOPBITS_1;
	hUARTprintmsg.Init.Parity 		= UART_PARITY_NONE;
	hUARTprintmsg.Init.Mode 		= UART_MODE_TX_RX;
	hUARTprintmsg.Init.HwFlowCtl 	= UART_HWCONTROL_NONE;
	hUARTprintmsg.Init.OverSampling = UART_OVERSAMPLING_8;
	if ( HAL_UART_Init(&hUARTprintmsg) != HAL_OK )
	{
		// there is a problem
		Error_Handler();
	}
}

void UARTprintmsg_GPIOInit(void)
{
	GPIO_InitTypeDef gpio_uart;

	//	1. enable peripheral clock usart and gpioa
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	/**USART1 GPIO Configuration
    	PA9     ------> USART1_TX
    	PA10     ------> USART1_RX
	 */

	//	2. pin muxing configurations (tx rx pins / 2gpios : alternate func. -> UART)
	gpio_uart.Pin   	= GPIO_PIN_9 | GPIO_PIN_10;
	gpio_uart.Mode  	= GPIO_MODE_AF_PP;
	gpio_uart.Pull  	= GPIO_PULLUP;
	gpio_uart.Speed 	= GPIO_SPEED_FREQ_VERY_HIGH;
	gpio_uart.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init( GPIOA, &gpio_uart);

	//	3. set priority
	HAL_NVIC_SetPriority(USART1_IRQn, 15, 0);

	//	4. enable peripheral irq in the nvic
	HAL_NVIC_EnableIRQ(USART1_IRQn);

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
