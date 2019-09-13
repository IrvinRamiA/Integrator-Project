/***********************************************************************************************************************
 * Copyright [2015-2017] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hal_entry.c
* Description  : Integrator Project main file.
***********************************************************************************************************************/

#include "hal_data.h"

int adcData = 0;
int percentage = 0;

void hal_entry(void) {
    g_adc0.p_api->open(g_adc0.p_ctrl,  g_adc0.p_cfg);
    g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg);
    g_adc0.p_api->scanStart(g_adc0.p_ctrl);

    while(1)
    {
        g_adc0.p_api->read(g_adc0.p_ctrl, ADC_REG_CHANNEL_0, &adcData);
        percentage = (adcData * 100) / 255;
    }

}

/*
time = 0
samplingTime = 0

time = getTimeInMs();
samplingTime = time - previousTime;

if(samplingTime >= 100)
{
    measuredValue = getRPM();
    error = setPoint - measuredValue;
    derivativeError = (error - previousError) / 10;
    integrativeError += error * 10;

    P = 0.5 * error;
    I = 0.5 * integrativeError;
    D = 0.5 * derivativeError;

    U = P + I + D;

    if(U < 0)
    {
        U = 0;
    }
    else if (U > 255)
    {
        U = 255;
    }

    if(setPoint < 0)
    {
       setPWM(Pin A, U);
    }
    else if(setPoint >= 0)
    {
       setPWM(Pin B, U);
    }

    // Display the values

    previousError = error;
    previousTime = time;
    measuredValue = 0;
}
*/
