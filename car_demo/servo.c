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
#include <pwm.h>
#include <fpioa.h>
#include "servo.h"

void servo_init(servo_control_t *servo)
{
	fpioa_set_function(servo->pwm_pin, FUNC_TIMER0_TOGGLE1 + servo->pwm_device * 4 + servo->pwm_channel);
	pwm_init(servo->pwm_device);
	servo_set_duty(servo);
	pwm_set_enable(servo->pwm_device, servo->pwm_channel, 1);
}

void servo_set_duty(servo_control_t *servo)
{
	servo->frequency = pwm_set_frequency(servo->pwm_device, servo->pwm_channel, servo->frequency, servo->duty);
}