/*
Concepts: Data structure starting with Circular Linked List
*/
#include<stdio.h>
#include<stdlib.h>

// defining struct circularlinkedlist as cll
typedef struct circularlinkedlist cll;

// circular linked list with a pointer and an integer value 
struct circularlinkedlist{
	cll *ptr;
	int value;
};

// declaring functions to manipulate circular linked list 
cll * insert_in_front(cll *,int);
cll * delete_from_front(cll *);
int traverse(cll *);

int main(){

	int i;
	// creating a first header pointer (pivot for linied list)
	cll *head = NULL;
	
	// insterting elements in the front of circular linked list
	for(i=0;i<=9;i++){
		head = insert_in_front(head,i);
	}

	// checking are elements inserted properly or not ?
	traverse(head);
	printf("\n");

	// delelting elements from the circular linked list
	for(i=0;i<=1;i++){
		head = delete_from_front(head);
	}
	
	// checking are elements deleted properly or not ?
	traverse(head);
	printf("\n");

	return 0;
}

/* Logic for inserting a new node in the front of a circular linked list 
Step 1: Create a pointer which points to new block of memory; assign a value to structure variable using pointer
Step 2:	Check base case
"You have to add two links; one link is direct but for other link one you have to traverse"
Step 3: Link new node's pointer where head is pointing (first link)
Step 4: Traverse towards the end of the list and add the link between last node and new node
Step 5: Redirect header to the new node
*/
cll* insert_in_front(cll *head,int i){
	cll *n,*temp;
	n = malloc(sizeof(cll));
	n->value = i;
	if (head == NULL){
		head = n;
		head->ptr = head;
		return head;
	}
	n->ptr = head;
	temp = head->ptr;
	while(head != temp->ptr){
		temp = temp->ptr;
	}
	temp->ptr= n;
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
cll* delete_from_front(cll *head){
	cll *temp;
	if(head==NULL){
		printf("No Elements in the List to Delete\n");
		return head;
	}
	temp = head->ptr;
	while(temp->ptr != head){
		temp = temp->ptr;
	}
	temp->ptr = head->ptr;
	free(head);
	head = temp->ptr;
	return head;
}

/* Logic for traversing a circular linked list from the front 
Step 1:	Traverse till the temporary pointer points to header
*/
int traverse(cll *head){
	cll *temp;
	temp = head;
	if(head == NULL)
		printf("empty \n");

	while(temp->ptr != head){
		printf("%d ",temp->value);
		temp = temp->ptr;
	}
	printf("\n");
	return 0;
}
