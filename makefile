CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = maze.o initialMaze.o terminal.o buildMaze.o winCondition.o loseCondition.o printMaze.o movement.o linkedList.o snakeMovement.o
EXEC = maze

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

maze.o : maze.c initialMaze.h terminal.h buildMaze.h winCondition.h loseCondition.h printMaze.h movement.h snakeMovement.h linkedList.h
	$(CC) $(CFLAGS) maze.c -c

initialMaze.o : initialMaze.c initialMaze.h
	$(CC) $(CFLAGS) initialMaze.c -c
	
terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c
	
buildMaze.o : buildMaze.c buildMaze.h
	$(CC) $(CFLAGS) buildMaze.c -c
	
winCondition.o : winCondition.c winCondition.h
	$(CC) $(CFLAGS) winCondition.c -c
	
loseCondition.o : loseCondition.c loseCondition.h
	$(CC) $(CFLAGS) loseCondition.c -c
	
printMaze.o : printMaze.c printMaze.h
	$(CC) $(CFLAGS) printMaze.c -c

movement.o : movement.c movement.h
	$(CC) $(CFLAGS) movement.c -c
	
snakeMovement.o : snakeMovement.c snakeMovement.h
	$(CC) $(CFLAGS) snakeMovement.c -c
	
linkedList.o : linkedList.c linkedList.h
	$(CC) $(CFLAGS) linkedList.c -c

clean :
	rm -f $(EXEC) $(OBJ) 
