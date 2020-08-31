#pragma once

#include "WifiConnectionProvider.h"
#include "ConnectionProvider.h"

namespace MicroController
{
	class ConnectionFactory final
	{
	public:
		static ConnectionProvider *Create(int type, OperationMenager *menager);
	};
}
