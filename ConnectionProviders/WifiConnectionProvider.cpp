#include "WifiConnectionProvider.h"

namespace MicroController
{
	WifiConnectionProvider::WifiConnectionProvider(OperationMenager *menager) : ConnectionProvider(menager) {
		client = new WebsocketsClient();
	}

	WifiConnectionProvider::~WifiConnectionProvider() {
		delete client;
	}

	bool WifiConnectionProvider::Setup()
	{
		WifiConnectionProvider::State = Preparing;
		SendMessage("Wifi Provider");
		ssid = AppSettings::SSID;
		pass = AppSettings::PASS;
		return true;
	}

	int WifiConnectionProvider::Connect()
	{
		State = Connecting;

		if (WiFi.status() == WL_CONNECTED) {
			WiFi.disconnect();
		}

		for(int i = 0; i < ssid.size(); i++ ) {
			SendMessage("->" + ssid[i]);
			WiFi.begin(ssid[i].c_str(), pass[i].c_str());

			for(int w = 0; w < 10 && WiFi.status() != WL_CONNECTED; w++) {
				delay(1000);
			}

			if(WiFi.status() != WL_CONNECTED) {
				if (connectionCount == ssid.size()) {
					SendMessage("Connection failed.");
					State = NoConnection;
				}
			} else {
				SendMessage("OK: " + ssid[i]);
				break;
			}
			connectionCount++;
		}

		SendMessage(GetIp(WiFi.localIP()));

		bool connected = client->connect(AppSettings::Host.c_str(), AppSettings::Port, "/");

		if (connected) {
			State = Connected;
			SendMessage("Connected to Socket");

			client->onMessage([&](WebsocketsMessage message){
				SendMessage(message.c_str());
				Menager->AddOperation(message.c_str(), [&] (std::string result) {
					OnMessage(result);
				});
			});

		} else {
			SendMessage("Socket Fail");
			State = Error;
			ResetConnection();
		}

		return State;
	}

	void WifiConnectionProvider::Loop() 
	{
		if(client->available()) {
        	client->poll();
		} else {
			SendMessage("Socket Fail");
			ResetConnection();
		}
		ConnectionProvider::Loop();
	}

	string WifiConnectionProvider::GetIp(IPAddress ipAddress) {
		uint32_t ip = (uint32_t)ipAddress;
		char bytes[4];
		bytes[0] = ip & 0xFF;
		bytes[1] = (ip >> 8) & 0xFF;
		bytes[2] = (ip >> 16) & 0xFF;
		bytes[3] = (ip >> 24) & 0xFF;
		return std::to_string(bytes[0]) + "." + std::to_string(bytes[1]) + "." + std::to_string(bytes[2]) + "." + std::to_string(bytes[3]);
	}

	void WifiConnectionProvider::OnMessage(const std::string &result)
	{
        client->send(result.c_str());
	}
}