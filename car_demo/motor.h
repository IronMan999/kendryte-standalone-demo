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
#ifndef _MOTOR_H
#define _MOTOR_H

#include <stdint.h>

/* motor control struct */
typedef struct {
        uint32_t control_pin1;
        uint32_t control_pin2;
        uint32_t control_io1;
        uint32_t control_io2;
        uint32_t pwm_pin;
        uint32_t pwm_device;
        uint32_t pwm_channel;
        uint32_t mode;
        float frequency;
        float duty;
} motor_control_t;

void motor_init(motor_control_t *motor);
void motor_set_duty(motor_control_t *motor);
void motor_set_mode(motor_control_t *motor);

#endif /* _MOTOR_H */

