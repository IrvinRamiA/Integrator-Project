/*
 * @file
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#ifndef ANALOG_TO_DIGITAL_CONVERTER
#define ANALOG_TO_DIGITAL_CONVERTER

#include "hal_data.h"

enum ConversionToPercentageVariables
{
    AdcMaxOutputValue = 255,
    MaxPercentageValue = 100
};

void OpenAdc();
void ScanCfgAdc();
void ScanStartAdc();
void ReadAdcChannel0(uint16_t *data);
timer_size_t AdcDataToPercentage(uint16_t *data);

#endif
