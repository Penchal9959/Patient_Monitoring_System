# Patient Monitoring System

> **Archived.** The reviewed and corrected version of this project lives in
> [embedded-iot-projects / patient-monitoring](https://github.com/Penchal9959/embedded-iot-projects/tree/main/patient-monitoring), alongside the others from the same series. Work happens there;
> nothing here changes.

## What this was

A bedside monitor for three vitals - blood-oxygen saturation, pulse and body
temperature - that texts the doctor when a reading leaves its normal range.

## Hardware

Arduino UNO, MAX30100 pulse oximeter, LM35 temperature sensor, SIM900A GSM
module, 16x2 LCD, buzzer.

## Known defects

**The thresholds in this version are wrong, and wrong in the dangerous
direction.** It alerts on a temperature at or above 98 °F, which is normal; on
a heart rate at or above 80 bpm, which is normal; and on SpO2 at or **above**
95%, which is the healthy direction - low blood oxygen is what harms you, so
that comparison is inverted. A missing `pinMode` also leaves the buzzer pin
undriven.

All four are corrected in the maintained copy. **Do not use this version as a
health monitor.**

## Why it was archived

Twelve one-off repositories of two files each is not a portfolio, it is a
list. They were consolidated into one maintained repository with the
documentation and the build check they never had. This one is kept so
existing links still resolve.

## Licence

[MIT](LICENSE)
