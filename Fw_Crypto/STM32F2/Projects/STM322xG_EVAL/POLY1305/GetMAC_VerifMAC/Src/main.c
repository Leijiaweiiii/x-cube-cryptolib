/**
  ******************************************************************************
  * @file    POlY1305/GetMAC_VerifMAC/Src/main.c
  * @author  MCD Application Team
  * @version V3.1.0
  * @date    30-October-2015
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/** @addtogroup STM32_Crypto_Examples
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

const uint8_t Key[] = 
{
  0xec, 0x07, 0x4c, 0x83, 0x55, 0x80, 0x74, 0x17, 
  0x01, 0x42, 0x5b, 0x62, 0x32, 0x35, 0xad, 0xd6,
  0x85, 0x1f, 0xc4, 0x0c, 0x34, 0x67, 0xac, 0x0b, 
  0xe0, 0x5c, 0xc2, 0x04, 0x04, 0xf3, 0xf7, 0x00
};
const uint8_t Nonce[] = 
  { 
  0xfb, 0x44, 0x73, 0x50, 0xc4, 0xe8, 0x68, 0xc5, 
  0x2a, 0xc3, 0x27, 0x5c, 0xf9, 0xd4, 0x32, 0x7e 
  };
const uint8_t Input[] = { 0xf3, 0xf6 };


/* Buffer to store the output data */
uint8_t OutputMessage[16];

/* Size of the output data */
uint32_t OutputMessageLength = 0;

const uint8_t Expected_Result[] =
  {
    0xf4, 0xc6, 0x33, 0xc3, 0x04, 0x4f, 0xc1, 0x45, 
    0xf8, 0x4f, 0x33, 0x5c, 0xb8, 0x19, 0x53, 0xde
  };

static GPIO_InitTypeDef  GPIO_InitStruct;

/* Private function prototypes -----------------------------------------------*/
int32_t STM32_POLY1305_GET_MAC(const uint8_t *input, 
                       const uint8_t *key,
                       const uint8_t *nonce, 
                       int32_t inputSize, 
                       uint8_t  *OutputMessage,
                       uint32_t *OutputMessageLength);
int32_t STM32_POLY1305_VERIFY_MAC
                        (const uint8_t *input, 
                         const uint8_t *key, 
                         const uint8_t *nonce, 
                         int32_t inputSize, 
                         const uint8_t *expectedResult);


TestStatus Buffercmp(const uint8_t* pBuffer,
                     uint8_t* pBuffer1,
                     uint16_t BufferLength);

static void SystemClock_Config(void);
static void Led_Config(void);
static void Led_Toggle(uint32_t toggle_delay);
static void Error_Handler(void);                     
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{

  int32_t status = POLY1305_SUCCESS;

  /* STM32F2xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
     */
  HAL_Init();
  
  /* Configure the system clock to 64 MHz */
  SystemClock_Config(); 
  
  /* Configure the green led */
  Led_Config();
  
  /* Toggle the green led before starting the algorithm */
  Led_Toggle(500);
  
    
  /* Enable CRC clock */
   __CRC_CLK_ENABLE();  


  status = STM32_POLY1305_GET_MAC(Input, 
                             Key, 
                             Nonce, 
                             sizeof(Input),
                             OutputMessage,
                             &OutputMessageLength);

  
  if (status == POLY1305_SUCCESS)
  {
    if ((Buffercmp(Expected_Result, OutputMessage, 16) == PASSED) || OutputMessageLength == 16)
    {
      /* add application traitment in case of POLY1305 encryption is passed */    
      
    }
    else
    {
      

      Error_Handler();
     
    }
  }
  else
  {
    /* In case of POLY1305 encryption not success possible values of status:
       * POLY1305_ERR_BAD_CONTEXT, POLY1305_ERR_BAD_PARAMETER, POLY1305_ERR_BAD_OPERATION
       */

      Error_Handler();  
  }
  status = STM32_POLY1305_VERIFY_MAC(Input,
                               Key, 
                               Nonce, 
                               sizeof(Input), 
                               OutputMessage);
  
  if (status == AUTHENTICATION_SUCCESSFUL)
  {
      /* add application traitment in case of POLY1305 authentication is successful */

  }
  else
  {
    /* In case of POLY1305 authentication is failed possible values of status:
       * POLY1305_ERR_BAD_CONTEXT, POLY1305_ERR_BAD_PARAMETER, POLY1305_ERR_BAD_OPERATION, 
       * AUTHENTICATION_FAILED*/ 
             
      Error_Handler();       
  }

  /* Turn on the green led in case of POLY1305 operations are successful*/
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);
	while (1)
	{
	}
}

/**
* @brief  Function to test the TAG Generation Functionalities of Poly1305-AES
* @param[in]  *input          Input message to be authenticated
* @param[in]  *key            Key 
* @param[in]  *nonce          Nonce
* @param[in]   inputSize      Size of input
* @retval error status: can be POLY1305_SUCCESS if success or one of
*         POLY1305_ERR_BAD_CONTEXT, POLY1305_ERR_BAD_PARAMETER, POLY1305_ERR_BAD_OPERATION
*         if error occured.
*/
int32_t STM32_POLY1305_GET_MAC(const uint8_t *input, const uint8_t *key, const uint8_t *nonce, int32_t inputSize, uint8_t  *OutputMessage,
                        uint32_t *OutputMessageLength)
{

  int32_t outputLength = 16;
  Poly1305ctx_stt polyctx;
  uint32_t error_status = POLY1305_SUCCESS;
  

  /* Initialize Context by setting the size of the required TAG */
  polyctx.mTagSize = 16;

  /* Initialize operation */
  error_status = Poly1305_Auth_Init(&polyctx, key, nonce);
  
  if (error_status == POLY1305_SUCCESS)
  {
   error_status = Poly1305_Auth_Append(&polyctx, 
                                        input, 
                                        inputSize); 
   
   
   if (error_status == POLY1305_SUCCESS)
      {
        
       error_status = Poly1305_Auth_Finish(&polyctx, OutputMessage , &outputLength);
       
      }
  }
   
  return error_status;
}


/**
* @brief  Function to test the TAG Verification Functionalities of Poly1305-AES
* @param[in]  *input          Input message to be authenticated
* @param[in]  *key            Key
* @param[in]  *nonce          Nonce
* @param[in]   inputSize      Size of input
* @param[in]  *expectedResult Expected Result, used in verification
* @retval error status: can be AUTHENTICATION_SUCCESSFUL if success or one of
*         POLY1305_ERR_BAD_CONTEXT, POLY1305_ERR_BAD_PARAMETER, POLY1305_ERR_BAD_OPERATION, AUTHENTICATION_FAILED
*         if error occured.
*/
int32_t STM32_POLY1305_VERIFY_MAC(const uint8_t *input, const uint8_t *key, const uint8_t *nonce, int32_t inputSize, const uint8_t *expectedResult)
{
  uint32_t error_status ;
  Poly1305ctx_stt polyctx;

  /* Initialize Context by setting the size of the required TAG and pointer to TAG to be verified */
  polyctx.mTagSize = 16;  
  polyctx.pmTag = expectedResult;

  /* Initialize operation */
  error_status = Poly1305_Verify_Init(&polyctx, key, nonce);
  if (error_status == POLY1305_SUCCESS)
  {
    error_status = Poly1305_Verify_Append(&polyctx, input, inputSize);
    
    if (error_status == POLY1305_SUCCESS)
    {
     /* Generate TAG */
      error_status = Poly1305_Verify_Finish(&polyctx, NULL, NULL);
    }

  }
  return error_status;
}


/**
  * @brief  Compares two buffers.
  * @param  pBuffer, pBuffer1: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval PASSED: pBuffer identical to pBuffer1
  *         FAILED: pBuffer differs from pBuffer1
  */
TestStatus Buffercmp(const uint8_t* pBuffer, uint8_t* pBuffer1, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if (*pBuffer != *pBuffer1)
    {
      return FAILED;
    }

    pBuffer++;
    pBuffer1++;
  }

  return PASSED;
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 120000000
  *            HCLK(Hz)                       = 120000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 240
  *            PLL_P                          = 2
  *            PLL_Q                          = 5
  *            VDD(V)                         = 3.3
  *            Flash Latency(WS)              = 3
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 240;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 5;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3);
}

/**
  * @brief  Configures the green led.
  * @param  None
  * @retval None
  */
static void Led_Config(void)
{
    /* -1- Enable each GPIO Clock (to be able to program the configuration registers) */
  __GPIOG_CLK_ENABLE();

  /* -2- Configure IOs in output push-pull mode to drive external LEDs */
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct); 
  
}

/**
  * @brief  Toggles the green led three times.
  * @param[in]  toggle_delay : toggle frequency
  * @retval None
  */
static void Led_Toggle(uint32_t toggle_delay)
{
      HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
      HAL_Delay(toggle_delay);      
      HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
      HAL_Delay(toggle_delay);
      HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
      HAL_Delay(toggle_delay);
      HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
      HAL_Delay(toggle_delay);
      HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
      HAL_Delay(toggle_delay);
      HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
      HAL_Delay(toggle_delay);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  Led_Toggle(250);
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/**
  * @}
  */


/******************* (C) COPYRIGHT 2015 STMicroeleCCMonics *****END OF FILE****/

