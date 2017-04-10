/*
Problem Statement: Given a linked list where every node represents a linked list and contains two pointers of its type:
(i) Pointer to next node in the main list (we call it ‘right’ pointer in below code)
(ii) Pointer to a linked list where this node is head (we call it ‘down’ pointer in below code).
All linked lists are sorted. See the following example

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
	   Write a function flatten() to flatten the lists into a single linked list. 
	   The flattened linked list should also be sorted. For example, for the above 
	   input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50.

*/

#include <stdio.h>
#include <string.h>

struct node {
	int data;
	struct node *right;
	struct node *down;
};

void appendNodeRight(struct node **tempHead, int val) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->right = NULL;
	temp->down = NULL;

	if (*tempHead == NULL) {
		*tempHead = temp;
	}
	else {
		//Traverse and find the last element in the list
		struct node *t = *tempHead;
		while (t->right) {
			t = t->right;
		}
		t->right = temp;
	}
}

void appendNodeDown(struct node **tempHead, int val) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->right = NULL;
	temp->down = NULL;

	if (*tempHead == NULL) {
		*tempHead = temp;
	}
	else {
		//Traverse and find the last element in the list
		struct node *t = *tempHead;
		while (t->down) {
			t = t->down;
		}
		t->down = temp;
	}
}

void printListRight(struct node *tempHead) {
	printf("List = ");

	struct node *t = tempHead;
	while (t) {
		printf("%d-->",t->data);
		t = t->right;
	}
	printf("NULL\n");
}

void printListDown(struct node *tempHead) {
	struct node *t = tempHead;
	t = t->down;
	while (t) {
		printf("\n\t%d", t->data);
		t = t->down;
	}
	printf("\n\tNULL\n");
}

void insertNode_ToFlattenList(struct node **tempHeadRight, struct node **tempHeadDown) {
	struct node *tempNode, *tempNodeNext;
	tempNode = *tempHeadDown;
	tempNodeNext = (*tempHeadDown)->down;

	// remove the links from the specified node
	(*tempHeadRight)->down = (*tempHeadDown)->down;
	tempNode->right = NULL;
	tempNode->down  = NULL;

	//insert this node at the right place
	tempNode->right = (*tempHeadRight)->right;
	(*tempHeadRight)->right = tempNode;

	//update the tempHeadDown node address, so that it again points to next node to be processed
	*tempHeadDown = tempNodeNext;

}

void findAndInsertNode_ToFlattenList(struct node **tempHeadRight, struct node **tempHeadDown) {
	struct node *tempNode, *tempRight, *tempRight_Prev, *tempNodeNext;
	tempNode = *tempHeadDown;
	tempNodeNext = (*tempHeadDown)->down;
	tempRight_Prev = *tempHeadRight;
	tempRight = (*tempHeadRight)->right;

	//1. Find the right place for the node to be inserted
	while (tempRight) {
		if ((*tempHeadDown)->data > tempRight->data) {
			tempRight_Prev = tempRight;
			tempRight = tempRight->right;
		}
		else
			break;
	}

	//2. Insert the node

	// remove the links from the specified node
	(*tempHeadRight)->down = (*tempHeadDown)->down;
	tempNode->right = NULL;
	tempNode->down = NULL;

	//insert this node at the right place
	tempNode->right = tempRight;
	tempRight_Prev->right = tempNode;

	//update the tempHeadDown node address, so that it again points to next node to be processed
	*tempHeadDown = tempNodeNext;
}

void __flattenList(struct node **tempHead) {
	struct node *traverseRight, *traverseDown;

	traverseRight = *tempHead;
	

	while (traverseRight) {
		traverseDown = traverseRight->down;
		while (traverseDown) {

			// Found the right place for traverseDown->data
			if (traverseDown->data <= traverseRight->right->data)
				insertNode_ToFlattenList(&traverseRight, &traverseDown);
			else
				findAndInsertNode_ToFlattenList(&traverseRight, &traverseDown);
		}
		//Move to next node in right side
		traverseRight = traverseRight->right;
	}
}

void main() {
	struct node *head=NULL;

	printf("\n--------------------------------------\n");
	printf("Before Flattening the List : ");
	printf("\n--------------------------------------\n");
	appendNodeRight(&head, 5);
	appendNodeRight(&head, 10);
	appendNodeRight(&head, 19);
	appendNodeRight(&head, 28);
	appendNodeDown(&head, 7);
	appendNodeDown(&head, 8);
	appendNodeDown(&head, 30);

	appendNodeDown(&(head->right), 20);
	appendNodeDown(&(head->right->right), 22);
	appendNodeDown(&(head->right->right->right), 35);
	appendNodeDown(&(head->right->right->right), 40);
	appendNodeDown(&(head->right->right->right), 45);

	printListRight(head);
	printf("List under 5 is: ");
	printListDown(head);

	printf("List under 10 is: ");
	printListDown(head->right);
	
	printf("List under 19 is: ");
	printListDown(head->right->right);

	printf("List under 28 is: ");
	printListDown(head->right->right->right);


	// Flatten the list
	__flattenList(&head);

	printf("\n\n--------------------------------------\n");
	printf("After Flattening the List : ");
	printf("\n--------------------------------------\n");

	printListRight(head);
	printf("List under 5 is: ");
	printListDown(head);

	printf("List under 10 is: ");
	printListDown(head->right);

	printf("List under 19 is: ");
	printListDown(head->right->right);

	printf("List under 28 is: ");
	printListDown(head->right->right->right);

}


/*
Sample Output:
--------------------------------------
Before Flattening the List :
--------------------------------------
List = 5-->10-->19-->28-->NULL
List under 5 is:
7
8
30
NULL
List under 10 is:
20
NULL
List under 19 is:
22
NULL
List under 28 is:
35
40
45
NULL


--------------------------------------
After Flattening the List :
--------------------------------------
List = 5-->7-->8-->10-->19-->20-->22-->28-->30-->35-->40-->45-->NULL
List under 5 is:
NULL
List under 10 is:
NULL
List under 19 is:
NULL
List under 28 is:
NULL
Press any key to continue . . .

*/