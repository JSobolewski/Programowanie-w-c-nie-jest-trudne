#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	unsigned long val; 
	struct element *next; 
} element;

/* Zadanie 11.1 
head - pointer to the first element
value - value of the new element
*/
void put_top(element **head, long value) {
	if (*head == NULL) {
		*head = (element*)malloc(sizeof(element));
		(*head)->val = value; 
		(*head)->next = NULL; 
	}
	else {
		element *generated = (element*)malloc(sizeof(element));
		generated->val = value;
		generated->next = *head;
		*head = generated;
	}
}

/* Zadanie 11.2 
head - pointer to the first element
value - value of the new element
*/
void push_back(element **head, long value) {
	if (*head == NULL) {
		*head = (element*)malloc(sizeof(element));
		(*head)->val = value;
		(*head)->next = NULL;
	}
	else {
		element *last = *head; 
		while (last->next) {
			last = last->next;
		}

		last->next = (element*)malloc(sizeof(element)); 
		last->next->val = value;
		last->next->next = NULL;
	}
}

/* Zadanie 11.3 
head - pointer to the first element
value - value of the new element 
*/
void put_sorted(element **head, long value) {
	if (*head == NULL) {
		*head = (element*)malloc(sizeof(element));
		(*head)->val = value;
		(*head)->next = NULL;
	} else {
		element *position = *head; 

		if (position->val > value) {
			put_top(head, value);
		} else {
			while (position->next && position->next->val <= value) {
				position = position->next;
			}

			element *tmp = position->next;
			position->next = NULL;
			position->next = (element*)malloc(sizeof(element));

			position->next->val = value;
			position->next->next = tmp;
		}
	}
}

/* 
head - pointer to the first element
*/
void print_list(element **head) {
	while (*head) {
		printf("%d\n", (*head)->val); 
		*head = (*head)->next;
	}
}

int main() {
	element *head = NULL;

	//put_top(&head, 10); 
	//put_top(&head, 15); 
	//push_back(&head, 5); 

	put_sorted(&head, 2); 
	put_sorted(&head, 6);
	put_sorted(&head, 1);
	put_sorted(&head, 5);
	put_sorted(&head, 10); 
	put_sorted(&head, 3);

	print_list(&head); 

	free(head); 

	system("PAUSE");
	return 0;
}
