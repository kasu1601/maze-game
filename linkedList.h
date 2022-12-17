
/* 	FILE NAME: linkedList.h
	AUTHOR : Harshi Kasundi Bandaranayake
	DATE : 02/10/2021	
	PURPOSE: build a linked list	*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode {

	void* data;
	struct LinkedListNode* next;
	
} LinkedListNode;

typedef struct
{
	LinkedListNode* head;
	
} LinkedList;


LinkedList* createLinkedList();
void insertFirst(LinkedList *list, void* data,int size);
int listLength(LinkedListNode* h);
void* deleteFirst(LinkedList *list);
void freeLinkedList(LinkedList *list);


#endif
