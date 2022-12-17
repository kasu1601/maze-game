
/* 	FILE NAME : maze.c
	AUTHOR : HARSHI KASUNDI BANDARANAYAKE
	CURTIN ID : 20583387
	SLIIT ID : IT21151606
	UNIT CODE : COMP1000
	DATE : 02/10/2021
	INCLUDES : winCondition.h, loseCondition.h, initialMaze.h, map.h, buildMaze.h, snakeMovement.h, printMaze.h, movement.h, terminal.h linkedList.h	*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "winCondition.h"
#include "loseCondition.h"
#include "buildMaze.h"
#include "initialMaze.h"
#include "printMaze.h"
#include "movement.h"
#include "snakeMovement.h"
#include "linkedList.h"
#include "terminal.h"

int main (int argc, char* argv[]) 
{
	/*DECLARING VARIABLES*/
	int amount = 0; int row = 0; int col = 0; int rowPos = 0; int colPos = 0; int objectCode = 0; int i = 0;
	int playerRow = 0; int playerCol = 0; int snakeRow = 0; int snakeCol = 0; int goalRow = 0; int goalCol = 0;
	char player='^'; char direction =' '; char** maze = NULL; 
	void* remove; LinkedList* list;
  	
	
	/*CHECKS FOR THE CORRECT AMOUNT OF COMMAND LINE ARGUMENTS*/
	if(argc != 2) 
	{
		printf("Error : Please enter a file name!\n");
		
	}else{
		
		/*OPENING THE FILE TO READ IN DATA*/
		FILE *fptr = NULL;
		fptr = fopen(argv[1], "r");
		
		/*ERROR HANDLING : file does not exist*/
		if(fptr == NULL) 
		{
			perror("Error opening the text file");
			
		}else{
			/*READS IN MAZE DATA FOR ROW COLOMNS AND NO.OF OBJECTS*/
			fscanf(fptr,"%d%d%d", &amount, &row, &col);
		
			/*READING THE FILE TO GET PLAYER/GOAL/SNAKE LOCATIONS*/
			while(!feof(fptr))
			{
				fscanf(fptr,"%d%d%d", &rowPos, &colPos, &objectCode);
				
				if(objectCode == 0)
				{
					playerRow = rowPos;
					playerCol = colPos;
					
				}else if(objectCode == 1){
				
					snakeRow = rowPos;
					snakeCol = colPos;
					
				}else if(objectCode == 2){
					
					goalRow = rowPos;
					goalCol = colPos;
				}
			}
			
			/*CLOSE THE FILE AFTER READING DATA*/
			fclose(fptr); 	
			
			maze = buildMaze(argv[1],row,col);
			initialMaze(argv[1],row,col);
			
			/*CREATING A LINKED LIST*/
			list = createLinkedList();	
		
			/*PROGRAM LOOPS UNTIL THE PLAYER REACHES THE END OF THE GOAL OR THE SNAKE CATCHES UPTO THE PLAYER*/
			while((winCondition(&playerRow,&playerCol,goalRow,goalCol) == FALSE) && (loseCondition(&playerRow,&playerCol,&snakeRow,&snakeCol) == FALSE))
			{
				disableBuffer();
				scanf(" %c", &direction);
				enableBuffer();
				
				/*CLEARS THE TERMINAL BEFORE REPRINTING*/
				system("clear");
				
				/*CHECK FOR UNDO OPTION AND END OF THE LINKED LIST*/
				if(direction == 'u')
				{
					if((*list).head != NULL )
					{			
						remove = deleteFirst(list);
						player = *((char *)remove);
						free(remove);
						
						remove = deleteFirst(list);
						snakeCol = *((int *)remove);
						free(remove);
						
						remove = deleteFirst(list);
						snakeRow = *((int *)remove);
						free(remove);
						
						remove = deleteFirst(list);
						playerCol = *((int *)remove);
						free(remove);
						
						remove = deleteFirst(list);
						playerRow = *((int *)remove);
						free(remove);
					}
				
				}else{
					/*RECORD PLAYER MOVEMENTS INTO THE LINKED LIST*/
					insertFirst(list,&playerRow,sizeof(playerRow));
					insertFirst(list,&playerCol,sizeof(playerCol));
					insertFirst(list,&snakeRow,sizeof(snakeRow));
					insertFirst(list,&snakeCol,sizeof(snakeCol));
					insertFirst(list,&player,sizeof(player));
					
					/*UPDATE PLAYER'S POSITION*/
					player = movement(maze,direction,&playerRow,&playerCol,row,col);
					
					/*UPDATE SNAKE'S POSITION*/
					snakeMovement(maze,&playerRow,&playerCol,&snakeRow,&snakeCol,row,col);
				}
				
				/*PRINT THE UPDATED ARRAY*/
				printMaze(maze,player,&playerRow,&playerCol,&snakeRow,&snakeCol,row,col);
			}
			
			
			
			/*PRINT CONGRATULATORY MESSAGE IF PLAYER WINS*/
			if(winCondition(&playerRow,&playerCol,goalRow,goalCol) == TRUE)
			{
				printf("You Won :) Congratulations!!\n");
			
			/*PRINT GAME OVER MESSAGE IF PLAYER LOSES*/
			}else{
				printf("You Lost :( Try again.\n");
			}
			
			
			/*FREEING THE LINKED LIST*/
			freeLinkedList(list);
	
			/*MEMORY DE-ALLOCATION*/
			for(i = 0; i < row; i++)
			{
    				free(maze[i]);
    				maze[i] = NULL;
    			}
				free(maze);
				maze = NULL;
		}	
	}
	
	return 0;
}
