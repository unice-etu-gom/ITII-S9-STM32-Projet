/* Corresponding header inclusion */
#include "ui_text.h"

/* System includes */

/* Libraries includes */
#include "stm32412g_discovery_lcd.h"

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

void    ui_text_draw(
                const TsUiText  *pObj )
{
    BSP_LCD_SetBackColor(pObj->colorBG);
    BSP_LCD_SetTextColor(pObj->colorFG);

    BSP_LCD_SetFont(pObj->font);

    BSP_LCD_DisplayStringAt(
                pObj->X,
                pObj->Y,
                pObj->text,
                pObj->lineMode );
}

/* ########################################################################## */
/* ########################################################################## */

void    ui_text_init(TsUiText *pObj)
{
    pObj->colorBG   = LCD_COLOR_GRAY;
    pObj->colorFG   = LCD_COLOR_BLACK;

    pObj->font      = &Font24;

    pObj->lineMode  = CENTER_MODE;

    pObj->text      = "";

    pObj->X         = 0U;
    pObj->Y         = 0U;
}

/* ########################################################################## */
/* ########################################################################## */

void    ui_text_set(
                TsUiText    *pObj,
                const char  *pText )
{
    pObj->text  = (uint8_t*)pText;
}

/* ########################################################################## */
/* ########################################################################## */
