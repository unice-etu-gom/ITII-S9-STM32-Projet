/*
 * display_management.c
 *
 *  Created on: 30 nov. 2019
 *      Author: gom
 */
#include "display_management.h"

#include <assert.h>

#include "stm32412g_discovery_ts.h"


/* ########################################################################## */
/* ########################################################################## */

static const TsDisplayView*	s_currentViewPtr    = 0;

/* ########################################################################## */
/* ########################################################################## */

void    display_periodicUiUpdate(void)
{
    if(     s_currentViewPtr != 0
        &&  s_currentViewPtr->funcPeriodicUiUpdate != 0 )
    {
        (s_currentViewPtr->funcPeriodicUiUpdate)();
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    display_repaint(void)
{
    if(     s_currentViewPtr != 0
        &&  s_currentViewPtr->funcDrawView != 0 )
    {
        (s_currentViewPtr->funcDrawView)();
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    display_setView(const TsDisplayView *pViewPtr)
{
    assert(     pViewPtr != 0
            &&  "pViewPtr must not be null!");
    assert(     pViewPtr->funcDrawView != 0
            &&  "pViewPtr must contain a draw function!");
    assert(     pViewPtr->funcHandlerOnEnter != 0
            &&  "pViewPtr must contain an OnEnter handler!");
    assert(     pViewPtr->funcHandlerOnExit != 0
            &&  "pViewPtr must contain an OnExit handler!");


    if(     s_currentViewPtr != 0
        &&  s_currentViewPtr->funcHandlerOnExit != 0    )
    {
        (s_currentViewPtr->funcHandlerOnExit)();
    }

    s_currentViewPtr    = pViewPtr;

    if( s_currentViewPtr->funcHandlerOnEnter != 0 )
    {
        (s_currentViewPtr->funcHandlerOnEnter)();
    }

    display_repaint();
}

/* ########################################################################## */
/* ########################################################################## */

void    display_touchscreen_poll(void)
{
    static uint8_t  s_touchDetectedPrevious = 0U;

    TS_StateTypeDef	lTS_State;
    BSP_TS_GetState(&lTS_State);


    if(     s_touchDetectedPrevious == 0
        &&  lTS_State.touchDetected != 0 )
    {
        if(     s_currentViewPtr != 0
            &&  s_currentViewPtr->funcEvent_touchscreen   != 0    )
        {
            (s_currentViewPtr->funcEvent_touchscreen)(
                        ((const TS_StateTypeDef*)&lTS_State) );
        }
    }

    s_touchDetectedPrevious = lTS_State.touchDetected;
}

/* ########################################################################## */
/* ########################################################################## */
