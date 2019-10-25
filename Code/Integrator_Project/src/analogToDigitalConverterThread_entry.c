/*
 * @file analogToDigitalConverterThread_entry.c
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#include <analogToDigitalConverterThread.h>
#include <mainControlThread.h>
#include <displayThread.h>
#include "AnalogToDigitalConverter.h"

ULONG setPointFromAdcTx[SizeOne] = {Zero};

uint16_t adcData = Zero;

void analogToDigitalConverterThread_entry(void)
{
    InitializeAdc();
    while (True)
    {
        ReadAdcChannelZero(&adcData);
        setPointFromAdcTx[IndexZero] = AdcDataToPercentage(&adcData);
        tx_queue_send(&gSetPointMainControlQueue, setPointFromAdcTx, TX_NO_WAIT);
        tx_queue_send(&gSetPointDisplayQueue, setPointFromAdcTx, TX_NO_WAIT);
        tx_thread_sleep (TenMilliseconds);
    }
}
