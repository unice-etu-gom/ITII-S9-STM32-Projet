/* Corresponding header inclusion */
#include "TViewMain.h"

/* System includes */
#include <stdio.h>
#include <stdlib.h>

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"
#include "stm32412g_discovery_ts.h"

/* Project includes */


static int s_main_value	= 0;


/* ########################################################################## */
/* ########################################################################## */

void    viewMain_draw(void)
{
    BSP_LCD_DisplayStringAtLine(0, (uint8_t*)__FUNCTION__);

    char	lBuffer[10]= {0};
    itoa(s_main_value++, lBuffer, 10);

    BSP_LCD_DisplayStringAtLine(1, (uint8_t*)"Number of redraws:");
    BSP_LCD_DisplayStringAtLine(2, (uint8_t*)lBuffer);
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

    snprintf(   (char*)lBuffer,
                32,
                "X[1] = %04u",
                pTSState->touchX[1] );
    BSP_LCD_DisplayStringAtLine(6, lBuffer);

    snprintf(   (char*)lBuffer,
                32,
                "Y[1] = %04u",
                pTSState->touchY[1] );
    BSP_LCD_DisplayStringAtLine(7, lBuffer);




//    snprintf(   (char*)lBuffer,
//                32,
//                "gesture ID = %04u",
//                pTSState->gestureId );
//    BSP_LCD_DisplayStringAtLine(8, lBuffer);
}

/* ########################################################################## */
/* ########################################################################## */

void    viewMain_handlerOnEnter(void)
{
    BSP_LCD_Clear(LCD_COLOR_BLACK);
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

        .funcEvent_touchscreen  = viewMain_Event_touchscreen
    };

/* ########################################################################## */
/* ########################################################################## */
