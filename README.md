# Sensor-Data-Logger-with-Serial-Communication-Interface

This project is designed to collect environmental and positional data from various sensors and transfer the data to a companion computer in real-time. It integrates multiple sensors connected to an Arduino, which sends data to a Raspberry Pi, Jetson Nano, or any computer via serial communication. The data is captured using a Python script (verikaydetme.py) and saved to a CSV file for later analysis. This setup is perfect for creating datasets to power AI-driven applications or perform advanced data analysis.

## Sensors and Hardware Used:
  - BMP180: Measures barometric pressure and temperature.
  - DHT11: Collects temperature and humidity data.
  - MPU6050: Provides accelerometer and gyroscope readings for motion tracking.
  - NEO8 GPS: Supplies location data (latitude, longitude, and altitude).
  - Arduino: Acts as the main controller that gathers data from all sensors and transmits it via serial communication.
  - Companion Computer: A Raspberry Pi, Jetson Nano, or a standard computer receives the sensor data and processes it.

## Features:
  - Real-Time Data Logging: Data from multiple sensors is transmitted to the companion computer in real-time.
  - CSV File Creation: The Python script verikaydetme.py saves the incoming data in CSV format, making it easy to manage and process.
  - Flexible Companion Computer Support: The system can be paired with various computing devices like Raspberry Pi, Jetson Nano, or any other computer.
  - Dataset Creation: The system can generate datasets from the sensor data, which can be used for AI model training, data analytics, or future applications.

## Electronic Diagram: A schematic showing the wiring between the sensors, Arduino, and companion computer.
  ![avionic_electronic_diyagram](https://github.com/user-attachments/assets/c7eaa55c-57f7-4bbb-94b8-324540a09394)

## Screenshots: Displays of real-time data being logged in the terminal.
  ![data_receiving_with_serial_monitor_using_python_language](https://github.com/user-attachments/assets/637e9ca3-3406-4418-9353-86d597859bd1)

## How to Use:
  - Setup the Arduino with the sensors (BMP180, DHT11, MPU6050, NEO8 GPS).
  - Upload the Arduino code (avionik_full_cod_v2) that reads and sends sensor data over the serial interface.
  - Run the Python script (verikaydetme.py) on the companion computer to capture the data.
  - Monitor the terminal output for real-time data display and find the saved CSV file for analysis.
