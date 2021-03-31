#include <Arduino.h>
#include <ESP8266WiFi.h>

int cnt = 0;

void setup()  

{
	Serial.begin(115200);  #กำหนดความเร็วในการส่งข้อมูล
	WiFi.mode(WIFI_STA); #ตั้งค่า WiFi เป็นโหมดสถานีและตัดการเชื่อมต่อจากเครื่อข่ายหากเชื่อมต่อไว้ก่อนหน้านี้
	WiFi.disconnect();
	delay(100);
	Serial.println("\n\n\n");
}

void loop()
{
	Serial.println("========== เริ่มต้นแสกนหา Wifi ===========");
	int n = WiFi.scanNetworks();   #กำหนดตัวแปร
	String ssid;
	int32_t rssi;
	uint8_t* bssid;
	int32_t channel;

	
	if(n == 0) {
		Serial.println("NO NETWORK FOUND");
	} else {
		for(int i=0; i<n; i++) {
			WiFi.getNetworkInfo(i, ssid, rssi, bssid, channel); #แสดงข้อมูล WiFi ในรูปแบบของฟังก์ชัน
			Serial.printf("%d: %s Ch:%d %d %s) \n", i + 1, ssid.c_str(), channel, rssi, bssid);  
			delay(10);
		}
	}
	Serial.println("\n\n");
	delay(1000);
}
