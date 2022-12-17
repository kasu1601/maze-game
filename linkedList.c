
/* 	FILE NAME: linkedList.c
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021
	INCLUDES : linkedList.h	*/
	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"

/*	FUNCTION NAME: createLinkedList
	PURPOSE: create an empty linked list
	IMPORTS: NONE
	EXPORTS: list			*/

LinkedList* createLinkedList()
{
	LinkedList* list = (LinkedList *) malloc (sizeof(LinkedList));
	(*list).head = NULL;
	
	return list;
}


/*	FUNCTION NAME: listLength
	PURPOSE: calculates the length of the linked list
	IMPORTS: LinkedListNode 
	EXPORTS: length				*/

int listLength(LinkedListNode* h)
{
  int length=0;

  if(h != NULL)
  {
    length = 1+ listLength((*h).next);
  }

  return length;
}


/*	FUNCTION NAME: insertFirst
	PURPOSE: adds a linked list node beginning of the linked list
	IMPORTS: list, data, size
	EXPORTS: NONE				*/

void insertFirst(LinkedList *list, void* data, int size)
{
   LinkedListNode* newNode;
   
   newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
   (*newNode).next = (*list).head;
   (*list).head = newNode;

   (*newNode).data = malloc(size);
   memcpy(newNode->data, data, size); 
}


/*	FUNCTION NAME: deleteFirst
	PURPOSE: deletes the first node of the linked list and returns data stored in it
	IMPORTS: NONE
	EXPORTS: temp				*/

void* deleteFirst(LinkedList *list) 
{	
   void* temp;
   LinkedListNode* tempLink;
   tempLink = (*list).head;
   
   if(tempLink != NULL )
   {
   	(*list).head = (*tempLink).next;
   }
   
   temp = (*tempLink).data; 
   free(tempLink);
   
   return temp;
   
}

/*	FUNCTION NAME: freeLinkedList
	PURPOSE: de-allocates memory in the linked list
	IMPORTS: list
	EXPORTS: NONE			*/

void freeLinkedList(LinkedList *list)
{
  LinkedListNode *current, *nextNode;
  current = (*list).head;
  
  while(current != NULL)
  {
       nextNode = (*current).next;
       free(current->data); 
       free(current); 
       current = nextNode;
  }
  
  free(list);
}	

