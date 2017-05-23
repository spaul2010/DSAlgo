/*
Problem Statement:  Write a program to Calculate Size of a tree.
                    (Size of a tree is the number of elements present in the tree.)   

*/

#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node structure
struct node
{
	int data;
	struct node *left, *right;
};


struct node * addNew_Node(int val)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void inorderTraversal(struct node *root)
{
	if (root == NULL) return;
	inorderTraversal(root->left);
	printf(" %d ", root->data);
	inorderTraversal(root->right);
}

int sizeOfBT(struct node *t)
{
	if (t)
		return (1 + sizeOfBT(t->left) + sizeOfBT(t->right));
	else
		return 0;
}

int main()
{
	// Create a BT
	struct node *root;
	root = addNew_Node(5);
	root->left = addNew_Node(6);
	root->right = addNew_Node(7);

	root->left->left  = addNew_Node(8);
	root->left->right = addNew_Node(9);

	root->right->left  = addNew_Node(10);
	root->right->right = addNew_Node(11);
	printf("\nBinary Tree : \n");
	inorderTraversal(root);

	printf("\nSize of the Binary Tree(BT) is %d\n", sizeOfBT(root));

	return 0;
}