#include "esphome.h"
using namespace esphome;
#define P1_MAXTELEGRAMLENGTH 100

class TDSSensorComponent : public Component, public uart::UARTDevice {
 protected:
   unsigned char receive[P1_MAXTELEGRAMLENGTH];
   int index;
   int receiveHeadLen = 3;
   int receiveTotalLen = 11;
   unsigned char temp;
 
 public:
  TDSSensorComponent(UARTComponent *parent) : UARTDevice(parent) {}
  Sensor *tds1 = new Sensor();
  Sensor *tds2 = new Sensor();
  Sensor *temperature1 = new Sensor();
  Sensor *temperature2 = new Sensor();
  
  void setup() override {
    // lastread = 0;
	}
  
  void loop() override {
	unsigned long now = millis();
		// ESP_LOGD("DmsrCustom","0x%x",now);
		// if (available()) { // Check for x seconds if there's data available
			// ESP_LOGD("DmsrCustom","0x%x",now);
			// bool have_message = read_message();
			// ESP_LOGD("DmsrCustom","0x%x",read());
		// }	
	if (available()) {
		byte temp = read();
		// ESP_LOGD("DmsrCustom","%d: 0x%x",index, temp);
		if (index == 0) {
			if (temp == 0x55) {
				receive[index++] = temp;
			} else {
				index = 0;
			}
		} else if (index == 1) {
			if (temp == 0x0a) {
				receive[index++] = temp;
			} else {
				index = 0;
			}
		} else if (index == 2) {
			if (temp == 0x85) {
				receive[index++] = temp;
			} else {
				index = 0;
			}
		} else if (index > 2 && index < 10) {
			receive[index++] = temp;
		} else {
			int channel = receive[3];

			int tds = (receive[4]*255 + receive[5])/20;
			float temperature = ((float)(receive[6]*255 + receive[7]))/10;

			ESP_LOGD("DmsrCustom","channel:%d tds:%d temperature:%f",channel, tds, temperature);

			if (channel == 1) {
				tds1->publish_state(tds);
				temperature1->publish_state(temperature);
			}
			if (channel == 2) {
				tds2->publish_state(tds);
				temperature2->publish_state(temperature);
			}

			index = 0;
		}
	}
  }	
//   bool write_message(const char *buf) {
//   	ascii2hex(buf, telegram, strlen(buf));
// 		for(cnt=0;cnt<strlen(buf)/2;cnt++)
// 		{
// 			write(telegram[cnt]);
// 			ESP_LOGD("DmsrCustom","0x%x",telegram[cnt]);
// 		}
// 		return false;	  
//   }
};