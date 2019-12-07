/* Corresponding header inclusion */
#include "parameters.h"

/* System includes */

/* Libraries includes */
//#include "stm32412g_discovery_eeprom.h"
#include "stm32412g_discovery_qspi.h"

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

#define C_TSPARAMETERSEEPROM_STRUCTVERSION  (20191206190500)

TsParametersEEPROM  g_parameters;

/* ########################################################################## */
/* ########################################################################## */

static uint8_t  parameters_set(const TsParametersEEPROM *pDataPtr);

/* ########################################################################## */
/* ########################################################################## */

void    parameters_init(void)
{
    g_parameters.struct_version = C_TSPARAMETERSEEPROM_STRUCTVERSION;


    g_parameters.magnetometer_correction_deg    = 90.0l;

    g_parameters.serial_txPeriod_MAG_100ms  = 10U;

    g_parameters._test= 0U;
}

/* ########################################################################## */
/* ########################################################################## */

uint8_t parameters_readFromEEPROM(void)
{
    TsParametersEEPROM  lParameters     = {0};
    uint16_t            lParametersSize = (uint16_t) sizeof(TsParametersEEPROM);

    uint8_t retval  = 0;


    /* Init EEPROM driver */
    if( BSP_QSPI_Init() != QSPI_OK )
    {
        retval  = 1;
    }


    /* Read the EEPROM */
    else if(    BSP_QSPI_Read(
                    (uint8_t*)&lParameters,
                    0x00,
                    lParametersSize )
            !=  QSPI_OK )
    {
        retval  = 2;
    }


    /* Try to set the data we just read */
    else if( parameters_set(&lParameters) != 0 )
    {
        parameters_init();
        if( parameters_writeToEEPROM() != 0 )
        {
            retval  = 3;
        }
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

uint8_t parameters_set(const TsParametersEEPROM *pDataPtr)
{
    uint8_t retval  = 0U;


    if(pDataPtr->struct_version != C_TSPARAMETERSEEPROM_STRUCTVERSION)
    {
        retval  = 1;
    }
    else
    {
        g_parameters    = (*pDataPtr);
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

uint8_t parameters_writeToEEPROM(void)
{
    QSPI_Info   lInfos  = {0};
    uint8_t retval  = 0U;


    /* Init EEPROM driver */
    if( BSP_QSPI_Init() != QSPI_OK )
    {
        retval  = 1;
    }


//    /* test : clear the chip */
//    else if( BSP_QSPI_Erase_Chip() != QSPI_OK )
//    {
//#warning pour test
//        while(1);
//    }
    else if( BSP_QSPI_GetInfo(&lInfos) != QSPI_OK )
    {
#warning pour test
        while(1);
    }


    /* Write to the EEPROM */
    else if(    BSP_QSPI_Write(
                    (uint8_t*)&g_parameters,
                    0x00,
                    sizeof(TsParametersEEPROM) )
            !=  QSPI_OK )
    {
        retval  = 2;
    }


    else
    {
        retval  = 0U;
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */
