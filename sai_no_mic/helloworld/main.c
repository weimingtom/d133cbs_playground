/*
 * Copyright (c) 2022, ArtInChip Technology Co., Ltd
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Authors: weilin.peng@artinchip.com
 */

#include <rtthread.h>
#include <stdio.h>

#ifdef AIC_AB_SYSTEM_INTERFACE
#include <absystem.h>
#include <stdlib.h>
#include <stdio.h>
#include <dfs.h>
#include <dfs_fs.h>
#endif

#ifdef __cplusplus
extern "C"{ 
#endif

void * __dso_handle = 0;

#ifdef __cplusplus
}
#endif

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
//#include "tensorflow/lite/micro/examples/micro_speech/main_functions.h"
#include "./tflm/src/main_functions.h"

// This is the default main used on systems that have the standard C entry
// point. Other devices (for example FreeRTOS or ESP32) that have different
// requirements for entry code (like an app_main function) should specialize
// this main.cc file in a target-specific subfolder.
int main_(int argc, char* argv[]) {
  setup();
  //rt_kprintf("model load successfully!!\n");
   for (int i =0; i<1000; ++i) { //while (1) {
     loop();
   }

  return 0;
}

int main(void)
{
//luban-lite-master_v1.7z
//artinchip_20240203_luban-lite-master.zip
printf("Sai Demo Start...\n");
main_(0, 0);

#ifdef AIC_AB_SYSTEM_INTERFACE
    char target[32] = { 0 };

    aic_ota_status_update();
    aic_get_rodata_to_mount(target);
    printf("Mount APP in blk %s\n", target);

    if (dfs_mount(target, "/rodata", "elm", 0, 0) < 0)
        printf("Failed to mount elm\n");
#endif
    return 0;
}
