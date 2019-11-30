#ifndef TSDISPLAYVIEW_H
#define TSDISPLAYVIEW_H


/**
 *  @brief  This structure holds function pointers that manage a view on the
 *          LCD display.
 */
typedef struct _SDisplayView
{
    void    (*funcDrawView)(void);
    void    (*funcHandlerOnEnter)(void);
    void    (*funcHandlerOnExit)(void);

}   TsDisplayView;

#endif  /*< TSDISPLAYVIEW_H */
