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
#ifndef _SERVO_H
#define _SERVO_H

#include <stdint.h>

/* servo control struct */
typedef struct {
        uint32_t pwm_pin;
        uint32_t pwm_device;
        uint32_t pwm_channel;
        float frequency;
        float duty;
} servo_control_t;

void servo_init(servo_control_t *servo);
void servo_set_duty(servo_control_t *servo);

#endif /* _SERVO_H */

