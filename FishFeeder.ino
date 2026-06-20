// Code
// Automated Fish Feeder Using Arduino UNO and RTC DS1307

#include <Wire.h>      // Library for I2C communication
#include "RTClib.h"    // Library for RTC module
#include <Servo.h>     // Library for Servo Motor

// Create RTC object
RTC_DS1307 rtc;

// Create Servo object
Servo myServo;

// Variable to store the last feeding minute
int lastMinute = -1;

void setup() {

  // Start serial communication
  Serial.begin(9600);

  // Check whether RTC module is connected
  if (!rtc.begin()) {
    Serial.println("RTC not found!");
    while (1); // Stop execution if RTC is not detected
  }

  // Attach servo motor to digital pin 4
  myServo.attach(4);

  // Set initial servo position (closed position)
  myServo.write(0);

  Serial.println("System Started");
}


// Function to move servo smoothly
void smoothMove(int startPos, int endPos) {

  // Move servo forward
  if (startPos < endPos) {

    for (int pos = startPos; pos <= endPos; pos++) {

      myServo.write(pos);
      Serial.print("Servo Angle: ");
      Serial.println(pos);

      delay(30);
    }

  }

  // Move servo backward
  else {

    for (int pos = startPos; pos >= endPos; pos--) {

      myServo.write(pos);
      Serial.print("Servo Angle: ");
      Serial.println(pos);

      delay(30);
    }
  }
}



void loop() {

  // Read current time from RTC
  DateTime now = rtc.now();

  // Display current time on Serial Monitor

  if (now.hour() < 10) Serial.print('0');
  Serial.print(now.hour());
  Serial.print(':');

  if (now.minute() < 10) Serial.print('0');
  Serial.print(now.minute());
  Serial.print(':');

  if (now.second() < 10) Serial.print('0');
  Serial.println(now.second());



  // Feeding condition:
  // Servo rotates once every minute

  if ((now.second() < 10) &&
      (lastMinute != now.minute())) {

    // Save current minute to avoid repeated feeding
    lastMinute = now.minute();

    Serial.println(" --> Servo Rotating");

    // Open feeder
    smoothMove(30, 90);

    // Wait for food dispensing
    delay(500);

    // Close feeder
    smoothMove(90, 30);

    Serial.println(" --> Servo Done");
  }

  // Small delay for stability
  delay(200);
}
