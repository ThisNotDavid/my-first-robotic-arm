/*
 * joystick.h
 *
 *  Created on: Oct 14, 2025
 *      Author: David Chang Gum Wai
 */

#ifndef INC_JOYSTICK_H_
#define INC_JOYSTICK_H_

void joystick_ADC_task(double *baseAngle, double *y, double *z, double *clawAngle, uint32_t* adc_readValue);

#endif /* INC_JOYSTICK_H_ */
