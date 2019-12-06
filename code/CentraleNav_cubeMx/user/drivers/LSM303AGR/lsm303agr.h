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
#ifndef __LSM303AGR_H
#define __LSM303AGR_H

#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes ------------------------------------------------------------------*/
#include "../../../Drivers/BSP/Components/Common/accelero.h"
#include "../../../Drivers/BSP/Components/Common/magneto.h"
#include "../../../Inc/i2c.h"
#include <stdint.h>
 /******************************************************************************/
 /*************************** START REGISTER MAPPING  **************************/
 /******************************************************************************/
 /* Exported constant IO ------------------------------------------------------*/
#define LSM303AGR_ACC_I2C_ADDRESS_W                    0x32
#define LSM303AGR_ACC_I2C_ADDRESS_R                    0x33
#define LSM303AGR_MAG_I2C_ADDRESS_W                    0x3C
#define LSM303AGR_MAG_I2C_ADDRESS_R                    0x3D

 /* Acceleration Registers */
#define LSM303AGR_WHO_AM_I_ADDR_A           0x0F  /* device identification register : Default is 0x33*/
#define LSM303AGR_CTRL_REG1_A               0x20  /* Control register 1 acceleration */
#define LSM303AGR_CTRL_REG2_A               0x21  /* Control register 2 acceleration */
#define LSM303AGR_CTRL_REG3_A               0x22  /* Control register 3 acceleration */
#define LSM303AGR_CTRL_REG4_A               0x23  /* Control register 4 acceleration */
#define LSM303AGR_CTRL_REG5_A               0x24  /* Control register 5 acceleration */
#define LSM303AGR_CTRL_REG6_A               0x25  /* Control register 6 acceleration */
#define LSM303AGR_REFERENCE_A               0x26  /* Reference register acceleration */
#define LSM303AGR_STATUS_REG_A              0x27  /* Status register acceleration */
#define LSM303AGR_OUT_X_L_A                 0x28  /* Output Register X acceleration */
#define LSM303AGR_OUT_X_H_A                 0x29  /* Output Register X acceleration */
#define LSM303AGR_OUT_Y_L_A                 0x2A  /* Output Register Y acceleration */
#define LSM303AGR_OUT_Y_H_A                 0x2B  /* Output Register Y acceleration */
#define LSM303AGR_OUT_Z_L_A                 0x2C  /* Output Register Z acceleration */
#define LSM303AGR_OUT_Z_H_A                 0x2D  /* Output Register Z acceleration */
#define LSM303AGR_FIFO_CTRL_REG_A           0x2E  /* Fifo control Register acceleration */
#define LSM303AGR_FIFO_SRC_REG_A            0x2F  /* Fifo src Register acceleration */

 /*Interrupt 1 registers accelerometer*/
#define LSM303AGR_INT1_CFG_A                0x30  /* Interrupt 1 configuration Register acceleration */
#define LSM303AGR_INT1_SOURCE_A             0x31  /* Interrupt 1 source Register acceleration */
#define LSM303AGR_INT1_THS_A                0x32  /* Interrupt 1 Threshold register acceleration */
#define LSM303AGR_INT1_DURATION_A           0x33  /* Interrupt 1 DURATION register acceleration */

 /*Interrupt 2 registers accelerometer*/
#define LSM303AGR_INT2_CFG_A                0x34  /* Interrupt 2 configuration Register acceleration */
#define LSM303AGR_INT2_SOURCE_A             0x35  /* Interrupt 2 source Register acceleration */
#define LSM303AGR_INT2_THS_A                0x36  /* Interrupt 2 Threshold register acceleration */
#define LSM303AGR_INT2_DURATION_A           0x37  /* Interrupt 2 DURATION register acceleration */

#define LSM303AGR_CLICK_CFG_A               0x38  /* Click configuration Register acceleration */
#define LSM303AGR_CLICK_SOURCE_A            0x39  /* Click 2 source Register acceleration */
#define LSM303AGR_CLICK_THS_A               0x3A  /* Click 2 Threshold register acceleration */

#define LSM303AGR_TIME_LIMIT_A              0x3B  /* Time Limit Register acceleration */
#define LSM303AGR_TIME_LATENCY_A            0x3C  /* Time Latency Register acceleration */
#define LSM303AGR_TIME_WINDOW_A             0x3D  /* Time window register acceleration */

/*Magnetic field registers*/
/*Magneto hard-iron registers : Offsets for environmental effects compensation*/
#define LSM303AGR_OFFSET_X_REG_L_M			0x45 /* X axis compensation */
#define LSM303AGR_OFFSET_X_REG_H_M			0x46 /* X axis compensation */
#define LSM303AGR_OFFSET_Y_REG_L_M			0x47 /* Y axis compensation */
#define LSM303AGR_OFFSET_Y_REG_H_M			0x48 /* Y axis compensation */
#define LSM303AGR_OFFSET_Z_REG_L_M			0x49 /* Z axis compensation */
#define LSM303AGR_OFFSET_Z_REG_H_M			0x50 /* Z axis compensation */

#define LSM303AGR_WHO_AM_I_ADDR_M           0x4F  /* device identification register : Default is 0x40*/

/* Magneto configuration registers */

/* Configure output data rate and measurement configuration */
#define LSM303AGR_CFG_REG_A_M				0x60
#define LSM303AGR_CFG_REG_B_M				0x61
#define LSM303AGR_CFG_REG_C_M				0x62

/* Magnetometer interrupt configuration */
#define LSM303AGR_INT_CTRL_REG_M			0x63 /* enable and configure interrupt recognition */
#define LSM303AGR_INT_SOURCE_REG_M			0x64 /* Source register magneto */
#define LSM303AGR_INT_THS_L_REG_M			0x65 /* Threshold register magneto */
#define LSM303AGR_INT_THS_H_REG_M			0x66 /* Threshold register magneto */

#define LSM303AGR_STATUS_REG_M				0x67 /* Status register magneto */

/* Magnetometer output registers */
 #define LSM303AGR_OUT_X_L_M				0x68 /*  Output Register X magneto */
 #define LSM303AGR_OUT_X_H_M				0x69 /*  Output Register X magneto */
 #define LSM303AGR_OUT_Y_L_M				0x6A /*  Output Register Y magneto */
 #define LSM303AGR_OUT_Y_H_M				0x6B /*  Output Register Y magneto */
 #define LSM303AGR_OUT_Z_L_M				0x6C /*  Output Register Z magneto */
 #define LSM303AGR_OUT_Z_H_M				0x6D /*  Output Register Z magneto */


 /******************************************************************************/
 /**************************** END REGISTER MAPPING  ***************************/
 /******************************************************************************/
 /* Accelerometer Values */
#define I_AM_LMS303AGR_A                    ((uint8_t)0x33)

 /** @defgroup Acc_Power_Mode_selection
   * @{
   */
	#define LSM303AGR_NORMAL_MODE_A         ((uint8_t)0x00)
	#define LSM303AGR_LOWPOWER_MODE_A       ((uint8_t)0x08)
 /**
   * @}
   */

 /** @defgroup Acc_Axes_Selection
   * @{
   */
 #define LSM303_XYZ_DISABLE_A				((uint8_t)0x00)
 #define LSM303AGR_X_ENABLE_A				((uint8_t)0x01)
 #define LSM303AGR_Y_ENABLE_A				((uint8_t)0x02)
 #define LSM303AGR_Z_ENABLE_A				((uint8_t)0x04)
 #define LSM303AGR_XYZ_ENABLE_A				(LSM303AGR_X_ENABLE_A|LSM303AGR_Y_ENABLE_A|LSM303AGR_Z_ENABLE_A)
 /**
   * @}
   */

 /** @defgroup Acc_OutPut_DataRate_Selection
   * @{
   */
 #define LSM303AGR_ODR_DOWN_A				((uint8_t)0x00)
 #define LSM303AGR_ODR_1_HZ_A				((uint8_t)0x10) /*!< Output Data Rate = 1 Hz */
 #define LSM303AGR_ODR_10_HZ_A				((uint8_t)0x20) /*!< Output Data Rate = 10 Hz */
 #define LSM303AGR_ODR_25_HZ_A				((uint8_t)0x30) /*!< Output Data Rate = 25 Hz */
 #define LSM303AGR_ODR_50_HZ_A				((uint8_t)0x40) /*!< Output Data Rate = 50 Hz */
 #define LSM303AGR_ODR_100_HZ_A				((uint8_t)0x50) /*!< Output Data Rate = 100 Hz */
 #define LSM303AGR_ODR_200_HZ_A				((uint8_t)0x60) /*!< Output Data Rate = 200 Hz */
 #define LSM303AGR_ODR_400_HZ_A				((uint8_t)0x70) /*!< Output Data Rate = 400 Hz */
 #define LSM303AGR_ODR_LP_1620_HZ_A			((uint8_t)0x80) /*!< Output Data Rate = 1620 Hz only in low power mode */
 #define LSM303AGR_ODR_1344_HZ_A			((uint8_t)0x90) /*!< Output Data Rate = 1344 Hz in normal mode, 5376 in low power mode */
 /**
   * @}
   */


 /** @defgroup Acc_High_Resolution
   * @{
   */
 #define LSM303AGR_HR_ENABLE_A               ((uint8_t)0x08)
 #define LSM303AGR_HR_DISABLE_A              ((uint8_t)0x00)
 /**
   * @}
   */

 /** @defgroup Acc_Full_Scale_Selection
   * @{
   */
 #define LSM303AGR_FULLSCALE_2G            ((uint8_t)0x00)  /*!< ±2 g */
 #define LSM303AGR_FULLSCALE_4G            ((uint8_t)0x10)  /*!< ±4 g */
 #define LSM303AGR_FULLSCALE_8G            ((uint8_t)0x20)  /*!< ±8 g */
 #define LSM303AGR_FULLSCALE_16G           ((uint8_t)0x30)  /*!< ±16 g */
 /**
   * @}
   */
 /** @defgroup Acc_Sensitivity
   * @{
   */
 #define LSM303AGR_ACC_SENSITIVITY_2G     	((uint8_t)1)  /*!< accelerometer sensitivity with 2 g full scale [mg/LSB] */
 #define LSM303AGR_ACC_SENSITIVITY_4G     	((uint8_t)2)  /*!< accelerometer sensitivity with 4 g full scale [mg/LSB] */
 #define LSM303AGR_ACC_SENSITIVITY_8G       ((uint8_t)4)  /*!< accelerometer sensitivity with 8 g full scale [mg/LSB] */
 #define LSM303AGR_ACC_SENSITIVITY_16G      ((uint8_t)12) /*!< accelerometer sensitivity with 12 g full scale [mg/LSB] */
 /**
   * @}
   */

 /** @defgroup Acc_Block_Data_Update
   * @{
   */
 #define LSM303AGR_BlockUpdate_Continous    ((uint8_t)0x00) /*!< Continuous Update */
 #define LSM303AGR_BlockUpdate_Single       ((uint8_t)0x80) /*!< Single Update: output registers not updated until MSB and LSB reading */
 /**
   * @}
   */

 /** @defgroup Acc_Endian_Data_selection
   * @{
   */
 #define LSM303AGR_BLE_LSB                 ((uint8_t)0x00) /*!< Little Endian: data LSB @ lower address */
 #define LSM303AGR_BLE_MSB                 ((uint8_t)0x40) /*!< Big Endian: data MSB @ lower address */
 /**
   * @}
   */

 /** @defgroup Acc_Boot_Mode_selection
   * @{
   */
 #define LSM303AGR_BOOT_NORMALMODE_A         ((uint8_t)0x00)
 #define LSM303AGR_BOOT_REBOOTMEMORY_A       ((uint8_t)0x80)
 /**
   * @}
   */

 /** @defgroup Acc_High_Pass_Filter_Mode
   * @{
   */
 #define LSM303AGR_HPM_NORMAL_MODE_RES_A   ((uint8_t)0x00)
 #define LSM303AGR_HPM_REF_SIGNAL_A        ((uint8_t)0x40)
 #define LSM303AGR_HPM_NORMAL_MODE_A       ((uint8_t)0x80)
 #define LSM303AGR_HPM_AUTORESET_INT_A     ((uint8_t)0xC0)
 /**
   * @}
   */

 /** @defgroup Acc_High_Pass_CUT OFF_Frequency
   * @{
   */
 #define LSM303AGR_HPFCF_8_A               ((uint8_t)0x00)
 #define LSM303AGR_HPFCF_16_A              ((uint8_t)0x10)
 #define LSM303AGR_HPFCF_32_A              ((uint8_t)0x20)
 #define LSM303AGR_HPFCF_64_A              ((uint8_t)0x30)
 /**
   * @}
   */

 /** @defgroup Acc_High_Pass_Filter_status
   * @{
   */
 #define LSM303AGR_HIGHPASSFILTER_DISABLE_A ((uint8_t)0x00)
 #define LSM303AGR_HIGHPASSFILTER_ENABLE_A  ((uint8_t)0x08)
 /**
   * @}
   */

 /** @defgroup Acc_High_Pass_Filter_Click_status
   * @{
   */
 #define LSM303AGR_HPF_CLICK_DISABLE_A      ((uint8_t)0x00)
 #define LSM303AGR_HPF_CLICK_ENABLE_A       ((uint8_t)0x04)
 /**
   * @}
   */

 /** @defgroup Acc_High_Pass_Filter_AOI1_status
   * @{
   */
 #define LSM303AGR_HPF_AOI1_DISABLE_A      ((uint8_t)0x00)
 #define LSM303AGR_HPF_AOI1_ENABLE_A       ((uint8_t)0x01)
 /**
   * @}
   */

 /** @defgroup Acc_High_Pass_Filter_AOI2_status
   * @{
   */
 #define LSM303AGR_HPF_AOI2_DISABLE_A      ((uint8_t)0x00)
 #define LSM303AGR_HPF_AOI2_ENABLE_A       ((uint8_t)0x02)
 /**
   * @}
   */

 /** @defgroup Acc_Interrupt1_Configuration_definition
   * @{
   */
 #define LSM303AGR_IT1_CLICK_A             ((uint8_t)0x80)
 #define LSM303AGR_IT1_AOI1_A              ((uint8_t)0x40)
 #define LSM303AGR_IT1_AOI2_A              ((uint8_t)0x20)
 #define LSM303AGR_IT1_DRY1_A              ((uint8_t)0x10)
 #define LSM303AGR_IT1_DRY2_A              ((uint8_t)0x08)
 #define LSM303AGR_IT1_WTM_A               ((uint8_t)0x04)
 #define LSM303AGR_IT1_OVERRUN_A           ((uint8_t)0x02)
 /**
   * @}
   */

 /** @defgroup Acc_Interrupt2_Configuration_definition
   * @{
   */
 #define LSM303AGR_IT2_CLICK_A             ((uint8_t)0x80)
 #define LSM303AGR_IT2_INT1_A              ((uint8_t)0x40)
 #define LSM303AGR_IT2_INT2_A              ((uint8_t)0x20)
 #define LSM303AGR_IT2_BOOT_A              ((uint8_t)0x10)
 #define LSM303AGR_IT2_ACT_A               ((uint8_t)0x08)
 #define LSM303AGR_IT2_HLACTIVE_A          ((uint8_t)0x02)
 /**
   * @}
   */

 /** @defgroup Acc_INT_Combination_Status
   * @{
   */
 #define LSM303AGR_OR_COMBINATION_A        ((uint8_t)0x00)  /*!< OR combination of enabled IRQs */
 #define LSM303AGR_AND_COMBINATION_A       ((uint8_t)0x80)  /*!< AND combination of enabled IRQs */
 #define LSM303AGR_MOV_RECOGNITION_A       ((uint8_t)0x40)  /*!< 6D movement recognition */
 #define LSM303AGR_POS_RECOGNITION_A       ((uint8_t)0xC0)  /*!< 6D position recognition */
 /**
   * @}
   */

 /** @defgroup Acc_INT_Axes
   * @{
   */
 #define LSM303AGR_Z_HIGH_A                 ((uint8_t)0x20)  /*!< Z High enabled IRQs */
 #define LSM303AGR_Z_LOW_A                  ((uint8_t)0x10)  /*!< Z low enabled IRQs */
 #define LSM303AGR_Y_HIGH_A                 ((uint8_t)0x08)  /*!< Y High enabled IRQs */
 #define LSM303AGR_Y_LOW_A                  ((uint8_t)0x04)  /*!< Y low enabled IRQs */
 #define LSM303AGR_X_HIGH_A                 ((uint8_t)0x02)  /*!< X High enabled IRQs */
 #define LSM303AGR_X_LOW_A                  ((uint8_t)0x01)  /*!< X low enabled IRQs */
 /**
   * @}
   */

 /** @defgroup Acc_INT_Click
 * @{
 */
 #define LSM303AGR_Z_DOUBLE_CLICK_A         ((uint8_t)0x20)  /*!< Z double click IRQs */
 #define LSM303AGR_Z_SINGLE_CLICK_A         ((uint8_t)0x10)  /*!< Z single click IRQs */
 #define LSM303AGR_Y_DOUBLE_CLICK_A         ((uint8_t)0x08)  /*!< Y double click IRQs */
 #define LSM303AGR_Y_SINGLE_CLICK_A         ((uint8_t)0x04)  /*!< Y single click IRQs */
 #define LSM303AGR_X_DOUBLE_CLICK_A         ((uint8_t)0x02)  /*!< X double click IRQs */
 #define LSM303AGR_X_SINGLE_CLICK_A         ((uint8_t)0x01)  /*!< X single click IRQs */
 /**
 * @}
 */

 /** @defgroup Acc_INT1_Interrupt_status
   * @{
   */
 #define LSM303AGR_INT1INTERRUPT_DISABLE_A  ((uint8_t)0x00)
 #define LSM303AGR_INT1INTERRUPT_ENABLE_A   ((uint8_t)0x80)
 /**
   * @}
   */

 /** @defgroup Acc_INT1_Interrupt_ActiveEdge
   * @{
   */
 #define LSM303AGR_INT1INTERRUPT_LOW_EDGE_A  ((uint8_t)0x20)
 #define LSM303AGR_INT1INTERRUPT_HIGH_EDGE_A ((uint8_t)0x00)
 /**
   * @}
   */

 #define LSM303AGR_REG1_A_DFLT_A				((uint8_t)LSM303AGR_ODR_1344_HZ_A | LSM303AGR_NORMAL_MODE_A | LSM303AGR_XYZ_ENABLE_A)
 #define LSM303AGR_REG4_A_DFLT_A				((uint8_t)LSM303AGR_BlockUpdate_Continous | LSM303AGR_BLE_LSB | LSM303AGR_FULLSCALE_16G | LSM303AGR_HR_ENABLE_A)

 /* Magnetometer Values */
 #define I_AM_LMS303AGR_M					((uint8_t)0x40)


 /** @defgroup Mag_Temp_compensation
     * @{
     */
 /* Enable the magnetometer temperature compensation. Default value: 0 */
 #define LSM303AGR_TEMP_COMPENSATION_DISABLE_M ((uint8_t)0x00)
 #define LSM303AGR_TEMP_COMPENSATION_ENABLE_M  ((uint8_t)0x80)
  /**
    * @}
    */

/** @defgroup Mag_Boot_Mode_selection
    * @{
    */
  /* Reboot magnetometer memory content. Default value: 0 */
  #define LSM303AGR_BOOT_NORMALMODE_M         ((uint8_t)0x00)
  #define LSM303AGR_BOOT_REBOOTMEMORY_M       ((uint8_t)0x40)
 /**
   * @}
   */
 /** @defgroup Mag_Config_RST
     * @{
     */
  #define LSM303AGR_NOT_RST_CFG_M 				  ((uint8_t)0x20)
  #define LSM303AGR_RST_CFG_M 				  ((uint8_t)0x20) /*When this bit is set, the configuration registers and user registers are reset. Flash registers keep their values.*/
 /**
    * @}
    */
 /** @defgroup Mag_Power_Mode_selection
   * @{
   */
	#define LSM303AGR_NORMAL_MODE_M         ((uint8_t)0x00)
	#define LSM303AGR_LOWPOWER_MODE_M       ((uint8_t)0x10)
 /**
   * @}
   */
 /** @defgroup Mag_OutPut_DataRate_Selection
    * @{
    */
  #define LSM303AGR_ODR_10_HZ_M				((uint8_t)0x00) /*!< Output Data Rate = 10 Hz (Default) */
  #define LSM303AGR_ODR_20_HZ_M				((uint8_t)0x04) /*!< Output Data Rate = 20 Hz */
  #define LSM303AGR_ODR_50_HZ_M				((uint8_t)0x08) /*!< Output Data Rate = 50 Hz */
  #define LSM303AGR_ODR_100_HZ_M			((uint8_t)0x0C) /*!< Output Data Rate = 100 Hz */
  /**
    * @}
    */
 /** @defgroup Mag_Block_Data_Update
   * @{
   */
	#define LSM303AGR_BlockUpdate_Continous_M			((uint8_t)0x00) /*!< Continuous Update */
	#define LSM303AGR_BlockUpdate_Single_M				((uint8_t)0x01) /*!< Single Update: output registers not updated until MSB and LSB reading */
	#define LSM303AGR_BlockUpdate_Idle1_M				((uint8_t)0x02)
	#define LSM303AGR_BlockUpdate_Idle2_M				((uint8_t)0x03)
 /**
   * @}
   */


	#define LSM303AGR_Offset_Cancelation_Disable_OS_M	((uint8_t)0x00) /** offset cancellation in single measurement mode disabled */
	#define LSM303AGR_Offset_Cancelation_Enable_OS_M	((uint8_t)0x10) /** offset cancellation in single measurement mode enabled */
	#define LSM303AGR_INT_on_DataOff_M					((uint8_t)0x08) /** If ‘1’, the interrupt block recognition checks data after the hard-iron correction to discover the interrrupt */
	#define LSQM303AGR_FREQ_SET_PULSE_CYCLE_M			((uint8_t)0x00) /** set pulse is released every 63 ODR */
	#define LSQM303AGR_FREQ_SET_PULSE_PD_M				((uint8_t)0x04) /**  set pulse is released only at power-on after PD condition */
	#define LSM303AGR_Offset_Cancelation_Disable_M		((uint8_t)0x00) /** offset cancellation disabled */
	#define LSM303AGR_Offset_Cancelation_Enable_M		((uint8_t)0x02) /** offset cancellation enabled */
	#define LSM303AGR_LPF_Disable_M						((uint8_t)0x00) /** digital filter disabled */
	#define LSM303AGR_LPF_Enable_M						((uint8_t)0x01) /** digital filter enabled */

	#define LSM303AGR_REG_A_DFLT_M						((uint8_t)LSM303AGR_TEMP_COMPENSATION_ENABLE_M | LSM303AGR_BOOT_NORMALMODE_M|LSM303AGR_NOT_RST_CFG_M|LSM303AGR_NORMAL_MODE_M|LSM303AGR_ODR_100_HZ_M|LSM303AGR_BlockUpdate_Continous_M)
	#define	LSM303AGR_REG_B_DFLT_M						((uint8_t)LSM303AGR_LPF_Disable_M | LSM303AGR_Offset_Cancelation_Disable_OS_M | LSQM303AGR_FREQ_SET_PULSE_CYCLE_M | LSM303AGR_Offset_Cancelation_Disable_M)
 /** @defgroup LSM303AGR_Exported_Functions
   * @{
   */
 /* Accelero functions */
 uint8_t	LSM303AGR_AccReadXYZ(int16_t* pData);
 uint8_t	LSM303AGR_ConfigureAcc(ACCELERO_InitTypeDef* initStruct);
 uint8_t	LSM303AGR_AccInit(void);

 /* Magneto functions*/
 uint8_t LSM303AGR_MagReadXYZ(int16_t* pData);
 uint8_t	LS303AGR_MagInit(void);
 uint8_t LSM303AGR_MagReadID(uint8_t *pData);
 /**
   * @}
   */

#ifdef __cplusplus
 extern "C" {
#endif

#endif /* __LSM303AGR_H */
