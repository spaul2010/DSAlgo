/*
Problem Statement : Implement Queue data structure using array.

Time Complexities of operations on stack: O(1)
*/

#include <stdio.h>
#define MAX 5

/*Global data for Queue implementation*/
int queue[MAX];
int front = -1;
int rear = -1;

/*Queue Operations*/
int isEmpty() {
	if (front == -1 && rear == -1)
		return 1;
	else
		return 0;
}

int isFull() {
	if (rear == MAX - 1)
		return 1;
	else
		return 0;
}

void enQueue(int data) {
	
	if (isFull()) {
		/*When Queue is FULL*/
		printf("\nOverflow. Queue is Full!!");
		return;
	}
	else if (isEmpty()) {
		/*When Queue is empty*/
		front = 0;
		rear = 0;
	}
	else {
		/*When Queue is neither Full nor Empty*/
		rear++;
	}

	queue[rear] = data;
	printf("\n %d is inserted in the Queue", data);
}

int deQueue() {
	int tempData;
	if (isEmpty()) {
		/*When Queue is empty*/
		printf("\nUnderflow. Queue is Empty!!");
		return;
	}
	else if (front > rear) {
		/*When front becomes greater than rear*/
		front = -1;
		rear = -1;
		printf("\nUnderflow. Queue is Empty!!");
	}
	else {
		/*Otherwise*/
		tempData = queue[front];
		printf("\n %d is deleted from the Queue", tempData);
		front++;
		return tempData;
	}
	
}

void main() {
	enQueue(10);
	enQueue(20);
	enQueue(30);
	enQueue(40);
	enQueue(50);
	enQueue(60);

	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();

}