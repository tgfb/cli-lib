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

