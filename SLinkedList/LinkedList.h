#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdbool.h>
struct Node_tag {
	int val;
	struct Node_tag *next;
};
typedef struct Node_tag node;

struct linked_list_tag {
	int size;
	node *sentinel;
};
typedef struct linked_list_tag llist;

llist * init_list();
int get_first(llist *);
void add_first(llist *, int);
int remove_first(llist *);
int size(llist *);
bool is_empty(llist *);
void free_list(llist *);
#endif
