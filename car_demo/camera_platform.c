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
#include "servo.h"
#include "camera_platform.h"

/* camera platform hardware config */
#define VERTICAL_SERVO_PWM_PIN		8
#define VERTICAL_SERVO_PWM_DEVICE	0
#define VERTICAL_SERVO_PWM_CHANNEL	0
#define HORIZONTAL_SERVO_PWM_PIN	10
#define HORIZONTAL_SERVO_PWM_DEVICE	0
#define HORIZONTAL_SERVO_PWM_CHANNEL	1

#define VERTICAL_SERVO_FREQUENCY	50
#define VERTICAL_SERVO_DUTY_MIN		0.025
#define VERTICAL_SERVO_DUTY_MAX		0.125
#define HORIZONTAL_SERVO_FREQUENCY	50
#define HORIZONTAL_SERVO_DUTY_MIN	0.025
#define HORIZONTAL_SERVO_DUTY_MAX	0.125

/* camera platform control struct */
typedef struct {
        servo_control_t vertical_servo;
        servo_control_t horizontal_servo;
} camera_platform_control_t;

static camera_platform_control_t cp_ctl;

void camera_platform_init(void)
{
	cp_ctl.vertical_servo.pwm_pin = VERTICAL_SERVO_PWM_PIN;
	cp_ctl.vertical_servo.pwm_device = VERTICAL_SERVO_PWM_DEVICE;
	cp_ctl.vertical_servo.pwm_channel = VERTICAL_SERVO_PWM_CHANNEL;
	cp_ctl.vertical_servo.frequency = VERTICAL_SERVO_FREQUENCY;
	cp_ctl.vertical_servo.duty = (VERTICAL_SERVO_DUTY_MIN + VERTICAL_SERVO_DUTY_MAX) / 2 - 0.01;

	cp_ctl.horizontal_servo.pwm_pin = HORIZONTAL_SERVO_PWM_PIN;
	cp_ctl.horizontal_servo.pwm_device = HORIZONTAL_SERVO_PWM_DEVICE;
	cp_ctl.horizontal_servo.pwm_channel = HORIZONTAL_SERVO_PWM_CHANNEL;
	cp_ctl.horizontal_servo.frequency = HORIZONTAL_SERVO_FREQUENCY;
	cp_ctl.horizontal_servo.duty = (HORIZONTAL_SERVO_DUTY_MIN + HORIZONTAL_SERVO_DUTY_MAX) / 2;

	servo_init(&cp_ctl.vertical_servo);
	servo_init(&cp_ctl.horizontal_servo);
}

void camera_platform_horizontal_angle_set(float angle)
{

}

void camera_platform_vertical_angle_set(float angle)
{

}
