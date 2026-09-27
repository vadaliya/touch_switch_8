/***********************************************************************************************************************
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
************************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : qe_touch_define.h
* Description  : This file includes definitions.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History      : MM/DD/YYYY Version Description
*              : 09/02/2019 1.00    First Release
*              : 12/26/2019 1.10    Corresponding for FSP V0.10.0
*              : 01/16/2020 1.11    Adding "Button State Mask" macros
*              : 02/20/2020 1.20    Corresponding for FSP V0.12.0
*              : 03/04/2020 1.21    Corresponding for FSP V1.0.0 RC0
*              : 06/26/2020 1.22    Corresponding for FSP V1.1.0
*              : 09/10/2020 1.30    Corresponding for FSP V2.0.0 Beta2
*              : 05/26/2021 1.40    Adding Diagnosis Supporting
*              : 06/01/2021 1.41    Fixing a Little
*              : 11/17/2021 1.50    Adding information for Initial Offset Tuning
*              : 12/06/2021 1.51    Fixing a Little
*              : 09/05/2022 1.52    Fixing a Little
*              : 03/23/2023 1.60    Adding 3 Frequency Judgement Supporting
*              : 03/31/2023 1.61    Improving Traceability
*              : 07/25/2024 1.70    Adding Auto Correction / Auto Multi Clock Correction / MEC Supporting
*              : 09/04/2024 1.71    Adding version info macro of QE
*              : 12/06/2024 1.72    Adding macro for auto judgment
***********************************************************************************************************************/
/***********************************************************************************************************************
* Touch I/F Configuration File  : g_touch0.tifcfg
***********************************************************************************************************************/

#ifndef QE_TOUCH_DEFINE_H
#define QE_TOUCH_DEFINE_H


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define QE_TOUCH_VERSION             (0x0440)


#define QE_TOUCH_MACRO_UART_TUNNING_AS_1METHOD (0)
#define CTSU_CFG_NUM_SELF_ELEMENTS   (8 + QE_TOUCH_MACRO_UART_TUNNING_AS_1METHOD)
#define CTSU_CFG_NUM_MUTUAL_ELEMENTS (0)
#define CTSU_CFG_NUM_CFC             (0)
#define CTSU_CFG_NUM_CFC_TX          (0)

#define TOUCH_CFG_MONITOR_ENABLE (1)
#define TOUCH_CFG_NUM_BUTTONS    (8)
#define TOUCH_CFG_NUM_SLIDERS    (0)
#define TOUCH_CFG_NUM_WHEELS     (0)
#define TOUCH_CFG_PAD_ENABLE     (0)

#define QE_TOUCH_MACRO_CTSU_IP_KIND (2)

#define CTSU_CFG_VCC_MV           (3300)
#define CTSU_CFG_LOW_VOLTAGE_MODE (0)

#define CTSU_CFG_PCLK_DIVISION (0)

#define CTSU_CFG_TSCAP_PORT (0x010C)

#define CTSU_CFG_NUM_SUMULTI   (3)
#define CTSU_CFG_SUMULTI0      (0x3F)
#define CTSU_CFG_SUMULTI1      (0x36)
#define CTSU_CFG_SUMULTI2      (0x48)

#define CTSU_CFG_CALIB_RTRIM_SUPPORT       (0)
#define CTSU_CFG_TEMP_CORRECTION_SUPPORT   (0)
#define CTSU_CFG_TEMP_CORRECTION_TS        (0)
#define CTSU_CFG_TEMP_CORRECTION_TIME      (0)



#define CTSU_CFG_TARGET_VALUE_QE_SUPPORT (1)





#define CTSU_CFG_MAJORITY_MODE (1)
#define CTSU_CFG_NUM_AUTOJUDGE_SELF_ELEMENTS   (0)
#define CTSU_CFG_NUM_AUTOJUDGE_MUTUAL_ELEMENTS (0)

/***********************************************************************************************************************
Button State Mask for each configuration.
***********************************************************************************************************************/
#define CONFIG01_INDEX_SW1     (6)
#define CONFIG01_MASK_SW1      (1ULL << CONFIG01_INDEX_SW1)
#define CONFIG01_INDEX_SW2     (7)
#define CONFIG01_MASK_SW2      (1ULL << CONFIG01_INDEX_SW2)
#define CONFIG01_INDEX_SW3     (5)
#define CONFIG01_MASK_SW3      (1ULL << CONFIG01_INDEX_SW3)
#define CONFIG01_INDEX_SW4     (4)
#define CONFIG01_MASK_SW4      (1ULL << CONFIG01_INDEX_SW4)
#define CONFIG01_INDEX_SW5     (1)
#define CONFIG01_MASK_SW5      (1ULL << CONFIG01_INDEX_SW5)
#define CONFIG01_INDEX_SW6     (3)
#define CONFIG01_MASK_SW6      (1ULL << CONFIG01_INDEX_SW6)
#define CONFIG01_INDEX_SW7     (0)
#define CONFIG01_MASK_SW7      (1ULL << CONFIG01_INDEX_SW7)
#define CONFIG01_INDEX_SW8     (2)
#define CONFIG01_MASK_SW8      (1ULL << CONFIG01_INDEX_SW8)

#endif /* QE_TOUCH_DEFINE_H */
