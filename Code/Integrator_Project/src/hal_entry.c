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

uint16_t adcData;
timer_size_t percentage;
uint32_t measuredSpeedInRpm = 0;
uint32_t setPointInRpm = 0;
uint32_t outputValue = 0;

void hal_entry(void)
{
    OpenAdc();
    ScanCfgAdc();
    ScanStartAdc();

    OpenTimer();
    StartTimer();

    InitializeInputCapture();

    setGains(100, 0.001, 0);

    while(1)
    {
        ReadAdcChannel0(&adcData);
        setPointInRpm = (uint16_t) AdcDataToPercentage(&adcData);

        measuredSpeedInRpm = (uint16_t) rpm;

        PidSpeedControl(&measuredSpeedInRpm, &setPointInRpm, &outputValue);

        SetDutyCycle(outputValue);
    }
}
