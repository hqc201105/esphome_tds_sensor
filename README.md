# esphome_tds_sensor
本项目可在home assistanct中显示纯水tds值，自来水tds值以及水温，其中纯水tds值刷新时间为1秒，自来水tds值刷新时间为1分钟，同时设置了一个虚拟开关，当开关关闭时停止采集数据，并关闭显示屏。

home assistant效果如下：

![image](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/b1bb9a78-5a0c-4b4b-ad34-1b9c884fd2b7)

![image](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/4ef68f76-b085-4a41-978f-f7483fff66c8)

实物如下图所示：


## 硬件方案
### 处理器
使用esp8266 nodemcu
### tds模块
使用的是某宝购买的双路tds传感器模块，样子长这样：

![image](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/52920817-eca3-4913-9bfd-d3eb19bc6eb8)

![image](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/9faba25d-4508-40bd-8b05-7ed162330d42)


有温度补偿，有休眠模式，使用uart通讯，通讯协议如下：
![command1](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/8a3f92e9-a771-4d98-9a37-f193ed26190c)

![command2](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/2f7c4593-7161-4c53-9f7b-78153579f0fe)

![command3](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/256b87cc-d10d-4485-9297-92a0cb89ed60)

### 显示模块
使用某宝购买的4位数码管TM1637模块，样子长这样：

![image](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/6811b185-9e7f-401f-b43a-23e7f28fe1a2)

### 电源模块
使用dc-dc降压模块，从净水器的24v电源处取电，样子长这样：
![image](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/dc9ced2c-108f-418c-b493-52b14206eb48)

### 电路图
![image](https://github.com/hqc201105/esphome_tds_sensor/assets/84075765/32d65f54-2b67-453e-a56c-7a04151b0d81)



## 软件方案
本项目使用esphome的自定义串口设备功能完成，文档可参考：

https://esphome.io/components/uart.html

https://esphome.io/custom/uart.html

### 使用方法：
将
