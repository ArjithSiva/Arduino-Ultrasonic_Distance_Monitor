# Arduino Ultrasonic Distance Monitor

My first Arduino project — a simple distance-monitoring system using an **Arduino Uno R3**, **HC-SR04 ultrasonic sensor**, and **0.96-inch I2C OLED display**.

The project measures the distance between the ultrasonic sensor and an object and displays the result on the OLED. The distance is also printed to the Arduino Serial Monitor.

## 📌 Project Overview

This project was built as my first step into Arduino and embedded systems.

The system works as follows:

**HC-SR04 → Arduino Uno → OLED Display**

The HC-SR04 sends an ultrasonic pulse and measures the time taken for the echo to return. The Arduino uses this measurement to calculate the distance in centimeters and displays the result on the OLED.

The display also shows a simple status based on the measured distance:

* **VERY NEAR** — less than 10 cm
* **NEAR** — 10–30 cm
* **CLEAR** — more than 30 cm

## 🧰 Components Used

* Arduino Uno R3
* HC-SR04 Ultrasonic Distance Sensor
* 0.96-inch I2C OLED Display
* Breadboard
* Jumper wires
* USB Type-B cable

## 🔌 Wiring

### HC-SR04 → Arduino Uno

| HC-SR04 | Arduino Uno |
| ------- | ----------- |
| VCC     | 5V          |
| GND     | GND         |
| TRIG    | D9          |
| ECHO    | D10         |

### OLED → Arduino Uno

| OLED | Arduino Uno |
| ---- | ----------- |
| VCC  | 3.3V        |
| GND  | GND         |
| SDA  | A4          |
| SCL  | A5          |

> **Note:** The Arduino Uno uses **A4 for SDA** and **A5 for SCL** for I2C communication.

## 💻 Software

The project was developed using the **Arduino IDE**.

### Libraries

The following libraries are required:

* **Adafruit SSD1306**
* **Adafruit GFX Library**

The HC-SR04 does not require an additional library for this project.

## 🚀 How It Works

1. The Arduino sends a short trigger pulse to the HC-SR04.
2. The ultrasonic sensor sends out an ultrasonic wave.
3. The sensor waits for the reflected wave to return.
4. The Arduino measures the echo duration.
5. The duration is converted into distance in centimeters.
6. The distance is displayed on the OLED.
7. The same measurement is printed to the Serial Monitor.

The basic distance calculation used is:

```text
Distance = Echo Time × Speed of Sound ÷ 2
```

The division by 2 is required because the ultrasonic pulse travels **to the object and back**.

## 🖥️ Example Output

The OLED displays information similar to:

```text
ULTRASONIC SENSOR

    24.7 cm

Status: NEAR
```

The Serial Monitor outputs:

```text
Distance: 24.7 cm
Distance: 24.3 cm
Distance: 23.9 cm
```

## 📂 Project Structure

```text
first-sketch/
│
├── first-sketch.ino
└── README.md
```

## 📚 What I Learned

This project introduced me to:

* Arduino Uno programming
* Digital input and output
* Ultrasonic distance measurement
* I2C communication
* OLED displays
* Arduino libraries
* Serial Monitor debugging
* Breadboard prototyping
* Basic troubleshooting and wiring

One of the first wiring issues I encountered was confusing the **A4 I2C pin with D4**. After identifying the mistake and correcting the wiring, the OLED worked as expected. This was a useful first lesson in debugging hardware projects.

## 🔮 Future Improvements

Possible improvements for future versions:

* Add an LED indicator
* Add a piezo buzzer for proximity warnings
* Add a servo to rotate the ultrasonic sensor
* Create an obstacle-avoidance robot
* Add Bluetooth control
* Move the project to an ESP32
* Log distance measurements

## 📸 Project

*Add photos/videos of the completed hardware here.*

---

### First Step into Embedded Systems 🚀

This is my first project in my journey of learning **Arduino, embedded systems, sensors, and robotics**.

More projects coming soon.
