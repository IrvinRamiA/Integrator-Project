/*
 * @file PulseWidthModulation.c
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#ifndef PULSE_WIDTH_MODULATION_H
#define PULSE_WIDTH_MODULATION_H

#include <mainControlThread.h>
#include "hal_data.h"
#include "r_timer_api.h"

enum Pins
{
    PinOne = 1
};

void OpenTimer();
void StartTimer();
void InitializePwm();
void SetDutyCyclePwm(timer_size_t percentage);

#endif
