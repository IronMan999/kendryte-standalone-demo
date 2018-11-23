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
#include <gpiohs.h>
#include "motor.h"

void motor_init(motor_control_t *motor)
{
        fpioa_set_function(motor->control_pin1, FUNC_GPIOHS0 + motor->control_io1);
        fpioa_set_function(motor->control_pin2, FUNC_GPIOHS0 + motor->control_io2);
        gpiohs_set_drive_mode(motor->control_io1, GPIO_DM_OUTPUT);
        gpiohs_set_drive_mode(motor->control_io2, GPIO_DM_OUTPUT);
        fpioa_set_function(motor->pwm_pin, FUNC_TIMER0_TOGGLE1 + motor->pwm_device * 4 + motor->pwm_channel);
        pwm_init(motor->pwm_device);
        motor_set_mode(motor);
        pwm_set_enable(motor->pwm_device, motor->pwm_channel, 1);
}

void motor_set_duty(motor_control_t *motor)
{
        motor->frequency = pwm_set_frequency(motor->pwm_device, motor->pwm_channel, motor->frequency, motor->duty);
}

void motor_set_mode(motor_control_t *motor)
{
        gpiohs_set_pin(motor->control_io1, motor->mode & 0x01);
        gpiohs_set_pin(motor->control_io2, motor->mode & 0x02 ? 1 : 0);
        if (motor->mode == 0)
                motor->duty = 0;
        else if (motor->mode == 3)
                motor->duty = 1;
        else
                return;
        motor_set_duty(motor);
}
