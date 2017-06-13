/*
Problem Statement: Write an Efficient Function to Convert a Binary Tree into its Mirror Tree.

Change a tree so that the roles of the  left and
right pointers are swapped at every node.

So the tree...
		4
	   / \
	  2   5
	 / \
	1   3

is changed to...
		4
	   / \
	  5   2
         / \
		3   1

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node * addNewNode(int val)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node *));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


void inorderTraversal(struct node *root)
{
	if (root == NULL)
		return;

	inorderTraversal(root->left);
	printf("%d ", root->data);
	inorderTraversal(root->right);
}


void mirrorTree(struct node *root)
{
	if (!root)
		return;
	
	mirrorTree(root->left);       /* call for left sub tree*/
	mirrorTree(root->right);      /* call for right sub tree*/

	/* Swap the left and right pointer*/
	struct node *temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;

}

int main()
{
	struct node *root = addNewNode(4);
	root->left = addNewNode(5);
	root->right = addNewNode(2);
	root->right->left  = addNewNode(3);
	root->right->right = addNewNode(1);
	
	printf("\nInorder Traversal of the Tree is = ");
	inorderTraversal(root);

	mirrorTree(root);

	printf("\nInorder Traversal of the Tree is = ");
	inorderTraversal(root);
}


/*
Sample Output:

Inorder Traversal of the Tree is = 5 4 3 2 1
Inorder Traversal of the Tree is = 1 2 3 4 5

*/