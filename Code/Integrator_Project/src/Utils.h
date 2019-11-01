/*
 * @file Utils.h
 * @brief
 *
 * Copyright DSE - Confidential - All rights reserved
 */

#ifndef UTILS_H
#define UTILS_H

#include "hal_data.h"

enum InitializationValues
{
    Zero = 0,
    RpmSamplesNumber = 2,
    AdcSamplesNumber = 3
};

enum TimeThreadX
{
    TenMilliseconds = 1,
    OneHundredMilliseconds = 10,
    WaitTime = 20
};

enum Bool
{
    True = 1,
    False = 0
};

enum Arrays
{
    IndexZero = 0,
    SizeOne = 1
};

#endif
