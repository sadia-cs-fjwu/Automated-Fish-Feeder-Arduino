# Automated Fish Feeder Using Arduino UNO and RTC Module

## Project Overview

The Automated Fish Feeder is an Arduino-based system designed to feed fish automatically at scheduled intervals without human intervention. The project uses a DS1307 Real-Time Clock (RTC) module to maintain accurate timing and a Servo Motor to dispense fish food.

This system is particularly useful for aquarium owners who may forget feeding schedules or remain away from home for extended periods.

---

## Components Used

* Arduino UNO
* RTC DS1307 Module
* Servo Motor
* 7V Battery Pack
* ON/OFF Switch
* PVC Fish Food Container
* Jumper Wires
* Mounting Board

---

## Features

* Automatic fish feeding
* Accurate RTC-based scheduling
* Low power consumption
* Portable battery-powered design
* Easy to use and reliable
* Cost-effective implementation

---

## Circuit Connections

### RTC DS1307

| RTC Pin | Arduino UNO |
| ------- | ----------- |
| VCC     | 5V          |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

### Servo Motor

| Servo Wire    | Arduino UNO |
| ------------- | ----------- |
| Red           | 5V          |
| Brown/Black   | GND         |
| Orange/Yellow | D4          |

---

## Working Principle

1. Arduino initializes the RTC module and Servo Motor.
2. RTC continuously provides the current time.
3. Arduino checks time in each loop cycle.
4. When a new minute begins, the Servo Motor activates.
5. The servo rotates from 30° to 90°.
6. Fish food is dispensed.
7. The servo returns to 30° and waits for the next cycle.

---

## Technologies Used

* Arduino Programming
* Embedded Systems
* RTC Communication (I2C)
* Servo Motor Control

---

## Future Improvements

* LCD Display Integration
* Adjustable Feeding Schedules
* Mobile App Monitoring
* IoT-Based Remote Control

---

## Author
Sadia Ali
BCS-IV (B)
Department of Computer Science
Fatima Jinnah Women University

