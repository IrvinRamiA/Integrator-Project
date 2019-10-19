/*!
 * @file PidControl.c
 * @brief
 *
 * Copyright DSE 3 - Confidential - All rights reserved
 */

#include "PidControl.h"

void setGains(double proportionalGain, double integralGain, double derivativeGain)
{
    sampleTimeInSec = (double) SampleTimeInMs / (double) MsPerSec;
    kP = proportionalGain;
    kI = (integralGain * sampleTimeInSec);
    kD = (derivativeGain / sampleTimeInSec);

    lastTimeInMs = DWT->CYCCNT / CyclesPerMs - SampleTimeInMs;
}

void PidSpeedControl(uint32_t *myMeasuredSpeedInRpm, uint32_t *mySetPointInRpm, uint32_t *myOutputValue)
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
            error = 0;
            //error = (uint32_t) (*myMeasuredSpeedInRpm - *mySetPointInRpm);
        }
        derivativeError = (uint32_t) (error - lastError);
        integralError = (uint32_t) (integralError + error);

        outputDebug = (uint32_t) (kP * error + kI * integralError + kD * derivativeError);

        if(outputDebug > 255)
        {
            outputDebug = 255;  // 0 - 255
        }

        test = (uint32_t) (outputDebug * ((double)100 / (double)255));
        *myOutputValue = MaxPercentageValue - (uint32_t) (outputDebug * ((double) MaxPercentageValue / (double) PidMaxOutputValue));

        lastError = error;
        lastTimeInMs = currentTimeInMs;
    }
}
