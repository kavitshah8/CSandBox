/*
Thesis: Tree based Group Key Management
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	NODES represents # of intermediate nodes (ie without counting the leaf nodes)
	HEIGHT represents the height of a tree
	Binary Tree < = > Number of intermediate nodes = (2^ height of a tree - 1)
	These two globale variables helps identify the binary tree using above formula
*/
extern int NODES;
extern int HEIGHT;

//Data structure
typedef struct
{
	// unit32_t (needs to figure out)
	unsigned int publicValue, privateValue, height, depth, type;
	struct node_t *left;
	struct node_t *right;
	struct node_t *next;
	struct node_t *parent;
}node_t;

// Function Prototypes
node_t * new_node(unsigned int);
node_t * find_sponsor(node_t **);
void join(node_t **, node_t **);
void update_tree(node_t **, node_t **);//, node_t **, node_t **);
void update_depth(node_t *);

int main()
{
	node_t *root=NULL;
	node_t *header=NULL;
	NODES = 0;
	HEIGHT = 0;
	join(&root , &header);
	
	return 0;
}
// Checked
node_t * new_node(unsigned int i)
{	
	node_t *temp;
	temp = (node_t*) malloc(sizeof(node_t));
	return temp;
}
node_t * find_sponsor(node_t ** header)
{
	int d;
	node_t * sponsor;
	node_t * temp;
	*temp = (*header);
	
	d =0;

	while(*temp != NULL)
	{
		if((*temp)->depth) <= d)
		{
			d = (*temp)->depth;
			*sponsor = temp;
		}
		temp = temp->next;
	}
	return sponsor;
}
// Checked
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
		/*
		leaf = new_node(1);
		node = new_node(0);
		NODES ++;
		// */
		update_tree(root, header);//, &node, &leaf);
	}
}
void update_tree(node_t **root, node_t **header)//, node_t **node, node_t **leaf)
{
	node_t *sponsor;
	node_t *temp;
	node_t *leaf;
	node_t *node;
	leaf = new_node(1);
	node = new_node(0);
	NODES ++;
	// BASE CASE
	if (NODES == 1)
	{
		(node)->left = &(*root); 
		(node)->right = (*leaf);
		(node)->height = 1;

		(*root)->parent = (*node);
		(*root)->next = (*leaf);
		(*root)->depth = (*node)->height + 1;

		(*leaf)->parent = (*node);
		(*leaf)->next = NULL;
		(*leaf)->depth = (*node)->height + 1;

		(*root) = (*node); 
		
		HEIGHT++;
	}
	else if(NODES == ((int)pow(2,(float)HEIGHT) - 1))
	{
		(*node)->left = (*root); 
		(*node)->right = (*leaf);
		(*node)->height = (*root)->height + 1;

		(*root)->parent = (*node);
		(*root) = (*node);
		// depth_update(header);
		//(*root)->next = (*leaf);
		//(*root)->depth = (*node)->height + 1;

		(*leaf)->parent = (*node);
		(*leaf)->next = NULL;
		(*leaf)->depth = 1;

		sponsor = find_sponsor(header);
		(*sponsor)->next = (*leaf);

		
		NODES ++;
		HEIGHT++;
	}

	else
	{
		sponsor = find_sponsor(header);
		(*node)->left = sponsor; 
		(*node)->right = (*leaf);
		(*node)->parent = sponsor->parent;
		(*node)->height = (*root)->height + 1;
		
		temp = (*sponsor)->next; 
 		(*sponsor)->next = (*leaf);
		(*sponsor)->parent =(*node);
		sponsor->depth ++;

		(*leaf)->parent = (*node);
		(*leaf)->next = temp;
		(*leaf)->depth = sponsor->depth;
		
		NODES ++;
	}

}
void update_depth(node_t *)
{

}


