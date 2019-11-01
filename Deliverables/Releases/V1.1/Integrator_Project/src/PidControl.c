/*!
 * @file PidControl.c
 * @brief
 *
 * Copyright DSE 3 - Confidential - All rights reserved
 */

#include "PidControl.h"

void InitializeVariablesPid()
{
    error = ZeroPid;
    derivativeError = ZeroPid;
    integralError = ZeroPid;
    lastError = ZeroPid;
    outputDebug = ZeroPid;

    currentTimeInMs = ZeroPid;
    currentTimeInCycles = ZeroPid;
    lastTimeInMs = ZeroPid;
    timeChangeInMs = ZeroPid;
    sampleTimeInSec = ZeroPid;

    kP = ZeroPid;
    kI = ZeroPid;
    kD = ZeroPid;
}

void SetGainsPid(double proportionalGain, double integralGain, double derivativeGain)
{
    InitializeVariablesPid();

    sampleTimeInSec = (double) SampleTimeInMs / (double) MsPerSec;
    kP = proportionalGain;
    kI = integralGain * sampleTimeInSec;
    kD = derivativeGain / sampleTimeInSec;

    lastTimeInMs = DWT->CYCCNT / CyclesPerMs - SampleTimeInMs;
}

void ComputePidControl(uint32_t *myMeasuredSpeedInRpm, uint32_t *mySetPointInRpm, uint32_t *myOutputValue)
{
    currentTimeInCycles = DWT->CYCCNT;
    currentTimeInMs = currentTimeInCycles / CyclesPerMs;
    timeChangeInMs = currentTimeInMs - lastTimeInMs;

    if(timeChangeInMs >= SampleTimeInMs)
    {
        if(*mySetPointInRpm >= *myMeasuredSpeedInRpm){
            error = (uint32_t) (*mySetPointInRpm - *myMeasuredSpeedInRpm);
        }
        else
        {
            error = ZeroPid;
        }

        derivativeError = (uint32_t) (error - lastError);
        integralError = (uint32_t) (integralError + error);

        outputDebug = (uint32_t) (kP * error + kI * integralError + kD * derivativeError);

        if(outputDebug > PidMaxOutputValue)
        {
            outputDebug = PidMaxOutputValue;
        }

        outputNotInverted = (uint32_t) (outputDebug * ((double)MaxPercentageValue / (double)PidMaxOutputValue));
        *myOutputValue = MaxPercentageValue - outputNotInverted;

        lastError = error;
        lastTimeInMs = currentTimeInMs;
    }
}
