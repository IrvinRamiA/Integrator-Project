/*
 * @file InputCapture.h
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#ifndef INPUT_CAPTURE_H
#define INPUT_CAPTURE_H

#include "hal_data.h"

#define CHANNEL_TWO (2U)
#define TIMER_ONE_SECOND (1000000000U)
#define BIT_32 (0x100000000U)
#define ROUND_VALUE (0.5F)

uint32_t rpm;
input_capture_info_t input_capture_info;
uint64_t captureOverflow;
uint32_t captureCounter;
uint32_t timeCapturedTruncated;
uint32_t frequency;

enum InitializationValuesInputCapture
{
    ZeroInputCapture = 0
};

enum RpmConversion
{
    FrequencyToRpmFactor = 1
};

void InitializeVariablesInputCapture(void);
void InitializeInputCapture(void);

#endif
