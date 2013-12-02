/*
Thesis: Tree based Group Key Management
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Global variables
extern int NODES;
extern int HEIGHT;

//Data structure
typedef struct
{
	unsigned int publicValue, privateValue, height, depth, type;
	struct node_t *left;
	struct node_t *right;
	struct node_t *next;
	struct node_t *parent;
}node_t;


// Function Prototypes
void join(node_t **, node_t **);
node_t * find_sponsor(node_t **);
node_t * new_node(unsigned int);
void update_tree(node_t **, node_t **, node_t **, node_t **);
void update_depth(node_t *);

int main()
{
	node_t *root=NULL;
	node_t *header=NULL;
	
	join(&root , &header);

	return 0;
}


void join(node_t ** root, node_t ** header)
{
	node_t *leaf;
	node_t *node;
	
	if(*root == NULL)
	{	
		 // 1- leaf ; 0 - node
		 leaf = new_node(1);
		 (*root) = leaf;
		 (*header) = leaf;
	}
	else
	{
		leaf = new_node(1);
		node = new_node(0);
		update_tree(root, header, &node, &leaf);
	}
}

void update_tree(node_t **root, node_t **header, node_t **node, node_t **leaf)
{
	node_t *sponsor;
	// BASE CASE
	if (NODES == 1)
	{
		(*node)->left = (*root); 
		(*node)->right = (*leaf);
		(*node)->height = 1;

		(*root)->parent = (*node);
		(*root)->next = (*leaf);
		(*root)->depth = (*node)->height + 1;

		(*leaf)->parent = (*node);
		(*leaf)->next = NULL;
		(*leaf)->depth = (*node)->height + 1;

		(*root) = (*node); 
		NODES ++;
		HEIGHT++;
	}
	else if(NODES = ((int)pow(2,(float)HEIGHT) - 1))
	{
		(*node)->left = (*root); 
		(*node)->right = (*leaf);
		(*node)->height = (*root)->height + 1;

		(*root)->parent = (*node);
		(*root) = (*node);
		//depth_update(header);
		//(*root)->next = (*leaf);
		//(*root)->depth = (*node)->height + 1;

		(*leaf)->parent = (*node);
		(*leaf)->next = NULL;
		(*leaf)->depth = 1;

		sponsor = find_sponsor(header);
		(*root) = (*node); 
		NODES ++;
		HEIGHT++;
	}

}
node_t * find_sponsor(node_t ** header)
{
	int d;
	node_t * sponsor;
	node_t * temp;
	*temp = (*header);
	
	d =0;

	while(*temp !=NULL)
	{
		if((*temp)->depth) <= d)
		{
			d = (*temp)->depth;
			*sponsor = temp;
		}
		temp = temp.next;
	}
	return &sponsor;
}

node_t * new_node(unsigned int);
