#pragma once
#include <Arduino.h>
#include "Settings/AppSettings.h"
#include "ConnectionProviders/ConnectionFactory.h"
#include "Oled/OledDisplay.h"

namespace MicroController
{
	class Program
	{
	public:
		void Start();
		void Loop();
		void Restart();
		Program();

		string Name = "Smart Dzialka";
		float Version = 0.1f;

	private:
		ConnectionProvider* Provider;
		OledDisplay* Oled;
		void Provider_OnMessage(const std::string &message);
	};
}
