/**
  ******************************************************************************
  * @file    lsm303agr.c
  * @author  CIANCI Adrien - GO Mathias
  * @version V0.0.1
  * @date    30-November-2019
  * @brief   This file provides a set of functions needed to manage the lsm303agr
  *          MEMS accelerometer and magnetometer.
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/
#include "lsm303agr.h"
#include "stdio.h"

 /**
   * @brief  Init LSM303AGR Accelerometer with default value and all axis enabled
   * @retval HAL status
   */
 uint8_t	LSM303AGR_AccInit(void)
 {

	 uint8_t config_REG1_A = 0x57;
	 uint8_t config_REG2_A = 0x00;
	 uint8_t config_REG3_A = 0x00;
	 uint8_t config_REG4_A = 0x81;

	 if (HAL_I2C_Mem_Write(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_W,LSM303AGR_CTRL_REG2_A,1,&config_REG2_A,1,10000) != HAL_OK)
		 return HAL_ERROR;

	 if (HAL_I2C_Mem_Write(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_W,LSM303AGR_CTRL_REG3_A,1,&config_REG3_A,1,10000) != HAL_OK)
	  	 return HAL_ERROR;

	 if (HAL_I2C_Mem_Write(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_W,LSM303AGR_CTRL_REG4_A,1,&config_REG4_A,1,10000) != HAL_OK)
	 	return HAL_ERROR;

	 if (HAL_I2C_Mem_Write(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_W,LSM303AGR_CTRL_REG1_A,1,&config_REG1_A,1,10000) != HAL_OK)
		 return HAL_ERROR;

	 printf("Config ok\n\r");
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
 uint8_t	LSM303AGR_AccReadXYZ(int16_t* pData)
 {

	 if(HAL_I2C_Mem_Read(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_R,LSM303AGR_OUT_X_L_A,1,(uint8_t*)pData,6,10000)!= HAL_OK)
	 {
		 return HAL_ERROR;
	 }
	 return HAL_OK;
 }

 /**
   * @brief  Init LSM6DSL Magnetometer with default value and all axis enabled
   * @retval HAL status
   */
 uint8_t	LS303AGR_MagInit(void)
 {
	 uint8_t config = 0x00;
	 if(HAL_I2C_Mem_Write(&hi2c2,LSM303AGR_MAG_I2C_ADDRESS_W,LSM303AGR_CFG_REG_A_M,1,&config,1,10000) != HAL_OK)
		 return HAL_ERROR;
	 return HAL_OK;
 }

 /**
    * @brief  Read all axis values from magnetometer
    * @param  pData Pointer on data buffer. At least 3 int16_t are required.
    * pData[0] will contains X axis value.
    * pData[1] will contains Y axis value.
    * pData[2] will contains Z axis value.
    * @retval HAL status
    */
 uint8_t LSM303AGR_MagReadXYZ(int16_t* pData)
 {

	 if(HAL_I2C_Mem_Read(&hi2c2,LSM303AGR_MAG_I2C_ADDRESS_R,LSM303AGR_OUT_X_L_M,1,(uint8_t*)pData,6,10000)!= HAL_OK)
	 {
		 return HAL_ERROR;
	 }
	 return HAL_OK;
 }


 uint8_t LSM303AGR_MagReadID(uint8_t *pData)
 {
	 uint8_t lbuffer = 0;
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM303AGR_MAG_I2C_ADDRESS_R,LSM303AGR_WHO_AM_I_ADDR_M,1,&lbuffer,1,10000)!=HAL_OK)
	 {
		 return HAL_ERROR;
	 }
	 *pData = lbuffer;
	 return HAL_OK;
 }
