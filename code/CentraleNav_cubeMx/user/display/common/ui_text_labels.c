/* Corresponding header inclusion */
#include "ui_text_labels.h"

/* System includes */

/* Libraries includes */

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

TsUiText g_textLabel_view_title  =
{
    .text   = (uint8_t*)"",

    .X  = 0U,
    .Y  = 0U,

    .lineMode   = CENTER_MODE,

    .font       = &Font24,

    .colorBG    = LCD_COLOR_WHITE,
    .colorFG    = LCD_COLOR_BLACK
};

TsUiText g_textLabel_viewConfig_param   =
{
    .text   = (uint8_t*)"",

    .X  = 0U,
    .Y  = 60U,

    .lineMode   = CENTER_MODE,

    .font       = &Font24,

    .colorBG    = LCD_COLOR_BLACK,
    .colorFG    = LCD_COLOR_RED
};

TsUiText g_textLabel_viewConfig_section =
{
    .text   = (uint8_t*)"",

    .X  = 0U,
    .Y  = 30U,

    .lineMode   = CENTER_MODE,

    .font       = &Font24,

    .colorBG    = LCD_COLOR_BLACK,
    .colorFG    = LCD_COLOR_ORANGE
};

/* ########################################################################## */
/* ########################################################################## */
