/**
  ******************************************************************************
  * @file    lsm6dsl.h
  * @author  CIANCI Adrien - GO Mathias
  * @version V0.0.1
  * @date    30-November-2019
  * @brief   This file contains all the functions prototypes for the lsm6dsl.c driver.
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

#define LSM6DSL_GYRO_I2C_ADDRESS_W	0xD4
#define LSM6DSL_GYRO_I2C_ADDRESS_R	0xD5

#define LSM6DSL_CTRL1_XL_REGISTER	0x10
#define LSM6DSL_CTRL2_GYRO_REGISTER	0x11
#define LSM6DSL_XL_DFLT_CONFIG		0x88
#define LSM6DSL_GYRO_DFTL_CONFIG	0XA1
#define LSM6DSL_REG_TEMP			0x20
#define LSM6DSL_REG_OUT_GYRO_X		0x22
#define LSM6DSL_REG_OUT_GYRO_Y		0x24
#define LSM6DSL_REG_OUT_GYRO_Z		0x26
#define LSM6DSL_REG_OUT_XL_X		0x28
#define LSM6DSL_REG_OUT_XL_Y		0x2A
#define LSM6DSL_REG_OUT_XL_Z		0x2C

 uint8_t	LSM6DSL_XlInit(void);
 uint8_t	LSM6DSL_GyroInit(void);
 uint8_t	LSM6DSL_XlRead_XYZ(int16_t* pData);
 uint8_t	LSM6DSL_Gyro_Read_XYZ(int16_t *pData);
 uint8_t	LSM6DSL_Read_TEMP(int16_t *pData);



#endif /* __LSM303AGR_H */
