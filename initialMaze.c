
/* 	FILE NAME: initialMaze.c
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021
	INCLUDES : initialMaze.h
	REFERENCES : initialMaze.c file used in Assignment 1	*/

#include <stdio.h>
#include <stdlib.h>
#include "initialMaze.h"

/* 	FUNCTION NAME: initialMaze
	PURPOSE: build and print out the original maze with the initial position of the player as determined by the metadata function
	IMPORTS: visibility, doublePtr, amount, row, col
	EXPORTS: NONE 								*/
	
void initialMaze(char* fileName, int row, int col)
{
	/*DECLARING VARIABLES*/
	int i = 0; int j = 0;
	int rowPos = 0; int colPos = 0; int objectCode = 0;
	char** maze = NULL; FILE *fptr = NULL;
	
	/*MAKING THE 2D ARRAY*/
	maze = (char **) calloc(sizeof(char *) , (row));
	
	for(i=0; i < row; i++)
	{
		maze[i] = (char *) calloc (sizeof(char) , (col));
	}
	
	/*FILLING UP THE 2D ARRAY USING GETMETADATA*/
	
	fptr = fopen(fileName, "r");
	
	if(fptr == NULL) 
	{
		perror("Error opening the text file");
			
	}else{
		while(!feof(fptr))
		{
			fscanf(fptr,"%d%d%d", &rowPos, &colPos, &objectCode);
				
			/*FILLING UP THE 2D ARRAY USING GETMETADATA*/	
			if(objectCode == 3){
			
				maze[rowPos][colPos] = 'o';
					
			}else if(objectCode == 2){
		
				maze[rowPos][colPos] = 'x';
			
			}else if(objectCode == 1){
		
				maze[rowPos][colPos] = '~';
			
			}else if(objectCode == 0){
			
				maze[rowPos][colPos] = '^';
			}	
		}
		
		/*CLOSE THE FILE AFTER READING DATA*/
		fclose(fptr); 	
	}		
	
	/*PRINTING OUT THE MASTER ARRAY*/
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			/*PRINTING OUT THE WALL OF THE MAZE*/
			if(i == 0 || i == row - 1 || j == 0 || j == col - 1)
			{
				printf("#");
				printf(" ");
			
			/*FILLING OUT THE EMPTY AREAS*/
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

	/*MEMORY DE-ALLOCATION*/
	for(i = 0; i < row; i++)
	{
    		free(maze[i]);
    		maze[i] = NULL;
    	}

	free(maze);
	maze = NULL;
}
