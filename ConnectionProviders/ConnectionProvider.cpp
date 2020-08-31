#include "ConnectionProvider.h"

namespace MicroController
{
	ConnectionProvider::ConnectionProvider(OperationMenager *menager) {
		Menager = menager;
	}

	ConnectionProvider::~ConnectionProvider() {
		
	}

	int ConnectionProvider::Connect()
	{
		return State;
	}

	bool ConnectionProvider::Setup()
	{
		return true;
	}

	void ConnectionProvider::Loop() {
		Menager->Loop();
	}

	void ConnectionProvider::ResetConnection() {
		SendMessage("Reseting connection...");
		delay(3000);
		Setup();
		Connect();
	}

	void ConnectionProvider::SendMessage(std::string message) {
		for (auto listener : OnMessage->listeners())
		{
			listener(message);
		}
	}
}
