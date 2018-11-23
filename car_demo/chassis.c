/* Copyright 2018 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "motor.h"
#include "chassis.h"

/* chassis hardware config */
#define LEFT_FRONT_MOTOR_CONTROL_PIN1	24
#define LEFT_FRONT_MOTOR_CONTROL_IO1	8
#define LEFT_FRONT_MOTOR_CONTROL_PIN2	25
#define LEFT_FRONT_MOTOR_CONTROL_IO2	9
#define LEFT_FRONT_MOTOR_PWM_PIN	26
#define LEFT_FRONT_MOTOR_PWM_DEVICE	1
#define LEFT_FRONT_MOTOR_PWM_CHANNEL	0

#define LEFT_REAR_MOTOR_CONTROL_PIN1	29
#define LEFT_REAR_MOTOR_CONTROL_IO1	10
#define LEFT_REAR_MOTOR_CONTROL_PIN2	28
#define LEFT_REAR_MOTOR_CONTROL_IO2	11
#define LEFT_REAR_MOTOR_PWM_PIN		27
#define LEFT_REAR_MOTOR_PWM_DEVICE	1
#define LEFT_REAR_MOTOR_PWM_CHANNEL	1

#define RIGHT_FRONT_MOTOR_CONTROL_PIN1	19
#define RIGHT_FRONT_MOTOR_CONTROL_IO1	12
#define RIGHT_FRONT_MOTOR_CONTROL_PIN2	18
#define RIGHT_FRONT_MOTOR_CONTROL_IO2	13
#define RIGHT_FRONT_MOTOR_PWM_PIN	20
#define RIGHT_FRONT_MOTOR_PWM_DEVICE	1
#define RIGHT_FRONT_MOTOR_PWM_CHANNEL	2

#define RIGHT_REAR_MOTOR_CONTROL_PIN1	22
#define RIGHT_REAR_MOTOR_CONTROL_IO1	14
#define RIGHT_REAR_MOTOR_CONTROL_PIN2	23
#define RIGHT_REAR_MOTOR_CONTROL_IO2	15
#define RIGHT_REAR_MOTOR_PWM_PIN	21
#define RIGHT_REAR_MOTOR_PWM_DEVICE	1
#define RIGHT_REAR_MOTOR_PWM_CHANNEL	3

#define MOTOR_FREQUENCY			50
#define ANGLE_FACTOR			0.002

/* chassis control struct */
typedef struct {
        motor_control_t left_front_motor;
        motor_control_t left_rear_motor;
        motor_control_t right_front_motor;
        motor_control_t right_rear_motor;
} chassis_control_t;

static chassis_control_t chassis_ctl;

void chassis_init(void)
{
	chassis_ctl.left_front_motor.control_pin1 = LEFT_FRONT_MOTOR_CONTROL_PIN1;
	chassis_ctl.left_front_motor.control_io1 = LEFT_FRONT_MOTOR_CONTROL_IO1;
	chassis_ctl.left_front_motor.control_pin2 = LEFT_FRONT_MOTOR_CONTROL_PIN2;
	chassis_ctl.left_front_motor.control_io2 = LEFT_FRONT_MOTOR_CONTROL_IO2;
	chassis_ctl.left_front_motor.pwm_pin = LEFT_FRONT_MOTOR_PWM_PIN;
	chassis_ctl.left_front_motor.pwm_device = LEFT_FRONT_MOTOR_PWM_DEVICE;
	chassis_ctl.left_front_motor.pwm_channel = LEFT_FRONT_MOTOR_PWM_CHANNEL;
	chassis_ctl.left_front_motor.frequency = MOTOR_FREQUENCY;
	chassis_ctl.left_front_motor.duty = 0;
	chassis_ctl.left_front_motor.mode = 0;

	chassis_ctl.left_rear_motor.control_pin1 = LEFT_REAR_MOTOR_CONTROL_PIN1;
	chassis_ctl.left_rear_motor.control_io1 = LEFT_REAR_MOTOR_CONTROL_IO1;
	chassis_ctl.left_rear_motor.control_pin2 = LEFT_REAR_MOTOR_CONTROL_PIN2;
	chassis_ctl.left_rear_motor.control_io2 = LEFT_REAR_MOTOR_CONTROL_IO2;
	chassis_ctl.left_rear_motor.pwm_pin = LEFT_REAR_MOTOR_PWM_PIN;
	chassis_ctl.left_rear_motor.pwm_device = LEFT_REAR_MOTOR_PWM_DEVICE;
	chassis_ctl.left_rear_motor.pwm_channel = LEFT_REAR_MOTOR_PWM_CHANNEL;
	chassis_ctl.left_rear_motor.frequency = MOTOR_FREQUENCY;
	chassis_ctl.left_rear_motor.duty = 0;
	chassis_ctl.left_rear_motor.mode = 0;

	chassis_ctl.right_front_motor.control_pin1 = RIGHT_FRONT_MOTOR_CONTROL_PIN1;
	chassis_ctl.right_front_motor.control_io1 = RIGHT_FRONT_MOTOR_CONTROL_IO1;
	chassis_ctl.right_front_motor.control_pin2 = RIGHT_FRONT_MOTOR_CONTROL_PIN2;
	chassis_ctl.right_front_motor.control_io2 = RIGHT_FRONT_MOTOR_CONTROL_IO2;
	chassis_ctl.right_front_motor.pwm_pin = RIGHT_FRONT_MOTOR_PWM_PIN;
	chassis_ctl.right_front_motor.pwm_device = RIGHT_FRONT_MOTOR_PWM_DEVICE;
	chassis_ctl.right_front_motor.pwm_channel = RIGHT_FRONT_MOTOR_PWM_CHANNEL;
	chassis_ctl.right_front_motor.frequency = MOTOR_FREQUENCY;
	chassis_ctl.right_front_motor.duty = 0;
	chassis_ctl.right_front_motor.mode = 0;

	chassis_ctl.right_rear_motor.control_pin1 = RIGHT_REAR_MOTOR_CONTROL_PIN1;
	chassis_ctl.right_rear_motor.control_io1 = RIGHT_REAR_MOTOR_CONTROL_IO1;
	chassis_ctl.right_rear_motor.control_pin2 = RIGHT_REAR_MOTOR_CONTROL_PIN2;
	chassis_ctl.right_rear_motor.control_io2 = RIGHT_REAR_MOTOR_CONTROL_IO2;
	chassis_ctl.right_rear_motor.pwm_pin = RIGHT_REAR_MOTOR_PWM_PIN;
	chassis_ctl.right_rear_motor.pwm_device = RIGHT_REAR_MOTOR_PWM_DEVICE;
	chassis_ctl.right_rear_motor.pwm_channel = RIGHT_REAR_MOTOR_PWM_CHANNEL;
	chassis_ctl.right_rear_motor.frequency = MOTOR_FREQUENCY;
	chassis_ctl.right_rear_motor.duty = 0;
	chassis_ctl.right_rear_motor.mode = 0;

	motor_init(&chassis_ctl.left_front_motor);
	motor_init(&chassis_ctl.left_rear_motor);
	motor_init(&chassis_ctl.right_front_motor);
	motor_init(&chassis_ctl.right_rear_motor);
}

void chassis_stop(void)
{
	chassis_ctl.left_front_motor.mode = 3;
	chassis_ctl.left_rear_motor.mode = 3;
	chassis_ctl.right_front_motor.mode = 3;
	chassis_ctl.right_rear_motor.mode = 3;
	motor_set_mode(&chassis_ctl.left_front_motor);
	motor_set_mode(&chassis_ctl.left_rear_motor);
	motor_set_mode(&chassis_ctl.right_front_motor);
	motor_set_mode(&chassis_ctl.right_rear_motor);
}

void chassis_motion_set(float speed, float angle)
{
	float left_speed, right_speed;

	left_speed = speed + ANGLE_FACTOR * angle;
	right_speed = speed - ANGLE_FACTOR * angle;

	left_speed = left_speed < -1 ? -1 : left_speed;
	left_speed = left_speed > 1 ? 1 : left_speed;
	right_speed = right_speed < -1 ? -1 : right_speed;
	right_speed = right_speed > 1 ? 1 : right_speed;

	if (left_speed >= 0) {
		chassis_ctl.left_front_motor.mode = 1;
		chassis_ctl.left_rear_motor.mode = 1;
		chassis_ctl.left_front_motor.duty = left_speed;
		chassis_ctl.left_rear_motor.duty = left_speed;
	} else {
		chassis_ctl.left_front_motor.mode = 2;
		chassis_ctl.left_rear_motor.mode = 2;
		chassis_ctl.left_front_motor.duty = left_speed;
		chassis_ctl.left_rear_motor.duty = left_speed;
	}
	if (right_speed >= 0) {
		chassis_ctl.right_front_motor.mode = 1;
		chassis_ctl.right_rear_motor.mode = 1;
		chassis_ctl.right_front_motor.duty = right_speed;
		chassis_ctl.right_rear_motor.duty = right_speed;
	} else {
		chassis_ctl.right_front_motor.mode = 2;
		chassis_ctl.right_rear_motor.mode = 2;
		chassis_ctl.right_front_motor.duty = right_speed;
		chassis_ctl.right_rear_motor.duty = right_speed;
	}
	motor_set_mode(&chassis_ctl.left_front_motor);
	motor_set_mode(&chassis_ctl.left_rear_motor);
	motor_set_mode(&chassis_ctl.right_front_motor);
	motor_set_mode(&chassis_ctl.right_rear_motor);
	motor_set_duty(&chassis_ctl.left_front_motor);
	motor_set_duty(&chassis_ctl.left_rear_motor);
	motor_set_duty(&chassis_ctl.right_front_motor);
	motor_set_duty(&chassis_ctl.right_rear_motor);
}