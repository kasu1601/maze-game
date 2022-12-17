
/* 	FILE NAME: winCondition.c
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021
	INCLUDES : winCondition.h
	REFERENCES : winCondition.c file used in Assignment 1	*/
	
#include <stdio.h>
#include "winCondition.h"

/* 	FUNCTION NAME: winCondition
	PURPOSE: determines whether the user has reached the goal 
	IMPORTS: pRow, pCol, gRow, gCol
	EXPORTS: endReached	*/
	
int winCondition(int *pRow, int *pCol, int gRow, int gCol)
{
	int endReached = 0;
	
	if(*pRow==gRow && *pCol ==gCol) /*PLAYER HAS REACHED THE GOAL*/
	{
   		 endReached = TRUE;
   	}else{
   		 endReached = FALSE;
   	}
   	
   	return endReached;
}


