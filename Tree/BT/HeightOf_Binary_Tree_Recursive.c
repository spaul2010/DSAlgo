/*
Problem Statement: Write a Program to Find the Maximum Depth or Height of a Tree.
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

int height(struct node *root)
{
	if (!root)
		return 0;
	else if (!root->left && !root->right)
		return 0;
	else
	{
		int l_Height, r_Height;
		l_Height = height(root->left);
		r_Height = height(root->right);
		return ((l_Height > r_Height) ? (l_Height+1) : (r_Height+1));

	}
}


int main()
{
	// Create a BT
	struct node *root;
	root = addNew_Node(5);
	root->left = addNew_Node(6);
	root->right = addNew_Node(7);

	root->left->left = addNew_Node(8);
	root->left->right = addNew_Node(9);

	root->right->left = addNew_Node(10);
	root->right->right = addNew_Node(11);

	root->left->left->left = addNew_Node(12);
	root->left->left->left->right = addNew_Node(13);

	printf("\nBinary Tree : \n");
	inorderTraversal(root);

	printf("\nHeight of the Binary Tree(BT) is %d\n", height(root));

	return 0;
}