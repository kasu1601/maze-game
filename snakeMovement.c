
/* 	FILE NAME: snakeMovement.c
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021
	INCLUDES : snakeMovement.h	*/
	
#include <stdio.h>
#include <stdlib.h>
#include "snakeMovement.h"

/* 	FUNCTION NAME: snakeMovement
	PURPOSE: moves the snake around the map to follow player
	IMPORTS: maze, pRow, pCol, sRow, sCol, row, col
	EXPORTS: NONE
																							*/
void snakeMovement(char** maze,int* pRow, int* pCol, int* sRow, int* sCol, int row, int col)
{
	if(*sRow < *pRow && maze[*sRow+1][*sCol] != 'o' && *sRow + 1 < row && *sRow + 1 > 0 && *sCol < col && *sCol > 0)
	{
		++*sRow;
			
	}else if(*sRow > *pRow && maze[*sRow-1][*sCol] != 'o' && *sRow - 1 < row && *sRow - 1 > 0 && *sCol < col && *sCol > 0){
	
		--*sRow;

	}else if(*sCol < *pCol && maze[*sRow][*sCol+1] != 'o' && *sCol + 1 < col && *sCol + 1 > 0 && *sRow < row && *sRow > 0){
	
		++*sCol;
		
	}else if(*sCol > *pCol && maze[*sRow][*sCol-1] != 'o' && *sCol - 1 < col && *sCol + 1 > 0 && *sRow < row && *sRow > 0){
	
		--*sCol;
		
	}/*else if(*sRow == *pRow){
	
		if(*sCol < *pCol && maze[*sRow][*sCol+1] != 'o' && *sCol + 1 < col && *sCol + 1 > 0 && *sRow < row && *sRow > 0){
		
			++*sCol;
		
		}else if(*sCol > *pCol && maze[*sRow][*sCol-1] != 'o' && *sCol - 1 < col && *sCol - 1 > 0 && *sRow < row && *sRow > 0){
	
			--*sCol;
		}

	}else if(*sCol == *pCol){
	
		if(*sRow < *pRow && maze[*sRow+1][*sCol] != 'o' && *sCol + 1 < col && *sCol + 1 > 0 && *sRow < row && *sRow > 0){
			
			++*sRow;
		
		}else if(*sRow > *pRow && maze[*sRow-1][*sCol] != 'o' && *sRow - 1 < col && *sRow - 1 > 0 && *sRow < row && *sRow > 0){
	
			--*sRow;
		}
	}*/	
}
	
