#pragma once

#include <string>
#include <deque>
#include "Operation.h"
#include "Parser/CommandParser.h"
#include <Arduino.h>
#include "Operations/OperationResolver.h"

using namespace std;

namespace MicroController
{
	class OperationMenager
	{
	private:
		std::deque<Operation*> *_operations;
		OperationResolver *_resolver;
		int _lastCheck = 0;
		int _operationExecuteDelay = 500;
	public:
		
		~OperationMenager();
		OperationMenager();

		void AddOperation(const string &command, OperationDelegate callback);

		void AddOperation(Operation *operation);

		void Loop();
	};
}
