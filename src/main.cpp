#include <Arduino.h>
#include "wifi/WifiCreator.h"
#include "wifiserver/CustomWifiServer.h"
#include "DNSServer/CustomDNSServer.h"

WifiCreator wifi;
CustomDNSServer dnsServer;
CustomWifiServer server;
SensorReader SR;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\n[*] Creating AP");
  SR.initSensorReader();
  wifi.startWifiAP();
  dnsServer.initCustomDNSServer(wifi.getIP());
  server.initServer();
}

void loop() {
  dnsServer.getDNSServer().processNextRequest();
  server.rootHandler(wifi.getIP().toString(), SR);
  // put your main code here, to run repeatedly:
  //server.handleClient(SR);
}

