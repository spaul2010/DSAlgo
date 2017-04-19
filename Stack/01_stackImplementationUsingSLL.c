/*
Problem Statement : Implement Stack data structure using array.

Time Complexities of operations on stack: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *HEAD;

void push(int element) {
	// Create the new node
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = element;

	// Add the new node at the beginning of the linked list
	//HEAD is acting as Top in this case
	newNode->link = HEAD;
	HEAD = newNode;

	printf("\n%d pushed to stack", element);
}

int isEmpty() {
	if (HEAD == NULL)
		return 1;
	else
		return 0;
}

int pop() {
	struct node *tempNode;
	int tempData;
	if (isEmpty()) {
		printf("\nStack underflow!!\n");
		return -9999999;
	}

	//delete the element from beginning of the linked list
	//HEAD is acting as Top in this case
	tempNode = HEAD;
	HEAD = HEAD->link;

	tempData = tempNode->data;
	printf("\n%d popped from stack", tempData);
	free(tempNode);
	return tempData;
}

void main() {
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);

	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
}

/*
Sample Output:
10 pushed to stack
20 pushed to stack
30 pushed to stack
40 pushed to stack
50 pushed to stack
60 pushed to stack
60 popped from stack
50 popped from stack
40 popped from stack
30 popped from stack
20 popped from stack
10 popped from stack
Stack underflow!!
*/