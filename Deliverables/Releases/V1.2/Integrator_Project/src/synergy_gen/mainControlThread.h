/* generated thread header file - do not edit */
#ifndef MAINCONTROLTHREAD_H_
#define MAINCONTROLTHREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus 
extern "C" void mainControlThread_entry(void);
#else 
extern void mainControlThread_entry(void);
#endif
#include "r_gpt.h"
#include "r_timer_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer1;
#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
extern TX_QUEUE gSpeedMainControlQueue;
extern TX_QUEUE gSetPointMainControlQueue;
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* MAINCONTROLTHREAD_H_ */