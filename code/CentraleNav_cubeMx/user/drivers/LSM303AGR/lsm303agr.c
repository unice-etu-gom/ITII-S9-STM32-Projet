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
/*
 uint8_t	LSM303AGR_ConfigureAcc(ACCELERO_InitTypeDef* initStruct)
 {

	 if (HAL_I2C_Mem_Write(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_W,LSM303AGR_CTRL_REG4_A,1,initStruct->AccFull_Scale | initStruct->BlockData_Update | initStruct -> High_Resolution,1,10000)!= HAL_OK)
	 	 return HAL_ERROR;
	 if(HAL_I2C_Mem_Write(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_W,LSM303AGR_CTRL_REG1_A,1,initStruct->AccOutput_DataRate | initStruct->Axes_Enable | initStruct -> Power_Mode,1,10000)!= HAL_OK)
		 return HAL_ERROR;
	 return HAL_OK;

 }
 */
 uint8_t	LSM303AGR_AccInit(void)
 {
	 //uint8_t l_data1 = LSM303AGR_REG1_A_DFLT_A;
	 //uint8_t l_data2 = LSM303AGR_REG4_A_DFLT_A;

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

 uint8_t	LSM303AGR_AccReadXYZ(int16_t* pData)
 {
	 uint8_t lbufferx[2] = {0};
	 uint8_t lbuffery[2] = {0};
	 uint8_t lbufferz[2] = {0};
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_R,LSM303AGR_OUT_X_L_A,1,lbufferx,2,10000)!= HAL_OK)
	 {
		 return HAL_ERROR;
	 }
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_R,LSM303AGR_OUT_Y_L_A,1,lbuffery,2,10000)!= HAL_OK)
	 {
			 return HAL_ERROR;
	 }
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM303AGR_ACC_I2C_ADDRESS_R,LSM303AGR_OUT_Z_L_A,1,lbufferz,2,10000)!= HAL_OK)
	 {
			 return HAL_ERROR;
	 }
	 printf("0x%02x 0x%02x\n\r",lbufferx[1],lbufferx[0]);
	 pData[0] = lbufferx[1];
	 pData[0] <<= 8;
	 pData[0] |= lbufferx[0];
	 pData[0] >>= 6;

	 pData[1] = lbuffery[1];
	 pData[1] <<= 8;
	 pData[1] |= lbuffery[0];
	 pData[1] >>= 6;

	 pData[2] = lbufferz[1];
	 pData[2] <<= 8;
	 pData[2] |= lbufferz[0];
	 pData[2] >>= 6;

	 return HAL_OK;
 }


 uint8_t	LS303AGR_MagInit(void)
 {
	 uint8_t config = 0x00;
	 if(HAL_I2C_Mem_Write(&hi2c2,LSM303AGR_MAG_I2C_ADDRESS_W,LSM303AGR_CFG_REG_A_M,1,&config,1,10000) != HAL_OK)
		 return HAL_ERROR;
	 return HAL_OK;
 }


 uint8_t LSM303AGR_MagReadXYZ(int16_t* pData)
 {
	 uint8_t lbufferx[2] = {0};
	 uint8_t lbuffery[2] = {0};
	 uint8_t lbufferz[2] = {0};

	 if(HAL_I2C_Mem_Read(&hi2c2,LSM303AGR_MAG_I2C_ADDRESS_R,LSM303AGR_OUT_X_L_M,1,lbufferx,2,10000)!= HAL_OK)
	 {
		 return HAL_ERROR;
	 }
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM303AGR_MAG_I2C_ADDRESS_R,LSM303AGR_OUT_Y_L_M,1,lbuffery,2,10000)!= HAL_OK)
	 {
	 		 return HAL_ERROR;
	 }
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM303AGR_MAG_I2C_ADDRESS_R,LSM303AGR_OUT_Z_L_M,1,lbufferz,2,10000)!= HAL_OK)
	 {
	 		 return HAL_ERROR;
	 }
	 pData[0] = lbufferx[1];
	 pData[0] <<= 8;
	 pData[0] |= lbufferx[0];

	 pData[1] = lbuffery[1];
	 pData[1] <<= 8;
	 pData[1] |= lbuffery[0];

	 pData[2] = lbufferz[1];
	 pData[2] <<= 8;
	 pData[2] |= lbufferz[0];
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
