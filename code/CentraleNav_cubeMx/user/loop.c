#include "loop.h"

#include <stdio.h>

#include "stm32412g_discovery.h"
#include "stm32f4xx_hal.h"

#include "display/display_management.h"

#include "variables_globales.h"

/* ########################################################################## */
/* ########################################################################## */

void	actions_period100ms(void)
{
    BSP_LED_Toggle(LED_ORANGE);
    display_touchscreen_poll();
}

/* ########################################################################## */
/* ########################################################################## */

void	actions_period1000ms(void)
{
#if 0
    display_repaint();
#endif
    printf(".");
    fflush(stdout);
    BSP_LED_Toggle(LED_GREEN);

    display_periodicUiUpdate();
}

/* ########################################################################## */
/* ########################################################################## */

void    loop(void)
{

    if( g_flag_delayedActions_10ms )
    {
        g_flag_delayedActions_10ms  = 0;


        /* Note : The 10ms time base must not be done here due to performance
         * reasons ! (see the blue led variation!) */
        BSP_LED_Toggle(LED_BLUE);


        if(g_flag_delayedActions_10ms)
        {
            /* An over-run is detected */
            BSP_LED_Toggle(LED_RED);
        }
    }


    if( g_flag_delayedActions_100ms )
    {
        g_flag_delayedActions_100ms = 0;


        actions_period100ms();


        if(g_flag_delayedActions_100ms)
        {
            /* An over-run is detected */
            BSP_LED_Toggle(LED_RED);
        }
    }


    if( g_flag_delayedActions_1000ms )
    {
        g_flag_delayedActions_1000ms    = 0;


        actions_period1000ms();


        if(g_flag_delayedActions_1000ms)
        {
            /* An over-run is detected */
            BSP_LED_Toggle(LED_RED);
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */
