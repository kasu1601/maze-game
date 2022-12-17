
/* 	FILE NAME: buildMaze.c
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021
	INCLUDES : buildMaze.h
	REFERENCES : buildMaze.c file used in Assignment 1	*/

#include <stdio.h>
#include <stdlib.h>
#include "buildMaze.h"

/*	FUNCTION NAME: buildMaze
	PURPOSE: build the structure of the maze as determined by the metadata function
	IMPORTS: fileName, row, col
	EXPORTS: maze				*/

char** buildMaze(char* fileName, int row, int col)
{
	/*DECLARING VARIABLES*/
	char** maze = NULL; FILE *fptr = NULL;
	int i = 0; int rowPos = 0; int colPos = 0; int objectCode = 0;

	/*MAKING THE 2D ARRAY BASED OFF OF THE PASSED METADATA TABLE*/
	maze = (char **) calloc(sizeof(char *) , (row));
	
	for(i=0; i < row; i++)
	{
		maze[i] = (char *) calloc (sizeof(char) , (col));
	}
	
	/*OPEN FILE TO READ IN DATA*/
	fptr = fopen(fileName, "r");
	
	if(fptr == NULL) 
	{
		perror("Error opening the text file");
			
	}else{
	
		while(!feof(fptr))
		{
			fscanf(fptr,"%d%d%d", &rowPos, &colPos, &objectCode);
				
			/*FILLING UP THE 2D ARRAY USING GETMETADATA*/	
			if (objectCode == 3){
			
				maze[rowPos][colPos] = 'o';
				
			}else if (objectCode == 2){
		
				maze[rowPos][colPos] = 'x';
			}
		}
		
		/*CLOSE THE FILE AFTER READING DATA*/
		fclose(fptr); 	
	}
		
	return maze;
}
