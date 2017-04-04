/*
Problem Statement : Write a function to get the intersection point of two Linked Lists.

Algorithm:

Step-1:  for each <node-1> for first List
	Step-2:  for each <node-2> of second List
		Step-3:  if address of <node-1> matches address of <node-2>
		Step-4:  Return the value of <node-1>
		Step-5:  Move to next node in second List
	Step-6:  Move to next node in first List
Step-4:  Otherwise, return -1, indication no intersection node found

Complexity:  Time complexity for this program is O(mn), where m is the size of first list 
             and n is the size of second list
*/

#include <stdio.h>
struct node {
	int data;
	struct node *link;
};

void printList(struct node *tempHead) {
	printf("\nList = ");
	while (tempHead) {
		printf("%d --> ", tempHead->data);
		tempHead = tempHead->link;
	}
	printf("NULL\n");
}

int __getInsertionPointOfTwoSLL(struct node **tempHead1, struct node **tempHead2) {
	struct node *t1, *t2;
	t1 = *tempHead1;
	t2 = *tempHead2;

	while (t1) {
		t2 = *tempHead2;
		while (t2) {
			if (t1 == t2)
				return t1->data;
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	return -1;
}

void main() {
	struct node *head1 = NULL, *head2 = NULL, *temp = NULL;

	/*Create two list as follows : 
	First List  =  10 -> 20-> 30-> 40 -> 50 -> 60
	Second List =      25 -> 35 -> 40 -> 50-> 60
	Intersection point is  = 40
	*/

	//Create List 1
	head1 = (struct node *)malloc(sizeof(struct node));
	head1->data = 10;
	head1->link = (struct node *)malloc(sizeof(struct node));

	head1->link->data = 20;
	head1->link->link = (struct node *)malloc(sizeof(struct node));

	head1->link->link->data = 30;
	head1->link->link->link = (struct node *)malloc(sizeof(struct node));
	temp = head1->link->link->link;

	head1->link->link->link->data = 40;
	head1->link->link->link->link = (struct node *)malloc(sizeof(struct node));
	
	head1->link->link->link->link->data = 50;
	head1->link->link->link->link->link = (struct node *)malloc(sizeof(struct node));

	head1->link->link->link->link->link->data = 60;
	head1->link->link->link->link->link->link = NULL;
	
	printList(head1);

	//Create List 2
	head2 = (struct node *)malloc(sizeof(struct node));
	head2->data = 25;
	head2->link = (struct node *)malloc(sizeof(struct node));

	head2->link->data = 35;
	head2->link->link = temp;

	printList(head2);

	//Find out intersection node
	printf("\nIntersection node is = %d\n", __getInsertionPointOfTwoSLL(&head1,&head2));

}