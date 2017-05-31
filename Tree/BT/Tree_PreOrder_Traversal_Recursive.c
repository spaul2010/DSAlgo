/*
Problem Statement: Preorder Traversal for the following Binary Tree:

  1
/   \
2      3
/\      /\
/  \    /  \
4   5    6   7

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

/*print its nodes in preorder*/
void preorderTraversal(struct node *root)
{
	if (root == NULL) return;

	/* First print the data of node */
	printf(" %d ", root->data);

	/* Then recur on left child */
	preorderTraversal(root->left);

	/* now recur on right child */
	preorderTraversal(root->right);
}

/*Driver program to test the above function*/
int main()
{
	// Create the Binary Tree
	struct node *root   =  addNew_Node(1);
	root->left          =  addNew_Node(2);
	root->right         =  addNew_Node(3);
	root->left->left    =  addNew_Node(4);
	root->left->right   =  addNew_Node(5);
	root->right->left   =  addNew_Node(6);
	root->right->right  =  addNew_Node(7);

	printf("\preorder Traversal of binary tree is : \n");
	preorderTraversal(root);
	printf("\n");

	return 0;
}


/*
Output: 

preorder Traversal of binary tree is :
1  2  4  5  3  6  7
*/