# Automatic Fan Speed Control using LM35

## 🔍 Aim
To design a temperature-based fan speed control system using an LM35 temperature sensor and Arduino to adjust the fan speed automatically based on temperature.

---

## ⚙️ Components Required
- Arduino UNO – 1  
- DC Motor (fan) – 1  
- LM35 Temperature Sensor – 1  
- 16x2 LCD Display – 1  
- Relay Module (5V) – 1  
- Resistor (220 ohm) – 1  
- Jumper Wires & Breadboard  
- USB Cable  
- Power Supply  

---

## 🔌 Circuit Connections

| Component               | Arduino Pin        |
|------------------------|--------------------|
| LM35 Sensor OUT        | A1                 |
| LCD RS                 | D12                |
| LCD E                  | D11                |
| LCD D4 to D7           | D5 to D2           |
| Relay Signal Pin       | D8                 |
| Fan (PWM)              | D9                 |
| GND (all components)   | GND                |
| VCC (all components)   | 5V                 |

---

## 🧪 Procedure
1. Connect Arduino to your computer via USB.
2. Attach LM35 to analog pin A1 and set up power and ground.
3. Connect the fan to digital pin 9 (PWM) and the relay module to pin 8.
4. Set up the LCD display to show temperature, fan status, and speed.
5. Upload the program using Arduino IDE.
6. Observe the fan speed change based on the temperature.

---
