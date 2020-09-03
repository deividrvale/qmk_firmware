/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include_next "mcuconf.h"

// The SysTick timer from the normal quantum/stm32 uses TIM2 -- the WS2812 pin used
// on the Planck requires the use of TIM2 to run PWM -- rework which timers are
// allocated for PWM usage.
#undef STM32_PWM_USE_TIM2
#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM2 TRUE
#define STM32_PWM_USE_TIM3 FALSE

// As mentioned above, we need to reallocate the SysTick timer used from
// TIM2 to TIM3.
#undef STM32_ST_USE_TIMER
#define STM32_ST_USE_TIMER 3
