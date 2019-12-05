/* Corresponding header inclusion */
#include "ui_button.h"

/* System includes */
#include <assert.h>

/* Libraries includes */

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

void    ui_button_draw(
                TsUiButton* pButton )
{
    /* Draw the background */
    BSP_LCD_SetTextColor(pButton->colorBG);
    BSP_LCD_FillRect(
                pButton->origX,
                pButton->origY,
                pButton->sizeX,
                pButton->sizeY );


    /* Draw the image */
    if( pButton->imagePtr != 0 )
    {
        BSP_LCD_DrawRGBImage(
                    pButton->origX,
                    pButton->origY,
                    pButton->imagePtr->width,
                    pButton->imagePtr->height,
                    pButton->imagePtr->pixel_data );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    ui_button_init(TsUiButton *pButtonPtr)
{
    assert(     pButtonPtr != 0
            &&  "pButton must be a valid struct!" );


    pButtonPtr->colorBG = LCD_COLOR_GRAY;
    pButtonPtr->colorFG = LCD_COLOR_BLACK;

    pButtonPtr->origX   = 0U;
    pButtonPtr->origY   = 0U;

    pButtonPtr->sizeX   = 60U;
    pButtonPtr->sizeY   = 60U;

    pButtonPtr->imagePtr    = 0U;
}

/* ########################################################################## */
/* ########################################################################## */

void    ui_button_setColorBackground(
                TsUiButton* pButtonPtr,
                uint16_t    pColor )
{
    pButtonPtr->colorBG    = pColor;
}

/* ########################################################################## */
/* ########################################################################## */

void    ui_button_setColorForeground(
                TsUiButton* pButton,
                uint16_t    pColor )
{
    pButton->colorFG    = pColor;
}

/* ########################################################################## */
/* ########################################################################## */

void    ui_button_setImage(
                TsUiButton*     pButton,
                TsGimpImage*    pImagePtr )
{
    pButton->imagePtr   = pImagePtr;
}

/* ########################################################################## */
/* ########################################################################## */

void    ui_button_setOrig(TsUiButton *pButtonPtr,
                uint16_t    pOrigX,
                uint16_t    pOrigY )
{
    pButtonPtr->origX  = pOrigX;
    pButtonPtr->origY  = pOrigY;
}

/* ########################################################################## */
/* ########################################################################## */

uint8_t ui_button_touchIsIn(
                const TsUiButton*       pButton,
                const TS_StateTypeDef*  pTSStatePtr )
{
    uint8_t retval  = 0;


    if( pTSStatePtr->touchDetected == 0 )
    {
        retval  = 0;
    }
    else if(    pTSStatePtr->touchX[0] < pButton->origX
            ||  pTSStatePtr->touchX[0] > pButton->origX + pButton->sizeX )
    {
        retval  = 0;
    }
    else if(    pTSStatePtr->touchY[0] < pButton->origY
            ||  pTSStatePtr->touchY[0] > pButton->origY + pButton->sizeY )
    {
        retval  = 0;
    }
    else
    {
        retval  = 1;
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */
