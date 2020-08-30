
#include "OperationResolver.h"

namespace MicroController
{
	OperationResolver::OperationResolver() {
		_parser = new CommandParser();
	}

	OperationResolver::~OperationResolver() {
		delete _parser;
	}

	Operation* OperationResolver::Resolve(const string command, OperationDelegate callback) {
		auto descriptor = _parser->Parse(command);

		if (descriptor == nullptr) {
			return nullptr;
		}

		if (descriptor->OperationName == "PIN") {
			if (descriptor->Parameters->size() == 2) {
				int pinNum = stoi(descriptor->Parameters->at(0));
				int pinVal = LOW;
				if (descriptor->Parameters->at(1) == "HIGH") {
					pinVal = HIGH;
				} else if (descriptor->Parameters->at(1)  == "LOW") {
					pinVal = LOW;
				}

				auto body = [=] () { 
					pinMode(pinNum, OUTPUT);
					digitalWrite(pinNum, pinVal);
					string result = "PIN " + to_string(pinNum) + " SET TO " + to_string(pinVal);
					return result; 
				};

				auto operation = new Operation(body, callback);

				return operation;		
			}
		}

		return nullptr;
	}
}
