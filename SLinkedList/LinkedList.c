#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

llist * init_list() {
	llist *new_list = (llist *) malloc(sizeof(*new_list));
	if (new_list == NULL) {
		fprintf(stderr, "Fail to allocate list.\n");
		exit(EXIT_FAILURE);
	}

	new_list->size = 0;
	new_list->sentinel = (node *) malloc(sizeof(* new_list->sentinel));
	new_list->sentinel->next = NULL;
	if (new_list->sentinel == NULL) {
		fprintf(stderr, "Fail to allocate sentinel.\n");
		exit(EXIT_FAILURE);
	}
	return new_list;
}

int size(llist *list) {
	return list->size; 
}
bool is_empty(llist *list) {
	return size(list) == 0;
}

int get_first(llist *list) {
	if (list == NULL || is_empty(list)) {
		fprintf(stderr, "Invalid list.\n");
		exit(EXIT_FAILURE);
	}
	node *p = list->sentinel;
	return p->next->val; 
}
void add_first(llist *list, int val) {
	node *new_first = (node *) malloc(sizeof(*new_first));
	if (new_first == NULL) {
		exit(EXIT_FAILURE);
	}
	node *p = list->sentinel;
	list->size++;	
	new_first->val = val;
	new_first->next = p->next;
	p->next = new_first;
}
int remove_first(llist * list) {
	assert(!is_empty(list));
	int first_val;
	node *p = list->sentinel->next;
	list->sentinel->next = p->next;
	first_val = p->val;
	free(p);
	list->size--;
	return first_val;
}

void free_list(llist *list) {
	node *p = list->sentinel;
	while (!is_empty(list)) {
		remove_first(list);
	}
	free(p);
	free(list);
}

