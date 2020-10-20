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
*	Power Supply(3 18500 li-ion batteries) and Switch
*	Breadboard and Jumper wires
*	Clamps, Nut, Screws and Tapes
