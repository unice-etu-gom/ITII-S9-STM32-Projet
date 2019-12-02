/* Corresponding header inclusion */
#include "ui_buttons.h"

/* System includes */

/* Libraries includes */

/* Project includes */
#include "../images/ImageArrowNext.h"
#include "../images/ImageArrowPrevious.h"


/* ########################################################################## */
/* ########################################################################## */

TsUiButton   g_buttonArrowNext  =
{
    .origX  = 0U,
    .origY  = 0U,

    .sizeX  = 60U,
    .sizeY  = 60U,

    .colorBG    = LCD_COLOR_DARKGRAY,
    .colorFG    = LCD_COLOR_RED,

    .imagePtr   = &ImageArrowNext
};


TsUiButton   g_buttonArrowPrevious  =
{
    .origX  = 0U,
    .origY  = 0U,

    .sizeX  = 60U,
    .sizeY  = 60U,

    .colorBG    = LCD_COLOR_DARKGRAY,
    .colorFG    = LCD_COLOR_RED,

    .imagePtr   = &ImageArrowPrevious
};

/* ########################################################################## */
/* ########################################################################## */
