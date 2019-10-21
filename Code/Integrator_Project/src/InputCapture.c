/*
 * @file InputCapture.c
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include "InputCapture.h"

void InitializeVariablesInputCapture()
{
    rpm = ZeroInputCapture;
    captureOverflow = ZeroInputCapture;
    captureCounter = ZeroInputCapture;
    timeCapturedTruncated = ZeroInputCapture;
    frequency = ZeroInputCapture;
}

void InitializeInputCapture(void)
{
    g_input_capture.p_api->open(g_input_capture.p_ctrl, g_input_capture.p_cfg);

    InitializeVariablesInputCapture();
}

void InputCapture_Callback(input_capture_callback_args_t *p_args)
{
    uint32_t pclkdFreq = ZeroInputCapture;
    uint64_t timeCaptured = ZeroInputCapture;

    if(CHANNEL_TWO == p_args->channel)
    {
        switch(p_args->event)
        {
            case INPUT_CAPTURE_EVENT_MEASUREMENT:
                captureCounter = p_args->counter;
                g_cgc_on_cgc.systemClockFreqGet(CGC_SYSTEM_CLOCKS_PCLKD, &pclkdFreq);
                timeCaptured = (uint64_t)(((captureOverflow * BIT_32) + (uint64_t)captureCounter) * TIMER_ONE_SECOND / pclkdFreq);
                timeCapturedTruncated = (uint32_t)((float) timeCaptured + ROUND_VALUE);

                frequency = (uint32_t)((float)TIMER_ONE_SECOND / (float)timeCapturedTruncated);

                rpm = frequency * FrequencyToRpmFactor;

                timeCaptured = ZeroInputCapture;
                captureOverflow = ZeroInputCapture;
                break;

            case INPUT_CAPTURE_EVENT_OVERFLOW:
                captureOverflow++;
                break;

            default:
                break;
        }
    }
}
