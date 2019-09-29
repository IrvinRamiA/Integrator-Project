/*!
 * @file
 * @brief
 *
 * Copyright DSE 3 - Confidential - All rights reserved
 */

#ifndef PID_CONTROL_H
#define PID_CONTROL_H

#include "hal_data.h"

enum PidControlConstants
{
    Kp = 5,
    Ki = 1,
    Kd = 4
};

enum TimeVariables
{
    SamplingTimeInMs = 100,
};

enum PwmDutyCycleLimits
{
    PwmDutyCycleLowerLimit = 0,
    PwmDutyCycleUpperLimit = 255
};

uint8_t error = 0;
uint8_t derivativeError = 0;
uint8_t integralError = 0;
uint8_t previousError = 0;
uint8_t proportional = 0;
uint8_t derivative = 0;
uint8_t integral = 0;
uint8_t output = 0;
uint8_t time = 0;
uint8_t previousTime = 0;
uint8_t samplingTime = 0;

uint8_t SpeedPidControl(uint8_t measuredSpeedInRpm, uint8_t setPointInRpm);

#endif
