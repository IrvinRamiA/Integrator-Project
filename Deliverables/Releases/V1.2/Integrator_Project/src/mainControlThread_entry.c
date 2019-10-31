/*
 * @file mainControlThread_entry.c
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include <mainControlThread.h>
#include <displayThread.h>
#include "hal_data.h"
#include "PulseWidthModulation.h"
#include "PidControl.h"

ULONG dutyCycleFromMainTx[SizeOne] = {Zero};

ULONG setPointFromAdcRx[SizeOne] = {Zero};
ULONG speedFromInputCaptureRx[SizeOne] = {Zero};

uint32_t outputValue = Zero;
uint32_t setPointInRpm = Zero;
uint32_t measuredSpeedInRpm = Zero;

void mainControlThread_entry(void)
{
    InitializePwm();
    SetGainsPid(100, 0.001, 0);
    while (True)
    {
        tx_queue_receive(&gSetPointMainControlQueue, setPointFromAdcRx, WaitTime);
        tx_queue_receive(&gSpeedMainControlQueue, speedFromInputCaptureRx, WaitTime);
        setPointInRpm = setPointFromAdcRx[IndexZero];
        measuredSpeedInRpm = speedFromInputCaptureRx[IndexZero];

        ComputePidControl(&measuredSpeedInRpm, &setPointInRpm, &outputValue);
        SetDutyCyclePwm(outputValue);

        dutyCycleFromMainTx[IndexZero] = outputValue;
        tx_queue_send(&gDutyCycleDisplayQueue, dutyCycleFromMainTx, TX_NO_WAIT);

        tx_thread_sleep (TenMilliseconds);
    }
}
