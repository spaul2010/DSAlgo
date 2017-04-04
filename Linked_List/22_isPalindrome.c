/*
Problem Statement : Given a singly linked list, write a function that returns true if 
                    the given list is palindrome, else false.

Algorithm:

	Step-1:  Find out the middle of the linked list and split it into two halves
	Step-2:  Reverse the second half of the linked list.
	Step-3:  Check if the first half and second half are identical.
	Step-4:  Construct the original linked list by reversing the second half again and 
	         attaching it back to the first half

Complexity:  This method takes O(n) time and O(1) extra space.
*/

#include <stdio.h>
struct node {
	int data;
	struct node *link;
};

void appendNode(struct node **tempHead, int val) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->link = NULL;

	if (*tempHead == NULL)
		*tempHead = temp;
	else {
		struct node *t = *tempHead;

		while (t->link) {
			t = t->link;
		}
		t->link = temp;
	}
}

void printList(struct node *tempHead) {
	printf("\nList = ");
	while (tempHead) {
		printf("%d --> ", tempHead->data);
		tempHead = tempHead->link;
	}
	printf("NULL\n");
}

void reverseList(struct node **tempHead) {
	struct node *prev, *curr, *next;
	prev = NULL;
	curr = *tempHead;
	next = *tempHead;

	while (curr) {
		next = curr->link;
		curr->link = prev;

		prev = curr;
		curr = next;
	}
	*tempHead = prev;

}

int compareLists(struct node **tempHead1, struct node **tempHead2) {

	struct node *t1, *t2;
	t1 = *tempHead1;
	t2 = *tempHead2;

	while (t1 && t2) {
		if (t1->data == t2->data) {
			t1 = t1->link;
			t2 = t2->link;
			continue;
		}
		else
			return 0;
	}

	//both list are same
	if (t1 == NULL && t2 == NULL) {
		return 1;
	}
	// When one list is NULL and other is not
	return 0;
}

int isPalindrome(struct node **tempHead) {
	struct node *fast, *slow, *slow_prev, *mid, *firstHalfHead, *secondHalfHead;
	int compareResult = 0;

	fast = *tempHead;
	slow = *tempHead;
	slow_prev = NULL;

	firstHalfHead = *tempHead;

	// In empty list, return 1
	if (*tempHead == NULL || (*tempHead)->link == NULL)
		return 1;

	//Find the middle element, After this loop, 
	//slow pointer will point to the mid of the list
	while (fast && fast->link) {
		fast = fast->link->link;
		slow_prev = slow;
		slow = slow->link;
	}

	// Adjust the middle pointer 
	if (fast == NULL) {
		// even no of nodes in list
		secondHalfHead = slow;
	}
	else {
		// Odd no of elements in list
		secondHalfHead = slow->link;
	}

	//split the list in two halves
	mid = slow_prev;
	mid->link = NULL;

	//Reverse the second half 
	reverseList(&secondHalfHead);

	// Compare the first half and second half and check if they are same
	// If they are same, then the original list is Palindrome
	compareResult = compareLists(&firstHalfHead, &secondHalfHead);

	//Reverse the second half again and get back to original list
	reverseList(&secondHalfHead);

	//Link the second half back to the first half to construct the original list
	if (fast == NULL) {
		mid->link = secondHalfHead;
	}
	else {
		mid->link = slow;
	}

	//return the compareResult
	return compareResult;
}

void main() {
	struct node *head = NULL;

	//1
	printf("\n1. Check Palindrome -- Case -1\n");
	printList(head);
	printf("List is Palindrome = %d (0=No,1=Yes)\n\n", isPalindrome(&head));

	//2
	printf("\n2. Check Palindrome -- Case -2\n");
	appendNode(&head, 10);
	printList(head);
	printf("List is Palindrome = %d (0=No,1=Yes)\n\n", isPalindrome(&head));

	//3
	printf("\n3. Check Palindrome -- Case -3\n");
	head = NULL;
	appendNode(&head, 10);
	appendNode(&head, 20);
	printList(head);
	printf("List is Palindrome = %d (0=No,1=Yes)\n\n", isPalindrome(&head));


	//4
	printf("\n4. Check Palindrome -- Case -4\n");
	head = NULL;
	appendNode(&head, 10);
	appendNode(&head, 20);
	appendNode(&head, 10);
	printList(head);
	printf("List is Palindrome = %d (0=No,1=Yes)\n\n", isPalindrome(&head));

	//5
	printf("\n5. Check Palindrome -- Case -5\n");
	head = NULL;
	appendNode(&head, 10);
	appendNode(&head, 20);
	appendNode(&head, 30);
	appendNode(&head, 30);
	printList(head);
	printf("List is Palindrome = %d (0=No,1=Yes)\n\n", isPalindrome(&head));

	//6
	printf("\n6. Check Palindrome -- Case -6\n");
	head = NULL;
	appendNode(&head, 10);
	appendNode(&head, 20);
	appendNode(&head, 20);
	appendNode(&head, 10);
	printList(head);
	printf("List is Palindrome = %d (0=No,1=Yes)\n\n", isPalindrome(&head));

	//7
	printf("\n7. Check Palindrome -- Case -7\n");
	head = NULL;
	appendNode(&head, 10);
	appendNode(&head, 20);
	appendNode(&head, 30);
	appendNode(&head, 40);
	appendNode(&head, 50);
	appendNode(&head, 40);
	appendNode(&head, 30);
	appendNode(&head, 20);
	appendNode(&head, 1000);
	printList(head);
	printf("List is Palindrome = %d (0=No,1=Yes)\n\n", isPalindrome(&head));

	//8
	printf("\n8. Check Palindrome -- Case -8\n");
	head = NULL;
	appendNode(&head, 10);
	appendNode(&head, 20);
	appendNode(&head, 30);
	appendNode(&head, 40);
	appendNode(&head, 50);
	appendNode(&head, 40);
	appendNode(&head, 30);
	appendNode(&head, 20);
	appendNode(&head, 10);
	printList(head);
	printf("List is Palindrome = %d (0=No,1=Yes)\n\n", isPalindrome(&head));
}