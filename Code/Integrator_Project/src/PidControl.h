/*!
 * @file PidControl.h
 * @brief
 *
 * Copyright DSE 3 - Confidential - All rights reserved
 */

#ifndef PID_CONTROL_H
#define PID_CONTROL_H

#include "hal_data.h"

uint32_t error;
uint32_t derivativeError;
uint32_t integralError;
uint32_t lastError;
uint32_t outputDebug;

uint32_t currentTimeInMs;
uint32_t currentTimeInCycles;
uint32_t lastTimeInMs;
uint32_t timeChangeInMs;
double sampleTimeInSec;

double kP;
double kI;
double kD;

uint32_t test;

enum ConversionToPercentageVariables
{
    PidMaxOutputValue = 255,
    MaxPercentageValue = 100
};

enum TimeVariables
{
    SampleTimeInMs = 1,
    CyclesPerMs = 240000,
    MsPerSec = 1000
};

void PidSpeedControl(uint32_t *myMeasuredSpeedInRpm, uint32_t *mySetPointInRpm, uint32_t *myOutputValue);
void setGains(double proportionalGain, double integralGain, double derivativeGain);

#endif
