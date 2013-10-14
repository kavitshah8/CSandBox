/*
Concepts: Data structure starting with single linked list
*/
#include<stdio.h>
#include<stdlib.h>

// defining struct linkedlist as ll
typedef struct linkedlist ll;

// signly linked list with a pointer and a value 
struct linkedlist{
	ll *ptr;
	int value;
};

// declaring functions to manipulate singly linked list 
ll* insert_in_front(ll *,int);
ll* delete_in_front(ll *);
int traverse(ll *head);

int main(){

	int i;
	// creating a first header pointer (pivot for linked list)
	ll *head = NULL;

	// insterting elements in the linked list
	for(i=0;i<=9;i++){
		head = insert_in_front(head,i);
	}

	// checking elements are inserted properly or not ?
	traverse(head);
	printf("\n");

	// delelting elements from the linked list
	for(i=0;i<=1;i++){
		head = delete_in_front(head);
	}
	
	// checking elements are deleted properly or not ?
	traverse(head);
	printf("\n");

	return 0;
}

/* Logic for inserting a new node in the front of linked list 
Step 1: Create a pointer to new block of memory, assign a value using pointer variable
Step 2:	Check base case
Step 3: Link new node with last node in linked list using header
Step 4: Redirect header
*/
ll* insert_in_front(ll *head,int i){
	ll *n;
	n = malloc(sizeof(ll));
	n->value = i;
	if (head == NULL){
		head = n;
		head->ptr = NULL;
		return head;
	}
	n->ptr = head;
	head = n;
	return head;
}

/* Logic for deleting a node in the front of linked list 
Step 1: Create a temporary pointer
Step 2:	Is there any element to delete from Linked List ?
Step 3: Redirect new pointer to second last node in linked list using header
Step 4: Free last node
Step 5: Redirect header
*/
ll* delete_in_front(ll *head){
	ll *temp;
	if(head==NULL){
		printf("No Elements in the List to Delete\n");
		return head;
	}
	temp = head->ptr;
	free(head);
	head = temp;
	return head;
}

/* Logic for traversing a linked list from the front 
Step 1:	Traverse till the header points to NULL
Step 2: Print value of current node
Step 5: Redirect header to next node in the list
*/
int traverse(ll *head){

	while(head != NULL){
		printf("%d ",head->value);
		head = head->ptr;
	}
	printf("\n");
	return 0;
}