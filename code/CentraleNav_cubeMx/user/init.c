#include "init.h"

#include <stdio.h>

#include "stm32412g_discovery.h"
#include "stm32412g_discovery_lcd.h"

#include "tim.h"

#include "comm/serial.h"
#include "display/display_management.h"
#include "display/views/TViewHello.h"
#include "display/views/TViewMain.h"

/* ########################################################################## */
/* ########################################################################## */

/* @see https://fr.wikipedia.org/wiki/Code_Morse_international § Représentation
 *      et cadence. */
#define MORSE_DELAY_ELT     (250)

#define MORSE_DELAY_SHORT   (MORSE_DELAY_ELT)
#define MORSE_DELAY_LONG    (3*MORSE_DELAY_ELT)

#define MORSE_DELAY_SEPSYM  (MORSE_DELAY_ELT)
#define MORSE_DELAY_SEPLTR  (MORSE_DELAY_LONG)
#define MORSE_DELAY_SEPWRD  (7*MORSE_DELAY_SHORT)


void    init_LED(void);
void    init_LCD(void);

void    start(void);

/* ########################################################################## */
/* ########################################################################## */

void    init(void)
{
    /*
     *  Initialize modules
     */
    init_LED();
    init_LCD();

    serial_init();


    /*
     *  Wait a bit then end the init by entering in "normal operation" mode.
     */
    HAL_Delay(1000);

    start();
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

    BSP_LED_On(LED_BLUE);
    BSP_LED_On(LED_GREEN);
    BSP_LED_On(LED_ORANGE);
    BSP_LED_On(LED_RED);
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


    /* touch screen */
    uint8_t retTS
            = BSP_TS_InitEx(
                    BSP_LCD_GetXSize(),
                    BSP_LCD_GetYSize(),
                    LCD_ORIENTATION_PORTRAIT );

    if( retTS != TS_OK )
    {
        while(1)
        {
            /* T */
            BSP_LED_On(LED_RED);
            HAL_Delay(MORSE_DELAY_LONG);
            BSP_LED_Off(LED_RED);

            HAL_Delay(MORSE_DELAY_SEPLTR);

            /* S */
            BSP_LED_On(LED_RED);
            HAL_Delay(MORSE_DELAY_SHORT);
            BSP_LED_Off(LED_RED);
            HAL_Delay(MORSE_DELAY_SEPSYM);
            BSP_LED_On(LED_RED);
            HAL_Delay(MORSE_DELAY_SHORT);
            BSP_LED_Off(LED_RED);
            HAL_Delay(MORSE_DELAY_SEPSYM);
            BSP_LED_On(LED_RED);
            HAL_Delay(MORSE_DELAY_SHORT);
            BSP_LED_Off(LED_RED);

            HAL_Delay(MORSE_DELAY_SEPWRD);
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    start(void)
{
    printf("Alive");
    fflush(stdout);


    /* Clear LEDs */
    BSP_LED_Off(LED_BLUE);
    BSP_LED_Off(LED_GREEN);
    BSP_LED_Off(LED_ORANGE);
    BSP_LED_Off(LED_RED);


    /* Display the main screen */
    display_setView(&c_view_main);


    /* Start time base timers */
    HAL_TIM_Base_Start_IT(&htim11);
    HAL_TIM_Base_Start_IT(&htim12);
    HAL_TIM_Base_Start_IT(&htim13);
}

/* ########################################################################## */
/* ########################################################################## */
