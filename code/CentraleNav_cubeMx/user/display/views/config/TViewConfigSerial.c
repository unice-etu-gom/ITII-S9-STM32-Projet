/* Corresponding header inclusion */
#include "TViewConfigSerial.h"

/* System includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"
#include "stm32412g_discovery_ts.h"

/* Project includes */
#include "comm/serial.h"

#include "display/common/ui_button.h"
#include "display/common/ui_buttons.h"
#include "display/common/ui_text.h"
#include "display/common/ui_text_labels.h"
#include "display/display_management.h"

#include "../TViewConfig.h"
#include "../TViewMagnetometer.h"
#include "../TViewMain.h"

/* ########################################################################## */
/* ########################################################################## */

#define C_TEXTBUFFER_SIZE   (8)

static TsUiText     s_textParamValue;
static char         s_textParamValueBuffer[C_TEXTBUFFER_SIZE];

/* ########################################################################## */
/* ########################################################################## */

void    viewConfigSerial_PeriodicUiUpdate(void);

/* ########################################################################## */
/* ########################################################################## */

void    viewConfigSerial_draw(void)
{
    /* Display view title */

    snprintf(
            s_textParamValueBuffer,
            C_TEXTBUFFER_SIZE,
            "%.1f s",
            g_serial_txPeriod_MAG_100ms / 10.0 );


    ui_text_draw(&g_textLabel_view_title);
    ui_text_draw(&g_textLabel_viewConfig_section);
    ui_text_draw(&g_textLabel_viewConfig_param);
    ui_text_draw(&s_textParamValue);



    /* Draw buttons */
    ui_button_draw(&g_buttonArrowPrevious);
    ui_button_draw(&g_buttonArrowNext);
    ui_button_draw(&g_buttonBack);

    ui_button_draw(&g_buttonLess);
    ui_button_draw(&g_buttonMore);


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
    else if( ui_button_touchIsIn(&g_buttonBack, pTSState) )
    {
        display_setView(&c_view_config);
    }


    else if( ui_button_touchIsIn(&g_buttonLess, pTSState) )
    {
        serial_emitPeriod_MAG_dec();
        display_repaint();
    }
    else if( ui_button_touchIsIn(&g_buttonMore, pTSState) )
    {
        serial_emitPeriod_MAG_inc();
        display_repaint();
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

void    viewConfigSerial_handlerOnEnter(void)
{
    const uint16_t  c_controls_vpos = 105U;


    BSP_LCD_Clear(LCD_COLOR_BLACK);


    ui_button_setOrig(
                &g_buttonArrowPrevious,
                0,
                240 - g_buttonArrowPrevious.sizeY );

    ui_button_setOrig(
                &g_buttonBack,
                (BSP_LCD_GetXSize()/2) - (g_buttonBack.sizeX/2),
                BSP_LCD_GetYSize() - g_buttonBack.sizeY );

    ui_button_setOrig(
                &g_buttonArrowNext,
                240 - g_buttonArrowNext.sizeX,
                240 - g_buttonArrowNext.sizeY );


    ui_button_setOrig(
                &g_buttonLess,
                0U,
                c_controls_vpos );

    ui_button_setOrig(
                &g_buttonMore,
                BSP_LCD_GetXSize() - g_buttonMore.sizeX,
                c_controls_vpos );



    /* -------------------------------------------------------------------------
     *  Configure text structures
     */
    ui_text_set(&g_textLabel_view_title, "Serial Config");

    ui_text_set(&g_textLabel_viewConfig_param, "MAG frame");

    ui_text_set(&g_textLabel_viewConfig_section, "Emit. period");



    ui_text_init(&s_textParamValue);
    ui_text_set(&s_textParamValue, s_textParamValueBuffer);
    s_textParamValue.Y          = c_controls_vpos
                                + (30)
                                - (s_textParamValue.font->Height/2);
    s_textParamValue.colorBG    = LCD_COLOR_BLACK;
    s_textParamValue.colorFG    = LCD_COLOR_WHITE;
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
