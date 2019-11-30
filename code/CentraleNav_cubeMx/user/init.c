#include "init.h"

#include <stdio.h>

#include "stm32412g_discovery.h"
#include "stm32412g_discovery_lcd.h"

/* ########################################################################## */
/* ########################################################################## */

void    init_LED(void);
void    init_LCD(void);

/* ########################################################################## */
/* ########################################################################## */

void	init(void)
{
    init_LED();
    init_LCD();

    printf("\n\nSTM32F412Discovery: Hello, World!\n");
    printf("Alive");
    fflush(stdout);
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
}

/* ########################################################################## */
/* ########################################################################## */
