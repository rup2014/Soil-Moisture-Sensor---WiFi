#ifndef WIFI_CREATOR_H
#define WIFI_CREATOR_H

#include <string>

class WifiCreator{
    public:
        WifiCreator();
        void startWifiAP();
        IPAddress getIP();
    private:
        const char* ssid     = "uPesy_AP";
        const char* password = "super_strong_password";
};

#endif