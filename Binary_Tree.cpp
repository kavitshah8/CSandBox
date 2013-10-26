/*
Concepts: Data structure starting with Binary Trees
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

struct node{
	int value;
	node *left;
	node *right	;
};

node* new_node(int value);
node * _insert(node *,int);
node * _delete(node *);
int lookup(node *);

int main(){

	int i;
	node *root = NULL;
	
	for(i=0;i<10;i++){
		root = _insert(root,i);
	}

	return 0;
}

node* new_node(int value){
	node *root;
	root = malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	root->value = value;
	return (root);
}

node * _insert(node* root, int value){
			
	if(root == NULL){
		return(new_node(value));	
	}	
	else {
		if(value<= root->value)
			root->left = _insert(root->left,value);
		else
			root->right = _insert(root->right,value);
	}
	return root;
}
