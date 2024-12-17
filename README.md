<div align="center">

# Super-Mario-Game

Super Mario is a platform game series created by Nintendo starring their mascot, Mario. It is the central series of the greater Mario franchise. At least one Super Mario game has been released for every major Nintendo video game console. However, there have also been a number of Super Mario video games released on non-Nintendo gaming platforms. There are more than 20 games in the series.

![mario](https://github.com/user-attachments/assets/b9638350-b6ab-4334-b95a-837c750bf4b4)

</div>
   
# Introduction
This project is a simple arcade-style game where the player controls Mario to get a better score. The game is built using an LED matrix for display, a joystick for control, while an LCD screen displays the main character. This project aims to learn and deepen information about embedded programming. I chose this game because I made a connection with the past when I was 10 years old and played Super Mario. Back then, I played this game thinking it was the coolest game, and now it's time to make it myself. For me, this project represents progression and a way to accumulate new information.

# General Description
The game begins when the player presses the fire button, initiating a countdown sequence ("3... 2... 1..."). Once the countdown ends, Mario appears and you control him. The player uses the joystick to control the main character to make a better score and to avoid obstacles.During the game, the score is counted by time, where I said that the time should be the score until Mario hits the obstacles and the game is lost. The game ends when Mario hits an obstacle.
After the game ends, the score appears on the display and restart game.

#### For this project, I will use various features from previous lab exercises:
- The interrupts and timers in Lab 2 will be used for precise timing of events, such as the movement of the main character Mario.
- The button manipulation in Lab 0 will handle the press of the trigger button and the joystick.
- The AnalogWrite and AnalogRead in Lab 3 will be used for joystick control.

# Hardware Design
#### General Description :
In terms of hardware, my project contains an 84x48 LCD display and has an I2C protocol, the model is Nokia 5110, which is also on older Nokia phones. These screens are small but very visible and come with backlighting and this display is made up of 84x48 individual pixels, so you can use it for graphics, text or bitmaps. so less expensive than using an OLED display. I also used 3 buttons, these buttons give a nice soft click every time they are pressed, so you know you have definitely activated it. Their almost instant return makes them great for building your own home buffer. it is also a good reset switch or user feedback for microcontroller circuits. My project has Arduino Uno R3 board , it has 14 digital input/output pins (6 of which can be used as PWM outputs), 6 analog inputs, a 16 MHz quartz crystal, a USB connection, a power jack, an ICSP header and a reset button. In addition I have also used Jumper wires , We will use jumpers to connect on a breadboard or female header connector, size and color to distinguish the different working signals. we will use the male to male jumper for 7 segment and the buttons to connect to arduino. Finally I have used the breadboard , which I have from the faculty , University of Bucharest , we will be using a Single Panel Breadboard it is a solderless device for temporary prototype with electronics and test circuit designs. both side of the breadboard is the power rail it is horizontal lining and the middle is the vertical rail for arduino components.

To run the display we need 5 digital output pins. the LIGHT pin can be used to control (via on/off or PWM) the backlight, the GND and the LIGht pin should be connected to GND on the arduino board, The display driver is a PCD8544 chip which is on the library we have recently downloaded, VCC level must be 3.3V to prevent damage so you must use some kind of resistance. or we can use resistor between the light pin and the GND pin on the arduino. the remaining pin on the LCD will be connected to the specified digital pin out on the arduino board listed below. We have pin 8 - CLK, pin 9 - DIN, pin 10 - DC, pin 11 - CE, pin 12 - RST, pin GND - GND, pin GND - resistor - LIGHT, pin 3.3V - VCC.

Push buttons have 4 sets of legs but we will use 2 legs, both the right leg is connected to the GND pin on the arduino, the left one is connected to the specified arduino pin depends on the use of it.
To run mario back ward place in pin 5 with button 1 , to jump/select or enter the game place pin 5 with button 2 , to run mario forward place pin 7 with button 3 , combine all the components together in one single panel breadboard



#### Component List:

| Name                               | Source                   |
|------------------------------------|--------------------------|
| Arduino Uno                        | University Of Bucharest  |
|LCD display                         | Electronicgadgets        |                  
| Buttons                            | University Of Bucharest  |
| Connecting Wires                   | University Of Bucharest  | 
| Breadboard                         | University Of Bucharest  |
| Resistor (220 Ohm)                | University Of Bucharest   |       


## Pins Configuration

| Component               | Arduino Pin   | Function Description                                                        |
|-------------------------|---------------|-----------------------------------------------------------------------------|
| CLK (Clock)             | Pin 8         | Clock signal for display communication                                      |
| DIN (Data Input)        | Pin 9         | Data input for display communication                                        |
| DC (Data/Command)       | Pin 10        | Controls whether data or command is being sent                              |
| CE (Chip Enable)        | Pin 11        | Enables the display for communication                                       |
| RST (Reset)             | Pin 12        | Resets the display                                                          |
| LIGHT                   | Resistor → GND | Controls backlight brightness (via resistor or PWM control)                |
| VCC                     | 3.3V          | Power supply for display (must be 3.3V to avoid damage)                     |
| GND                     | GND           | Ground connection                                                           |
| Button 1                | Pin 2         | Input for the first button                                                  |
| Button 2                | Pin 3         | Input for the second button                                                 |
| Button 3                | Pin 4         | Input for the third button                                                  |


#### Circuit Diagrams:

![display](https://github.com/user-attachments/assets/dec8b44e-828a-4d99-b6eb-3aecba8370df)
![buttons](https://github.com/user-attachments/assets/a4f05286-754d-428d-ad4e-ef2534adc104)

#### Block Diagram:
![robotica](https://github.com/user-attachments/assets/6a9a0b14-d236-41cb-8d80-8f037492506b)

#### Photos assembly: 


# Software Design
For this project, I am using PlatformIO as the development environment.
# Results
# Conclusions

