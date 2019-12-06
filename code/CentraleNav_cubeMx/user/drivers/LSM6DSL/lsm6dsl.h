/**
  ******************************************************************************
  * @file    lsm303agr.h
  * @author  CIANCI Adrien - GO Mathias
  * @version V0.0.1
  * @date    30-November-2019
  * @brief   This file contains all the functions prototypes for the lsm303agr.c driver.
  ******************************************************************************
  **/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LSM303DSL_H
#define __LSM303DSL_H

#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes ------------------------------------------------------------------*/
#include "../../../Inc/i2c.h"
#include <stdint.h>
#include "math.h"
 /******************************************************************************/
 /*************************** START REGISTER MAPPING  **************************/
 /******************************************************************************/
 /* Exported constant IO ------------------------------------------------------*/
#define LSM6DSL_ACC_I2C_ADDRESS_W	0xD6
#define LSM6DSL_ACC_I2C_ADDRESS_R	0xD7
#define LSM6DSL_CTRL1_XL_REGISTER	0x10
#define LSM6DSL_CTRL1_GYRO_REGISTER	0x11
#define LSM6DSL_DFLT_CONFIG			0x88
#define LSM6DSL_OUT_XL_X			0x28
#define LSM6DSL_OUT_XL_Y			0x2A
#define LSM6DSL_OUT_XL_Z			0x2C

 uint8_t	LSM6DSL_XlInit(void);
 uint8_t	LSM6DSL_XlRead_XYZ(int16_t* pData);



#endif /* __LSM303AGR_H */
