/**
  ******************************************************************************
  * @file    stm32l1xx_hal_lcd.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    16-January-2015
  * @brief   Header file of LCD Controller HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L1xx_HAL_LCD_H
#define __STM32L1xx_HAL_LCD_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup STM32L1xx_HAL_Driver
  * @{
  */

#if defined (STM32L100xB) || defined (STM32L100xBA) || defined (STM32L100xC) ||\
    defined (STM32L152xB) || defined (STM32L152xBA) || defined (STM32L152xC) || defined (STM32L152xCA) || defined (STM32L152xD) || defined (STM32L152xE) || defined (STM32L152xDX) ||\
    defined (STM32L162xC) || defined (STM32L162xCA) || defined (STM32L162xD) || defined (STM32L162xE) || defined (STM32L162xDX)

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_hal_def.h"

/** @addtogroup LCD
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/

/** @defgroup LCD_Exported_Types LCD Exported Types
  * @{
  */

/** 
  * @brief LCD Init structure definition
  */

typedef struct
{
  uint32_t Prescaler;       /*!< Configures the LCD Prescaler. 
                                 This parameter can be one value of @ref LCD_Prescaler */
  uint32_t Divider;         /*!< Configures the LCD Divider.
                                 This parameter can be one value of @ref LCD_Divider */
  uint32_t Duty;            /*!< Configures the LCD Duty.
                                 This parameter can be one value of @ref LCD_Duty */
  uint32_t Bias;            /*!< Configures the LCD Bias.
                                 This parameter can be one value of @ref LCD_Bias */ 
  uint32_t VoltageSource;   /*!< Selects the LCD Voltage source.
                                 This parameter can be one value of @ref LCD_Voltage_Source */  
  uint32_t Contrast;        /*!< Configures the LCD Contrast.
                                 This parameter can be one value of @ref LCD_Contrast */
  uint32_t DeadTime;        /*!< Configures the LCD Dead Time.
                                 This parameter can be one value of @ref LCD_DeadTime */
  uint32_t PulseOnDuration; /*!< Configures the LCD Pulse On Duration.
                                 This parameter can be one value of @ref LCD_PulseOnDuration */
  uint32_t BlinkMode;       /*!< Configures the LCD Blink Mode.
                                 This parameter can be one value of @ref LCD_BlinkMode */
  uint32_t BlinkFrequency;  /*!< Configures the LCD Blink frequency.
                                 This parameter can be one value of @ref LCD_BlinkFrequency */
  uint32_t MuxSegment;      /*!< Enable or disable mux segment.
                                 This parameter can be set to ENABLE or DISABLE. */ 
}LCD_InitTypeDef;

/** 
  * @brief HAL LCD State structures definition
  */ 
typedef enum
{
  HAL_LCD_STATE_RESET             = 0x00,    /*!< Peripheral is not yet Initialized */
  HAL_LCD_STATE_READY             = 0x01,    /*!< Peripheral Initialized and ready for use */
  HAL_LCD_STATE_BUSY              = 0x02,    /*!< an internal process is ongoing */
  HAL_LCD_STATE_TIMEOUT           = 0x03,    /*!< Timeout state */
  HAL_LCD_STATE_ERROR             = 0x04     /*!< Error */
}HAL_LCD_StateTypeDef;

/** 
  * @brief  HAL LCD Error Code structure definition
  */ 
typedef enum
{
  HAL_LCD_ERROR_NONE      = 0x00,    /*!< No error */
  HAL_LCD_ERROR_FCRSF     = 0x01,    /*!< Synchro flag timeout error */
  HAL_LCD_ERROR_UDR       = 0x02,    /*!< Update display request flag timeout error */
  HAL_LCD_ERROR_UDD       = 0x04,    /*!< Update display done flag timeout error */
  HAL_LCD_ERROR_ENS       = 0x08,    /*!< LCD enabled status flag timeout error */
  HAL_LCD_ERROR_RDY       = 0x10     /*!< LCD Booster ready timeout error */
}HAL_LCD_ErrorTypeDef;

/** 
  * @brief  UART handle Structure definition
  */  
typedef struct
{
  LCD_TypeDef                   *Instance;  /* LCD registers base address */
  
  LCD_InitTypeDef               Init;       /* LCD communication parameters */

  HAL_LockTypeDef               Lock;       /* Locking object */

  __IO HAL_LCD_StateTypeDef     State;      /* LCD communication state */
  
  __IO HAL_LCD_ErrorTypeDef     ErrorCode;  /* LCD Error code */
  
}LCD_HandleTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup LCD_Exported_Constants LCD Exported Constants
  * @{
  */

/** @defgroup LCD_Prescaler LCD Prescaler
  * @{
  */

#define LCD_PRESCALER_1        ((uint32_t)0x00000000)  /*!< CLKPS = LCDCLK        */
#define LCD_PRESCALER_2        ((uint32_t)0x00400000)  /*!< CLKPS = LCDCLK/2      */
#define LCD_PRESCALER_4        ((uint32_t)0x00800000)  /*!< CLKPS = LCDCLK/4      */
#define LCD_PRESCALER_8        ((uint32_t)0x00C00000)  /*!< CLKPS = LCDCLK/8      */
#define LCD_PRESCALER_16       ((uint32_t)0x01000000)  /*!< CLKPS = LCDCLK/16     */
#define LCD_PRESCALER_32       ((uint32_t)0x01400000)  /*!< CLKPS = LCDCLK/32     */
#define LCD_PRESCALER_64       ((uint32_t)0x01800000)  /*!< CLKPS = LCDCLK/64     */
#define LCD_PRESCALER_128      ((uint32_t)0x01C00000)  /*!< CLKPS = LCDCLK/128    */
#define LCD_PRESCALER_256      ((uint32_t)0x02000000)  /*!< CLKPS = LCDCLK/256    */
#define LCD_PRESCALER_512      ((uint32_t)0x02400000)  /*!< CLKPS = LCDCLK/512    */
#define LCD_PRESCALER_1024     ((uint32_t)0x02800000)  /*!< CLKPS = LCDCLK/1024   */
#define LCD_PRESCALER_2048     ((uint32_t)0x02C00000)  /*!< CLKPS = LCDCLK/2048   */
#define LCD_PRESCALER_4096     ((uint32_t)0x03000000)  /*!< CLKPS = LCDCLK/4096   */
#define LCD_PRESCALER_8192     ((uint32_t)0x03400000)  /*!< CLKPS = LCDCLK/8192   */
#define LCD_PRESCALER_16384    ((uint32_t)0x03800000)  /*!< CLKPS = LCDCLK/16384  */
#define LCD_PRESCALER_32768    ((uint32_t)LCD_FCR_PS)  /*!< CLKPS = LCDCLK/32768  */

#define IS_LCD_PRESCALER(__PRESCALER__) (((__PRESCALER__) == LCD_PRESCALER_1)     || \
                                         ((__PRESCALER__) == LCD_PRESCALER_2)     || \
                                         ((__PRESCALER__) == LCD_PRESCALER_4)     || \
                                         ((__PRESCALER__) == LCD_PRESCALER_8)     || \
                                         ((__PRESCALER__) == LCD_PRESCALER_16)    || \
                                         ((__PRESCALER__) == LCD_PRESCALER_32)    || \
                                         ((__PRESCALER__) == LCD_PRESCALER_64)    || \
                                         ((__PRESCALER__) == LCD_PRESCALER_128)   || \
                                         ((__PRESCALER__) == LCD_PRESCALER_256)   || \
                                         ((__PRESCALER__) == LCD_PRESCALER_512)   || \
                                         ((__PRESCALER__) == LCD_PRESCALER_1024)  || \
                                         ((__PRESCALER__) == LCD_PRESCALER_2048)  || \
                                         ((__PRESCALER__) == LCD_PRESCALER_4096)  || \
                                         ((__PRESCALER__) == LCD_PRESCALER_8192)  || \
                                         ((__PRESCALER__) == LCD_PRESCALER_16384) || \
                                         ((__PRESCALER__) == LCD_PRESCALER_32768))

/**
  * @}
  */
  
/** @defgroup LCD_Divider LCD Divider
  * @{
  */

#define LCD_DIVIDER_16    ((uint32_t)0x00000000)  /*!< LCD frequency = CLKPS/16 */
#define LCD_DIVIDER_17    ((uint32_t)0x00040000)  /*!< LCD frequency = CLKPS/17 */
#define LCD_DIVIDER_18    ((uint32_t)0x00080000)  /*!< LCD frequency = CLKPS/18 */
#define LCD_DIVIDER_19    ((uint32_t)0x000C0000)  /*!< LCD frequency = CLKPS/19 */
#define LCD_DIVIDER_20    ((uint32_t)0x00100000)  /*!< LCD frequency = CLKPS/20 */
#define LCD_DIVIDER_21    ((uint32_t)0x00140000)  /*!< LCD frequency = CLKPS/21 */
#define LCD_DIVIDER_22    ((uint32_t)0x00180000)  /*!< LCD frequency = CLKPS/22 */
#define LCD_DIVIDER_23    ((uint32_t)0x001C0000)  /*!< LCD frequency = CLKPS/23 */
#define LCD_DIVIDER_24    ((uint32_t)0x00200000)  /*!< LCD frequency = CLKPS/24 */
#define LCD_DIVIDER_25    ((uint32_t)0x00240000)  /*!< LCD frequency = CLKPS/25 */
#define LCD_DIVIDER_26    ((uint32_t)0x00280000)  /*!< LCD frequency = CLKPS/26 */
#define LCD_DIVIDER_27    ((uint32_t)0x002C0000)  /*!< LCD frequency = CLKPS/27 */
#define LCD_DIVIDER_28    ((uint32_t)0x00300000)  /*!< LCD frequency = CLKPS/28 */
#define LCD_DIVIDER_29    ((uint32_t)0x00340000)  /*!< LCD frequency = CLKPS/29 */
#define LCD_DIVIDER_30    ((uint32_t)0x00380000)  /*!< LCD frequency = CLKPS/30 */
#define LCD_DIVIDER_31    ((uint32_t)LCD_FCR_DIV) /*!< LCD frequency = CLKPS/31 */

#define IS_LCD_DIVIDER(__DIVIDER__) (((__DIVIDER__) == LCD_DIVIDER_16) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_17) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_18) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_19) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_20) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_21) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_22) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_23) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_24) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_25) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_26) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_27) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_28) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_29) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_30) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_31))

/**
  * @}
  */


/** @defgroup LCD_Duty LCD Duty
  * @{
  */
  
#define LCD_DUTY_STATIC                 ((uint32_t)0x00000000)            /*!< Static duty */
#define LCD_DUTY_1_2                    (LCD_CR_DUTY_0)                   /*!< 1/2 duty    */
#define LCD_DUTY_1_3                    (LCD_CR_DUTY_1)                   /*!< 1/3 duty    */
#define LCD_DUTY_1_4                    ((LCD_CR_DUTY_1 | LCD_CR_DUTY_0)) /*!< 1/4 duty    */
#define LCD_DUTY_1_8                    (LCD_CR_DUTY_2)                   /*!< 1/8 duty    */

#define IS_LCD_DUTY(__DUTY__) (((__DUTY__) == LCD_DUTY_STATIC)  || \
                               ((__DUTY__) == LCD_DUTY_1_2)     || \
                               ((__DUTY__) == LCD_DUTY_1_3)     || \
                               ((__DUTY__) == LCD_DUTY_1_4)     || \
                               ((__DUTY__) == LCD_DUTY_1_8))

/**
  * @}
  */ 
  

/** @defgroup LCD_Bias LCD Bias
  * @{
  */
  
#define LCD_BIAS_1_4                    ((uint32_t)0x00000000)  /*!< 1/4 Bias */
#define LCD_BIAS_1_2                    LCD_CR_BIAS_0           /*!< 1/2 Bias */
#define LCD_BIAS_1_3                    LCD_CR_BIAS_1           /*!< 1/3 Bias */

#define IS_LCD_BIAS(__BIAS__) (((__BIAS__) == LCD_BIAS_1_4) || \
                               ((__BIAS__) == LCD_BIAS_1_2) || \
                               ((__BIAS__) == LCD_BIAS_1_3))
/**
  * @}
  */ 
    
/** @defgroup LCD_Voltage_Source LCD Voltage Source
  * @{
  */
  
#define LCD_VOLTAGESOURCE_INTERNAL      ((uint32_t)0x00000000)  /*!< Internal voltage source for the LCD */
#define LCD_VOLTAGESOURCE_EXTERNAL      LCD_CR_VSEL             /*!< External voltage source for the LCD */

#define IS_LCD_VOLTAGE_SOURCE(SOURCE) (((SOURCE) == LCD_VOLTAGESOURCE_INTERNAL) || \
                                       ((SOURCE) == LCD_VOLTAGESOURCE_EXTERNAL))

/**
  * @}
  */  

/** @defgroup LCD_Interrupts LCD Interrupts
  * @{
  */
#define LCD_IT_SOF                      LCD_FCR_SOFIE
#define LCD_IT_UDD                      LCD_FCR_UDDIE

/**
  * @}
  */

/** @defgroup LCD_PulseOnDuration LCD Pulse On Duration
  * @{
  */

#define LCD_PULSEONDURATION_0           ((uint32_t)0x00000000)          /*!< Pulse ON duration = 0 pulse   */
#define LCD_PULSEONDURATION_1           (LCD_FCR_PON_0)                 /*!< Pulse ON duration = 1/CK_PS  */
#define LCD_PULSEONDURATION_2           (LCD_FCR_PON_1)                 /*!< Pulse ON duration = 2/CK_PS  */
#define LCD_PULSEONDURATION_3           (LCD_FCR_PON_1 | LCD_FCR_PON_0) /*!< Pulse ON duration = 3/CK_PS  */
#define LCD_PULSEONDURATION_4           (LCD_FCR_PON_2)                 /*!< Pulse ON duration = 4/CK_PS  */
#define LCD_PULSEONDURATION_5           (LCD_FCR_PON_2 | LCD_FCR_PON_0) /*!< Pulse ON duration = 5/CK_PS  */
#define LCD_PULSEONDURATION_6           (LCD_FCR_PON_2 | LCD_FCR_PON_1) /*!< Pulse ON duration = 6/CK_PS  */
#define LCD_PULSEONDURATION_7           (LCD_FCR_PON)                   /*!< Pulse ON duration = 7/CK_PS  */

#define IS_LCD_PULSE_ON_DURATION(__DURATION__) (((__DURATION__) == LCD_PULSEONDURATION_0) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_1) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_2) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_3) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_4) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_5) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_6) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_7))
/**
  * @}
  */


/** @defgroup LCD_DeadTime LCD Dead Time
  * @{
  */

#define LCD_DEADTIME_0                  ((uint32_t)0x00000000)            /*!< No dead Time  */
#define LCD_DEADTIME_1                  (LCD_FCR_DEAD_0)                  /*!< One Phase between different couple of Frame   */
#define LCD_DEADTIME_2                  (LCD_FCR_DEAD_1)                  /*!< Two Phase between different couple of Frame   */
#define LCD_DEADTIME_3                  (LCD_FCR_DEAD_1 | LCD_FCR_DEAD_0) /*!< Three Phase between different couple of Frame */
#define LCD_DEADTIME_4                  (LCD_FCR_DEAD_2)                  /*!< Four Phase between different couple of Frame  */
#define LCD_DEADTIME_5                  (LCD_FCR_DEAD_2 | LCD_FCR_DEAD_0) /*!< Five Phase between different couple of Frame  */
#define LCD_DEADTIME_6                  (LCD_FCR_DEAD_2 | LCD_FCR_DEAD_1) /*!< Six Phase between different couple of Frame   */
#define LCD_DEADTIME_7                  (LCD_FCR_DEAD)                    /*!< Seven Phase between different couple of Frame */

#define IS_LCD_DEAD_TIME(__TIME__) (((__TIME__) == LCD_DEADTIME_0) || \
                                    ((__TIME__) == LCD_DEADTIME_1) || \
                                    ((__TIME__) == LCD_DEADTIME_2) || \
                                    ((__TIME__) == LCD_DEADTIME_3) || \
                                    ((__TIME__) == LCD_DEADTIME_4) || \
                                    ((__TIME__) == LCD_DEADTIME_5) || \
                                    ((__TIME__) == LCD_DEADTIME_6) || \
                                    ((__TIME__) == LCD_DEADTIME_7))
/**
  * @}
  */

/** @defgroup LCD_BlinkMode LCD Blink Mode
  * @{
  */

#define LCD_BLINKMODE_OFF               ((uint32_t)0x00000000)  /*!< Blink disabled            */
#define LCD_BLINKMODE_SEG0_COM0         (LCD_FCR_BLINK_0)       /*!< Blink enabled on SEG[0], COM[0] (1 pixel)   */
#define LCD_BLINKMODE_SEG0_ALLCOM       (LCD_FCR_BLINK_1)       /*!< Blink enabled on SEG[0], all COM (up to 
                                                                    8 pixels according to the programmed duty)  */
#define LCD_BLINKMODE_ALLSEG_ALLCOM     (LCD_FCR_BLINK)         /*!< Blink enabled on all SEG and all COM (all pixels)  */

#define IS_LCD_BLINK_MODE(__MODE__) (((__MODE__) == LCD_BLINKMODE_OFF)            || \
                                     ((__MODE__) == LCD_BLINKMODE_SEG0_COM0)      || \
                                     ((__MODE__) == LCD_BLINKMODE_SEG0_ALLCOM)    || \
                                     ((__MODE__) == LCD_BLINKMODE_ALLSEG_ALLCOM))
/**
  * @}
  */    

/** @defgroup LCD_BlinkFrequency LCD Blink Frequency
  * @{
  */

#define LCD_BLINKFREQUENCY_DIV8         ((uint32_t)0x00000000)                /*!< The Blink frequency = fLCD/8    */
#define LCD_BLINKFREQUENCY_DIV16        (LCD_FCR_BLINKF_0)                    /*!< The Blink frequency = fLCD/16   */
#define LCD_BLINKFREQUENCY_DIV32        (LCD_FCR_BLINKF_1)                    /*!< The Blink frequency = fLCD/32   */
#define LCD_BLINKFREQUENCY_DIV64        (LCD_FCR_BLINKF_1 | LCD_FCR_BLINKF_0) /*!< The Blink frequency = fLCD/64   */
#define LCD_BLINKFREQUENCY_DIV128       (LCD_FCR_BLINKF_2)                    /*!< The Blink frequency = fLCD/128  */
#define LCD_BLINKFREQUENCY_DIV256       (LCD_FCR_BLINKF_2 |LCD_FCR_BLINKF_0)  /*!< The Blink frequency = fLCD/256  */
#define LCD_BLINKFREQUENCY_DIV512       (LCD_FCR_BLINKF_2 |LCD_FCR_BLINKF_1)  /*!< The Blink frequency = fLCD/512  */
#define LCD_BLINKFREQUENCY_DIV1024      (LCD_FCR_BLINKF)                      /*!< The Blink frequency = fLCD/1024 */

#define IS_LCD_BLINK_FREQUENCY(__FREQUENCY__) (((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV8)   || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV16)  || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV32)  || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV64)  || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV128) || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV256) || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV512) || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV1024))
/**
  * @}
  */

/** @defgroup LCD_Contrast LCD Contrast
  * @{
  */

#define LCD_CONTRASTLEVEL_0               ((uint32_t)0x00000000)        /*!< Maximum Voltage = 2.60V    */
#define LCD_CONTRASTLEVEL_1               (LCD_FCR_CC_0)                /*!< Maximum Voltage = 2.73V    */
#define LCD_CONTRASTLEVEL_2               (LCD_FCR_CC_1)                /*!< Maximum Voltage = 2.86V    */
#define LCD_CONTRASTLEVEL_3               (LCD_FCR_CC_1 | LCD_FCR_CC_0) /*!< Maximum Voltage = 2.99V    */
#define LCD_CONTRASTLEVEL_4               (LCD_FCR_CC_2)                /*!< Maximum Voltage = 3.12V    */
#define LCD_CONTRASTLEVEL_5               (LCD_FCR_CC_2 | LCD_FCR_CC_0) /*!< Maximum Voltage = 3.25V    */
#define LCD_CONTRASTLEVEL_6               (LCD_FCR_CC_2 | LCD_FCR_CC_1) /*!< Maximum Voltage = 3.38V    */
#define LCD_CONTRASTLEVEL_7               (LCD_FCR_CC)                  /*!< Maximum Voltage = 3.51V    */

#define IS_LCD_CONTRAST(__CONTRAST__) (((__CONTRAST__) == LCD_CONTRASTLEVEL_0) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_1) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_2) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_3) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_4) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_5) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_6) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_7))
/**
  * @}
  */
      
/** @defgroup LCD_MuxSegment LCD Mux Segment
  * @{
  */

#define LCD_MUXSEGMENT_DISABLE            ((uint32_t)0x00000000)        /*!< SEG pin multiplexing disabled */
#define LCD_MUXSEGMENT_ENABLE             (LCD_CR_MUX_SEG)              /*!< SEG[31:28] are multiplexed with SEG[43:40]    */

#define IS_LCD_MUXSEGMENT(__VALUE__) (((__VALUE__) == LCD_MUXSEGMENT_ENABLE) || \
                                      ((__VALUE__) == LCD_MUXSEGMENT_DISABLE))
/**
  * @}
  */
      
/** @defgroup LCD_Flag LCD Flag
  * @{
  */

#define LCD_FLAG_ENS                    LCD_SR_ENS
#define LCD_FLAG_SOF                    LCD_SR_SOF
#define LCD_FLAG_UDR                    LCD_SR_UDR
#define LCD_FLAG_UDD                    LCD_SR_UDD
#define LCD_FLAG_RDY                    LCD_SR_RDY
#define LCD_FLAG_FCRSF                  LCD_SR_FCRSR

/**
  * @}
  */   

/** @defgroup LCD_RAMRegister LCD RAMRegister
  * @{
  */

#define LCD_RAM_REGISTER0               ((uint32_t)0x00000000) /*!< LCD RAM Register 0  */
#define LCD_RAM_REGISTER1               ((uint32_t)0x00000001) /*!< LCD RAM Register 1  */
#define LCD_RAM_REGISTER2               ((uint32_t)0x00000002) /*!< LCD RAM Register 2  */
#define LCD_RAM_REGISTER3               ((uint32_t)0x00000003) /*!< LCD RAM Register 3  */
#define LCD_RAM_REGISTER4               ((uint32_t)0x00000004) /*!< LCD RAM Register 4  */
#define LCD_RAM_REGISTER5               ((uint32_t)0x00000005) /*!< LCD RAM Register 5  */
#define LCD_RAM_REGISTER6               ((uint32_t)0x00000006) /*!< LCD RAM Register 6  */
#define LCD_RAM_REGISTER7               ((uint32_t)0x00000007) /*!< LCD RAM Register 7  */
#define LCD_RAM_REGISTER8               ((uint32_t)0x00000008) /*!< LCD RAM Register 8  */
#define LCD_RAM_REGISTER9               ((uint32_t)0x00000009) /*!< LCD RAM Register 9  */
#define LCD_RAM_REGISTER10              ((uint32_t)0x0000000A) /*!< LCD RAM Register 10 */
#define LCD_RAM_REGISTER11              ((uint32_t)0x0000000B) /*!< LCD RAM Register 11 */
#define LCD_RAM_REGISTER12              ((uint32_t)0x0000000C) /*!< LCD RAM Register 12 */
#define LCD_RAM_REGISTER13              ((uint32_t)0x0000000D) /*!< LCD RAM Register 13 */
#define LCD_RAM_REGISTER14              ((uint32_t)0x0000000E) /*!< LCD RAM Register 14 */
#define LCD_RAM_REGISTER15              ((uint32_t)0x0000000F) /*!< LCD RAM Register 15 */

#define IS_LCD_RAM_REGISTER(__REGISTER__) (((__REGISTER__) == LCD_RAM_REGISTER0)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER1)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER2)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER3)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER4)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER5)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER6)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER7)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER8)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER9)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER10) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER11) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER12) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER13) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER14) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER15))

/**
  * @}
  */  
   
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup LCD_Exported_Macros LCD Exported Macros
  * @{
  */

/** @brief Reset LCD handle state
  * @param  __HANDLE__: specifies the LCD Handle.
  * @retval None
  */
#define __HAL_LCD_RESET_HANDLE_STATE(__HANDLE__)  ((__HANDLE__)->State = HAL_LCD_STATE_RESET)

/** @brief  macros to enables or disables the LCD
  * @param  __HANDLE__: specifies the LCD Handle.  
  * @retval None
  */     
#define __HAL_LCD_ENABLE(__HANDLE__)              (SET_BIT((__HANDLE__)->Instance->CR, LCD_CR_LCDEN))
#define __HAL_LCD_DISABLE(__HANDLE__)             (CLEAR_BIT((__HANDLE__)->Instance->CR, LCD_CR_LCDEN))

/** @brief  Macros to enable or disable the low resistance divider. Displays with high 
  *         internal resistance may need a longer drive time to achieve 
  *         satisfactory contrast. This function is useful in this case if some 
  *         additional power consumption can be tolerated.
  * @param  __HANDLE__: specifies the LCD Handle.
  * @note   When this mode is enabled, the PulseOn Duration (PON) have to be 
  *         programmed to 1/CK_PS (LCD_PULSEONDURATION_1).
  * @retval None
  */
#define __HAL_LCD_HIGHDRIVER_ENABLE(__HANDLE__)                                \
                              do{                                              \
                                  SET_BIT((__HANDLE__)->Instance->FCR, LCD_FCR_HD); \
                                  LCD_WaitForSynchro(__HANDLE__);              \
                                 }while(0)

#define __HAL_LCD_HIGHDRIVER_DISABLE(__HANDLE__)                               \
                              do{                                              \
                                  CLEAR_BIT((__HANDLE__)->Instance->FCR, LCD_FCR_HD); \
                                  LCD_WaitForSynchro(__HANDLE__);              \
                                 }while(0)

/**
  * @brief  Macro to configure the LCD pulses on duration.
  * @param  __HANDLE__: specifies the LCD Handle.
  * @param  __DURATION__: specifies the LCD pulse on duration in terms of 
  *         CK_PS (prescaled LCD clock period) pulses.
  *   This parameter can be one of the following values:
  *     @arg LCD_PULSEONDURATION_0: 0 pulse
  *     @arg LCD_PULSEONDURATION_1: Pulse ON duration = 1/CK_PS
  *     @arg LCD_PULSEONDURATION_2: Pulse ON duration = 2/CK_PS
  *     @arg LCD_PULSEONDURATION_3: Pulse ON duration = 3/CK_PS
  *     @arg LCD_PULSEONDURATION_4: Pulse ON duration = 4/CK_PS
  *     @arg LCD_PULSEONDURATION_5: Pulse ON duration = 5/CK_PS
  *     @arg LCD_PULSEONDURATION_6: Pulse ON duration = 6/CK_PS
  *     @arg LCD_PULSEONDURATION_7: Pulse ON duration = 7/CK_PS
  * @retval None
  */
#define __HAL_LCD_PULSEONDURATION_CONFIG(__HANDLE__, __DURATION__)                \
        do{                                                                       \
            MODIFY_REG((__HANDLE__)->Instance->FCR, LCD_FCR_PON, (__DURATION__)); \
            LCD_WaitForSynchro(__HANDLE__);                                       \
           }while(0)

/**
  * @brief  Macro to configure the LCD dead time.
  * @param  __HANDLE__: specifies the LCD Handle.
  * @param  __DEADTIME__: specifies the LCD dead time.
  *   This parameter can be one of the following values:
  *     @arg LCD_DEADTIME_0: No dead Time
  *     @arg LCD_DEADTIME_1: One Phase between different couple of Frame
  *     @arg LCD_DEADTIME_2: Two Phase between different couple of Frame
  *     @arg LCD_DEADTIME_3: Three Phase between different couple of Frame
  *     @arg LCD_DEADTIME_4: Four Phase between different couple of Frame
  *     @arg LCD_DEADTIME_5: Five Phase between different couple of Frame
  *     @arg LCD_DEADTIME_6: Six Phase between different couple of Frame 
  *     @arg LCD_DEADTIME_7: Seven Phase between different couple of Frame
  * @retval None
  */
#define __HAL_LCD_DEADTIME_CONFIG(__HANDLE__, __DEADTIME__)                        \
        do{                                                                        \
            MODIFY_REG((__HANDLE__)->Instance->FCR, LCD_FCR_DEAD, (__DEADTIME__)); \
            LCD_WaitForSynchro(__HANDLE__);                                        \
           }while(0)

/**
  * @brief  Macro to configure the LCD Contrast.
  * @param  __HANDLE__: specifies the LCD Handle.
  * @param  __CONTRAST__: specifies the LCD Contrast.
  *   This parameter can be one of the following values:
  *     @arg LCD_CONTRASTLEVEL_0: Maximum Voltage = 2.60V
  *     @arg LCD_CONTRASTLEVEL_1: Maximum Voltage = 2.73V
  *     @arg LCD_CONTRASTLEVEL_2: Maximum Voltage = 2.86V
  *     @arg LCD_CONTRASTLEVEL_3: Maximum Voltage = 2.99V
  *     @arg LCD_CONTRASTLEVEL_4: Maximum Voltage = 3.12V
  *     @arg LCD_CONTRASTLEVEL_5: Maximum Voltage = 3.25V
  *     @arg LCD_CONTRASTLEVEL_6: Maximum Voltage = 3.38V
  *     @arg LCD_CONTRASTLEVEL_7: Maximum Voltage = 3.51V
  * @retval None
  */
#define __HAL_LCD_CONTRAST_CONFIG(__HANDLE__, __CONTRAST__)                       \
        do{                                                                       \
            MODIFY_REG((__HANDLE__)->Instance->FCR, LCD_FCR_CC, (__CONTRAST__));  \
            LCD_WaitForSynchro(__HANDLE__);                                       \
           } while(0) 

/**
  * @brief  Macro to configure the LCD Blink mode and Blink frequency.
  * @param  __HANDLE__: specifies the LCD Handle.
  * @param  __BLINKMODE__: specifies the LCD blink mode.
  *   This parameter can be one of the following values:
  *     @arg LCD_BLINKMODE_OFF:           Blink disabled
  *     @arg LCD_BLINKMODE_SEG0_COM0:     Blink enabled on SEG[0], COM[0] (1 pixel)
  *     @arg LCD_BLINKMODE_SEG0_ALLCOM:   Blink enabled on SEG[0], all COM (up to 8 
  *                                       pixels according to the programmed duty)
  *     @arg LCD_BLINKMODE_ALLSEG_ALLCOM: Blink enabled on all SEG and all COM 
  *                                       (all pixels)
  * @param  __BLINKFREQUENCY__: specifies the LCD blink frequency.
  *     @arg LCD_BLINKFREQUENCY_DIV8:    The Blink frequency = fLcd/8
  *     @arg LCD_BLINKFREQUENCY_DIV16:   The Blink frequency = fLcd/16
  *     @arg LCD_BLINKFREQUENCY_DIV32:   The Blink frequency = fLcd/32
  *     @arg LCD_BLINKFREQUENCY_DIV64:   The Blink frequency = fLcd/64 
  *     @arg LCD_BLINKFREQUENCY_DIV128:  The Blink frequency = fLcd/128
  *     @arg LCD_BLINKFREQUENCY_DIV256:  The Blink frequency = fLcd/256
  *     @arg LCD_BLINKFREQUENCY_DIV512:  The Blink frequency = fLcd/512
  *     @arg LCD_BLINKFREQUENCY_DIV1024: The Blink frequency = fLcd/1024
  * @retval None
  */
#define __HAL_LCD_BLINK_CONFIG(__HANDLE__, __BLINKMODE__, __BLINKFREQUENCY__)  \
        do{                                                                    \
            MODIFY_REG((__HANDLE__)->Instance->FCR, (LCD_FCR_BLINKF | LCD_FCR_BLINK), ((__BLINKMODE__) | (__BLINKFREQUENCY__))); \
            LCD_WaitForSynchro(__HANDLE__);                                    \
          }while(0)

/** @brief  Enables or disables the specified LCD interrupt.
  * @param  __HANDLE__: specifies the LCD Handle.
  * @param  __INTERRUPT__: specifies the LCD interrupt source to be enabled or disabled.
  *          This parameter can be one of the following values:
  *     @arg LCD_IT_SOF: Start of Frame Interrupt
  *     @arg LCD_IT_UDD: Update Display Done Interrupt
  * @retval None
  */
#define __HAL_LCD_ENABLE_IT(__HANDLE__, __INTERRUPT__)                                \
                         do{                                                          \
                             SET_BIT((__HANDLE__)->Instance->FCR, (__INTERRUPT__));   \
                             LCD_WaitForSynchro(__HANDLE__);                          \
                            }while(0)         
#define __HAL_LCD_DISABLE_IT(__HANDLE__, __INTERRUPT__)                               \
                         do{                                                          \
                             CLEAR_BIT((__HANDLE__)->Instance->FCR, (__INTERRUPT__)); \
                             LCD_WaitForSynchro(__HANDLE__);                          \
                            }while(0)

/** @brief  Checks whether the specified LCD interrupt is enabled or not.
  * @param  __HANDLE__: specifies the LCD Handle.
  * @param  __IT__: specifies the LCD interrupt source to check.
  *        This parameter can be one of the following values:
  *        @arg LCD_IT_SOF: Start of Frame Interrupt
  *        @arg LCD_IT_UDD: Update Display Done Interrupt.
  * @note If the device is in STOP mode (PCLK not provided) UDD will not 
  *          generate an interrupt even if UDDIE = 1. 
  *          If the display is not enabled the UDD interrupt will never occur.
  * @retval The state of __IT__ (TRUE or FALSE).
  */
#define __HAL_LCD_GET_IT_SOURCE(__HANDLE__, __IT__) (((__HANDLE__)->Instance->FCR) & (__IT__))

/** @brief  Checks whether the specified LCD flag is set or not.
  * @param  __HANDLE__: specifies the LCD Handle.
  * @param  __FLAG__: specifies the flag to check.
  *        This parameter can be one of the following values:
  *        @arg LCD_FLAG_ENS: LCD Enabled flag. It indicates the LCD controller status.
  * @note  The ENS bit is set immediately when the LCDEN bit in the LCD_CR 
  *             goes from 0 to 1. On deactivation it reflects the real status of 
  *             LCD so it becomes 0 at the end of the last displayed frame.  
  *        @arg LCD_FLAG_SOF: Start of Frame flag. This flag is set by hardware at 
  *             the beginning of a new frame, at the same time as the display data is 
  *             updated.
  *        @arg LCD_FLAG_UDR: Update Display Request flag.
  *        @arg LCD_FLAG_UDD: Update Display Done flag. 
  *        @arg LCD_FLAG_RDY: Step_up converter Ready flag. It indicates the status 
  *             of the step-up converter.
  *        @arg LCD_FLAG_FCRSF: LCD Frame Control Register Synchronization Flag. 
  *             This flag is set by hardware each time the LCD_FCR register is updated 
  *             in the LCDCLK domain. 
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_LCD_GET_FLAG(__HANDLE__, __FLAG__)    (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))   

/** @brief  Clears the specified LCD pending flag.
  * @param  __HANDLE__: specifies the LCD Handle.
  * @param  __FLAG__: specifies the flag to clear.
  *        This parameter can be any combination of the following values:
  *        @arg LCD_FLAG_SOF: Start of Frame Interrupt
  *        @arg LCD_FLAG_UDD: Update Display Done Interrupt
  * @retval None
  */
#define __HAL_LCD_CLEAR_FLAG(__HANDLE__, __FLAG__)  ((__HANDLE__)->Instance->CLR = (__FLAG__))

/**
  * @}
  */
  
/* Exported functions ------------------------------------------------------- */

/** @addtogroup LCD_Exported_Functions
  * @{
  */

/** @addtogroup LCD_Exported_Functions_Group1
  * @{
  */

/* Initialization/de-initialization methods  **********************************/
HAL_StatusTypeDef     HAL_LCD_DeInit(LCD_HandleTypeDef *hlcd);
HAL_StatusTypeDef     HAL_LCD_Init(LCD_HandleTypeDef *hlcd);
void                  HAL_LCD_MspInit(LCD_HandleTypeDef *hlcd);
void                  HAL_LCD_MspDeInit(LCD_HandleTypeDef *hlcd);

/**
  * @}
  */

/** @addtogroup LCD_Exported_Functions_Group2
  * @{
  */

/* IO operation methods *******************************************************/
HAL_StatusTypeDef     HAL_LCD_Write(LCD_HandleTypeDef *hlcd, uint32_t RAMRegisterIndex, uint32_t RAMRegisterMask, uint32_t Data);
HAL_StatusTypeDef     HAL_LCD_Clear(LCD_HandleTypeDef *hlcd);
HAL_StatusTypeDef     HAL_LCD_UpdateDisplayRequest(LCD_HandleTypeDef *hlcd);

/**
  * @}
  */

/** @addtogroup LCD_Exported_Functions_Group3
  * @{
  */

/* Peripheral State methods  **************************************************/
HAL_LCD_StateTypeDef  HAL_LCD_GetState(LCD_HandleTypeDef *hlcd);
uint32_t              HAL_LCD_GetError(LCD_HandleTypeDef *hlcd);

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup LCD_Private_Functions
  * @{
  */

/* Private functions ---------------------------------------------------------*/
HAL_StatusTypeDef     LCD_WaitForSynchro(LCD_HandleTypeDef *hlcd);

/**
  * @}
  */

/**
  * @}
  */

#endif /* STM32L100xB || STM32L100xBA || STM32L100xC ||... || STM32L162xD || STM32L162xE || STM32L162xDX */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L1xx_HAL_LCD_H */

/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
