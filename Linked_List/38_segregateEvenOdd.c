/*
Problem Statement:

Given a Linked List of integers, write a function to modify the linked list such 
that all even numbers appear before all the odd numbers in the modified linked list. 
Also, keep the order of even and odd numbers same.

Examples:
Input: 17->15->8->12->10->5->4->1->7->6->NULL
Output: 8->12->10->4->6->17->15->5->1->7->NULL

Input: 8->12->10->5->4->1->6->NULL
Output: 8->12->10->4->6->5->1->NULL

// If all numbers are even then do not change the list
Input: 8->12->10->NULL
Output: 8->12->10->NULL

// If all numbers are odd then do not change the list
Input: 1->3->5->7->NULL
Output: 1->3->5->7->NULL
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node * appendNode(struct node **tempHead, int val) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->link = NULL;

	if (*tempHead == NULL)
		*tempHead = newNode;

	else {
		struct node *temp = *tempHead;
		while (temp->link)
			temp = temp->link;

		temp->link = newNode;
	}

	return newNode;
}


void printList(struct node *tempHead) {
	printf("List = ");

	while (tempHead) {
		printf("%d -->", tempHead->data);
		tempHead = tempHead->link;
	}

	printf("NULL\n");
}

void __segregateEvenOdd(struct node **tempHead, struct node **even, struct node **odd, struct node **result) {
	struct node *temp = *tempHead;
	struct node *evenLastPtr = NULL;

	while (temp) {
		if (temp->data % 2) {
			// odd
			appendNode(odd, temp->data);
		}
		else {
			//even
			evenLastPtr = appendNode(even, temp->data);
		}
		temp = temp->link;
	}

	// combine even and odd list
	evenLastPtr->link = *odd;
	*result = *even;
}

void main() {
	struct node *head = NULL, *resultList = NULL, *evenList = NULL, *oddList = NULL;

	appendNode(&head, 17);
	appendNode(&head, 15);
	appendNode(&head, 8);
	appendNode(&head, 12);
	appendNode(&head, 10);
	appendNode(&head, 5);
	appendNode(&head, 4);
	appendNode(&head, 1);
	appendNode(&head, 7);
	appendNode(&head, 6);

	printf("\n\n<Input> : \n");
	printList(head);

	printf("\n\n<output> After the segregation of Even and Odd Nodes : \n");
	__segregateEvenOdd(&head, &evenList, &oddList, &resultList);
	printList(resultList);
}

/*
Sample Output:

<Input> :
List = 17 -->15 -->8 -->12 -->10 -->5 -->4 -->1 -->7 -->6 -->NULL


<output> After the segregation of Even and Odd Nodes :
List = 8 -->12 -->10 -->4 -->6 -->17 -->15 -->5 -->1 -->7 -->NULL
Press any key to continue . . .

*/