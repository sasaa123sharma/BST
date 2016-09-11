//Delete a node in BST
//
//Test cases
//1. Delete leaf node
//1. Delete node with one child
//1. Delete node with two children

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
}NODE;

void InsertNode(NODE **root, int data)
{
	if(!*root)
	{
		NODE *new = malloc(sizeof(NODE));
		
		new->right = NULL;
		new->left = NULL;	
		new->data = data;
		*root = new;
	}
	
	else if((*root)->data < data)
		InsertNode(&(*root)->right, data);


	else if((*root)->data > data)
		InsertNode(&(*root)->left, data);

	return;
}

void PrintInorder(NODE *tree)
{
	if(tree)
	{
		PrintInorder(tree->left);
		printf("%d  ", tree->data);
		PrintInorder(tree->right);
	}
	return;
}

NODE *FindMin(NODE *root)
{
	if(root)
		while(root->left)
			root = root->left;

	return root;
}

void DeleteNode(NODE **tree, int data)
{
	if(*tree)
	{
		if((*tree)->data < data)
			DeleteNode(&(*tree)->right, data);		

		else if((*tree)->data > data)
			DeleteNode(&(*tree)->left, data);		

		else
		{
			if((*tree)->right == NULL)
			{
				*tree = (*tree)->left;

				if(*tree)
				{
					NODE *temp = (*tree)->left;
					(*tree)->left  = NULL;
					free(temp);
				}
			}
			else if((*tree)->left == NULL)
			{
				(*tree)->data = (*tree)->right->data;

				NODE *temp = (*tree)->right;
				(*tree)->right  = NULL;
				free(temp);
			}
			else //both children exist
			{
				NODE *temp = FindMin((*tree)->right);
				(*tree)->data = temp->data;
				DeleteNode(&(*tree)->right, temp->data);		
			}
		}
	}
	return;
}

int main()
{
	NODE *tree = NULL;
	PrintInorder(tree);
	InsertNode(&tree, 50);	
	InsertNode(&tree, 30);	
	InsertNode(&tree, 20);	
	InsertNode(&tree, 40);	
	InsertNode(&tree, 70);	
	InsertNode(&tree, 60);	
	InsertNode(&tree, 80);	

	PrintInorder(tree);
	printf("\n");
	DeleteNode(&tree, 80);
	PrintInorder(tree);
	printf("\n");
	InsertNode(&tree, 80);	
	PrintInorder(tree);
	printf("\n");
	DeleteNode(&tree, 70);
	PrintInorder(tree);
	printf("\n");
	return 0;
}

