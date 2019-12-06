/* Corresponding header inclusion */
#include "ui_buttons.h"

/* System includes */

/* Libraries includes */

/* Project includes */
#include "../images/ImageArrowNext.h"
#include "../images/ImageArrowPrevious.h"
#include "../images/ImageBack.h"
#include "../images/ImageLess.h"
#include "../images/ImageMore.h"


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


TsUiButton   g_buttonBack   =
{
    .origX  = 0U,
    .origY  = 0U,

    .sizeX  = 60U,
    .sizeY  = 60U,

    .colorBG    = LCD_COLOR_DARKGRAY,
    .colorFG    = LCD_COLOR_RED,

    .imagePtr   = &ImageBack
};


TsUiButton   g_buttonLess   =
{
    .origX  = 0U,
    .origY  = 90U,

    .sizeX  = 60U,
    .sizeY  = 60U,

    .colorBG    = LCD_COLOR_BLACK,
    .colorFG    = LCD_COLOR_BLACK,

    .imagePtr   = &ImageLess
};


TsUiButton   g_buttonMore   =
{
    .origX  = 180U,
    .origY  = 90U,

    .sizeX  = 60U,
    .sizeY  = 60U,

    .colorBG    = LCD_COLOR_BLACK,
    .colorFG    = LCD_COLOR_BLACK,

    .imagePtr   = &ImageMore
};

/* ########################################################################## */
/* ########################################################################## */
