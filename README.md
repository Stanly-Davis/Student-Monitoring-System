
# Student Monitoring System

This Project tracks the entry time and exit time of School student from their ID card and it is sent to Guardian/Parent instantaneously by SMS.


## Motivation

Primary School students are not allowed to bring phone to school. Hence, they cannot call/message their parents that they have reached school safely. If the parents themselves are dropping their kids to school, then its fine. But if they students travel to school by Public/Private transport, cycle or by walking, then the parents/Guardian don’t know if they have safely reached the school or at what time they have left the school.

In this System, whenever a student enters/exits the school, he/she has to scan their ID card. So, when the students enter school at 9 am, a SMS is sent to Guardian that student has reached the school. If the SMS has not reached, then that implies the student dint reach school, but went somewhere else.

When the student exits the school at 4pm, a SMS is sent to Guardian/Parent that student has exited at 4pm. The parent/Guardian can expect that the student reaches home by 5pm if student has exited school at 4pm.

In some case, the student exits the school early, may be at 2pm/3pm, then the student might go to playground/park/roadside/Gaming center/shops/Internet Cafe or any such places and spend time there. With the help of student monitoring this can be prevented.

This simple system will be most suited for Government school where students don’t maintain any discipline and bunk school very often. By tracking just the entry/exit timings, the students will have fear that they are being tracked and gradually start maintaining discipline.

## Components

1. RFID RECEIVER - RC 522 RECEIVER
2. RFID Tags
3. LCD DISPLAY – 16 *2 Display along with a I2C chip
4. GSM Module – Sim 800A
5. Microcontroller – Arduino Uno Rev 3

## Circuit

![App Screenshot](https://github.com/Stanly-Davis/Student-Monitoring-System/blob/main/Circuit.png)


## Code

Before Flashing the Final code into Microcontroller, we need to set up LCD, RFID and GSM

1.	Setting up LCD:
We are connecting LCD with an I2c chip which makes it easier to connect with Arduino.
After connecting I2C chip with LCD, only four pins (Vcc, Gnd, SDA and SCL) has to be connected to Arduino.
Below is the link to this tutorial. It is from Last Minute Engineers website.

https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/

2.	Setting Up RFID:
Below is the link for setting it up. It is explained wonderfully and in depth from Last Minute Engineers.

https://lastminuteengineers.com/how-rfid-works-rc522-arduino-tutorial/


3.	Setting up GSM module:
Sim800A is easy to use. It works well when we insert a 4G Airtel Sim. 3G sim dint work with this model.


Once all the above steps are followed correctly, the final code can be flashed into Arduino 




