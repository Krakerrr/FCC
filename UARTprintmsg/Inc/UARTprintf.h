/*
 * UARTprintf.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Administrator
 */

#ifndef INC_UARTPRINTF_H_
#define INC_UARTPRINTF_H_

#include "main_app.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define UARTprintmsg_CHANNEL				USART2
#define UARTprintmsg_BAUDRATE				115200
#define UARTprintmsg_GPIO					GPIOD
#define UARTprintmsg_TXPIN					GPIO_PIN_5
#define UARTprintmsg_GPIO_AF        		GPIO_AF7_USART2
#define __UARTprintmsg_CLK_ENABLE()   		do { \
												__HAL_RCC_USART2_CLK_ENABLE(); \
												__HAL_RCC_GPIOD_CLK_ENABLE(); \
											} while(0U)
#define __UARTprintmsg_NVIC_ENABLE()   		do { \
												HAL_NVIC_SetPriority(USART2_IRQn, 15, 0); \
												HAL_NVIC_EnableIRQ(USART2_IRQn); \
											} while(0U)



void UARTprintmsg(char *format,...);
void UARTprintmsg_Init(void);
void UARTprintmsg_GPIOInit(UART_HandleTypeDef *huart);


UART_HandleTypeDef hUARTprintmsg;



#endif /* INC_UARTPRINTF_H_ */
