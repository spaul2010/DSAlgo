/*
Problem Statement:
Write a function to reverse a linked list
Given pointer to the head node of a linked list, the task is to reverse the linked list.

Examples:

Input : Head of following linked list  
       1->2->3->4->NULL
Output : Linked list should be changed to,
       4->3->2->1->NULL

Input : Head of following linked list  
       1->2->3->4->5->NULL
Output : Linked list should be changed to,
       5->4->3->2->1->NULL

Input : NULL
Output : NULL

Input  : 1->NULL
Output : 1->NULL

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};
struct node *head = NULL;

void appendNode(struct node **tempHead, int val){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->link = NULL;
	
	if(*tempHead == NULL)
		*tempHead = newNode;
	else{
		struct node *temp = *tempHead;
		while(temp->link)	
			temp = temp->link;
		temp->link = newNode;
	}
}

void printSLL(struct node *tempHead){
	while(tempHead){
		printf("%d --> ", tempHead->data);
		tempHead = tempHead->link;
	}
	printf("NULL\n");
}


void reverseSLL(struct node *prev, struct node *curr){
	if(curr){
		// keep calling the function till curr pointer reaches NULL
		reverseSLL(curr, curr->link);
		
		//Link current node to previous node while returning
		curr->link = prev;
	}
	else
		// Adjust the Head node
		head = prev;
}

int main(void){
	appendNode(&head, 10);
	appendNode(&head, 20);
	appendNode(&head, 30);
	appendNode(&head, 40);
	appendNode(&head, 50);
	appendNode(&head, 60);
	printSLL(head);
	
	reverseSLL(NULL, head);
	printSLL(head);
	return 0;
}


/*
Sample Output : 
10 --> 20 --> 30 --> 40 --> 50 --> 60 --> NULL
60 --> 50 --> 40 --> 30 --> 20 --> 10 --> NULL
*/