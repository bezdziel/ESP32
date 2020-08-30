#include "AppSettings.h"

namespace MicroController
{

	int AppSettings::DefaultProvider = 0;
	int AppSettings::SerialBitRate = 115200;

	// Default Server settings
	string AppSettings::Host = "<HOST>";
	int AppSettings::Port = 80;

	// Default Light Pins Settings
	vector<int> AppSettings::LightPins = vector<int> { 13, 12, 14, 27 };

	// Default Wifi Settings
	vector<string> AppSettings::SSID = vector<string> { "<SSID_1>", "<SSID_2>" };
	vector<string> AppSettings::PASS = vector<string> { "<PASS_1>", "<PASS_2>" };

	// Default motion detection Pin
	int AppSettings::MotionDetectionPin = 34;

	// Default OLED Settings
	int AppSettings::ScreenWidth = 128;
	int AppSettings::ScreenHeight = 64;
	int AppSettings::OLED_MOSI = 21;	// -> D21 -> SDA
	int AppSettings::OLED_CLK = 18;	// -> D18 -> SCL 
	int AppSettings::OLED_DC = 16;	// -> RX2 -> DC
	int AppSettings::OLED_CS = 35; 	// Random (not used)
	int AppSettings::OLED_RESET = 4;	// -> D4 -> RES
}
