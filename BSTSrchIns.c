//BST
//Right sub tree will have all nodes greater than the root node
//Left sub tree will have all nodes lessor than the root node
//Right and left sub tree should be also BST
//There must be no duplicate nodes

//Insert and Delete in Binary search tree
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
}NODE;

void insert(NODE **root, int data)
{
	if(!(*root))		
	{	
		NODE *new = malloc(sizeof(NODE));
		new->data = data;
		new->left = new->right = NULL;
		*root = new;
	}

	else if(data > (*root)->data)
		insert(&(*root)->right, data);

	else if(data < (*root)->data)
		insert(&(*root)->left, data);
	
	return;
}

int SearchNode(NODE *tree, int data)
{
	if(tree)
	{
			if(tree->data == data) 
				return 1;

			else if(tree->data < data)
				return SearchNode(tree->right, data);

			else if(tree->data > data)
				return SearchNode(tree->left, data);
	}
	return 0;
}

void PrintInorder(NODE *tree)
{
	if(tree)
	{
		PrintInorder(tree->left);	
		printf("%d  ", tree->data);
		PrintInorder(tree->right);	
	}
}

int main()
{
	NODE *tree = NULL;
	insert(&tree, 50);
	insert(&tree, 30);
	insert(&tree, 20);
	insert(&tree, 40);
	insert(&tree, 70);
	insert(&tree, 60);
	insert(&tree, 80);

	PrintInorder(tree);

	printf("\n%d\n", SearchNode(tree, 10));	
	printf("%d\n", SearchNode(tree, 80));	
	printf("%d\n", SearchNode(tree, 30));	
	printf("%d\n", SearchNode(tree, 90));	
	printf("%d\n", SearchNode(tree, 180));	

	return 0;
}
