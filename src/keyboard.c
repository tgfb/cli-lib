/**
 * keyboard.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include <termios.h>
#include <unistd.h>

#include "keyboard.h"

static struct termios initialSettings, newSettings;
static int peekCharacter;


void keyboardInit()
{
    tcgetattr(0,&initialSettings);
    newSettings = initialSettings;
    newSettings.c_lflag &= ~ICANON;
    newSettings.c_lflag &= ~ECHO;
    newSettings.c_lflag &= ~ISIG;
    newSettings.c_cc[VMIN] = 1;
    newSettings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &newSettings);
}

void keyboardDestroy()
{
    tcsetattr(0, TCSANOW, &initialSettings);
}

int keyhit()
{
    unsigned char ch;
    int nread;

    if (peekCharacter != -1) return 1;
    
    newSettings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &newSettings);
    nread = read(0,&ch,1);
    newSettings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &newSettings);
    
    if(nread == 1) 
    {
        peekCharacter = ch;
        return 1;
    }
    
    return 0;
}

int readch()
{
    char ch;

    if(peekCharacter != -1)
    {
        ch = peekCharacter;
        peekCharacter = -1;
        return ch;
    }
    read(0,&ch,1);
    return ch;
}
