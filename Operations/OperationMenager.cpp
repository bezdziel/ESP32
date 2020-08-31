#include "OperationMenager.h"

namespace MicroController
{
	OperationMenager::OperationMenager()
	{
		_operations = new std::deque<Operation*>();
		_resolver = new OperationResolver();
	}

	OperationMenager::~OperationMenager() {
		delete _operations;
		delete _resolver;
	}

	void OperationMenager::AddOperation(const string &command, OperationDelegate callback)
	{
		auto operation = _resolver->Resolve(command, callback);
		if (operation != nullptr) {
			AddOperation(operation);
		} else {
			string com = "Unknown command - " + command;
			Serial.println(com.c_str());
			callback("UNKNOWN COMMAND!");
		}
	}

	void OperationMenager::AddOperation(Operation *operation)
	{
		Serial.println("Operation Added");
		_operations->push_back(operation);
	}

	void OperationMenager::Loop()
	{
		// Calling operations in 500 ms period to prevet getting hang by to many operation invokes
		if (millis() - _lastCheck < _operationExecuteDelay) {
			return;
		}
		_lastCheck = millis();
		if (_operations->size() > 0)
		{
			auto operation = _operations->front();
			if (operation->State == Finished) {
				_operations->pop_front();
				return;
			}
			if (operation->Ready()) {
				operation->Invoke();
			}
		}
	}
}
