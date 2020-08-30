#pragma once

#include <string>
#include <vector>

using namespace std;

namespace MicroController
{
	class AppSettings final
	{
	public:

		static int DefaultProvider;
		static int SerialBitRate;

		// Default Server settings
		static string Host;
		static int Port;

		// Default Light Pins Settings
		static vector<int> LightPins;

		// Default Wifi Settings
		static vector<string> SSID;
		static vector<string> PASS;

		// Default motion detection Pin
		static int MotionDetectionPin;

		// Default OLED Settings
		static int ScreenWidth;
		static int ScreenHeight;
		static int OLED_MOSI;	// -> D21 -> SDA
		static int OLED_CLK;	// -> D18 -> SCL 
		static int OLED_DC;	// -> RX2 -> DC
		static int OLED_CS; 	// Random (not used)
		static int OLED_RESET;	// -> D4 -> RES
	};
}
