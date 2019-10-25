/* generated thread header file - do not edit */
#ifndef INPUTCAPTURETHREAD_H_
#define INPUTCAPTURETHREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus 
extern "C" void inputCaptureThread_entry(void);
#else 
extern void inputCaptureThread_entry(void);
#endif
#include "r_gpt_input_capture.h"
#include "r_input_capture_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_input_capture;
#ifndef InputCaptureCallback
void InputCaptureCallback(input_capture_callback_args_t *p_args);
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* INPUTCAPTURETHREAD_H_ */
