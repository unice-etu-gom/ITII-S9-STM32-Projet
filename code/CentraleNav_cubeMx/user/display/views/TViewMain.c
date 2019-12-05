/* Corresponding header inclusion */
#include "TViewMain.h"

/* System includes */
#include <stdio.h>
#include <stdlib.h>

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"
#include "stm32412g_discovery_ts.h"

/* Project includes */
#include "../display_management.h"

#include "../common/ui_button.h"
#include "../common/ui_buttons.h"

#include "TViewMagnetometer.h"


static int s_main_value	= 0;


/* ########################################################################## */
/* ########################################################################## */

void    viewMain_draw(void)
{
    BSP_LCD_DisplayStringAtLine(0, (uint8_t*)__FUNCTION__);

    char	lBuffer[10]= {0};
    itoa(s_main_value++, lBuffer, 10);

    BSP_LCD_DisplayStringAtLine(1, (uint8_t*)"Nbr of redraws:");
    BSP_LCD_DisplayStringAtLine(2, (uint8_t*)lBuffer);


    ui_button_draw(&g_buttonArrowNext);
    ui_button_draw(&g_buttonArrowPrevious);
}

/* ########################################################################## */
/* ########################################################################## */

void    viewMain_Event_touchscreen(const TS_StateTypeDef* pTSState)
{
    uint8_t lBuffer[32] = {0};

    snprintf(   (char*)lBuffer,
                32,
                "X[0] = %04u",
                pTSState->touchX[0] );
    BSP_LCD_DisplayStringAtLine(4, lBuffer);

    snprintf(   (char*)lBuffer,
                32,
                "Y[0] = %04u",
                pTSState->touchY[0] );
    BSP_LCD_DisplayStringAtLine(5, lBuffer);


    if( ui_button_touchIsIn(&g_buttonArrowNext,pTSState) )
    {
        display_setView(&c_view_magnetometer);
    }
    else if( ui_button_touchIsIn(&g_buttonArrowPrevious, pTSState) )
    {
        display_setView(&c_view_magnetometer);
    }
    else
    {
        BSP_LCD_DisplayStringAtLine(
                6,
                (uint8_t*)"No button." );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    viewMain_handlerOnEnter(void)
{
    BSP_LCD_Clear(LCD_COLOR_BLACK);
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

void    viewMain_handlerOnExit(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

const TsDisplayView c_view_main
    = {
        .funcDrawView   = viewMain_draw,

        .funcHandlerOnEnter = viewMain_handlerOnEnter,
        .funcHandlerOnExit  = viewMain_handlerOnExit,

        .funcEvent_touchscreen  = viewMain_Event_touchscreen,

        .funcPeriodicUiUpdate   = 0U
    };

/* ########################################################################## */
/* ########################################################################## */
