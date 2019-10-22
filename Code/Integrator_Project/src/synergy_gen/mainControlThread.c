/* generated thread source file - do not edit */
#include "mainControlThread.h"

TX_THREAD mainControlThread;
void mainControlThread_create(void);
static void mainControlThread_func(ULONG thread_input);
static uint8_t mainControlThread_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.mainControlThread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer1) && !defined(SSP_SUPPRESS_ISR_GPT1)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 1);
#endif
#endif
static gpt_instance_ctrl_t g_timer1_ctrl;
static const timer_on_gpt_cfg_t g_timer1_extend =
{ .gtioca =
{ .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW } };
static const timer_cfg_t g_timer1_cfg =
{ .mode = TIMER_MODE_PWM, .period = 1000, .unit = TIMER_UNIT_FREQUENCY_HZ, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_PERCENT,
  .channel = 1, .autostart = true, .p_callback = NULL, .p_context = &g_timer1, .p_extend = &g_timer1_extend, .irq_ipl =
          (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t g_timer1 =
{ .p_ctrl = &g_timer1_ctrl, .p_cfg = &g_timer1_cfg, .p_api = &g_timer_on_gpt };
TX_QUEUE gSpeedMainControlQueue;
static uint8_t queue_memory_gSpeedMainControlQueue[20];
TX_QUEUE gSetPointMainControlQueue;
static uint8_t queue_memory_gSetPointMainControlQueue[20];
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void mainControlThread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */
    UINT err_gSpeedMainControlQueue;
    err_gSpeedMainControlQueue = tx_queue_create (&gSpeedMainControlQueue, (CHAR *) "SpeedMainControlQueue", 1,
                                                  &queue_memory_gSpeedMainControlQueue,
                                                  sizeof(queue_memory_gSpeedMainControlQueue));
    if (TX_SUCCESS != err_gSpeedMainControlQueue)
    {
        tx_startup_err_callback (&gSpeedMainControlQueue, 0);
    }
    UINT err_gSetPointMainControlQueue;
    err_gSetPointMainControlQueue = tx_queue_create (&gSetPointMainControlQueue, (CHAR *) "SetPointMainControlQueue", 1,
                                                     &queue_memory_gSetPointMainControlQueue,
                                                     sizeof(queue_memory_gSetPointMainControlQueue));
    if (TX_SUCCESS != err_gSetPointMainControlQueue)
    {
        tx_startup_err_callback (&gSetPointMainControlQueue, 0);
    }

    UINT err;
    err = tx_thread_create (&mainControlThread, (CHAR *) "MainControlThread", mainControlThread_func, (ULONG) NULL,
                            &mainControlThread_stack, 1024, 1, 1, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&mainControlThread, 0);
    }
}

static void mainControlThread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    mainControlThread_entry ();
}
