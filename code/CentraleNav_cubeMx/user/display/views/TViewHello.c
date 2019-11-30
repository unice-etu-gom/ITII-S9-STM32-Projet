/* Corresponding header inclusion */
#include "TViewHello.h"

/* System includes */

/* Libraries includes */

/* Project includes */
#include "stm32412g_discovery_lcd.h"


/* ########################################################################## */
/* ########################################################################## */

void    viewHello_draw(void)
{
    BSP_LCD_Clear(LCD_COLOR_LIGHTBLUE);
    BSP_LCD_DisplayStringAtLine(1, (uint8_t*)__FUNCTION__);
}

/* ########################################################################## */
/* ########################################################################## */

void    viewHello_handlerOnEnter(void)
{
    BSP_LCD_SetBackColor(LCD_COLOR_LIGHTBLUE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
}

/* ########################################################################## */
/* ########################################################################## */

void    viewHello_handlerOnExit(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

const TsDisplayView c_view_hello
    = {
        .funcDrawView   = viewHello_draw,

        .funcHandlerOnEnter = viewHello_handlerOnEnter,
        .funcHandlerOnExit  = viewHello_handlerOnExit
    };

/* ########################################################################## */
/* ########################################################################## */
