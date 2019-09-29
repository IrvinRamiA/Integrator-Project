/*!
 * @file
 * @brief
 *
 * Copyright DSE 3 - Confidential - All rights reserved
 */

#include "PidControl.h"

uint8_t SpeedPidControl(uint8_t measuredSpeedInRpm, uint8_t setPointInRpm)
{
    time = millis();
    samplingTime = time - previousTime;
    if(samplingTime >= SamplingTimeInMs)
    {
        error = setPointInRpm - measuredSpeedInRpm;
        derivativeError = (error - previousError) / SamplingTimeInMs;
        integralError += error * SamplingTimeInMs;

        proportional = Kp * error;
        derivative = Kd * derivativeError;
        integral = Ki * integralError;

        output = proportional + integral + derivative;

        if(output < PwmDutyCycleLowerLimit)
        {
            output = PwmDutyCycleLowerLimit;
        }
        else if(output > PwmDutyCycleUpperLimit)
        {
            output = PwmDutyCycleUpperLimit;
        }

        previousError = error;
        previousTime = time;
    }

    return output;
}




