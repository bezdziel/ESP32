#pragma once

#include "ConnectionProvider.h"
#include "Settings/AppSettings.h"
#include <Wifi.h>
#include <vector>
#include <ArduinoWebsockets.h>

using namespace std;
using namespace websockets;

namespace MicroController
{
	class WifiConnectionProvider : public ConnectionProvider {
	public:
		WifiConnectionProvider();
		~WifiConnectionProvider();
		vector<string> ssid;
		vector<string> pass;
		int Connect() override;
		bool Setup() override;
		void Loop() override;
		void OnMessage(const std::string &result);
	private:
		string GetIp(IPAddress ipAddress);
		WebsocketsClient *client;
		WiFiClient *webClient;
		bool socketsConnected = false;
		int connectionCount = 0;
	};
}
