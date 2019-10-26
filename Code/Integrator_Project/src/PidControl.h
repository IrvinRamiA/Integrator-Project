/*!
 * @file PidControl.h
 * @brief
 *
 * Copyright DSE 3 - Confidential - All rights reserved
 */

#ifndef PID_CONTROL_H
#define PID_CONTROL_H

#include <mainControlThread.h>
#include "hal_data.h"
#include "Utils.h"

uint32_t error;
uint32_t derivativeError;
uint32_t integralError;
uint32_t lastInput;
uint32_t outputDebug;

uint32_t currentTimeInMs;
uint32_t currentTimeInCycles;
uint32_t lastTimeInMs;
uint32_t timeChangeInMs;
double sampleTimeInSec;

double kP;
double kI;
double kD;

uint32_t outputNotInverted;

enum ConversionToPercentageVariables
{
    PidMaxOutputValue = 100,
    MaxPercentageValue = 100
};

enum TimeVariables
{
    SampleTimeInMs = 1,
    CyclesPerMs = 240000,
    MsPerSec = 1000
};

void InitializeVariablesPid();
void ComputePidControl(uint32_t *myMeasuredSpeedInRpm, uint32_t *mySetPointInRpm, uint32_t *myOutputValue);
void SetGainsPid(double proportionalGain, double integralGain, double derivativeGain);

#endif
