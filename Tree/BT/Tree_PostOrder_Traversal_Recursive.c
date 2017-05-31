/*
Problem Statement: Postorder Traversal for the following Binary Tree:

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

/*print its nodes in postorder*/
void postorderTraversal(struct node *root)
{
	if (root == NULL) return;

	/* First recur on left child */
	postorderTraversal(root->left);

	/* Then recur on right child */
	postorderTraversal(root->right);

	/* At last print the data of node */
	printf(" %d ", root->data);
}

/*Driver program to test the above function*/
int main()
{
	// Create the Binary Tree
	struct node *root    =  addNew_Node(1);
	root->left           =  addNew_Node(2);
	root->right          =  addNew_Node(3);
	root->left->left     =  addNew_Node(4);
	root->left->right    =  addNew_Node(5);
	root->right->left    =  addNew_Node(6);
	root->right->right   =  addNew_Node(7);

	printf("\Postorder Traversal of binary tree is : \n");
	postorderTraversal(root);
	printf("\n");

	return 0;
}


/*
Output:

Postorder Traversal of binary tree is :
4  5  2  6  7  3  1

*/