/**
  ******************************************************************************
  * @file    hmac_sha224.h
  * @author  MCD Application Team
  * @version V3.0.0
  * @date    05-June-2015
  * @brief   Provides HMAC-SHA224 functions
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Image SW License Agreement V2, (the "License");
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CRL_HMAC_SHA224_H__
#define __CRL_HMAC_SHA224_H__

#ifdef __cplusplus
extern "C"
{
#endif

  /* Includes ------------------------------------------------------------------*/

  /** @ingroup HMAC_SHA224
    * @{
    */

  /**
    * @brief  HMAC-SHA-224 Context Structure
    */
  /* Exported constants --------------------------------------------------------*/
  /* Exported types ------------------------------------------------------------*/
  typedef HMACctx_stt HMAC_SHA224ctx_stt;


  /* Exported macro ------------------------------------------------------------*/
  /* Exported functions ------------------------------------------------------- */

  int32_t HMAC_SHA224_Init   (HMAC_SHA224ctx_stt *P_pHMAC_SHA224ctx);

  int32_t HMAC_SHA224_Append (HMAC_SHA224ctx_stt *P_pHMAC_SHA224ctx, \
                              const uint8_t *P_pInputBuffer,        \
                              int32_t P_inputSize);

  int32_t HMAC_SHA224_Finish (HMAC_SHA224ctx_stt *P_pHMAC_SHA224ctx, \
                              uint8_t *P_pOutputBuffer,             \
                              int32_t *P_pOutputSize);

  /**
    * @}
    */


#ifdef __cplusplus
}
#endif

#endif   /* __CRL_HMAC_SHA224_H__ */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
