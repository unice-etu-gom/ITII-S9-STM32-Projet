#include "init.h"

#include <stdio.h>

#include "stm32412g_discovery.h"

/* ########################################################################## */
/* ########################################################################## */

void	init(void)
{
	  BSP_LED_Init(LED_BLUE);
	  BSP_LED_Init(LED_RED);
	  BSP_LED_Init(LED_ORANGE);
	  BSP_LED_Init(LED_GREEN);

	  BSP_LED_On(LED_GREEN);


	  printf("\n\nSTM32F412Discovery: Hello, World!\n");
	  printf("Alive");
	  fflush(stdout);
}

/* ########################################################################## */
/* ########################################################################## */
