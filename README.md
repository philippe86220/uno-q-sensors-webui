# UNO Q – Sensors WebUI Dashboard

A simple and clean web dashboard for the Arduino UNO Q using Modulino sensors and the official Arduino WebUI brick.

This project demonstrates how to build a lightweight, readable, and reliable sensor dashboard without external web frameworks.

---

## Features

- Temperature and humidity monitoring (Modulino Thermo)
- Ambient light measurement (Modulino Light)
- Presence detection using distance threshold (Modulino Distance – ToF)
- Web dashboard refreshed every second
- Uses the official Arduino WebUI brick
- No external Python dependencies (no Flask, no FastAPI)
- Read-only web access (no remote control)

---

## Hardware

- Arduino UNO Q
- Modulino Thermo
- Modulino Light
- Modulino Distance

---

## Software Architecture

STM32 (sensors)
→ Bridge
→ Python application (UNO Q)
→ Arduino WebUI (assets/index.html)

---

## Installation

### STM32 firmware

Flash the STM32 sketch that reads the Modulino sensors and sends data to Linux via Bridge.

### Python application (UNO Q)

Copy the Python application into the UNO Q application directory.

The WebUI automatically serves the content of the `assets/` directory.

Once started, the web interface is available at:

http://<UNO_Q_IP>:7000

---

## Web Access

The web interface is provided by the official Arduino WebUI brick.

- GET /  
  Serves the dashboard (assets/index.html)

- GET /api/state  
  Returns the current sensor state as JSON

The dashboard refreshes automatically every second.

---

## Notes

- Presence detection is based on a configurable distance threshold (default: 80 cm).
- The application is intended for local use or temporary external access.
- No write or control endpoints are exposed.
- No sensitive system information is accessible through the web interface.

---

## Acknowledgements

This project was developed with the assistance of ChatGPT,
used as a technical partner for architecture design, debugging, and documentation.

---

## License

MIT
