/* Corresponding header inclusion */
#include "data_processing.h"

/* System includes */
#include <math.h>

/* Libraries includes */

/* Project includes */
#include "variables_globales.h"
#include "data/parameters.h"


/* ########################################################################## */
/* ########################################################################## */

/** @brief  Cette constante est utilisée pour obtenir un angle en degrés à
 *          partir d'un angle en radians (multiplier la valeur à convertir par
 *          cette constante).
 */
#define C_ANGLE_RAD_TO_DEG  (57.295779513)

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  This function sets an angle in the [0;360[ range.
 *
 *  If the value contained in the given \p pioValuePtr is not in the [0;360[
 *  range, then it will be set back in this range by 360 degrees increment/
 *  decrement steps.
 *
 *  @param  pioValuePtr A pointer to the value to be kept in the range.
 */
static void
        angle_in_0_360(volatile double  *pioValuePtr)
{
    while( (*pioValuePtr) < 0 )
    {
        (*pioValuePtr) += 360.0;
    }

    while( (*pioValuePtr) >= 360.0 )
    {
        (*pioValuePtr) -= 360.0;
    }
}

/* ########################################################################## */
/* ########################################################################## */

static void
        calculate_magnetometerAngle(void)
{
    /* Note: To know wether we should invert X and Y axis direction, we use Z
     * axis sign */
    volatile uint16_t   lInvert
            =   g_magnetometerValues.Z >= 0
                ?   1
                :   -1;

    volatile double  lAngle
            = atan2( (double)(-lInvert*g_magnetometerValues.X),
                     (double)(lInvert*g_magnetometerValues.Y) );

    lAngle  *= C_ANGLE_RAD_TO_DEG;

    /* Hotfix direction axes */
    lAngle  = 360 - lAngle;

    /* Apply some calibration correction on the angle */
    lAngle  += g_parameters.magnetometer_correction_deg;

    angle_in_0_360(&lAngle);
    g_magnetometerAngle = lAngle;
}

/* ########################################################################## */
/* ########################################################################## */

void    data_process(void)
{
    calculate_magnetometerAngle();
}

/* ########################################################################## */
/* ########################################################################## */
