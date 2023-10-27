# cli-lib
Command Line Interface library, for developing CLI applications and games in C. It has functions to access keyboard, screen and manage timing tasks.

## Requirements
- This library works with the follwing OS:
   - Linux based (Ubuntu, etc)
   - MacOS
- It is necessary to have GCC installed.

## Usage 
The file `main.c` has an example of how to use the Keyboard, Screen nd Timer functions. 

To build this example via command line, just switch to library root directory and type the following command:
```
$ gcc ./src/*.c -I./include -o cli-lib-example
```

To use this library to create your own apps, simply add source and header files to your project and compile it together with your own code, 
replacing the main.c file to your own.

## Modules:
   - The code is divided into several modules: keyboard, screen, and timer. Each module has specific responsibilities.

### Keyboard Module (keyboard.c and keyboard.h):
   - Provides functions to handle non-blocking keyboard input.
   - Initializes and configures terminal settings for non-blocking input.
   - Allows checking if a key has been pressed and reading it.

### Screen Module (screen.c and screen.h):
   - Manages terminal screen attributes, colors, and cursor positions.
   - Includes functions to set text attributes, draw borders, clear the screen, and update the display.

### Timer Module (timer.c and timer.h):
   - Implements a simple timer functionality using system time.
   - Allows initialization, destruction, updating, and checking if a specified time delay has passed.

## Main Program (main.c):
   - Acts as the entry point for the program.
   - Combines the functionalities of the keyboard, screen, and timer modules to create an interactive application.

## Global Variables:
   - x and y: Represent the current position of the "Hello World" text on the screen.
   - incX and incY: Control the movement direction of the text.

## Functions:
   - printHello: Prints "Hello World" at specified coordinates on the screen with a colored background.
   - printKey: Displays the ASCII code of a pressed key at a specific position on the screen.
   - main: Initializes modules, handles user input, updates the game state, and controls the program flow. It runs until the 'Enter' key is pressed.

## Program Flow:

1. **Initialization**:
   - The program begins by including necessary headers like `string.h`, `screen.h`, `keyboard.h`, and `timer.h` in `main.c`.
   - Global variables `x`, `y`, `incX`, and `incY` are initialized.

2. **Setting Up**:
   - `screenInit(1)` in `main.c` is called to initialize the screen with borders.
   - `keyboardInit()` in `main.c` is called to initialize non-blocking keyboard input.
   - `timerInit(50)` in `main.c` is called to set up a timer with a delay of 50 milliseconds.

3. **Printing "Hello World"**:
   - `printHello(x, y)` is called in `main.c` to display "Hello World" at the initial position. This function is located in `main.c`.

4. **Entering the Main Loop**:
   - The program enters a continuous loop (`while (ch != 10)`) in `main.c`. This loop keeps running until the 'Enter' key (ASCII 10) is pressed.

5. **Handling User Input**:
   - Within the loop:
     - `keyhit()` from `keyboard.c` is used to check if a key has been pressed.
     - If a key is pressed, `readch()` from `keyboard.c` is used to read the ASCII code of the key.
     - The ASCII code is then displayed on the screen using `printKey(ch)` located in `main.c`.

6. **Handling Timer Updates**:
   - `timerTimeOver()` from `timer.c` is used to check if the specified time delay has passed.
   - If the delay has passed, the game state is updated. Specifically:
     - The position of "Hello World" is adjusted based on the values of `incX` and `incY`.
     - The program checks if the text has reached the screen boundaries and changes direction if needed.
     - The ASCII code of the last pressed key is displayed again.

7. **Screen Updates**:
   - `screenUpdate()` from `screen.c` is called to flush the output buffer, ensuring that the screen is updated.

8. **Exiting the Loop**:
   - The loop continues until the 'Enter' key is pressed (`ch == 10`).

9. **Cleaning Up**:
   - After exiting the loop, the program proceeds to clean up and destroy modules:
     - `keyboardDestroy()` from `keyboard.c` is called to restore initial terminal settings.
     - `screenDestroy()` from `screen.c` is called to reset screen attributes and clear it.
     - `timerDestroy()` from `timer.c` is called to unset the delay.

10. **Returning from Main**:
    - Finally, the program returns 0, indicating successful execution.
