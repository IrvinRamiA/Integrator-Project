/*
 * @file hal_entry.c
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include "hal_data.h"

#include "AnalogToDigitalConverter.h"
#include "PulseWidthModulation.h"

uint16_t adcData;
timer_size_t percentage;

void hal_entry(void)
{
    OpenAdc();
    ScanCfgAdc();
    ScanStartAdc();

    OpenTimer();
    StartTimer();

    while(1)
    {
        ReadAdcChannel0(&adcData);
        percentage = AdcDataToPercentage(&adcData);

        SetDutyCycle(percentage);
    }
}
