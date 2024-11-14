# d133cbs_playground
[WIP] My ArtInChip D133CBS 7inch EVM playground for tflite-micro micro_speech and etc.

## How to build  
* Luban-lite v1.0.3  
git clone https://gitee.com/artinchip/luban-lite   
cd luban-lite  
git checkout -f 9f7ba670073271e4fcf876d4e020008e240096cf  
see artinchip_20240203_luban-lite-master.zip  
HEAD is now at 9f7ba670 v1.0.3  
* Replace luban-lite-master/application/rt-thread/helloworld with the helloworld folder, like sai_no_mic/helloworld    
* Comment the line '//INIT_APP_EXPORT(lvgl_thread_init);' in packages/artinchip/lv_demo.c to reduce the ram usage.  
* Execute win_env.bat and scons --apply-def=d13x_demo88-nor_rt-thread_helloworld_defconfig and scons -j8 to build (see scons --help, same as scons --apply-def=18)   
* Execute scons --menuconfig to config (not necessary)    
* Burn the file output/d13x_demo88-nor_rt-thread_helloworld/images/d13x_demo88-nor_v1.0.0.img with AiBurn    
see https://gitee.com/artinchip/tools  

## Failed codes    
* I try to run the project https://github.com/QingChuanWS/TensorflowLiteMicro failed, see failed/helloworld_v3.1_no_recog_output.7z    
