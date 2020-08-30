#include "Program.h"
#include <any>


namespace MicroController
{
    Program::Program() {
        Serial.begin(AppSettings::SerialBitRate);
        Provider = ConnectionFactory::Create(AppSettings::DefaultProvider);
        Oled = new OledDisplay();
    }

    void Program::Start()
	{
        Serial.println("Program Started");

        // Setup light pins
        for (int i = 0; i < AppSettings::LightPins.size(); i++) {
            pinMode(AppSettings::LightPins[i], OUTPUT);
        }

        pinMode(AppSettings::MotionDetectionPin, INPUT);

        Oled->Setup();
        Oled->Print(Name + " v" + to_string(Version).substr(0, 3), 0, 0);

        Provider->OnMessage->addListener(L"Provider_OnMessage", [&] (std::string message) {Provider_OnMessage(message);});

        Provider->Setup();
        Provider->Connect();
	}

	void Program::Loop()
	{
        Provider->Loop();
	}

    void Program::Restart() {
        Provider->OnMessage->removeListener(L"Provider_OnMessage");
        Provider = ConnectionFactory::Create(AppSettings::DefaultProvider);
        Start();
    }

    void Program::Provider_OnMessage(const std::string &message)
	{
        Oled->Print(message, 2);
		Serial.println(message.c_str());
	}
}
