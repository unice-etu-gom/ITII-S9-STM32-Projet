#ifndef PARAMETERS_H
#define PARAMETERS_H

/* Inherited classes */

/* System includes */
#include <stdint.h>

/* Libraries includes */

/* Project includes */



/* ########################################################################## */
/* ########################################################################## */

typedef struct  __attribute__((__packed__)) _SParametersEEPROM
{
    uint64_t    struct_version;

    uint8_t     serial_txPeriod_MAG_100ms;


    double      magnetometer_correction_deg;


    uint64_t    _test;

}   TsParametersEEPROM;


extern  TsParametersEEPROM  g_parameters;

/* ########################################################################## */
/* ########################################################################## */

void    parameters_init(void);

uint8_t parameters_readFromEEPROM(void);
uint8_t parameters_writeToEEPROM(void);

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< PARAMETERS_H */
