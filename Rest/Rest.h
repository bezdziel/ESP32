#pragma once

#include <string>
#include <WiFi.h>
#include "Settings/AppSettings.h"

using namespace std;

namespace MicroController {

    class Rest {
    public:
        Rest();
        ~Rest();
        string Get(string endopint);
    private:
        WiFiClient *webClient;
    };
}