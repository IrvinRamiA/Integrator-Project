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
uint16_t sumAdc = Zero;
uint16_t adcAverageSum = Zero;
uint8_t adcCounterSamples = Zero;
uint8_t adcAverageFlag = Zero;

void analogToDigitalConverterThread_entry(void)
{
    InitializeAdc();
    while (True)
    {
        if(adcCounterSamples > OneHundredMilliseconds)
        {
            ReadAdcChannelZero(&adcData);
            sumAdc = (uint16_t) (sumAdc + adcData);
            adcAverageFlag ++;

            if(adcAverageFlag == AdcSamplesNumber)
            {
                adcAverageSum = (uint16_t) (sumAdc / AdcSamplesNumber);
                sumAdc = 0;
                adcAverageFlag = 0;
                adcCounterSamples = 0;
            }
        }

        setPointFromAdcTx[IndexZero] = AdcDataToPercentage(&adcAverageSum);
        tx_queue_send(&gSetPointMainControlQueue, setPointFromAdcTx, TX_NO_WAIT);
        tx_queue_send(&gSetPointDisplayQueue, setPointFromAdcTx, TX_NO_WAIT);
        tx_thread_sleep(TenMilliseconds);

        adcCounterSamples ++;
    }
}
