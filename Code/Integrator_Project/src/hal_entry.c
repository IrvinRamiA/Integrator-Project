/*
 * @file hal_entry.c
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include "hal_data.h"
#include "r_timer_api.h"

#include "AnalogToDigitalConverter.h"

uint16_t adcData;
timer_size_t percentage;

void hal_entry(void)
{
    OpenAdc();
    ScanCfgAdc();
    ScanStartAdc();

    g_timer1.p_api->open(g_timer1.p_ctrl, g_timer1.p_cfg);
    g_timer1.p_api->start(g_timer1.p_ctrl);

    while(1)
    {
        ReadAdcChannel0(&adcData);
        percentage = AdcDataToPercentage(&adcData);

        g_timer1.p_api->dutyCycleSet(g_timer1.p_ctrl, percentage, TIMER_PWM_UNIT_PERCENT, 1);
    }
}
