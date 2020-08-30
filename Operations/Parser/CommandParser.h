#pragma once

#include "Operations/Operation.h"
#include <regex>

using namespace std;

namespace MicroController
{
	class OperationDescriptor {
	public:
		string OperationName;
		vector<string> *Parameters;
	};

	class CommandParser
	{
	public:
		CommandParser();
		~CommandParser();
		OperationDescriptor* Parse(const string command);
	private:
		vector<string> *_patterns;
	};
}
