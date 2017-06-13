/*
Problem Statement: Write Code to Determine if Two Trees are Identical.

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

int identicalTrees(struct node *t1, struct node *t2)
{
	
	if (t1 == NULL && t2 == NULL)        /* When both the Tress are NULL*/
		return 1;
	else if (t1 != NULL && t2 != NULL)   /* When both the Tress are not NULL*/
		return ((t1->data == t2->data) && 
			identicalTrees(t1->left, t2->left) &&
			identicalTrees(t1->right, t2->right) );
	else                                 /* When either one of the Tree is not NULL*/
		return 0;
}


int main()
{
	struct node *root1, *root2, *root3;
	root1 = addNewNode(4);
	root1->left = addNewNode(5);
	root1->right = addNewNode(2);
	root1->right->left = addNewNode(3);
	root1->right->right = addNewNode(1);

	root2 = addNewNode(4);
	root2->left = addNewNode(5);
	root2->right = addNewNode(2);
	root2->right->left = addNewNode(3);
	root2->right->right = addNewNode(1);

	root3 = addNewNode(4);
	root3->left = addNewNode(5);
	root3->right = addNewNode(2);
	root3->right->left = addNewNode(3);
	root3->right->right = addNewNode(4);

	printf("\nInorder Traversal of Tree-1 is = ");
	inorderTraversal(root1);

	printf("\nInorder Traversal of Tree-2 is = ");
	inorderTraversal(root2);

	printf("\nInorder Traversal of Tree-3 is = ");
	inorderTraversal(root3);

	printf("\n\nCheck if Tree-1 and Tree-2 are identical = %d", identicalTrees(root1, root2));
	printf("\n\nCheck if Tree-1 and Tree-3 are identical = %d", identicalTrees(root1, root3));
	printf("\n\nCheck if Tree-2 and Tree-3 are identical = %d\n", identicalTrees(root2, root3));

}


/*
Sample Output:

Inorder Traversal of Tree-1 is = 5 4 3 2 1
Inorder Traversal of Tree-2 is = 5 4 3 2 1
Inorder Traversal of Tree-3 is = 5 4 3 2 4

Check if Tree-1 and Tree-2 are identical = 1

Check if Tree-1 and Tree-3 are identical = 0

Check if Tree-2 and Tree-3 are identical = 0

*/