
/* 	FILE NAME: loseCondition.c
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021
	INCLUDES : loseCondition.h	*/
	
#include <stdio.h>
#include "loseCondition.h"

/* 	FUNCTION NAME: loseCondition
	PURPOSE: determines whether the user has stepped on the snake 
	IMPORTS: pRow, pCol, sRow, sCol
	EXPORTS: endReached	*/
	
int loseCondition(int *pRow, int *pCol, int *sRow, int *sCol)
{
	int endReached = 0;
	
	if(*pRow== *sRow && *pCol == *sCol) /*PLAYER HAS BEEN CAUGHT BY THE SNAKE*/
	{
   		 endReached = TRUE;
   		 
   	}else{
   		 endReached = FALSE;
   	}
   	
   	return endReached;
}


