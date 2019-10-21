/*
 * @file hal_entry.c
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include "hal_data.h"

#include "AnalogToDigitalConverter.h"
#include "PulseWidthModulation.h"
#include "InputCapture.h"
#include "PidControl.h"

uint16_t adcData = 0;
//uint32_t percentage = 0;
uint32_t measuredSpeedInRpm = 0;
uint32_t setPointInRpm = 0;
uint32_t outputValue = 0;

void hal_entry(void)
{
    InitializeAdc();
    InitializePwm();
    InitializeInputCapture();

    SetGainsPid(100, 0.001, 0);

    while(1)
    {
        ReadAdcChannelZero(&adcData);
        setPointInRpm = (uint16_t) AdcDataToPercentage(&adcData);
        measuredSpeedInRpm = (uint16_t) rpm;

        ComputePidControl(&measuredSpeedInRpm, &setPointInRpm, &outputValue);

        SetDutyCyclePwm(outputValue);
    }
}
