/*
Problem Statement : Given two singly linked list, each representing an integer, return 
                    a singly linked list with the multiplication result. 

*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

/*
------------------------------------------------------------------------------------------------
                START OF UTILITY CODE
------------------------------------------------------------------------------------------------
*/
struct node * appendNode(struct node **tempHead, int val) 
{
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

void printList(struct node *tempHead) 
{
	printf("List = ");

	while (tempHead) {
		printf("%d -->", tempHead->data);
		tempHead = tempHead->link;
	}

	printf("NULL\n");
}

void reverseSLL(struct node **tempHead) {
	struct node *prev, *curr, *next;
	prev = NULL;
	curr = *tempHead;
	next = NULL;

	while (curr) {
		// Hold the next node in next pointer and point it to the next node of current node
		next = curr->link;

		// Change the current node link and make it point to preivious node
		curr->link = prev;

		// Move prev and curr pointer and make it ready for next iteration
		prev = curr;
		curr = next;
	}
	*tempHead = prev;
}

int getLength(struct node *tempHead)
{
	int nodeCount = 0;
	while (tempHead)
	{
		nodeCount++;
		tempHead = tempHead ->link;
	}
	return nodeCount;
}


struct node * addition(struct node **tempHead1, struct node **tempHead2)
{
	int carry = 0, tempResult = 0;
	struct node *list1, *list2, *resultList;
	list1 = *tempHead1;
	list2 = *tempHead2;
	resultList = NULL;

	// Traverse both the list at the same time
	while (list1 && list2)
	{
		tempResult = list1->data + list2->data + carry;
		carry = tempResult / 10;
		tempResult = tempResult % 10;
		appendNode(&resultList, tempResult);

		// Move both the list pointer
		list1 = list1->link;
		list2 = list2->link;
	}

	// if list1 is still not empty
	if (list1)
	{
		while (list1)
		{
			tempResult = list1->data + carry;
			carry = tempResult / 10;
			tempResult = tempResult % 10;
			appendNode(&resultList, tempResult);
			list1 = list1->link;
		}
	}

	// if list2 is still not empty
	if (list2)
	{
		while (list2)
		{
			tempResult = list2->data + carry;
			carry = tempResult / 10;
			tempResult = tempResult % 10;
			appendNode(&resultList, tempResult);
			list2 = list2->link;
		}
	}
	return resultList;
}

/*
------------------------------------------------------------------------------------------------
END OF UTILITY CODE
------------------------------------------------------------------------------------------------
*/

struct node * ___Multiplication(struct node **tempHead1, struct node **tempHead2)
{
	int carry, tempMulRes, nodeCount;
	struct node *list1, *list2, *list1_hold, *list2_hold, *tempResult, *tempResult_hold, *finalResult;
	list1 = *tempHead1;
	list2 = *tempHead2;
	list1_hold = NULL;
	list2_hold = NULL;
	tempResult = NULL;
	tempResult_hold = NULL;
	finalResult = NULL;

	// Reverse both the input list
	reverseSLL(&list1);
	reverseSLL(&list2);


	// Swap the list pointer based on the length of the list
	// First list should have greater number of elements
	// Second list should have least number of elements
	if (getLength(list1) < getLength(list2))
	{
		// Swap the pointer
		tempResult = list1;
		list1 = list2;
		list2 = tempResult;
	}
	tempResult = NULL;


	// Multiply and store the result in tempResult with -999 delimeter
	list1_hold = list1;
	list2_hold = list2;
	nodeCount = 0;
	while (list2)
	{
		// Initialize these at every iteration for List2
		tempMulRes = 0;
		carry = 0;

		nodeCount++;

		// Point list1 each time to the beginning of the list1
		list1 = list1_hold;
		while (list1)
		{
			// Multiply and adjust the carry 
			tempMulRes = ((list2->data)*(list1->data)) + carry;
			carry = tempMulRes / 10;
			tempMulRes = tempMulRes % 10;

			// Add the value in the temporary resultant list
			appendNode(&tempResult, tempMulRes);

			list1 = list1->link;
		}

		// If list1 is fully processed, then add the carry in the list and -9999 as delimeter
		if (list1 == NULL)
		{
			// Add carry 
			appendNode(&tempResult, carry);
			// Add delimiter -999 in the resultant list
			appendNode(&tempResult, -9999);
		}

		if(list2->link)
			//padd zeros in the resultant list
			for(int i =0; i<nodeCount;i++)
				appendNode(&tempResult, 0);

		list2 = list2->link;
	}
	

	// Now, process the tempResult list and get the final output
	tempResult_hold = tempResult;
	struct node *addList;
	addList = NULL;

	while (tempResult)
	{
		if (tempResult->data != -9999)
			appendNode(&addList, tempResult->data);
		else
		{
			// call addition function
			finalResult = addition(&finalResult, &addList);
			// initialise addList1 to NULL again
			addList = NULL;
		}
		tempResult = tempResult->link;
	}

	// Reverse back both the input lists; Also reverse the output
	reverseSLL(&list1);
	reverseSLL(&list2);
	reverseSLL(&finalResult);

	return finalResult;
}


void main() 
{
	struct node *head1 = NULL, *head2 = NULL, *result = NULL;

	appendNode(&head1, 7);
	appendNode(&head1, 2);
	appendNode(&head1, 4);

	appendNode(&head2, 3);
	appendNode(&head2, 5);
	
	printf("\n\n<Input-1> : \n");
	printList(head1);
	printf("\n\n<Input-2> : \n");
	printList(head2);

	result = ___Multiplication(&head1, &head2);
	printf("\n\n<Multiplication Result> : \n");
	printList(result);

}


/*
Sample Output :
1)
<Input-1> :
List = 7 -->2 -->4 -->NULL


<Input-2> :
List = 3 -->5 -->NULL


<Multiplication Result> :
List = 2 -->5 -->3 -->4 -->0 -->NULL

2)
<Input-1> :
List = 1 -->2 -->3 -->4 -->5 -->NULL


<Input-2> :
List = 3 -->5 -->8 -->NULL


<Multiplication Result> :
List = 4 -->4 -->1 -->9 -->5 -->1 -->0 -->NULL

*/