# Soil Moisture Sensor — WiFi

A WiFi-enabled soil moisture sensor project, built using ESP32, that hosts a captive portal and real-time graphing interface for sensor readings. This project is designed for wireless monitoring of soil moisture via a web browser, making it useful for makers, gardeners, and IoT enthusiasts.

## Features

- **WiFi Access Point:** ESP32 creates its own AP (`uPesy_AP`) with a secure password.
- **Captive Portal:** On connection, users are redirected to a portal page.
- **Live Sensor Graph:** Real-time soil moisture sensor readings displayed using Chart.js.
- **REST API:** Sensor data is served as JSON at `/data`.
- **No external cloud required:** All data accessible locally via WiFi.

## Hardware Required

- Custom PCB board (https://github.com/rup2014/Soil-Moisture-Sensor-PCB-Schematic/)
- USB to TTL adapter for flashing

## Getting Started

### 1. Clone the Repository

```sh
git clone https://github.com/rup2014/Soil-Moisture-Sensor---WiFi.git
cd Soil-Moisture-Sensor---WiFi
```

### 2. Flash the Firmware

- Open `src/main.cpp` in Arduino IDE or PlatformIO.
- Select ESP32 board type.
- Build and upload to your device.

### 3. Connect and Explore

- Power on the ESP32. It creates a WiFi AP named `uPesy_AP` (default password: `super_strong_password`).
- Connect to the AP using your phone or computer.
- A captive portal appears, click **Continue** to visit the live graph page.
- Visit `/graph` to see real-time sensor data plotted.
- Visit `/data` for raw JSON sensor output.

## Project Structure

```
src/
  main.cpp                 # Entry point, WiFi/server initialization
  sensor/SensorReader.*    # Sensor abstraction and reading logic
  wifi/WifiCreator.*       # WiFi AP setup
  DNSServer/CustomDNSServer.* # DNS redirect for captive portal
  wifiserver/CustomWifiServer.* # HTTP server logic
  webpages/Portal.h        # Captive portal HTML
  webpages/GraphWebPage.h  # Graph page HTML/JS (Chart.js)
```

## How It Works

1. ESP32 creates a WiFi AP and captive DNS server.
2. On connection, all DNS queries redirect to ESP32's HTTP server.
3. The root handler serves the captive portal and routes `/graph` and `/data` endpoints.
4. Sensor readings are fetched and graphed in real-time via AJAX/Chart.js.

## Customization

- Change WiFi SSID/password in `src/wifi/WifiCreator.h`.
- Adjust sensor setup/code in `src/sensor/SensorReader.cpp`.
- Customize portal and graph UI in `src/webpages/Portal.h` and `src/webpages/GraphWebPage.h`.

## License

No license specified. If you reuse or modify, please credit the original author.

## Author

[@rup2014](https://github.com/rup2014)

---

**Note:** This project is new and may be under development. For issues or contributions, use GitHub's issue tracker or pull requests.
