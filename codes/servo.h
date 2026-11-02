/*
 * servo.h
 *
 *  Created on: Sep 26, 2025
 *      Author: David Chang Gum Wai
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

// servo functions
void setServoAngle(TIM_HandleTypeDef *htim, uint32_t timChannel, uint16_t servoAngle);
void moveToAngle(double servoAngle0, double servoAngle1, double servoAngle2);
void setBaseAngle(double angle);
void setClawAngle(double angle);
void moveToPos(double baseAngle, double x, double y);
void Servo_Init(void);
void checkAngle(void);

#endif /* INC_SERVO_H_ */
