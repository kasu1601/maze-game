
/* 	FILE NAME: movement.c
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021
	INCLUDES : movement.h,	*/
	
#include <stdio.h>
#include <stdlib.h>
#include "movement.h"

/* 	FUNCTION NAME: movement
	PURPOSE: takes user input and determines the whether the player should be allowed to move or not and changes player co-ordinates accordingly
	IMPORTS: maze, direction, pRow, pCol, row, col
	EXPORTS: pSymbol
																							*/
char movement(char** maze, char direction,int* pRow, int* pCol, int row, int col)
{
	/*DECLARING VARIABLES*/
	char pSymbol = '^';
	
	/*WHERE direction is 'w' = UP, 's' = DOWN, 'a' = LEFT and 'd' = RIGHT*/
	switch(direction)
	{
		case 'w':
		
			pSymbol = '^';
			
			/*CHECKS IF THE PLAYER IS TRYING TO GO OUT OF THE MAP OR PASS THROUGH A WALL*/
			if(maze[*pRow-1][*pCol] != 'o' && *pRow - 1 < row-1 && *pRow - 1 > 0)
			{
				--*pRow;
			}
			
		break;
		
		case 's':
		
			pSymbol = 'v';
			
			if(maze[*pRow+1][*pCol] != 'o' && *pRow+1 < row-1 && *pRow + 1 > 0)
			{
				++*pRow;
			}	
			
		break;
		
		case 'a':
		
			pSymbol = '<';
			
			if(maze[*pRow][*pCol-1] != 'o' && *pCol-1 < col-1 && *pCol - 1 > 0)
			{
				--*pCol;
			}
			
		break;
		
		case 'd':
		
			pSymbol = '>';
			
			if(maze[*pRow][*pCol+1] != 'o' && *pCol+1 < col-1 && *pCol + 1 > 0)
			{
				++*pCol;
			}
			
		break;
	
		/*DO NOTHING TO PLAYER'S POSITION*/
		default:
		
			pSymbol = '^';
	}
	
	return pSymbol;	
}
