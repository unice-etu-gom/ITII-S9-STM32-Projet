#ifndef UI_TEXT_H
#define UI_TEXT_H

/* Inherited classes */

/* System includes */
#include <stdint.h>

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"

/* Project includes */
#include "Utilities/Fonts/fonts.h"



/* ########################################################################## */
/* ########################################################################## */

typedef struct  _SUiText
{
    const uint8_t*      text;


    uint16_t    X;
    uint16_t    Y;
//    uint16_t    sizeX;
//    uint16_t    sizeY;

    Line_ModeTypdef lineMode;

    sFONT           *font;

    uint16_t        colorBG;
    uint16_t        colorFG;


}   TsUiText;

/* ########################################################################## */
/* ########################################################################## */

void    ui_text_init(TsUiText* pObj);

void    ui_text_set(TsUiText* pObj, const char* pText);

void    ui_text_draw(const TsUiText *pObj);

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< UI_TEXT_H */
