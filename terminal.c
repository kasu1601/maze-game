/* 
	FILE NAME: terminal.c
	SOURCE : provided with the Assignment 1
	DATE : 02/10/2021
	INCLUDES : terminal.h									*/

#include<stdio.h>
#include<termios.h>
#include"terminal.h"

/*	FUNCTION NAME: disableBuffer
	PURPOSE: allows to take in input w/o pressing the Enter key
	IMPORTS: NONE
	EXPORTS: NONE								*/
	
void disableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}

/*	FUNCTION NAME: enableBuffer
	PURPOSE: disables the buffer which allows to take in user input w/o pressing the Enter key
	IMPORTS: NONE
	EXPORTS: NONE								*/
	
void enableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag |= (ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}
