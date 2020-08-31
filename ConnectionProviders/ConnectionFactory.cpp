
#include "ConnectionFactory.h"

namespace MicroController
{

	ConnectionProvider *ConnectionFactory::Create(int type, OperationMenager *menager)
	{
		switch(type) {
			case ConnectionType::Wifi:
			case ConnectionType::Bluetooth:
			case ConnectionType::SMS:
				return new WifiConnectionProvider(menager);
		}

		return new ConnectionProvider(menager);
	}
}
