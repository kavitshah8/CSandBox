/*
Thesis: Tree based Group Key Management
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Global variables
int NODES;
int HEIGHT;

//Data structure
struct node_t
{
        unsigned int publicValue, privateValue, height, depth, type;
        struct node_t *left;
        struct node_t *right;
        struct node_t *next;
        struct node_t *parent;
};


// Function Prototypes
void join(struct node_t **,struct node_t **);
struct node_t * find_sponsor(struct node_t **);
struct node_t * new_node(unsigned int);
//void update_tree(struct node_t **, struct node_t **);//, struct node_t **, struct node_t **);
//void update_depth(struct node_t *);

int main()
{
        struct node_t *root=NULL;
        struct node_t *header=NULL;
        NODES = 0;
		HEIGHT =0;
        join(&root , &header);

        return 0;
}
struct node_t * new_node(unsigned int i)
{
	struct node_t * ret;
	ret = (struct node_t*)malloc(sizeof(struct node_t));
	return ret;
}

void join(struct node_t ** root, struct node_t ** header)
{
        struct node_t *leaf;
        struct node_t *node;
        if(*root == NULL)
        {        
                 // 1- leaf ; 0 - node
                 leaf = new_node(1);
                 (*root) = leaf;
                 (*header) = leaf;
        }
        else
        {
			struct node_t *sponsor;
			struct node_t * leaf,* temp,*node;
			leaf = new_node(1);
			node = new_node(0);
			NODES ++;
			// BASE CASE
			if (NODES == 1)
			{
                (node)->left = (*root);
                (node)->right = (leaf);
                (node)->height = 1;

                (*root)->parent = (node);
                (*root)->next = (leaf);
                (*root)->depth = (node)->height + 1;

                (leaf)->parent = (node);
                (leaf)->next = NULL;
                (leaf)->depth = (node)->height + 1;

                (*root) = (node);
                HEIGHT++;
			}        
			else if(NODES == ((2^HEIGHT) - 1))
			{
                (node)->left = (*root);
                (node)->right = (leaf);
                (node)->height = (*root)->height + 1;

                (*root)->parent = (node);
                (*root) = (node);
                //depth_update(header);
                //(*root)->next = (*leaf);
                //(*root)->depth = (*node)->height + 1;

                (leaf)->parent = (node);
                (leaf)->next = NULL;
                (leaf)->depth = 1;

                sponsor = find_sponsor(header);
                (*root) = (node);

                HEIGHT++;
			}
			else
			{
				sponsor = find_sponsor(header);
				(node)->left = sponsor;
                (node)->right = (leaf);
				(node)->parent = sponsor->parent;
				(node)->height = sponsor->depth;
				
				sponsor->parent = node;
				sponsor->next = leaf;
				sponsor->depth ++;

				leaf->next = NULL;
				leaf->parent = (node);
				leaf->depth = sponsor->depth;
			}

		}
}

struct node_t * find_sponsor(struct node_t ** header)
{
        int d;
        struct node_t * sponsor;
        struct node_t * temp;
        temp = (*header);
        
        d =0;

        while(temp !=NULL)
        {
                if((temp)->depth <= d)
                {
                        d = (temp)->depth;
                        sponsor = temp;
                }
                temp = temp->next;
        }
        return sponsor;
}
