/* Corresponding header inclusion */
#include "TViewMain.h"

/* System includes */
#include <stdlib.h>

/* Libraries includes */

/* Project includes */
#include "stm32412g_discovery_lcd.h"


static int s_main_value	= 0;


/* ########################################################################## */
/* ########################################################################## */

void    viewMain_draw(void)
{
    BSP_LCD_DisplayStringAtLine(2, (uint8_t*)__FUNCTION__);

    char	lBuffer[10]= {0};
    itoa(s_main_value++, lBuffer, 10);

    BSP_LCD_DisplayStringAtLine(4, (uint8_t*)"Number of updates:");
    BSP_LCD_DisplayStringAtLine(5, (uint8_t*)lBuffer);
}

/* ########################################################################## */
/* ########################################################################## */

void    viewMain_handlerOnEnter(void)
{
    BSP_LCD_Clear(LCD_COLOR_BLACK);
}

/* ########################################################################## */
/* ########################################################################## */

void    viewMain_handlerOnExit(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

const TsDisplayView c_view_main
    = {
        .funcDrawView   = viewMain_draw,

        .funcHandlerOnEnter = viewMain_handlerOnEnter,
        .funcHandlerOnExit  = viewMain_handlerOnExit
    };

/* ########################################################################## */
/* ########################################################################## */
