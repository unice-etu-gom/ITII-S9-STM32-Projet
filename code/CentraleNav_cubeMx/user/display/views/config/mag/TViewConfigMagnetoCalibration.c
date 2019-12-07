/* Corresponding header inclusion */
#include "TViewConfigMagnetoCalibration.h"

/* System includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"
#include "stm32412g_discovery_ts.h"

/* Project includes */
#include "variables_globales.h"

#include "comm/serial.h"

#include "data/parameters.h"

#include "display/common/ui_button.h"
#include "display/common/ui_buttons.h"
#include "display/common/ui_text.h"
#include "display/common/ui_text_labels.h"
#include "display/display_management.h"

#include "../../TViewConfig.h"

/* ########################################################################## */
/* ########################################################################## */

#define C_TEXTBUFFER_SIZE   (12)

//static TsUiText     s_textParamValue;
static char         s_textParamValueBuffer[C_TEXTBUFFER_SIZE];

static TsUiButton   s_btnCalibrate;

/* ########################################################################## */
/* ########################################################################## */

void    viewMagnetoCalib_PeriodicUiUpdate(void);

/* ########################################################################## */
/* ########################################################################## */

void    viewMagnetoCalib_draw(void)
{
    /* Display view title */


    ui_text_draw(&g_textLabel_view_title);
    ui_text_draw(&g_textLabel_viewConfig_section);
//    ui_text_draw(&g_textLabel_viewConfig_param);
//    ui_text_draw(&s_textParamValue);



    /* Draw buttons */
//    ui_button_draw(&g_buttonArrowPrevious);
//    ui_button_draw(&g_buttonArrowNext);
    ui_button_draw(&g_buttonBack);

//    ui_button_draw(&g_buttonLess);
//    ui_button_draw(&g_buttonMore);


    /* Update display with current values */
    viewMagnetoCalib_PeriodicUiUpdate();
}

/* ########################################################################## */
/* ########################################################################## */

void    viewMagnetoCalib_Event_touchscreen(const TS_StateTypeDef* pTSState)
{
    /*if( ui_button_touchIsIn(&g_buttonArrowNext,pTSState) )
    {
        display_setView(&c_view_main);
    }
    else if( ui_button_touchIsIn(&g_buttonArrowPrevious, pTSState) )
    {
        display_setView(&c_view_magnetometer);
    }
    else */if( ui_button_touchIsIn(&g_buttonBack, pTSState) )
    {
        display_setView(&c_view_config);
    }


    else if( ui_button_touchIsIn(&s_btnCalibrate, pTSState) )
    {
        g_parameters.magnetometer_correction_deg
                -= g_magnetometerAngle;
        display_repaint();
    }


    else
    {
        /* Nothing to do */
//        BSP_LCD_DisplayStringAtLine(
//                6,
//                (uint8_t*)"No button." );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    viewMagnetoCalib_handlerOnEnter(void)
{
//    const uint16_t  c_controls_vpos = 105U;


    BSP_LCD_Clear(LCD_COLOR_BLACK);


    ui_button_setOrig(
                &g_buttonArrowPrevious,
                0,
                240 - g_buttonArrowPrevious.sizeY );

    ui_button_setOrig(
                &g_buttonBack,
                (BSP_LCD_GetXSize()/2) - (g_buttonBack.sizeX/2),
                BSP_LCD_GetYSize() - g_buttonBack.sizeY );

//    ui_button_setOrig(
//                &g_buttonArrowNext,
//                240 - g_buttonArrowNext.sizeX,
//                240 - g_buttonArrowNext.sizeY );


//    ui_button_setOrig(
//                &g_buttonLess,
//                0U,
//                c_controls_vpos );

//    ui_button_setOrig(
//                &g_buttonMore,
//                BSP_LCD_GetXSize() - g_buttonMore.sizeX,
//                c_controls_vpos );



    ui_button_init(&s_btnCalibrate);
    ui_button_setColorBackground(&s_btnCalibrate, LCD_COLOR_DARKGRAY);
    ui_button_setColorForeground(&s_btnCalibrate, LCD_COLOR_RED);
    ui_button_setOrig(&s_btnCalibrate, 30U, 90U);
    s_btnCalibrate.sizeX    = 180U;
    s_btnCalibrate.sizeY    = 60U;
    s_btnCalibrate.text = (uint8_t*)s_textParamValueBuffer;



    /* -------------------------------------------------------------------------
     *  Configure text structures
     */
    ui_text_set(&g_textLabel_view_title, "Magneto Conf.");

    ui_text_set(&g_textLabel_viewConfig_section, "Calibration");

//    ui_text_set(&g_textLabel_viewConfig_param, "Calibration");



//    ui_text_init(&s_textParamValue);
//    ui_text_set(&s_textParamValue, s_textParamValueBuffer);
//    s_textParamValue.Y          = c_controls_vpos
//                                + (30)
//                                - (s_textParamValue.font->Height/2);
//    s_textParamValue.colorBG    = LCD_COLOR_BLACK;
//    s_textParamValue.colorFG    = LCD_COLOR_WHITE;
}

/* ########################################################################## */
/* ########################################################################## */

void    viewMagnetoCalib_handlerOnExit(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

void    viewMagnetoCalib_PeriodicUiUpdate(void)
{

    snprintf(
            s_textParamValueBuffer,
            C_TEXTBUFFER_SIZE,
            "%05.1lf deg",
            g_magnetometerAngle );

    ui_button_draw(&s_btnCalibrate);
}

/* ########################################################################## */
/* ########################################################################## */

const TsDisplayView c_view_config_magnetoCalib
    = {
        .funcDrawView   = viewMagnetoCalib_draw,

        .funcHandlerOnEnter = viewMagnetoCalib_handlerOnEnter,
        .funcHandlerOnExit  = viewMagnetoCalib_handlerOnExit,

        .funcEvent_touchscreen  = viewMagnetoCalib_Event_touchscreen,

        .funcPeriodicUiUpdate   = viewMagnetoCalib_PeriodicUiUpdate,
    };

/* ########################################################################## */
/* ########################################################################## */
