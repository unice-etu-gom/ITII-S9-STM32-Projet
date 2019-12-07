#include "init.h"

#include <stdio.h>

#include "stm32412g_discovery.h"
#include "stm32412g_discovery_lcd.h"

#include "tim.h"

#include "comm/serial.h"
#include "data/parameters.h"
#include "display/display_management.h"
#include "display/views/TViewHello.h"
#include "display/views/TViewMain.h"
#include "drivers/LSM6DSL/lsm6dsl.h"
#include "drivers/LSM303AGR/lsm303agr.h"

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
void    init_MEMS(void);

void    start(void);

/* ########################################################################## */
/* ########################################################################## */

void    init(void)
{
    /*
     *  Initialize modules
     */
    /* LEDS must be the first module to be initialized as it is used to display
     * error codes. */
    init_LED();

    /* Now we initialize application parameters */
    parameters_init();


    serial_init();

    init_LCD();

    init_MEMS();



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

void    init_MEMS(void)
{
    uint8_t retval  = 0U;


    if( LS303AGR_MagInit() != HAL_OK )
    {
        retval++;
    }

    if( LSM6DSL_XlInit() != HAL_OK )
    {
        retval++;
    }

    if( LSM6DSL_GyroInit() != HAL_OK )
    {
        retval++;
    }




    /* -------------------------------------------------------------------------
     *  Prevent init to continue
     */
    if( retval != 0U )
    {
        while(1)
        {
            /* M */
            BSP_LED_On(LED_RED);
            HAL_Delay(MORSE_DELAY_LONG);
            BSP_LED_Off(LED_RED);
            HAL_Delay(MORSE_DELAY_SEPSYM);
            BSP_LED_On(LED_RED);
            HAL_Delay(MORSE_DELAY_LONG);
            BSP_LED_Off(LED_RED);
            HAL_Delay(MORSE_DELAY_SEPSYM);

            HAL_Delay(MORSE_DELAY_SEPLTR);


            /* E */
            BSP_LED_On(LED_RED);
            HAL_Delay(MORSE_DELAY_SHORT);
            BSP_LED_Off(LED_RED);

            HAL_Delay(MORSE_DELAY_SEPWRD);


            /* M */
            BSP_LED_On(LED_RED);
            HAL_Delay(MORSE_DELAY_LONG);
            BSP_LED_Off(LED_RED);
            HAL_Delay(MORSE_DELAY_SEPSYM);
            BSP_LED_On(LED_RED);
            HAL_Delay(MORSE_DELAY_LONG);
            BSP_LED_Off(LED_RED);
            HAL_Delay(MORSE_DELAY_SEPSYM);

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
