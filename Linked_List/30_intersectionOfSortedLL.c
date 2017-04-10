/*
Problem Statement: 

Given two lists sorted in increasing order, create and return a new list 
representing the intersection of the two lists. The new list should be 
made with its own memory — the original lists should not be changed.

For example, let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8, 
then your function should create and return a third list as 2->4->6.
*/


#include <stdio.h>

struct node {
	int data;
	struct node *link;
};

void appendNode(struct node **tempHead, int val) {
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
}

void printList(struct node *tempHead) {
	printf("List = ");

	while (tempHead) {
		printf("%d -->",tempHead->data);
		tempHead = tempHead->link;
	}

	printf("NULL\n");
}


void __intersectOfSortedLL(struct node **tempHead_1, struct node **tempHead_2, struct node **result) {
	struct node *t1 = *tempHead_1;
	struct node *t2 = *tempHead_2;

	while (t1) {
		while (t2) {
			if (t1->data < t2->data)
				break;
			else if (t1->data == t2->data) {
				appendNode(result, t1->data);
				break;
			}
			else
				t2 = t2->link;
		}
		t1 = t1->link;
	}

}

void main() {
	struct node *head_1 = NULL, *head_2 = NULL, *resultList = NULL;

	appendNode(&head_1, 1);
	appendNode(&head_1, 2);
	appendNode(&head_1, 3);
	appendNode(&head_1, 4);
	appendNode(&head_1, 6);

	appendNode(&head_2, 2);
	appendNode(&head_2, 4);
	appendNode(&head_2, 6);
	appendNode(&head_2, 8);

	printList(head_1);
	printList(head_2);
	printList(resultList);

	//Find Intersection
	printf("\n\nAfter Intersection operation \n ");
	__intersectOfSortedLL(&head_1, &head_2, &resultList);
	printList(resultList);

}

/*
Sample Output:

List = 1 -->2 -->3 -->4 -->6 -->NULL
List = 2 -->4 -->6 -->8 -->NULL
List = NULL


After Intersection operation
List = 2 -->4 -->6 -->NULL
Press any key to continue . . .

*/