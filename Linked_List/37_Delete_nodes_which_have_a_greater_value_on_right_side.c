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

void delete_node_right_greater(struct node **tempHead) {
	struct node *t1, *t1_prev, *t2;
	t1 = *tempHead;
	t1_prev = NULL;

	int delete_node_done;
	while (t1) {
		t2 = t1->link;
		delete_node_done = 0;
		while (t2) {
			if (t2->data > t1->data) {
				//delete first node
				if (t1 == *tempHead) {
					*tempHead = t1->link;
					free(t1);

					//readjust t1 and t2
					t1 = t2;
					delete_node_done = 1;
					break;
				}
				else {
					//delete t1 node
					t1_prev->link = t1->link;
					free(t1);
					//readjust t1 and t2
					t1 = t1_prev->link;
					delete_node_done = 1;
					break;
				}
			}
			t2 = t2->link;
		}
		if (delete_node_done)
			continue;
		else
			t1_prev = t1;
			t1 = t1->link;
	}
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
	delete_node_right_greater(&head);
	printlist(head);
}