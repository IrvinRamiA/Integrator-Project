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

uint16_t adcData;
timer_size_t percentage;

uint16_t measuredSpeedInRpm = 0;
uint16_t setPointInRpm = 0;
uint8_t outputValue = 0;

void hal_entry(void)
{
    OpenAdc();
    ScanCfgAdc();
    ScanStartAdc();

    OpenTimer();
    StartTimer();

    InputCapture();

    while(1)
    {
        ReadAdcChannel0(&adcData);
        percentage = AdcDataToPercentage(&adcData);

        SetDutyCycle(percentage);
    }
}
