/* Corresponding header inclusion */
#include "TViewConfig.h"

/* System includes */
#include <stdio.h>
#include <stdlib.h>

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"
#include "stm32412g_discovery_ts.h"

/* Project includes */
#include "../../variables_globales.h"

#include "../display_management.h"

#include "../common/ui_button.h"
#include "../common/ui_buttons.h"

#include "TViewMagnetometer.h"
#include "TViewMain.h"
#include "config/TViewConfigSerial.h"

/* ########################################################################## */
/* ########################################################################## */

static TsUiButton   s_buttonConfigSerial;

/* ########################################################################## */
/* ########################################################################## */

void    viewConfig_PeriodicUiUpdate(void);

/* ########################################################################## */
/* ########################################################################## */

void    viewConfig_draw(void)
{
    /* Display view title */
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_DisplayStringAt(
                0,
                LINE(0),
                (uint8_t*)"Config",
                CENTER_MODE );


    /* Draw buttons */
    ui_button_draw(&g_buttonArrowPrevious);
    ui_button_draw(&g_buttonArrowNext);
    ui_button_draw(&s_buttonConfigSerial);


    /* Update display with current values */
    viewConfig_PeriodicUiUpdate();
}

/* ########################################################################## */
/* ########################################################################## */

void    viewConfig_Event_touchscreen(const TS_StateTypeDef* pTSState)
{
    if( ui_button_touchIsIn(&g_buttonArrowNext,pTSState) )
    {
        display_setView(&c_view_main);
    }
    else if( ui_button_touchIsIn(&g_buttonArrowPrevious, pTSState) )
    {
        display_setView(&c_view_magnetometer);
    }


    else if( ui_button_touchIsIn(&s_buttonConfigSerial, pTSState) )
    {
        display_setView(&c_view_configSerial);
    }


    else
    {
        /* Nothing to do */
        BSP_LCD_DisplayStringAtLine(
                6,
                (uint8_t*)"No button." );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    viewConfig_handlerOnEnter(void)
{
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);


    ui_button_init(&s_buttonConfigSerial);
    ui_button_setColorBackground(
                &s_buttonConfigSerial,
                LCD_COLOR_ORANGE );
    ui_button_setColorForeground(
                &s_buttonConfigSerial,
                LCD_COLOR_BLACK );
    ui_button_setOrig(
                &s_buttonConfigSerial,
                0U,
                45U );
    s_buttonConfigSerial.sizeX  = 120U;
    s_buttonConfigSerial.text   = (uint8_t*)"Serial";


    ui_button_setOrig(
                &g_buttonArrowPrevious,
                0,
                240 - g_buttonArrowPrevious.sizeY );

    ui_button_setOrig(
                &g_buttonArrowNext,
                240 - g_buttonArrowNext.sizeX,
                240 - g_buttonArrowNext.sizeY );
}

/* ########################################################################## */
/* ########################################################################## */

void    viewConfig_handlerOnExit(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

void    viewConfig_PeriodicUiUpdate(void)
{
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
}

/* ########################################################################## */
/* ########################################################################## */

const TsDisplayView c_view_config
    = {
        .funcDrawView   = viewConfig_draw,

        .funcHandlerOnEnter = viewConfig_handlerOnEnter,
        .funcHandlerOnExit  = viewConfig_handlerOnExit,

        .funcEvent_touchscreen  = viewConfig_Event_touchscreen,

        .funcPeriodicUiUpdate   = viewConfig_PeriodicUiUpdate,
    };

/* ########################################################################## */
/* ########################################################################## */
