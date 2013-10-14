#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist ll;

struct linkedlist{
	ll *ptr;
	int value;
};

ll* insert_in_front(ll *,int);
ll* delete_in_front(ll *);
int traverse(ll *head);

int main(){

	int i;
	ll *head = NULL;

	for(i=0;i<=9;i++){
		head = insert_in_front(head,i);
	}

	traverse(head);
	printf("\n");

	for(i=0;i<=1;i++){
		head = delete_in_front(head);
	}
	
	traverse(head);
	printf("\n");

	return 0;
}

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

int traverse(ll *head){

	while(head != NULL){
		printf("%d ",head->value);
		head = head->ptr;
	}
	printf("\n");
	return 0;
}