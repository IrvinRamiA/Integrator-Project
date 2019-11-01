/*
 * @file AnalogToDigitalConverter.h
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#ifndef ANALOG_TO_DIGITAL_CONVERTER_H
#define ANALOG_TO_DIGITAL_CONVERTER_H

#include "hal_data.h"

enum ConversionToSetPointVariables
{
    AdcMaxOutputValue = 4095,
    MaxSetPointValue = 3000
};

void InitializeAdc();
void OpenAdc();
void ScanCfgAdc();
void ScanStartAdc();
void ReadAdcChannelZero(uint16_t *data);
timer_size_t AdcDataToPercentage(uint16_t *data);

#endif
