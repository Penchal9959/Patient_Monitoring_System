# Patient Monitoring System

> **This repository is archived.** The reviewed and corrected version
> of this project lives in [embedded-iot-projects / patient-monitoring](https://github.com/Penchal9959/embedded-iot-projects/tree/main/patient-monitoring), alongside the
> others from the same series. Work happens there; nothing here changes.

### Why you want the maintained copy

**The clinical thresholds in this version are wrong.** It alerts on a temperature at or above 98 F, which is normal; on a heart rate at or above 80 bpm, which is normal; and on SpO2 at or **above** 95%, which is the healthy direction - low blood oxygen is the dangerous one, so that comparison is inverted. A missing `pinMode` also left the buzzer pin undriven. All four are documented and corrected in the maintained copy. Do not use this version as a health monitor.

---

## Original description

Patient_Monitoring_System is Used for Monitoring the Patient Blood Oxyzen Levels, HeartBeat and Temperature, when Ever fluctuation are Occure Sensor Data is Sent to 
Concern Doctor, Through the GSM module.


Components:

1.Arduino UNO
2.GSM SIM900A Module
3.max30100 pulse Oximeter
4.100k Thermistor
5.PCB
6.DB9 connectors
7.12v DC Power Adapter
8.9v Battery
9.LED's
10.BUZZER
11.16x2 LCD

Skills Used:

1.Arduino IDE
2.MAX30100 Pulse Oximeter Libraries
3.SIM900A Libraries


---

> **Superseded.** This project now lives in
> [embedded-iot-projects](https://github.com/Penchal9959/embedded-iot-projects) alongside eleven
> other builds.

## SMS destination numbers

The `AT+CMGS` commands use `+91XXXXXXXXXX` placeholders. Set your own destination numbers before
flashing.

> **Privacy note.** Earlier versions of this repository contained real mobile numbers hardcoded in
> the sketch. They have been purged from the entire git history, but were publicly readable for
> several years.
