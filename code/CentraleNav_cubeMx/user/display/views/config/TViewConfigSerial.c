/* Corresponding header inclusion */
#include "TViewConfigSerial.h"

/* System includes */
#include <stdio.h>
#include <stdlib.h>

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"
#include "stm32412g_discovery_ts.h"

/* Project includes */
#include "comm/serial.h"

#include "display/common/ui_button.h"
#include "display/common/ui_buttons.h"
#include "display/display_management.h"

#include "../TViewMagnetometer.h"
#include "../TViewMain.h"

/* ########################################################################## */
/* ########################################################################## */

static TsUiButton   s_textPeriodMAG;
static TsUiButton   s_title;

/* ########################################################################## */
/* ########################################################################## */

void    viewConfigSerial_PeriodicUiUpdate(void);

/* ########################################################################## */
/* ########################################################################## */

void    viewConfigSerial_draw(void)
{
    /* Display view title */
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_SetBackColor(LCD_COLOR_ORANGE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_DisplayStringAt(
                0,
                LINE(0),
                (uint8_t*)"Serial Config",
                CENTER_MODE );


    /* Draw buttons */
    ui_button_draw(&g_buttonArrowPrevious);
    ui_button_draw(&g_buttonArrowNext);

    ui_button_draw(&s_title);
    ui_button_draw(&s_textPeriodMAG);


    /* Update display with current values */
    viewConfigSerial_PeriodicUiUpdate();
}

/* ########################################################################## */
/* ########################################################################## */

void    viewConfigSerial_Event_touchscreen(const TS_StateTypeDef* pTSState)
{
    if( ui_button_touchIsIn(&g_buttonArrowNext,pTSState) )
    {
        display_setView(&c_view_main);
    }
    else if( ui_button_touchIsIn(&g_buttonArrowPrevious, pTSState) )
    {
        display_setView(&c_view_magnetometer);
    }


//    else if( ui_button_touchIsIn(&s_buttonConfigSerial, pTSState) )
//    {
//        display_setView(&c_view_configSerial);
//    }


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

void    viewConfigSerial_handlerOnEnter(void)
{
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);


    ui_button_init(&s_title);
    ui_button_setColorBackground(
                &s_title,
                LCD_COLOR_BLACK );
    ui_button_setColorForeground(
                &s_title,
                LCD_COLOR_ORANGE );
    ui_button_setOrig(
                &s_title,
                60U,
                45U );
    s_title.sizeX   = 120U;
    s_title.sizeY   = 60U;
    s_title.text    = "MAG Frame emit";


    ui_button_init(&s_textPeriodMAG);
    ui_button_setColorBackground(
                &s_textPeriodMAG,
                LCD_COLOR_BLACK );
    ui_button_setColorForeground(
                &s_textPeriodMAG,
                LCD_COLOR_WHITE );
    ui_button_setOrig(
                &s_textPeriodMAG,
                60U,
                105U );
    s_textPeriodMAG.sizeX   = 120U;
    s_textPeriodMAG.sizeY   = 60U;
    s_textPeriodMAG.text    = "DD.D s";


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

void    viewConfigSerial_handlerOnExit(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

void    viewConfigSerial_PeriodicUiUpdate(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

const TsDisplayView c_view_configSerial
    = {
        .funcDrawView   = viewConfigSerial_draw,

        .funcHandlerOnEnter = viewConfigSerial_handlerOnEnter,
        .funcHandlerOnExit  = viewConfigSerial_handlerOnExit,

        .funcEvent_touchscreen  = viewConfigSerial_Event_touchscreen,

        .funcPeriodicUiUpdate   = viewConfigSerial_PeriodicUiUpdate,
    };

/* ########################################################################## */
/* ########################################################################## */
