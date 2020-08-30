#pragma once

#include "Operations/Operation.h"
#include "Operations/Parser/CommandParser.h"

using namespace std;

namespace MicroController
{
	class OperationResolver
	{
	public:
		OperationResolver();
		~OperationResolver();
		Operation* Resolve(const string command, OperationDelegate callback);
	private:
		CommandParser *_parser;

		
	};
}
