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
#### Implementation:
For this project, I am using PlatformIO as the development environment.
Once the game starts by pressing the "Start" button, Mario is controlled by the "Left" and "Right" buttons to move throughout the game, but also the "Jump" button that helps the game character jump to pass over obstacles. The central button in the menu is programmed for "Start", and during the game for "Jump".

#### Project Libraries:
The external libraries are:
- SPI.h (Provides support for the Serial Peripheral Interface (SPI) protocol, required for communication with peripheral devices)
- Adafruit_GFX.h (It provides a series of functions for drawing graphics (lines, shapes, texts) on screens that use different types of graphic displays)
- Adafruit_PCD8544.h (Provides support for controlling the Nokia 5110 PCD8544 LCD screen. This is a specialized library that allows the use of an LCD screen on Arduino platforms)
The internal libraries are:
-marduinotypes.h (A custom file that defines project-specific data types and structures, for example, BMP (the data type for bitmap tiles) and coordinate-related structures and map arrays)

The marduinotypes.h file contains:
- tilesetbitmap.h (In this file, several bitmap arrays are declared and initialized, which visually represent the tiles used for various visual elements in the game (for example, one image for each tile))
- tilemap.h (Here the TileMap class is defined, which contains functions for manipulating the map and tile sizes, and within this class are functionalities to calculate the positions of each tile and to actually draw the tiles on the screen)
- tilemap.cpp (This file implements the methods that allow setting the map dimensions, drawing tiles on the screen (interaction with Adafruit_PCD8544 to draw each tile))
- levels.h (This file defines various data sets that describe maps and collision maps (CollisionMap). The map is structured by a set of tiles, and the TileMap0[] function effectively represents the tiles that make up the map of a particular level in the game)

#### Functionalities from labs to game :
- Lab 0: GPIO for detecting button inputs (The buttons in the game are read as digital inputs from configurable pins. I used the digitalRead() function to detect the state of the buttons and use them as input for various in-game actions (movement, jump))
- Lab 2: Interrupts , Timers ( Here, we have used interrupts to respond to a fast event (button press). When we press the button, instead of waiting continuously to check, the processor goes into interrupt mode and fires the onButtonPress() function. This saves processor resources)
-  Lab 5: SPI (Here we used SPI to communicate with an RFID reader, which can be used to save game data to another device or access information related to game progress)
-  Lab 6: I2C (I used I2C to communicate with an LCD display)
#### Main function:
- setup() :(Initializes essential components of the game, including configuring the display, creating the TileMap object for level management, and setting variables involved in game mechanics, such as movement speed or gravity. It configures the initialization of player state variables, the initial position of the player, and other aspects of game setup)
- loop() :(The main loop that runs continuously and handles interaction with button inputs and updates the game state. For example, it checks whether the player should move left/right or jump based on button inputs and gravity (determining vertical movement))
- inputManager() :(One of the most important components of your game, which receives input from buttons. It checks whether the buttons are pressed or released and updates their states accordingly. It relies on reading input signals for player movement)
- updatePlayerMovement() :(This feature updates the player's movement based on button inputs and game logic. Movement includes adjusting the player's position on the X axis for left/right movement, adjusting the Y axis for jumps, and checking for collisions on the map)
- updateGameState() :(This function updates the game state, such as changing between GAME_INTRO, GAME_PLAY, and GAME_GAMEOVER, based on in-game events, such as losing a life or completing a level)
-  resetPlayer(): (Depending on the game state, the resetPlayer function could be used to reposition the player when a new level or game starts, resetting the player's position, state, and animations)

#### Global Variables:
- gamestate: Defines the current state of the game, such as the start of the game, the level in progress, and the end of the game. This is a crucial parameter to know whether to run gameplay, display the menu, or manage other game states.
             Example: gamestate = GAME_PLAY; (setting the game state to "Game in Progress")

- player_state: Stores the current state of the player, which can be from still (P_STILL) to moving (P_MOVE) or dead (P_DEAD). This is used to change the player's behavior, such as jumping or moving.
             Example: player_state = P_MOVE; (setting the player state to move)

- last_direction: Stores the last direction the player was moving (usually 1 for right or -1 for left). This variable is useful for managing directions in the game.
            Example: last_direction = 1; (sets the player's direction to the right)
 
- life:
Stores the player's number of lives. It is decremented when the player dies and is used to determine when the game is over
          Example: life = 3; (the player starts with 3 lives)

- player_position:Defines the player's position on the screen, both on the X and Y axes. It is essential for updating the player's movement during the game
Example: Vector2f player_position(0, display.height() - pimageh - 8); (places the player at the bottom of the screen)

- hspd:The player's horizontal speed, which controls their movement on the X axis. This can be adjusted to control how fast the player moves
Example: hspd = 3.0; (setting the player's horizontal speed)

- grav:The gravity value that influences the player's vertical movement, especially when jumping or in the air
Example: grav = 0.6; (setting gravity to a moderate value)

- vspd:The player's vertical speed. This is influenced by gravity and the player's jumping actions
Example: vspd = 0; (initially the player does not move vertically)

- frameMax: The maximum number of frames in an animation cycle. This is used to limit the number of frames and record animation sequences
Example: frameMax = 4; (setting the maximum number of frames in the animation)

- frameCounter: The frame counter that is used to manage the animation speed and frame changes.
Example: frameCounter = 0; (initializing the frame counter to 0)

- camera: Represents the camera position, which affects the perspective of the game. This is used to track the player's movements on the screen
- Example: Vector2f camera = {0, 0}; (initial camera position at 0)
  
- buttonPressing, buttonRelease, buttonPressed: These variables are used to track the state of buttons. buttonPressing indicates whether a button is pressed, buttonRelease indicates whether the button has been released, and buttonPressed handles whether a button has already been pressed
Example: buttonPressing[0] = true; (indicates that the first button is pressed)

- last_camera: It is used to compare the last known camera position, to detect significant changes in perspective.
Example: last_camera = camera; (save the last camera position for later comparisons).

# Results
Video with finished software and hardware :

# Conclusions
In conclusion, thanks to this project, this game that marked my childhood, I realized that I can do much more and that I can gradually learn more. I remembered what I did in the labs, I deepened the information, I can even say that this project helped me develop my skills.

