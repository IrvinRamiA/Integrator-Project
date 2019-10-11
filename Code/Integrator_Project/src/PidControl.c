/*!
 * @file PidControl.c
 * @brief
 *
 * Copyright DSE 3 - Confidential - All rights reserved
 */

#include "PidControl.h"

void setGains(uint8_t proportionalGain, uint8_t integralGain, uint8_t derivativeGain)
{
    sampleTimeInSec = SampleTimeInMs / MsPerSec;
    kP = proportionalGain;
    kI = (double) integralGain * sampleTimeInSec;
    kD = (double) derivativeGain / sampleTimeInSec;

    lastTimeInMs = DWT->CYCCNT / CyclesPerMs - SampleTimeInMs;
}

void PidSpeedControl(uint16_t *myMeasuredSpeedInRpm, uint16_t *mySetPointInRpm, uint8_t *myOutputValue)
{
    currentTimeInCycles = DWT->CYCCNT;
    currentTimeInMs = currentTimeInCycles / CyclesPerMs;
    timeChangeInMs = currentTimeInMs - lastTimeInMs;
    if(timeChangeInMs >= SampleTimeInMs)
    {
        error = (uint8_t) (*mySetPointInRpm - *myMeasuredSpeedInRpm);
        derivativeError = (uint8_t) (error - lastError);
        integralError = (uint8_t) (integralError + error);

        *myOutputValue = (uint8_t) (kP * error + kI * integralError + kD * derivativeError);

        lastError = error;
        lastTimeInMs = currentTimeInMs;
    }
}
