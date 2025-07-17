#include "CustomWifiServer.h"
#include "webpages/Portal.h"
#include "webpages/GraphWebPage.h"

CustomWifiServer::CustomWifiServer(){};

void CustomWifiServer::initServer(){
    server.begin();
}

void CustomWifiServer::sendProgmemPage(WiFiClient client, const char *page){
    size_t len = strlen_P(page);
    client.println(F("HTTP/1.1 200 OK"));
    client.println(F("Content-Type: text/html"));
    client.print(F("Content-Length: "));
    client.println(len);
    client.println(F("Connection: close\r\n"));

    char buffer[64];
    for (size_t i = 0; i < len; i += sizeof(buffer)) {
        size_t chunk = min(sizeof(buffer), len - i);
        for (size_t j = 0; j < chunk; j++) {
        buffer[j] = pgm_read_byte_near(page + i + j);
        }
        client.write((const uint8_t*)buffer, chunk); // write whole buffer
    }
}

void serverCaptivePage(WiFiClient client){
    // Serve captive page
    client.print(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Connection: close\r\n\r\n"
    );
    client.print(INDEX_HTML);
}

void getSensorValue(WiFiClient client,SensorReader SR){
    int val = SR.readSensor();
    client.println(F("HTTP/1.1 200 OK"));
    client.println(F("Content-Type: application/json"));
    client.println(F("Connection: close\r\n"));
    client.printf("{\"value\":%d}\n", val);
}

void CustomWifiServer::rootHandler(String myIP, SensorReader SR){
    WiFiClient client = server.available();
    if (!client) return;
    // Read HTTP request
    String request;
    while (client.connected() && client.available()) {
        char c = client.read();
        request += c;
        if (request.endsWith("\r\n\r\n")) break;
    }

    // Check host header
    if (request.indexOf("Host: " + myIP) == -1) {
        // Redirect to captive page
        serverCaptivePage(client);
    } else {
        // Parse the first request line
        int idx1 = request.indexOf(' ') + 1;
        int idx2 = request.indexOf(' ', idx1);
        String path = request.substring(idx1, idx2);  // e.g. "/" or "/next"
        Serial.println(path);
        Serial.println(request);
        if(path == "/graph"){
            sendProgmemPage(client, GRAPH_HTML);
        }
        else if (request.indexOf("GET /data") >= 0)
        {
            getSensorValue(client, SR);
        }
        else{
            serverCaptivePage(client);
        }
    }

    client.stop();
}


