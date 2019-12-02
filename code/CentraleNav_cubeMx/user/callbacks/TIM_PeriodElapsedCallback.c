#include "stm32412g_discovery.h"

#include "tim.h"
#include "../variables_globales.h"

/* ########################################################################## */
/* ########################################################################## */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *pTimerHandle)
{
    if( pTimerHandle == &htim13 )
    {
        g_flag_delayedActions_10ms  = 1;
    }
    else if( pTimerHandle == &htim12 )
    {
        g_flag_delayedActions_100ms = 1;
    }
    else if( pTimerHandle == &htim11 )
    {
        g_flag_delayedActions_1000ms    = 1;
    }
    else
    {
        /* Nothing to do */
    }
}

/* ########################################################################## */
/* ########################################################################## */
