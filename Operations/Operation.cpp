#include "Operation.h"

namespace MicroController
{
    Operation::Operation(OperationBodyDelegate body, OperationDelegate callback) {
        _body = body;
        _callback = callback;
    }

    bool Operation::Ready() {
        return true;
    }

    void Operation::Invoke() {
        Serial.println("Operation Invoked");
        _callback(_body());
    }
}
