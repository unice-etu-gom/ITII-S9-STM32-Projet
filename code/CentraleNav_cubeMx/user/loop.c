#include "loop.h"

#include <stdio.h>

#include "stm32412g_discovery.h"
#include "stm32f4xx_hal.h"

#include "display/display_management.h"

/* ########################################################################## */
/* ########################################################################## */

void    loop(void)
{
    printf(".");
    fflush(stdout);
    BSP_LED_Toggle(LED_GREEN);

    HAL_Delay(1000);
    display_repaint();
}

/* ########################################################################## */
/* ########################################################################## */
