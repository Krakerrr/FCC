/*
 * FCA_IO.c
 *
 *  Created on: 2 Eyl 2023
 *      Author: Administrator
 */

#include "FCA_IO.h"


uint32_t 	SYSTIMER_Clock;
sICM20608g 	ICM20608g_data;
sR9SBUS 	R9SBUS_data;
sRF			RF_data;

ExternalInputs_FCA 	FCA_U;
ExternalOutputs_FCA FCA_Y;

void FCA_Set_Inputs(void)
{
	// set KS
	memcpy( FCA_U.KS_channels, R9SBUS_data.channels, sizeof(FCA_U.KS_channels));
	FCA_U.KS_ch17 		= R9SBUS_data.ch17;
	FCA_U.KS_ch18		= R9SBUS_data.ch18;
	FCA_U.KS_failsafe 	= R9SBUS_data.failsafe;
	FCA_U.KS_framelost 	= R9SBUS_data.frame_lost;
	FCA_U.KS_status 	= R9SBUS_data.status;

	// set IMU
	FCA_U.IMU_acc_x 	= ICM20608g_data.acc_x;
	FCA_U.IMU_acc_y 	= ICM20608g_data.acc_y;
	FCA_U.IMU_acc_z 	= ICM20608g_data.acc_z;
	FCA_U.IMU_gyro_x 	= ICM20608g_data.gyro_x;
	FCA_U.IMU_gyro_y 	= ICM20608g_data.gyro_y;
	FCA_U.IMU_gyro_z 	= ICM20608g_data.gyro_z;
	FCA_U.IMU_temp   	= ICM20608g_data.temp;
	FCA_U.IMU_status 	= ICM20608g_data.datastatus;
}

void FCA_Set_Outputs(void)
{
	memcpy( RF_data.payload_address, FCA_Y.RFOUT, RF_DATAPAYLOADSIZE);
	PWM_SET_CHANNEL1(FCA_Y.Servo1CMD);
	PWM_SET_CHANNEL2(FCA_Y.Servo2CMD);
//	PWM_SET_CHANNEL3(FCA_Y.Servo3CMD);
//	PWM_SET_CHANNEL4(FCA_Y.Servo4CMD);
}
