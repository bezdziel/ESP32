#pragma once

#include <type_traits>
#include "tangible_event.h"
#include <Arduino.h>

using namespace std;

namespace MicroController
{
	using OperationDelegate = std::function<void (const std::string &result)>;
	using OperationBodyDelegate = std::function<std::string ()>;

	class Operation
	{
	public:
		Operation(OperationBodyDelegate body, OperationDelegate callback);
		~Operation();
		bool Ready();
		void Invoke();
	private:
		OperationDelegate _callback;
		OperationBodyDelegate _body;
		bool _isReady;
	};
}
