#include "lsm6dsl.h"

 uint8_t	LSM6DSL_XlInit(void)
 {
	 uint8_t config = LSM6DSL_DFLT_CONFIG;

	 if(HAL_I2C_Mem_Write(&hi2c2,LSM6DSL_ACC_I2C_ADDRESS_W,LSM6DSL_CTRL1_XL_REGISTER,1,&config,1,HAL_TIMEOUT)!= HAL_OK)
		 return HAL_ERROR;
	 return HAL_OK;
 }
 uint8_t	LSM6DSL_XlRead_XYZ(int16_t *pData)
 {
	 if(HAL_I2C_Mem_Read(&hi2c2,LSM6DSL_ACC_I2C_ADDRESS_R,LSM6DSL_OUT_XL_X,1,(uint8_t*)&pData[0],6,HAL_TIMEOUT)!= HAL_OK)
	 	 return HAL_ERROR;

	 return HAL_OK;
 }
