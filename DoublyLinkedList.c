/*
Concepts: Data structure starting with doubly linked list
*/
#include<stdio.h>
#include<stdlib.h>

// defining struct doublylinkedlist as dll
typedef struct doublylinkedlist dll;

// signly linked list with a pointer and a value 
struct doublylinkedlist {
	dll *bwptr;
	dll *fwptr;
	int value;
};

// declaring functions to manipulate singly linked list 
dll * insert_in_front(dll * ,int);
dll * delete_from_front(dll *);
int traverse(dll *);

int main(){
	int i;
	// creating a first header pointer (pivot for linked list)
	dll *head = NULL;
		
	// insterting elements in the linked list
	for(i=0;i<=9;i++){
		head = insert_in_front(head,i);
	}

	// checking elements are inserted properly or not ?
	traverse(head);
	printf("\n");

	// delelting elements from the linked list
	for(i=0;i<=3;i++){
		head = delete_from_front(head);
	}
	
	// checking elements are deleted properly or not ?
	traverse(head);
	printf("\n");
	return 0;
}

/* Logic for inserting a new node in the front of doubly linked list 
Step 1: Create a pointer which points to new block of memory; assign a value to a structure variable using pointer
Step 2:	Check base case
Step 3: Link new node's forward pointer to where head is pointing
Step 4: Redirect header
*/
dll * insert_in_front(dll *head ,int i) {

	dll *n;
	n = malloc(sizeof(dll));
	n->value = i;
	if(head ==NULL){
		n->fwptr = NULL;
		head = n;
		return head;
	}
	n->fwptr = head;
	head = n;
	return head;
}
/* Logic for deleting a node from the front of linked list 
Step 1: Create a pointer which points to new block of memory; assign a value to a structure variable using pointer
Step 2:	Check base case
Step 3: Link new node's forward pointer to where head is pointing
Step 4: Redirect header
*/
dll * delete_from_front(dll *head) {

	dll *temp;
	if(head ==NULL){
		printf("LIST IS EMPTY; NOTHING TO DELETE\n");
		return head;
	}
	temp = head->fwptr;
	free(head);
	head = temp;
	return head;
}

/* Logic for traversing from the front of doubly linked list 
Step 1:	Check base case
Step 2: print the value of a node, redirect the head pointer until head points to NULL
*/
int traverse(dll *head) {
	
	if(head==NULL){
		printf("List is empty\n");
	}
	while(head != NULL){
		printf("%d ",head->value);
		head = head->fwptr;
		}
	printf("\n\n");
	return 0;
}