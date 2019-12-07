#ifndef SERIAL_H
#define SERIAL_H

/* Inherited classes */

/* System includes */
#include <stdint.h>

/* Libraries includes */

/* Project includes */



/* ########################################################################## */
/* ########################################################################## */

extern  uint8_t g_serial_txPeriod_ACC_100ms;
extern  uint8_t g_serial_txPeriod_GYR_100ms;
extern  uint8_t g_serial_txPeriod_MAG_100ms;

/* ########################################################################## */
/* ########################################################################## */

void    serial_init(void);

void    serial_periodicAction100ms(void);

void    serial_transmit(void);


void    serial_emitPeriod_MAG_dec(void);
void    serial_emitPeriod_MAG_inc(void);

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< SERIAL_H */
