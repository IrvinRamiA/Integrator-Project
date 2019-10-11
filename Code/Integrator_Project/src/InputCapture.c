/*
 * @file
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include "InputCapture.h"

#define CHANNEL_ZERO (0U)
#define TIMER_ONE_SECOND (1000000000U)
#define BIT_32 (0x100000000U)

input_capture_info_t input_capture_info;
uint64_t captureOverflow = 0;
uint32_t captureCounter = 0;
uint32_t timeCapturedTruncated = 0;
uint32_t frequency = 0;

void InitializeInputCapture(void)
{
    g_input_capture.p_api->open(g_input_capture.p_ctrl, g_input_capture.p_cfg);
}

void InputCapture_Callback(input_capture_callback_args_t *p_args)
{
    uint32_t pclkdFreq = 0;
    uint64_t timeCaptured = 0;

    if(CHANNEL_ZERO == p_args->channel)
    {
        switch(p_args->event)
        {
            case INPUT_CAPTURE_EVENT_MEASUREMENT:
                captureCounter = p_args->counter;
                g_cgc_on_cgc.systemClockFreqGet(CGC_SYSTEM_CLOCKS_PCLKD, &pclkdFreq);
                timeCaptured = (uint64_t)(((captureOverflow * BIT_32) + (uint64_t)captureCounter) * TIMER_ONE_SECOND / pclkdFreq);
                timeCapturedTruncated = (uint32_t)((float) timeCaptured + 0.5F);
                frequency = (uint32_t)((float)TIMER_ONE_SECOND / (float)timeCapturedTruncated);
                rpm = frequency * 15;
                timeCaptured = 0;
                captureOverflow = 0;
                break;

            case INPUT_CAPTURE_EVENT_OVERFLOW:
                captureOverflow++;
                break;

            default:
                break;
        }
    }
}
