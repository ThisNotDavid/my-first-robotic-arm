/*
 * joystick.c
 *
 *  Created on: Oct 14, 2025
 *      Author: David Chang Gum Wai
 */


#include "stm32f1xx_hal.h"


#define DEADZONE_PERCENTAGE 30
#define SENSITIVITY 0.001


static double clamp_d(double v, double a, double b) {
    if (v < a) return a;
    if (v > b) return b;
    return v;
}

void joystick_ADC_task(double *p_x, double *p_y, double *p_z, double *pClawAngle, uint32_t* adc_readValue) {
	double x = DEADZONE_PERCENTAGE;
	double lower_dz = 2047 - (4096/100*x/2);
	double upper_dz = 2048 + (4096/100*x/2);

	for (uint8_t i = 0; i < 4; i++) {
		double v = (double)adc_readValue[i];
		double delta = 0.0;

		if (v < lower_dz) {
			delta = (-1.0) + (1.0 * v / lower_dz);
		} else if (v > upper_dz) {
			delta = (1.0 * (v - upper_dz) / (4095.0 - upper_dz));
		} else {
			delta = 0.0;
		}

//		if (i == 0)	delta = -delta; // invert x-axis joystick1

		switch (i) {

		case 0: // X
			*p_x += delta * SENSITIVITY;
			*p_x = clamp_d(*p_x, -24.0, 24.0);
			break;
		case 1: // Y
			*p_y += delta * SENSITIVITY;
			*p_y = clamp_d(*p_y, 0.0, 24.0);
			break;
		case 2: // Z
			*p_z += delta * SENSITIVITY;
			*p_z = clamp_d(*p_z, 0.0, 24.0);
			break;
		case 3: // Claw Angle
			*pClawAngle += delta * SENSITIVITY * 10;
			*pClawAngle = clamp_d(*pClawAngle, 0.0, 90.0);
			break;
		default:
		}
	}
}
