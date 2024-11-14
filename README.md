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
```
终于，我把artinchip的d133cbs跑通了tflm 2.4.0 micro_speech了，一度想放弃，
后来发现可以通过注释INIT_APP_EXPORT(lvgl_thread_init);来节省内存使用，
这样就能跑起来（运行的时候屏幕会显示彩色格子而非LVGL表盘），
比较过和h743的输出结果相同，1000次循环时间大概是27秒，
相当于stm32h743的2倍（13秒），不过也难怪，
因为这是同时运行了rt-thread的其他线程，可能实际还能更快，
相关代码我有空会开源到gh上
```

## Failed codes    
* I try to run the project https://github.com/QingChuanWS/TensorflowLiteMicro failed, see failed/helloworld_v3.1_no_recog_output.7z    
