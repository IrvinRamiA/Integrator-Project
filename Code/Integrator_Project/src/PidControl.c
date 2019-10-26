/*!
 * @file PidControl.c
 * @brief
 *
 * Copyright DSE 3 - Confidential - All rights reserved
 */

#include "PidControl.h"

void InitializeVariablesPid()
{
    error = Zero;
    derivativeError = Zero;
    integralError = Zero;
    lastInput = Zero;
    outputDebug = Zero;

    currentTimeInMs = Zero;
    currentTimeInCycles = Zero;
    lastTimeInMs = Zero;
    timeChangeInMs = Zero;
    sampleTimeInSec = Zero;

    kP = Zero;
    kI = Zero;
    kD = Zero;
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
            error = Zero;
        }

        derivativeError = (uint32_t) (*myMeasuredSpeedInRpm - lastInput);
        integralError = (uint32_t) (integralError + kD * error);
        if(integralError > PidMaxOutputValue)
        {
            integralError = PidMaxOutputValue;
        }

        outputDebug = (uint32_t) (kP * error + integralError - kD * derivativeError);

        if(outputDebug > PidMaxOutputValue)
        {
            outputDebug = PidMaxOutputValue;
        }

        outputNotInverted = (uint32_t) (outputDebug * ((double)MaxPercentageValue / (double)PidMaxOutputValue));
        *myOutputValue = MaxPercentageValue - outputNotInverted;

        lastInput = *myMeasuredSpeedInRpm;
        lastTimeInMs = currentTimeInMs;
    }
}
