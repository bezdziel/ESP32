#include "Operation.h"

namespace MicroController
{
    Operation::Operation(OperationBodyDelegate body, OperationDelegate callback) {
        _body = body;
        _callback = callback;
        _createdMillis = millis();
        State = Run;
    }

    bool Operation::Ready() {
        //if (State != Run) {
        //    return false;
        //}
        return millis() - _createdMillis >= _options->Delay;
    }

    void Operation::Invoke() {
        if (_options->LifeTime == OneTime) {
            Stop();
        }
        Serial.println("Operation Invoked");
        if (_callback == nullptr) {
            _callback(_body());
        } else {
            _body();
        }
    }

    void Operation::Stop() {
        State = Finished;
    }

    void Operation::SetOptions(OperationOptions *options) {
        _options = options;
    }
}
