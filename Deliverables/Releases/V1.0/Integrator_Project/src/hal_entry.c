/***********************************************************************************************************************
 * Copyright [2015-2017] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hal_entry.c
* Description  : Integrator Project main file.
***********************************************************************************************************************/

#include "hal_data.h"
#include "r_timer_api.h"

uint16_t adcData;
timer_size_t percentage;

void hal_entry(void)
{
    g_adc0.p_api->open(g_adc0.p_ctrl,  g_adc0.p_cfg);
    g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg);
    g_adc0.p_api->scanStart(g_adc0.p_ctrl);

    g_timer1.p_api->open(g_timer1.p_ctrl, g_timer1.p_cfg);
    g_timer1.p_api->start(g_timer1.p_ctrl);

    while(1)
    {
        g_adc0.p_api->read(g_adc0.p_ctrl, ADC_REG_CHANNEL_0, &adcData);
        percentage = (timer_size_t)(adcData * 100) / 255;

        g_timer1.p_api->dutyCycleSet(g_timer1.p_ctrl, percentage, TIMER_PWM_UNIT_PERCENT, 1);
    }
}
