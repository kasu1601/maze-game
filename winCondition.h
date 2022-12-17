
/* 	FILE NAME: winCondition.h
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021
	PURPOSE: determines whether the user has reached the goal 	*/
	
#ifndef WINCONDITION_H
#define WINCONDITION_H

#define FALSE 0
#define TRUE !FALSE

int winCondition(int *pRow, int *pCol, int gRow, int gCol);

#endif
