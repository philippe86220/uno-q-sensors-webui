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
- Read-only web interface: the dashboard only displays sensor data and does not allow any remote control or actuation.

---

## Hardware

- Arduino UNO Q
- Modulino Thermo
- Modulino Light
- Modulino Distance

---

## Requirements

- Arduino UNO Q
- Arduino App Lab (UNO Q)
- WebUI brick (HTML)
- Arduino library: Arduino_Modulino (current version, e.g. 0.7.0)

## Notes on libraries

With recent versions of **Arduino_Modulino** (e.g. **0.7.0**), installing this single library is usually enough.
Older setups often required extra dependency libraries, but this is no longer necessary in the current Modulino library releases.

---

## Software Architecture

STM32 (sensors)
→ Bridge
→ Python application (UNO Q)
→ Arduino WebUI (assets/index.html)

---

## Installation and Run (Arduino App Lab)

Arduino App Lab uses a fixed project structure with separate folders
for the STM32 sketch, the Python application, and WebUI assets.

1. In Arduino App Lab, open **Sketch Libraries** and install the
   **Arduino_Modulino** library (current version, e.g. 0.7.0).
2. Copy the content of `sketch/sketch.ino` from the repository
   into the App Lab sketch file.
3. Copy the content of `python/main.py` from the repository
   into the App Lab Python file.
4. Create an `assets/` directory in the App Lab file tree.
5. Create a new file named `index.html` inside the `assets/` directory.
6. Copy the content of `assets/index.html` from the repository
   into the App Lab `assets/index.html` file.
7. Make sure the **WebUI – HTML** brick is added to the project.
8. Click **Run** in Arduino App Lab.

Arduino App Lab handles the internal compilation, deployment, and startup
of the STM32 sketch, the Python application, the libraries, and the WebUI automatically.

Once running, the WebUI is available at:

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
- The application is intended for local use or external access.
- No write or control endpoints are exposed.
- No sensitive system information is accessible through the web interface.

---

## Screenshots
![Serveur](/docs/screenshots/IMG-2.jpg)
![Montage](/docs/screenshots/IMG.jpg)



---

## Acknowledgements

This project was developed with the assistance of ChatGPT,
used as a technical partner for architecture design, debugging, and documentation.

---

## License

MIT
