#include <WiFi.h>
#include "WifiCreator.h"


WifiCreator::WifiCreator(){};

void WifiCreator::startWifiAP(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    Serial.print("[+] AP Created with IP Gateway ");
    Serial.println(WiFi.softAPIP());
}

IPAddress WifiCreator::getIP(){
    return WiFi.softAPIP();
};


