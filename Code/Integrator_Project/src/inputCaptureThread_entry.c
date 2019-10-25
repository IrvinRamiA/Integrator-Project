/*
 * @file inputCaptureThread_entry.c
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include <inputCaptureThread.h>
#include <mainControlThread.h>
#include <displayThread.h>
#include "InputCapture.h"

ULONG speedFromInputCaptureTx[SizeOne] = {Zero};

void inputCaptureThread_entry(void)
{
    InitializeInputCapture();
    while (True)
    {
        speedFromInputCaptureTx[IndexZero] = (uint16_t) rpm;
        tx_queue_send(&gSpeedMainControlQueue, speedFromInputCaptureTx, TX_NO_WAIT);
        tx_queue_send(&gSpeedDisplayQueue, speedFromInputCaptureTx, TX_NO_WAIT);
        tx_thread_sleep (TenMilliseconds);
    }
}
