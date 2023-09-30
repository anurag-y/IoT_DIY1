# FLOOD DETECTION AND ALERTING SYSTEM: AN IoT PROJECT
## Introduction
This project aims to implement a basic IoT system that senses water level data at the site and sends it to the server. From there, actuators, e.g., dam gates or alarm alerts, can be manipulated to control dangerous situations. This project demonstrates that IoT systems can be helpful for the said purpose, and scalable and more complex systems can be built following the methodologies used here.

## Componenets/Tech stack Used
1. ESP8266
2. Ultrasonic Distance sensor
3. Buzzer
4. LEDs
5. ThingSpeak as cloud server

## Objectives
We aim to implement an IoT system to demonstrate its working and to understand the IoT ecosystem better. We design a Flood Detecting System to sense water level and send this data to the ThingSpeak Cloud server. On server we write a script to analyse this data, and based on the water level we send a command to an alarm that alerts people we also implement an actuator as an LED that symbolizes an actuator and in real life scenario it can be replaced by water pump-to drain excess water- or motors-to open or close sluice gate of a dam. We can see data trend using tools available on the ThingSpeak server.

## Implemented Attributes
We have implemented the following attributes:
1. Sensing of data at site: Water level is read at site, e.g., reservoir or river.
2. Visualising sensed data on an LCD Screen at the site.
3. Sending data to ThingSpeak channel.
4. Analysing data of ThingSpeak channel and based on that sending command to actuators.
5. Visualisation of data using visualisation tools available on ThingSpeak. We can see time v/s water surface distance value on the server.
6. Actuators acting on commands received from server.

## Images of working project
![Alt text](<WhatsApp Image 2023-09-30 at 20.05.17.jpg>)
When water level (distance of water surface from sensor) is less than a threshold value a red light goes on and an alarm buzzes. Here sensor and actuator are seen on the same MCU (to save use of another MCU) but in reality they are not communocating directly locally. These two components may be well separated as actuators get commands from server and sensor sends data to server.
## Dataflow diagram
![Alt text](<WhatsApp Image 2023-09-30 at 19.33.48.jpg>)
## Dataflow within server
![Alt text](<WhatsApp Image 2023-09-30 at 19.54.26.jpg>)

### For further details see report.


