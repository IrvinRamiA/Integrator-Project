/*!
 * @file PidControl.h
 * @brief
 *
 * Copyright DSE 3 - Confidential - All rights reserved
 */

#ifndef PID_CONTROL_H
#define PID_CONTROL_H

#include "hal_data.h"

enum TimeVariables
{
    SampleTimeInMs = 100,
    CyclesPerMs = 240000,
    MsPerSec = 1000
};

uint8_t error = 0;
uint8_t derivativeError = 0;
uint8_t integralError = 0;
uint8_t lastError = 0;
uint8_t output = 0;

uint32_t currentTimeInMs = 0;
uint32_t currentTimeInCycles = 0;
uint32_t lastTimeInMs = 0;
uint32_t timeChangeInMs = 0;
double sampleTimeInSec = 0;

double kP = 0;
double kI = 0;
double kD = 0;

void PidSpeedControl(uint16_t *myMeasuredSpeedInRpm, uint16_t *mySetPointInRpm, uint8_t *myOutputValue);
void setGains(uint8_t proportionalGain, uint8_t integralGain, uint8_t derivativeGain);

#endif
