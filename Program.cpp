﻿#include "Program.h"
#include <any>


namespace MicroController
{
    Program::Program() {
        Menager = new OperationMenager();
        Serial.begin(AppSettings::SerialBitRate);
        Provider = ConnectionFactory::Create(AppSettings::DefaultProvider, Menager);
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



        auto operation = new Operation([&] () {
           pinMode(2, OUTPUT);
           digitalWrite(2, HIGH); 
           return "";
        }, [&] (std::string message) {});

        auto operationOptions = new OperationOptions();
        operationOptions->Delay = 20000;
        operation->SetOptions(operationOptions);

        Menager->AddOperation(operation);
	}

	void Program::Loop()
	{
        Provider->Loop();
	}

    void Program::Restart() {
        Provider->OnMessage->removeListener(L"Provider_OnMessage");
        Provider = ConnectionFactory::Create(AppSettings::DefaultProvider, Menager);
        Start();
    }

    void Program::Provider_OnMessage(const std::string &message)
	{
        Oled->Print(message, 2);

        if (message == "Connected to Socket") {
            auto operation = new Operation([&] () {
                auto rest = new Rest();
                return rest->Get("/api/dashboard/time");
            }, [&] (std::string message) {
                Oled->Print(message, 3);
            });
            Menager->AddOperation(operation);
        }

		Serial.println(message.c_str());
	}
}
