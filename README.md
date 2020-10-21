# Line-Follower-Bot
Line follower or path follower is an automated bot that follows a track or path drawn on a surface. The path can contain straight lines, semi-circles, right angle turns, broken lines, zigzag lines etc. The path colour is chosen such that it is of high contrast with the colour of the surface so that the bot can detect it easily. Usually we use black line on white surface or white line on black surface. However, for using this method(discussed further) we must use the colour black.

### How the Bot Works:
Here we have used IR sensors to detect the path. Due to some limitations of the sensors(we've used) we can only detect colours as black and non-black. That is why we have chosen black colour as path-colour. The sensor gives the data to a microcontroller which processes it and identifies the colour of the path and surface, thus identifies the path and according to a program, microcontroller moves the bot forward, backward, left or right along the path or stops it with help of a motor driver. 

### Components Used:
This project was a Arduino project and completely modular. We have used the following components- 
*	Arduino Nano(Microcontroller: ATMega328P-AU)
*	L298N Motor Driver Module
*	3 IR Sensor Module 
*	2 Sets of BO Motors and Wheels
*	1 Castor wheel
*	Power Supply(2 18650 li-ion batteries in parallal) and a Switch
*	Breadboard and Jumper wires
*	Clamps, Nut, Screws and Tapes
### Circuit Diagram:

### Circuit Explaination:
The VCC & GND pins of the IR sensors are connected to the 5V and GND pin of arduino respectively. The OUT or data pin of the 3 three IR sensors are connected to the analog pins A0, A1, A2 of the arduino as the signal or input we are getting from the sensors are analog. And another benefit of using analog pins is that we can use both analog or digital value(.) of the input. The IN1, IN2, IN3, IN4 are connected to the digital pin 4,3,8,7 respectively and ENA, ENB are connected to digital pin 5 and 6 respectively. We have used digital pin 5 and 6 for ENA & ENB because they are PWM pins. The +ve terminal of the battery is connected to the switch and the –ve terminal is connected to the GND pin of the motor driver. The 12V pin of the motor driver is connected to another terminal of the switch. We have used two 18650 li-ion cells in series which gives us 8.4V when the cells are fully charged. The 5V pin of the motor driver gives 5V as output which is connected to the Vin of the arduino. 
