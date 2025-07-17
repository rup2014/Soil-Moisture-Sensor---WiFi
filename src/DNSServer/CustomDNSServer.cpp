#include "CustomDNSServer.h"

CustomDNSServer::CustomDNSServer(){};

void CustomDNSServer::initCustomDNSServer(IPAddress ip){
    // Redirect all DNS queries to our AP's IP
    dnsServer.start(DNS_PORT, "*", ip);
};

DNSServer& CustomDNSServer::getDNSServer() {
    return dnsServer; 
}