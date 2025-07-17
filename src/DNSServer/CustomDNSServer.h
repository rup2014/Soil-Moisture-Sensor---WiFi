#ifndef CUSTOM_DNS_SERVER_H
#define CUSTOM_DNS_SERVER_H

#include <WiFi.h>
#include <DNSServer.h>

class CustomDNSServer{
    public:
        CustomDNSServer();
        void initCustomDNSServer(IPAddress ip);
        DNSServer& getDNSServer();
    private:
        DNSServer dnsServer;
        const byte DNS_PORT = 53;
};

#endif