/* generated thread header file - do not edit */
#ifndef ANALOGTODIGITALCONVERTERTHREAD_H_
#define ANALOGTODIGITALCONVERTERTHREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus 
extern "C" void analogToDigitalConverterThread_entry(void);
#else 
extern void analogToDigitalConverterThread_entry(void);
#endif
#include "r_adc.h"
#include "r_adc_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** ADC on ADC Instance. */
extern const adc_instance_t g_adc0;
#ifndef NULL
void NULL(adc_callback_args_t *p_args);
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* ANALOGTODIGITALCONVERTERTHREAD_H_ */
