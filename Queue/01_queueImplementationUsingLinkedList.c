/*
Problem Statement : Implement Queue data structure using Linked List.

*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enQueue(int val) {
	/*Create a new node*/
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->link = NULL;

	if (front == NULL) 
		front = newNode;
	else {
		struct node *temp = front;
		while (temp->link)
			temp = temp->link;

		temp->link = newNode;
	}

	/*Update the rear pointer after inserting the element in Queue*/
	rear = newNode;

	printf("\n%d is inserted in the queue.", val);
}

int deQueue() {
	struct node *tempNode;
	int tempData;
	if (front == NULL) {
		printf("\nUnderflow. Queue is empty.\n");
		return -999999;
	}
	tempNode = front;
	front = front->link;

	tempData = tempNode->data;
	free(tempNode);
	printf("\n%d is deleted from Queue.",tempData);
	return tempData;
}

void printList(struct node *tempHead) {
	printf("List = ");

	while (tempHead) {
		printf("%d -->", tempHead->data);
		tempHead = tempHead->link;
	}

	printf("NULL\n");
}


void main() {
	enQueue(10);
	enQueue(20);
	enQueue(30);
	enQueue(40);
	enQueue(50);
	enQueue(60);
	enQueue(70);

	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();


}