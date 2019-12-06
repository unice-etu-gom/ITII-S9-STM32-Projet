/**
  ******************************************************************************
  * @file    lsm303dsl.c
  * @author  CIANCI Adrien - GO Mathias
  * @version V0.0.1
  * @date    30-November-2019
  * @brief   This file provides a set of functions needed to manage the lsm6dsl
  *          MEMS accelerometer and gyroscope.
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/
#include "lsm6dsl.h"

/**
  * @brief  Init LSM6DSL Accelerometer with default value and all axis enabled
  * @retval HAL status
  */
 uint8_t	LSM6DSL_XlInit(void)
 {
	 uint8_t config = LSM6DSL_XL_DFLT_CONFIG;

	 if(HAL_I2C_Mem_Write(&hi2c2,LSM6DSL_ACC_I2C_ADDRESS_W,LSM6DSL_CTRL1_XL_REGISTER,1,&config,1,10000)!= HAL_OK)
		 return HAL_ERROR;
	 return HAL_OK;
 }
 /**
   * @brief  Init LSM6DSL Gyroscope with default value and all axis enabled
   * @retval HAL status
   */
 uint8_t	LSM6DSL_GyroInit(void)
 {
	 uint8_t config = LSM6DSL_GYRO_DFTL_CONFIG;
	 if(HAL_I2C_Mem_Write(&hi2c2,LSM6DSL_ACC_I2C_ADDRESS_W,LSM6DSL_CTRL2_GYRO_REGISTER,1,&config,1,10000)!= HAL_OK)
		 return HAL_ERROR;
	 return HAL_OK;
 }
 /**
   * @brief  Read all axis values from accelerometer
   * @param  pData Pointer on data buffer. At least 3 int16_t are required.
   * pData[0] will contains X axis value.
   * pData[1] will contains Y axis value.
   * pData[2] will contains Z axis value.
   * @retval HAL status
   */
 uint8_t	LSM6DSL_XlRead_XYZ(int16_t *pData)
 {
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM6DSL_ACC_I2C_ADDRESS_R,LSM6DSL_REG_OUT_XL_X,1,(uint8_t*)&pData[0],6,10000)!= HAL_OK)
	 	 return HAL_ERROR;

	 return HAL_OK;
 }
 /**
    * @brief  Read all axis values from gyroscope
    * @param  pData Pointer on data buffer. At least 3 int16_t are required.
    * pData[0] will contains X axis value.
    * pData[1] will contains Y axis value.
    * pData[2] will contains Z axis value.
    * @retval HAL status
    */
 uint8_t	LSM6DSL_Gyro_Read_XYZ(int16_t *pData)
 {
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM6DSL_ACC_I2C_ADDRESS_R,LSM6DSL_REG_OUT_GYRO_X,1,(uint8_t*)&pData[0],6,10000)!= HAL_OK)
	 	 return HAL_ERROR;

	 return HAL_OK;
 }
 /**
    * @brief  Read temperature from mems
    * @param  pData Pointer on data buffer.
    * @retval HAL status
    */
 uint8_t	LSM6DSL_Read_TEMP(int16_t *pData)
 {
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM6DSL_ACC_I2C_ADDRESS_R,LSM6DSL_REG_TEMP,1,(uint8_t*)&pData[0],2,10000)!= HAL_OK)
	 	 return HAL_ERROR;

	 return HAL_OK;
 }
