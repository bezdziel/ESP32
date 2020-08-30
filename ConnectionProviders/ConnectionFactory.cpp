
#include "ConnectionFactory.h"

namespace MicroController
{

	ConnectionProvider *ConnectionFactory::Create(int type)
	{
		switch(type) {
			case ConnectionType::Wifi:
			case ConnectionType::Bluetooth:
			case ConnectionType::SMS:
				return new WifiConnectionProvider();
		}

		return new ConnectionProvider();
	}
}
