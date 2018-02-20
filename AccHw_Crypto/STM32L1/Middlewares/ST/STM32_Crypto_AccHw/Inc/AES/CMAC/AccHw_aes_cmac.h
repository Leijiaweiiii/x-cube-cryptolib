/**
  ******************************************************************************
  * @file    AccHw_aes_cmac.h
  * @author  MCD Application Team
  * @version V3.1.0
  * @date    30-October-2015
  * @brief   AES in CMAC Mode
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
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
  *****************************************************************************/

#ifndef __CRL_AccHw_AES_CMAC_H__
#define __CRL_AccHw_AES_CMAC_H__

#ifdef __cplusplus
 extern "C" {
#endif

/** @ingroup AESCMAC
  * @{
  */

typedef struct
{
  uint32_t   mContextId;   /*!< Unique ID of this context. \b Not \b used in current implementation. */  
  AccHw_SKflags_et mFlags; /*!< 32 bit mFlags, used to perform keyschedule, choose betwen hw/sw and future use */  
  const uint8_t *pmKey; /*!< Pointer to original Key buffer */  
  const uint8_t *pmIv; /*!< Pointer to original Initialization Vector buffer */  
  int32_t   mIvSize; /*!< Size of the Initialization Vector in bytes */  
  uint32_t   amIv[4]; /*!< Temporary result/IV */
  int32_t   mKeySize;   /*!< Key length in bytes */
  uint32_t   amExpKey[AccHw_CRL_AES_MAX_EXPKEY_SIZE];   /*!< Expanded AES key */
  const uint8_t *pmTag;   /*!< Pointer to Authentication TAG. This value must be set in decryption, and this TAG will be verified */  
  int32_t mTagSize; /*!< Size of the Tag to return. This must be set by the caller prior to calling Init */
} AccHw_AESCMACctx_stt; /*<! AES context structure for CMAC mode */


int32_t  AccHw_AES_CMAC_Encrypt_Init(AccHw_AESCMACctx_stt *P_pAESCMACctx);

int32_t  AccHw_AES_CMAC_Encrypt_Append (AccHw_AESCMACctx_stt *P_pAESCMACctx,
                        const uint8_t *P_pInputBuffer,
                        int32_t        P_inputSize);

int32_t  AccHw_AES_CMAC_Encrypt_Finish (AccHw_AESCMACctx_stt *P_pAESCMACctx,
                                uint8_t       *P_pOutputBuffer,
                                int32_t       *P_pOutputSize);

int32_t  AccHw_AES_CMAC_Decrypt_Init(AccHw_AESCMACctx_stt *P_pAESCMACctx);

int32_t  AccHw_AES_CMAC_Decrypt_Append (AccHw_AESCMACctx_stt *P_pAESCMACctx,
                        const uint8_t *P_pInputBuffer,
                        int32_t        P_inputSize);

int32_t  AccHw_AES_CMAC_Decrypt_Finish (AccHw_AESCMACctx_stt *P_pAESCMACctx,
                                uint8_t       *P_pOutputBuffer,
                                int32_t       *P_pOutputSize);


 /**
  * @}  
  */
 
#ifdef __cplusplus
}
#endif
 
#endif /* __CRL_AccHw_AES_CMAC_H__ */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
