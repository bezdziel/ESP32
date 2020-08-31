#pragma once

#include <type_traits>
#include "tangible_event.h"
#include <Arduino.h>

using namespace std;

namespace MicroController
{
	using OperationDelegate = std::function<void (const std::string &result)>;
	using OperationBodyDelegate = std::function<std::string ()>;

	enum OperationState {
		Run,
		Finished
	};

	enum OperationLifeTime {
		OneTime,
		ApplicationLife
	};
	
	class OperationOptions {
	public:
		int Delay = 0;
		OperationLifeTime LifeTime = OneTime;
		vector<string> *Times = new vector<string>();
	};

	class Operation
	{
	public:
		Operation(OperationBodyDelegate body, OperationDelegate callback);
		~Operation();
		bool Ready();
		void Invoke();
		void Stop();
		void SetOptions(OperationOptions *options);
		OperationState State;
	private:
		int _createdMillis = 0;
		OperationDelegate _callback;
		OperationBodyDelegate _body;
		OperationOptions *_options = new OperationOptions();
	};
}
