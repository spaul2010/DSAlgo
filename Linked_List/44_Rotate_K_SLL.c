#include <stdio.h>


struct node {
	int data;
	struct node *link;
};

struct node * appendnode(struct node **tempHead, int val) {
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
	return temp;
}

void printlist(struct node *tempHead) {
	printf("\n List = ");
	while (tempHead) {
		printf("%d --> ", tempHead->data);
		tempHead = tempHead->link;
	}
	printf("NULL\n");
}

void rotate_k_SLL(struct node **tempHead, int k) {
	struct node *t = *tempHead;

	// Traverse till kth node
	for (int i = 0; i < (k - 1); i++) {
		if (t == NULL)
			return;
		else
			t = t->link; 
	}

	//get the address of slice start and end address
	struct node *slice_start, *slice_end;
	slice_start = t->link;
	slice_end = t->link;
	t->link = NULL;

	//traverse till end of list
	while (slice_end->link)
		slice_end = slice_end->link;
	
	//add the slice to the beginning of the list
	slice_end->link = *tempHead;
	*tempHead = slice_start;
}
void main() {
	struct node *head = NULL; 
	appendnode(&head, 10);
	appendnode(&head, 20);
	appendnode(&head, 30);
	appendnode(&head, 40);
	appendnode(&head, 50);
	appendnode(&head, 60);
	printlist(head);
	rotate_k_SLL(&head, 4);
	printlist(head);
}