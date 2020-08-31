#pragma once

#include <string>
#include <Arduino.h>
#include "tangible_event.h"
#include "Settings/AppSettings.h"
#include "Operations/OperationMenager.h"

namespace MicroController
{
	enum ConnectionState {
		Unknown,
		Preparing,
		Connecting,
		Connected,
		NoConnection,
		Error
	};

	enum ConnectionType {
		Wifi,
		Bluetooth,
		SMS
	};

	using ConnectionProviderDelegate = std::function<void (const std::string &message)>;

	class ConnectionProvider
	{
	public:
		ConnectionProvider(OperationMenager *menager);
		~ConnectionProvider();
		virtual int Connect();
		virtual bool Setup();
		virtual void Loop();
		void ResetConnection();
	public:
		TangibleEvent<ConnectionProviderDelegate> *OnMessage = new TangibleEvent<ConnectionProviderDelegate>();
		int State;
	protected:
		void SendMessage(std::string message);
		OperationMenager* Menager;
	};
}
