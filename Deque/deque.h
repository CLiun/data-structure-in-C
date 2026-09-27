#ifndef DEQUE_H
#define DEQUE_H

struct Node_tag {
	int val;
	struct Node_tag *prev;
	struct Node_tag *next;
};
typedef Node_tag Node_t;

struct Deque_tag {
	size_t size;


#endif
