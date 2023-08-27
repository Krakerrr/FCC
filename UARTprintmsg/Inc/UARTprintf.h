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

#define UARTprintmsg_CHANNEL		USART1


void UARTprintmsg(char *format,...);
void UARTprintmsg_Init(void);
void UARTprintmsg_GPIOInit(void);


UART_HandleTypeDef hUARTprintmsg;



#endif /* INC_UARTPRINTF_H_ */
