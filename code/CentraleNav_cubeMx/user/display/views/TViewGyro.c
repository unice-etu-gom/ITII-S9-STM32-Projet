/* Corresponding header inclusion */
#include "TViewGyro.h"

/* System includes */
#include <stdio.h>
#include <stdlib.h>

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"
#include "stm32412g_discovery_ts.h"

/* Project includes */
#include "variables_globales.h"

#include "../display_management.h"

#include "../common/ui_button.h"
#include "../common/ui_buttons.h"
#include "../common/ui_text_labels.h"

#include "TViewConfig.h"
#include "TViewAccelero.h"

/* ########################################################################## */
/* ########################################################################## */

void    viewGyro_PeriodicUiUpdate(void);

/* ########################################################################## */
/* ########################################################################## */

void    viewGyro_draw(void)
{
    /* Display view title */
    ui_text_draw(&g_textLabel_view_title);


    /* Draw buttons */
    ui_button_draw(&g_buttonArrowNext);
    ui_button_draw(&g_buttonArrowPrevious);


    /* Update display with current values */
    viewGyro_PeriodicUiUpdate();
}

/* ########################################################################## */
/* ########################################################################## */

void    viewGyro_Event_touchscreen(const TS_StateTypeDef* pTSState)
{
    uint8_t lBuffer[32] = {0};

//    snprintf(   (char*)lBuffer,
//                32,
//                "X[0] = %04u",
//                pTSState->touchX[0] );
//    BSP_LCD_DisplayStringAtLine(4, lBuffer);

//    snprintf(   (char*)lBuffer,
//                32,
//                "Y[0] = %04u",
//                pTSState->touchY[0] );
//    BSP_LCD_DisplayStringAtLine(5, lBuffer);


    if( ui_button_touchIsIn(&g_buttonArrowNext,pTSState) )
    {
        display_setView(&c_view_config);
    }
    else if( ui_button_touchIsIn(&g_buttonArrowPrevious, pTSState) )
    {
        display_setView(&c_view_accelero);
    }
    else
    {
//        BSP_LCD_DisplayStringAtLine(
//                6,
//                (uint8_t*)"No button." );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    viewGyro_handlerOnEnter(void)
{
    BSP_LCD_Clear(LCD_COLOR_BLACK);

    ui_text_set(&g_textLabel_view_title,
                "Gyro");


    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);


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

void    viewGyro_handlerOnExit(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

void    viewGyro_PeriodicUiUpdate(void)
{
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);


    char    lBuffer[10] = {0};

    /*
     *  X Axis
     */
    itoa(g_gyroValues.X, lBuffer, 10);

    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAtLine(3, (uint8_t*)"X axis_________________________");

    BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);
    BSP_LCD_DisplayStringAt(
                0,
                LINE(3),
                (uint8_t*)lBuffer,
                RIGHT_MODE );


    /*
     *  Y Axis
     */
    itoa(g_gyroValues.Y, lBuffer, 10);

    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAtLine(5, (uint8_t*)"Y axis_________________________");

    BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);
    BSP_LCD_DisplayStringAt(
                0,
                LINE(5),
                (uint8_t*)lBuffer,
                RIGHT_MODE );


    /*
     *  Z Axis
     */
    itoa(g_gyroValues.Z, lBuffer, 10);

    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAtLine(7, (uint8_t*)"Z axis_________________________");

    BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);
    BSP_LCD_DisplayStringAt(
                0,
                LINE(7),
                (uint8_t*)lBuffer,
                RIGHT_MODE );
}

/* ########################################################################## */
/* ########################################################################## */

const TsDisplayView c_view_gyro
    = {
        .funcDrawView   = viewGyro_draw,

        .funcHandlerOnEnter = viewGyro_handlerOnEnter,
        .funcHandlerOnExit  = viewGyro_handlerOnExit,

        .funcEvent_touchscreen  = viewGyro_Event_touchscreen,

        .funcPeriodicUiUpdate   = viewGyro_PeriodicUiUpdate,
    };

/* ########################################################################## */
/* ########################################################################## */
