#include "Rest.h"

namespace MicroController {

    Rest::Rest() {
        webClient = new WiFiClient();
    }

    Rest::~Rest() {
        delete webClient;
    }

    string Rest::Get(string endpoint) {
        Serial.println("Rest GET");
        if (webClient->connect(AppSettings::Host.c_str(), AppSettings::Port)) {
            string header = "GET " + endpoint + " HTTP/1.1";
            webClient->println(header.c_str());
            string host = "Host: " + AppSettings::Host + ":" + to_string(AppSettings::Port);
            webClient->println(host.c_str());
            webClient->println("Connection: close");
            webClient->println();

            auto response = webClient->readString();

            Serial.println(response.c_str());

            return string(response.c_str());
        }

        return "";
    }
}