/**
  ******************************************************************************
  * @file    bsp_system.c
  * @author  Benedek Kupper
  * @version 1.0
  * @date    2018-03-10
  * @brief   DebugDongle BSP for system clocking
  *
  * Copyright (c) 2018 Benedek Kupper
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *     http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  */
#include <xpd_rcc.h>
#include <xpd_crs.h>

#include <bsp_system.h>

static const CRS_InitType crsSetup = {
    .Source     = CRS_SYNC_SOURCE_USB,
    .ErrorLimit = CRS_ERRORLIMIT_DEFAULT,
};

/** @brief System clocks configuration */
void SystemClock_Config(void)
{
    /* HSI48 configuration */
    RCC_eHSI48_Enable();
    CRS_vInit(&crsSetup);

    /* System clocks configuration */
    RCC_eHCLK_Config(HSI48, CLK_DIV1, 1);

    RCC_vPCLK1_Config(CLK_DIV1);
}
