#include "stm32412g_discovery.h"

#include "tim.h"
#include "../variables_globales.h"

#include "drivers/LSM6DSL/lsm6dsl.h"
#include "drivers/LSM303AGR/lsm303agr.h"

/* ########################################################################## */
/* ########################################################################## */

uint8_t actions_RT_10ms(void)
{
    uint8_t lRet    = 0U;

    uint8_t retval  = 0U;

    lRet    = LSM303AGR_MagReadXYZ( &g_magnetometerValues );
    if(lRet != HAL_OK)
    {
        retval++;
    }

    lRet    = LSM6DSL_XlRead_XYZ( &g_acceleroValues );
    if(lRet != HAL_OK)
    {
        retval++;
    }

    lRet    = LSM6DSL_Gyro_Read_XYZ( &g_gyroValues );
    if(lRet != HAL_OK)
    {
        retval++;
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *pTimerHandle)
{
    if( pTimerHandle == &htim13 )
    {
        g_flag_delayedActions_10ms  = 1;

        actions_RT_10ms();
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
