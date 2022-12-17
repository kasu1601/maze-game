/* 
	FILE NAME: printMaze.c
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021
	INCLUDES : printMaze.h
	REFERENCES : printMaze.c file used in Assignment 1
																	*/

#include <stdio.h>
#include "printMaze.h"

/* 	FUNCTION NAME: printMaze
	AUTHOR : Harshi Kasundi Bandaranayake
	PURPOSE: reprints the updated maze everytime the user moves around the map
	IMPORTS: maze, symbol, pRow, pCol, sRow, sCol, rows, cols
	EXPORTS: NONE
																	*/

void printMaze(char** maze, char symbol, int* pRow, int* pCol,int* sRow, int* sCol, int rows, int cols){
	
	/*DECLARING VARIABLES*/
	int i = 0; int j = 0; 
	
	for(i = 0; i < rows; i++)
	{
    		for(j=0; j < cols; j++)
    		{
        		if(j == *pCol && i== *pRow)
        		{ 
           	    		maze[i][j] = symbol;
        		}
        	}
        }
        
        for(i = 0; i < rows; i++)
	{
    		for(j=0; j < cols; j++)
    		{
        		if(j == *sCol && i== *sRow)
        		{ 
           	    		maze[i][j] = '~';
        		}
        	}
        }
	
	/*PRINTING OUT THE ARRAY*/
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
			{
				printf("#");
				printf(" ");
				
			}else if (maze[i][j] == '\0'){
			
                		maze[i][j] = ' ';
                		printf("%c",maze[i][j]);
                		printf(" ");
                		
            		}else{
				printf("%c",maze[i][j]);
				printf(" ");
			}
		}
		printf("\n\n");
	}
	
	/*CLEARING OUT THE MAZE BEFORE THE NEXT REPRINT*/
	for(i = 0; i < rows; i++)
	{
    		for(j=0; j < cols; j++)
    		{
        		if(j == *pCol && i== *pRow)
        		{ 
           	    		maze[i][j] = '\0';
        		}
        	}
        }
        
        for(i = 0; i < rows; i++)
	{
    		for(j=0; j < cols; j++)
    		{
        		if(j == *sCol && i== *sRow)
        		{ 
           	    		maze[i][j] = '\0';
        		}
        	}
        }
}
