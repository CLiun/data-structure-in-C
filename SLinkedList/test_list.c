#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));

	llist *my_list = init_list();

	int N = 5000;
	for (int i = 0; i < N; i++) {
		int opcode = rand() % 3;
		switch (opcode) {
			case 0:
				add_first(my_list, rand());
				break;
			case 1:
				printf("Size is: %d\n", size(my_list));
				break;
			case 2:
				if (is_empty(my_list)) {
					continue;
				}
				printf("Remove first: %d\n", remove_first(my_list));
				break;
		}
	}
	free_list(my_list);
	return 0;
}
