/**
  ******************************************************************************
  * @file    RAND/RandBytesGen/Src/main.c
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
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Entropy String. Uniformly distributed random bit string 1*/
uint8_t entropy_data[32] = {
                             0x9d, 0x20, 0x1a, 0x18, 0x9b, 0x6d, 0x1a, 0xa7, 0x0e,
                             0x79, 0x57, 0x6f, 0x36, 0xb6, 0xaa, 0x88, 0x55, 0xfd,
                             0x4a, 0x7f, 0x97, 0xe9, 0x71, 0x69, 0xb6, 0x60, 0x88,
                             0x78, 0xe1, 0x9c, 0x8b, 0xa5
                           };
/* Nonce. Non repeating sequence, such as a timestamp */
uint8_t nonce[] = {0xFE, 0xA9, 0x96, 0xD4, 0x62, 0xC5};
/* Personalization String */
uint8_t personalization_String[] = {0x1E, 0x6C, 0x7B, 0x82, 0xE5, 0xA5, 0x71, 0x8D};
/* Structure that will keep the Random State */
RNGstate_stt RNGstate;

/* Array that will be filled with random bytes */
uint8_t RandomString[32] = {0, };

static GPIO_InitTypeDef  GPIO_InitStruct;


/* Private function prototypes -----------------------------------------------*/
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

  /* Strucutre used to call the Random engine inizialition */
  RNGinitInput_stt RNGinit_st;
  
  int32_t status = RNG_SUCCESS;

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

  /* Set the values of EntropyData, Nonce, Personalization String and their sizes inside the RNGinit_st structure */
  RNGinit_st.pmEntropyData = entropy_data;
  RNGinit_st.mEntropyDataSize = sizeof(entropy_data);
  RNGinit_st.pmNonce =  nonce;
  RNGinit_st.mNonceSize = sizeof( nonce );
  RNGinit_st.pmPersData = personalization_String;
  RNGinit_st.mPersDataSize = sizeof( personalization_String );

  status = RNGinit(&RNGinit_st,&RNGstate); 
  if  ( status == RNG_SUCCESS )
  {
    /* The Random engine has been initialized, the status is in RNGstate */

    /* Now fill the random string with random bytes */
    status = RNGgenBytes(&RNGstate, NULL, RandomString, sizeof(RandomString));

    if (status == RNG_SUCCESS)
    {
      /* Random Generated Succefully, free the state before returning */
     status = RNGfree(&RNGstate);
        if  ( status == RNG_SUCCESS )
        {
        
        }
        else
        {
      Error_Handler();
        }
      
      
    }
    else
    {
      /* In case of randomization not success possible values of status:
       * RNG_ERR_BAD_PARAMETER, RNG_ERR_UNINIT_STATE
       */

      Error_Handler();
    }

  }
  else
  {
    /* In case of randomization not success possible values of status:
     * RNG_ERR_BAD_ENTROPY_SIZE, RNG_ERR_BAD_PERS_STRING_SIZE
     */
  
      Error_Handler();
  }

  /* Turn on the green led in case of RANDOM operations are successful*/
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);
	while (1)
	{
	}
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
