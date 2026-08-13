#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// HC-SR04 pins
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  // Start Serial Monitor
  Serial.begin(9600);

  // Set ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Start OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (true);
  }

  // Clear OLED
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(10, 10);
  display.println("Distance");

  display.display();
  delay(1000);
}

void loop() {

  // Make sure TRIG starts LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send 10 microsecond ultrasonic pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure how long the echo takes
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in centimeters
  float distance = duration * 0.0343 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Display on OLED
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ULTRASONIC SENSOR");

  display.setTextSize(2);
  display.setCursor(10, 20);
  display.print(distance, 1);
  display.println(" cm");

  // Status
  display.setTextSize(1);
  display.setCursor(0, 50);

  if (distance < 10) {
    display.println("Status: VERY NEAR");
  }
  else if (distance < 30) {
    display.println("Status: NEAR");
  }
  else {
    display.println("Status: CLEAR");
  }

  display.display();

  delay(200);
}