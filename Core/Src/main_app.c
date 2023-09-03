/*
 * main_app.c
 *
 *  Created on: 20 Ağu 2023
 *      Author: Administrator
 */

#include "main_app.h"




int main(void) {

	HAL_Init();

	SystemClock_Config_HSE(SYS_CLOCK_FREQ_50_MHZ);

	RF_Init();

	ICM20608g_Initialization();

	PWM_Initialization();

	R9SBUS_Init();

	FCA_initialize();

	SYSTIMER_Init();

	SYSTIMER_Start_IT();

	R9SBUS_RX_STARTtoIDLE_IT();

	while(1);
	return 0;
}



void SystemClock_Config_HSE(uint8_t clock_freq)
{

	// CLOCK init & config
	uint32_t FLatency = 0;
	RCC_OscInitTypeDef osc_init = {0};
	RCC_PLLInitTypeDef pll_init;
	RCC_ClkInitTypeDef clck_init = {0};

	clck_init.ClockType 		= ( RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_HCLK );


	switch(clock_freq)
	{

	case SYS_CLOCK_FREQ_50_MHZ:
		// 50 Mhz
		pll_init.PLLM = 8;
		pll_init.PLLN = 100;
		pll_init.PLLP = 2;
		clck_init.SYSCLKSource 		= RCC_SYSCLKSOURCE_PLLCLK;
		clck_init.AHBCLKDivider 	= RCC_SYSCLK_DIV1;
		clck_init.APB1CLKDivider 	= RCC_HCLK_DIV2;
		clck_init.APB2CLKDivider 	= RCC_HCLK_DIV2;
		FLatency = FLASH_ACR_LATENCY_1WS;
		break;

	case SYS_CLOCK_FREQ_84_MHZ:
		// 84 Mhz
		pll_init.PLLM = 8;
		pll_init.PLLN = 168;
		pll_init.PLLP = 2;
		clck_init.SYSCLKSource 		= RCC_SYSCLKSOURCE_PLLCLK;
		clck_init.AHBCLKDivider 	= RCC_SYSCLK_DIV1;
		clck_init.APB1CLKDivider 	= RCC_HCLK_DIV2;
		clck_init.APB2CLKDivider 	= RCC_HCLK_DIV2;
		FLatency = FLASH_ACR_LATENCY_2WS;
		break;

	case SYS_CLOCK_FREQ_120_MHZ:
		// 120 Mhz
		pll_init.PLLM = 8;
		pll_init.PLLN = 240;
		pll_init.PLLP = 2;
		clck_init.SYSCLKSource 		= RCC_SYSCLKSOURCE_PLLCLK;
		clck_init.AHBCLKDivider 	= RCC_SYSCLK_DIV1;
		clck_init.APB1CLKDivider 	= RCC_HCLK_DIV4;
		clck_init.APB2CLKDivider 	= RCC_HCLK_DIV2;
		FLatency = FLASH_ACR_LATENCY_3WS;
		break;

	case SYS_CLOCK_FREQ_168_MHZ:
		// 168 Mhz
		pll_init.PLLM = 8;
		pll_init.PLLN = 336;
		pll_init.PLLP = 2;
		clck_init.SYSCLKSource 		= RCC_SYSCLKSOURCE_PLLCLK;
		clck_init.AHBCLKDivider 	= RCC_SYSCLK_DIV1;
		clck_init.APB1CLKDivider 	= RCC_HCLK_DIV4;
		clck_init.APB2CLKDivider 	= RCC_HCLK_DIV2;
		FLatency = FLASH_ACR_LATENCY_5WS;

		// enable clock for the power controller (no need for stm32f407)
		//		__HAL_RCC_PWR_CLK_ENABLE();
		// set regulator voltage scale as 1
		//		__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
		break;

	}

	pll_init.PLLSource = RCC_PLLSOURCE_HSE;
	pll_init.PLLState = RCC_PLL_ON;
	pll_init.PLLQ = 2; // default

	osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	osc_init.HSEState       =  RCC_HSE_ON;
	osc_init.PLL = pll_init;

	if( HAL_RCC_OscConfig(&osc_init) != HAL_OK)
	{
		Error_Handler();
	}

	if( HAL_RCC_ClockConfig(&clck_init, FLatency) != HAL_OK)
	{
		Error_Handler();
	}

	/* SYSTICK CONFIG */
	HAL_SYSTICK_Config( HAL_RCC_GetHCLKFreq() / 1000 );
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
}


void Error_Handler(void)
{
	while (1)
	{
	}
}
