/*
 * @file
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include "PulseWidthModulation.h"

void OpenTimer()
{
    g_timer1.p_api->open(g_timer1.p_ctrl, g_timer1.p_cfg);
}

void StartTimer()
{
    g_timer1.p_api->start(g_timer1.p_ctrl);
}

void SetDutyCycle(timer_size_t percentage)
{
    g_timer1.p_api->dutyCycleSet(g_timer1.p_ctrl, percentage, TIMER_PWM_UNIT_PERCENT, 1);
}
