# Autonomous LEGO EV3 Line Following Robot

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus)
![Platform](https://img.shields.io/badge/Platform-LEGO%20EV3-005596?style=for-the-badge)
![Course](https://img.shields.io/badge/Course-Fundamentals%20of%20Programming%20(CS--114)-blue?style=for-the-badge)

An autonomous dual-IR sensor line-following robot built with the LEGO Mindstorms EV3 platform for the Fundamentals of Programming (CS-114) course.

---

## 📌 Project Summary

The objective of this robot is to detect and follow a dark path on a light background, navigating curves and turns with consistent speed and accuracy.

- **Differential Steering:** Driven by 2 Medium Servo Motors (Ports A and D).
- **Reflectance Sensing:** Uses 2 Infrared Sensors (Ports 1 and 4) placed above the ground at a distance wider than the black track line.
- **Sensor Calibration:**
  - White Surface Value: `> 20`
  - Black Line Value: `< 15`

---

## 🛠️ Hardware & Components

| Component | Quantity | Function / Placement |
| :--- | :--- | :--- |
| **EV3 Intelligent Brick** | 1 | Main control unit running the navigation program |
| **Medium Servo Motors** | 2 | Connected to output Ports A and D |
| **IR Sensors** | 2 | Connected to input Ports 1 and 4 (front mounted) |
| **Mechanical Parts** | - | Tyres, gears, frames, beams, connecting cables |

---

## 📂 Code Structure

The line-following logic is implemented in **C++** in [`src/main.cpp`](src/main.cpp):

1. **Both Sensors White:** Drives both motors forward at 75% speed.
2. **Left Sensor Black:** Reverses left motor and powers right motor to pivot left.
3. **Right Sensor Black:** Reverses right motor and powers left motor to pivot right.
4. **Both Sensors Black:** Stops motors (intersection / track end).

---

## 👩‍💻 Author

- **Momina Rizwan** (Reg # 473318)  
  *Department of Mechatronics Engineering*  
  *NUST College of E&ME, Rawalpindi*
