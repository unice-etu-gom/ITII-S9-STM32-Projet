/* Corresponding header inclusion */
#include "variables_globales.h"

/* System includes */

/* Libraries includes */

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

volatile uint8_t g_flag_delayedActions_10ms     = 0;
volatile uint8_t g_flag_delayedActions_100ms    = 0;
volatile uint8_t g_flag_delayedActions_1000ms   = 0;


volatile Ts3Dimentions  g_acceleroValues        = {0};

volatile Ts3Dimentions  g_gyroValues            = {0};

volatile Ts3Dimentions  g_magnetometerValues    = {0};
volatile double         g_magnetometerAngle     = 360.0l;

/* ########################################################################## */
/* ########################################################################## */
