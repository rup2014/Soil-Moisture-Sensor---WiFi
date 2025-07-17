#ifndef WEBSERVER_H
#define WEBSERVER_H
#include <WiFi.h>
#include "sensor/SensorReader.h"

class CustomWifiServer{
    public:
        CustomWifiServer();
        void initServer();
        void rootHandler(String ip, SensorReader SR);
        void sendProgmemPage(WiFiClient client, const char *page);
    private:
        WiFiServer server{80}; // Serve HTTP on port 80
};

#endif