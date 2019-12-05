#ifndef UI_BUTTON_H
#define UI_BUTTON_H

/* Inherited classes */

/* System includes */
#include <stdint.h>

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"
#include "stm32412g_discovery_ts.h"

/* Project includes */
#include "../images/TsGimpImage.h"


/* ########################################################################## */
/* ########################################################################## */

typedef struct  _SUiButton
{
    uint16_t    origX;
    uint16_t    origY;
    uint16_t    sizeX;
    uint16_t    sizeY;

    uint16_t    colorBG;
    uint16_t    colorFG;

    const TsGimpImage*  imagePtr;

}   TsUiButton;

/* ########################################################################## */
/* ########################################################################## */

void    ui_button_init(
                TsUiButton* pButton );


void    ui_button_draw(
                TsUiButton* pButton );


void    ui_button_setOrig(
                TsUiButton* pButtonPtr,
                uint16_t    pOrigX,
                uint16_t    pOrigY );

void    ui_button_setColorBackground(
                TsUiButton* pButtonPtr,
                uint16_t    pColor );

void    ui_button_setColorForeground(
                TsUiButton* pButton,
                uint16_t    pColor );

void    ui_button_setImage(
                TsUiButton*     pButton,
                TsGimpImage*    pImagePtr );



uint8_t ui_button_touchIsIn(
                const TsUiButton*       pButton,
                const TS_StateTypeDef*  pTSStatePtr );

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< UI_BUTTON_H */
