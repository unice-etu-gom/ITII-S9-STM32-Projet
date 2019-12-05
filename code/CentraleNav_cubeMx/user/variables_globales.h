#ifndef VARIABLES_GLOBALES_H
#define VARIABLES_GLOBALES_H

/* System includes */
#include <stdint.h>

/* Libraries includes */

/* Project includes */



/* ########################################################################## */
/* ########################################################################## */

extern volatile uint8_t g_flag_delayedActions_10ms;
extern volatile uint8_t g_flag_delayedActions_100ms;
extern volatile uint8_t g_flag_delayedActions_1000ms;


typedef struct _S3DimentionsInt
{
    int16_t X;
    int16_t Y;
    int16_t Z;
}   Ts3Dimentions;


extern volatile Ts3Dimentions   g_magnetometerValues;

extern volatile double  g_magnetometerAngle;

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< VARIABLES_GLOBALES_H */
