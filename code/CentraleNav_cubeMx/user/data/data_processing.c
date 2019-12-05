/* Corresponding header inclusion */
#include "data_processing.h"

/* System includes */
#include <math.h>

/* Libraries includes */

/* Project includes */
#include "../variables_globales.h"


/* ########################################################################## */
/* ########################################################################## */

void    data_process(void)
{
    volatile double  lAngle
            = atan2( g_magnetometerValues.Y,
                     g_magnetometerValues.X );
    lAngle  *= 180.0;
    lAngle  /= M_PI;

    g_magnetometerAngle = lAngle;
}

/* ########################################################################## */
/* ########################################################################## */
