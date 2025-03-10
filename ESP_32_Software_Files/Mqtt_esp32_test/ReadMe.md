# ESP32 pinout: 

![image](https://github.com/user-attachments/assets/55cdee1e-c070-4f87-a6ce-737fc9ff3d14)


# Connections:

![WhatsApp Image 2025-02-27 at 14 22 03_2f35d051](https://github.com/user-attachments/assets/92504580-4981-461b-9035-2ad041c31c94)


# Arduino IDE settup
To run code on an ESP32 using Arduino IDE, follow these steps:


### 🔹 1. Install Arduino IDE
If you haven’t installed Arduino IDE, download it from the official website and install it.


### 🔹 2. Add ESP32 Support to Arduino IDE
Open Arduino IDE and go to File → Preferences (or Settings in newer versions).

In the Additional Board Manager URLs field, add the following URL: [package_esp32.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)
➝ If there are other URLs, separate them with a comma.

Click OK, then go to Tools → Board → Boards Manager.

Search for ESP32, then install "esp32 by Espressif Systems".


### 🔹 3. Select the ESP32 Board
Connect your ESP32 to the PC via USB cable.
Go to Tools → Board and select your ESP32 model (e.g., ESP32 Dev Module).

Go to Tools → Port and select the correct serial port (e.g., COM3 on Windows or /dev/ttyUSB0 on Linux).

If no port appears, install the CP210x USB to UART driver from Silicon Labs.


### 🔹 4. Compile and Upload the Code to ESP32
Click Verify (✓) to check for errors.

Click Upload (→) to flash the code to the ESP32.

If you get Failed to connect to ESP32: Timed out, hold the BOOT button on the ESP32 while uploading.


### 🔹 5. Open Serial Monitor
Go to Tools → Serial Monitor and set the baud rate to 115200.
You should see messages from the ESP32.

✅ Done! Now you can run the web browser.🚀
