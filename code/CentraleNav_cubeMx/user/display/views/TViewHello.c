/* Corresponding header inclusion */
#include "TViewHello.h"

/* System includes */

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"

/* Project includes */
#include "../images/ImageEcranAccueil.h"


/* ########################################################################## */
/* ########################################################################## */

void    viewHello_draw(void)
{
    BSP_LCD_DrawRGBImage(
                0,
                0,
                ImageEcranAccueil.width,
                ImageEcranAccueil.height,
                ImageEcranAccueil.pixel_data );
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
