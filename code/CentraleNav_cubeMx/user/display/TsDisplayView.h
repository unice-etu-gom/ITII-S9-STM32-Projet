#ifndef TSDISPLAYVIEW_H
#define TSDISPLAYVIEW_H

#include "stm32412g_discovery_ts.h"


/**
 *  @brief  This structure holds function pointers that manage a view on the
 *          LCD display.
 */
typedef struct _SDisplayView
{
    void    (*funcDrawView)(void);
    void    (*funcHandlerOnEnter)(void);
    void    (*funcHandlerOnExit)(void);

    /*
     *  I/O Event handlers
     */
    void    (*funcEvent_touchscreen)(const TS_StateTypeDef* pTSState);

}   TsDisplayView;

#endif  /*< TSDISPLAYVIEW_H */
