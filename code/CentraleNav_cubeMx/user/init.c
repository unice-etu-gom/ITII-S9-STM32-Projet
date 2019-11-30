#include "init.h"

#include <stdio.h>

#include "stm32412g_discovery.h"
#include "stm32412g_discovery_lcd.h"

#include "display/display_management.h"
#include "display/views/TViewHello.h"
#include "display/views/TViewMain.h"

/* ########################################################################## */
/* ########################################################################## */

void    init_LED(void);
void    init_LCD(void);

/* ########################################################################## */
/* ########################################################################## */

void	init(void)
{
    /*
     *  Initialize modules
     */
    init_LED();
    init_LCD();

    printf("\n\nSTM32F412Discovery: Hello, World!\n");


    /*
     *  Wait a bit then end the init by entering in "normal operation" mode.
     */
    HAL_Delay(1000);

    printf("Alive");
    fflush(stdout);

    BSP_LED_Off(LED_GREEN);
    display_setView(&c_view_main);
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  This function initializes board's LED outputs.
 */
void    init_LED(void)
{
    BSP_LED_Init(LED_BLUE);
    BSP_LED_Init(LED_RED);
    BSP_LED_Init(LED_ORANGE);
    BSP_LED_Init(LED_GREEN);

    BSP_LED_On(LED_GREEN);
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  This function initializes the LCD display.
 */
void    init_LCD(void)
{
    BSP_LCD_InitEx(LCD_ORIENTATION_PORTRAIT);
    BSP_LCD_Clear(LCD_COLOR_BLACK);

    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_DisplayStringAtLine(4, (uint8_t*)"ITII-EII-P17");
    BSP_LCD_DisplayStringAtLine(5, (uint8_t*)"Hello, World!");

    display_setView(&c_view_hello);
}

/* ########################################################################## */
/* ########################################################################## */
