/*
Problem Statement: Write a program to Delete a Tree.

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


void postorderTraversal(struct node *root)
{
	if (root == NULL)
		return;
	postorderTraversal(root->left);    
	postorderTraversal(root->right);   
	printf("%d ", root->data);         
}

void deleteTree(struct node **root)
{
	if ((*root) == NULL)
		return;
	deleteTree((&(*root)->left));     /* Delete the left subtree first*/
	deleteTree((&(*root)->right));     /* Delete the left subtree first*/

	printf("\nDeleting %d from the Tree.",(*root)->data);
	free(*root);                         /* Then, delete the root node*/	
	*root = NULL;
}


int main()
{
	struct node *root;
	root = addNewNode(4);
	root->left = addNewNode(5);
	root->right = addNewNode(2);
	root->right->left = addNewNode(3);
	root->right->right = addNewNode(1);

	printf("\nPostorder Tree = ");
	postorderTraversal(root);

	deleteTree(&root);
	printf("\n Tree deleted ");

	return 0;
}


/*
Sample Output:


*/