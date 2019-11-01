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
uint16_t sumRpm = Zero;
uint16_t rpmAverageSum = Zero;
uint8_t rpmCounterSamples = Zero;
uint8_t rpmAverageFlag = Zero;

void inputCaptureThread_entry(void)
{
    InitializeInputCapture();
    while (True)
    {
        if(rpmCounterSamples > OneHundredMilliseconds)
        {
            sumRpm = (uint16_t) (sumRpm + rpm);
            rpmAverageFlag ++;

            if(rpmAverageFlag == RpmSamplesNumber)
            {
                rpmAverageSum = (uint16_t) (sumRpm / RpmSamplesNumber);
                speedFromInputCaptureTx[IndexZero] = (uint16_t) rpmAverageSum;
                tx_queue_send(&gSpeedDisplayQueue, speedFromInputCaptureTx, TX_NO_WAIT);

                sumRpm = 0;
                rpmAverageFlag = 0;
                rpmCounterSamples = 0;
            }
        }

        speedFromInputCaptureTx[IndexZero] = (uint16_t) rpm;
        tx_queue_send(&gSpeedMainControlQueue, speedFromInputCaptureTx, TX_NO_WAIT);
        tx_thread_sleep (TenMilliseconds);

        rpmCounterSamples ++;
    }
}
