/*
 * @file
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include "AnalogToDigitalConverter.h"

void OpenAdc()
{
    g_adc0.p_api->open(g_adc0.p_ctrl,  g_adc0.p_cfg);
}

void ScanCfgAdc()
{
    g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg);
}

void ScanStartAdc()
{
    g_adc0.p_api->scanStart(g_adc0.p_ctrl);
}

void ReadAdcChannel0(uint16_t *data)
{
    g_adc0.p_api->read(g_adc0.p_ctrl, ADC_REG_CHANNEL_0, data);
}

timer_size_t AdcDataToPercentage(uint16_t *data)
{
    return (timer_size_t)(*data * MaxPercentageValue) / AdcMaxOutputValue;
}
