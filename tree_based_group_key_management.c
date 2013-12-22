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
        unsigned int publicValue, privateValue, type,depth;
        struct node_t *left;
        struct node_t *right;
        struct node_t *next;
        struct node_t *parent;
};


// Function Prototypes
void join(struct node_t **,struct node_t **);
//struct node_t * find_sponsor(struct node_t **);
struct node_t * new_node(unsigned int);
int size(struct node_t *);
//void update_depth(struct node_t *);

int main()
{
        struct node_t *root=NULL;
        struct node_t *header=NULL;
        NODES = 0;
		HEIGHT =0;
        join(&root , &header);
		//printf("%d\n",size(root));
        return 0;
}
struct node_t * new_node(unsigned int i)
{
	struct node_t * node;
	
	node = (struct node_t*)malloc(sizeof(struct node_t));
	
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->next = NULL;
	node->depth = 0;
	return node;
}

void join(struct node_t ** root, struct node_t ** header)
{
        struct node_t *leaf,*node,*temp,*sponsor;
		int d;
		d = 0;

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
			NODES ++;
			
			// BASE CASE
			if (NODES == 1)
			{
                (node)->left = (*root);
                (node)->right = (leaf);
                //(node)->height = 1;

                (*root)->parent = (node);
                (*root)->next = (leaf);
				(*root)->depth = 1;
                
                (leaf)->parent = (node);
                (leaf)->next = NULL;
				(leaf)->depth = 1;

                (*root) = (node);
				// same as root's height
                HEIGHT++;
			}        
			
			else if(NODES == ((2^HEIGHT) - 1))
			{
                //Update Depth of each node
				temp = *header;
				while(temp != NULL)
				{
					temp -> depth++ ;
					temp = temp -> next;
				}

				(node)->left = (*root);
                (node)->right = (leaf);
                //(node)->height = (*root)->height + 1;

                (*root)->parent = (node);
                (*root) = (node);
                
                //(*root)->next = (*leaf);
                //(*root)->depth = (*node)->height + 1;

                (leaf)->parent = (node);
                (leaf)->next = NULL;
                (leaf)->depth = 1;

				//sponsor = find_sponsor(header);
				//Find the sponsor in Balanced Binary case
				sponsor = *header;
			    while(sponsor != NULL)
				{
					sponsor = sponsor->next;
				}
				
				sponsor->next = leaf;

				(*root) = (node);

                HEIGHT++;
			}
			
			else
			{
				//sponsor = find_sponsor(header);
				// To find shallowest right most leaf in tree
				sponsor = (*header);
				d = sponsor -> depth;

		        while(sponsor !=NULL)
				{		
					if((sponsor)->depth < d)
					{
                        d = (sponsor)->depth;
                        sponsor = temp;
					}
					sponsor = sponsor->next;
				}
			
				(node)->left = sponsor;
				(node)->right = (leaf);
				(node)->parent = sponsor->parent;
				//(node)->height = 1;
				
				sponsor->parent = node;
				sponsor->next = leaf;
				//sponsor->depth ++;

				leaf->next = NULL;
				leaf->parent = (node);
				//leaf->depth = sponsor->depth;
			}

		}
}

// Finds shallowest rightmost leaf
/*
struct node_t * find_sponsor(struct node_t ** header)
{
        int d;
        struct node_t * sponsor,* temp;
        
		temp = (*header);
		d = temp->depth;

        while(temp !=NULL)
        {		
                if((temp)->depth < d)
                {
                        d = (temp)->depth;
                        sponsor = temp;
                }
                temp = temp->next;
        }
        return sponsor;
}
*/
/*
int size(struct node_t *root){
        if (root==NULL)
                return 0;
        else
                return(size(root->left)+1+size(root->right));
}
*/