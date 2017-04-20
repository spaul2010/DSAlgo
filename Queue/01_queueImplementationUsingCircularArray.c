/*
Problem Statement : Implement Circular Queue data structure using array.

Time Complexities of operations on circular Queue: O(1)
*/

#include <stdio.h>
#define MAX 5

/*Global data for Circular Queue implementation*/
int queue[MAX];
int front = 0;
int rear = 0;

/*Circular Queue Operations*/
void enQueue(int data) {
	rear = (rear + 1) % MAX;
	if (front == rear) {
		printf("\nOverflow; Queue is Full");
		if (rear == 0)
			rear = MAX - 1;
		else
			rear--;
		return;
	}
	else {
		queue[rear] = data;
		printf("\n %d is inserted in the Queue", data);
	}
}

int deQueue() {
	if (front == rear) {
		printf("\nUnderflow. Queue is Empty!!");
		return;
	}
	else {
		front = (front + 1) % MAX;
		printf("\n%d is deleted from Queue.",queue[front]);
		return queue[front];
	}

}

void main() {
	enQueue(10);
	enQueue(20);
	enQueue(30);
	enQueue(40);

	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();

}