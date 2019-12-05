/* Corresponding header inclusion */
#include "serial.h"

/* System includes */
#include <stdio.h>

/* Libraries includes */

/* Project includes */
#include "../variables_globales.h"


uint8_t         g_serial_txPeriod_MAG_100ms = 10U;

static uint16_t s_periodicWakeupsCount100ms = 0U;

/* ########################################################################## */
/* ########################################################################## */

static void transmit_MAG(void);

/* ########################################################################## */
/* ########################################################################## */

void    serial_init(void)
{
    printf("\r\n\r\nCentrale Nav\r\n");
    printf("Init en cours...\r\n");
    fflush(stdout);
}

/* ########################################################################## */
/* ########################################################################## */

void    serial_periodicAction100ms(void)
{
    if( (s_periodicWakeupsCount100ms % g_serial_txPeriod_MAG_100ms) == 0 )
    {
        transmit_MAG();
    }

    fflush(stdout);
    s_periodicWakeupsCount100ms++;
}

/* ########################################################################## */
/* ########################################################################## */

void    serial_transmit(void)
{
    transmit_MAG();
    fflush(stdout);
}

/* ########################################################################## */
/* ########################################################################## */

void    transmit_MAG(void)
{
    printf("$XXMAG,%+06d,%+06d,%+06d,%05.01f*\r\n",
           g_magnetometerValues.X,
           g_magnetometerValues.Y,
           g_magnetometerValues.Z,
           g_magnetometerAngle );
}

/* ########################################################################## */
/* ########################################################################## */
