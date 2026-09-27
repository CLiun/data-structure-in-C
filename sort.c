#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *, int *);
void quick_sort(int *, size_t);
void merge_sort(int *, size_t);
void select_sort(int *, size_t);
void bubble_sort(int *, size_t);
void insert_sort(int *, size_t);


int main(int argc, char *argv[]) {
	srand(time(NULL));

	const int upper = 40000090;
	const int lower = 20000090;
	int size = rand() % (upper - lower + 1) + lower;
	int *unsort = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		unsort[i] = rand() % (size - 1) + 1;
	}
	// int unsort[] = {9999999, 32, 15, 2,-1,-3, 17, 9, 26, 41, 17, 17};

	// int size = sizeof(unsort) / sizeof(int);
	quick_sort(unsort, size);
  // merge_sort(unsort, size);
	// insert_sort(unsort, size);
	// bubble_sort(unsort, size);
	// select_sort(unsort, size);
	for (int i = 0; i < 200; i++) {
		printf("%d ", unsort[i]);
	}
	printf("\n");
	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void select_sort(int *arr, size_t size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i; j < size; j++) {
			min = (arr[j] < arr[min]) ? j : min;
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}


void bubble_sort(int *arr, size_t size) {
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr + j, arr + j + 1);
			}
		}
	}
}

 
void insert_sort(int *arr, size_t size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			}
		}
	}
}

void merge_sort(int *arr, size_t size) {
	if (size == 1) return ;
	int half = size / 2;
	merge_sort(arr, half);
	merge_sort(arr + half, size - half);

	int left = 0;
	int right = half;
	int *temp = malloc(sizeof(int) * size);
	int idx = 0;
	while (left < half || right < size) {
		if (left == half) {
			temp[idx++] = arr[right++];
		} else if (right == size) {
			temp[idx++] = arr[left++];
		} else {
			if (arr[left] < arr[right]) {
				temp[idx++] = arr[left++];
			} else {
				temp[idx++] = arr[right++];
			}
		}
	}
	for (int i = 0; i < size; i++) {
		arr[i] = temp[i];
	}
	free(temp);
}

void quick_sort(int *arr, size_t size) {
	if (size <= 1) return ;
	int pivot_i = 0;
	int pivot = arr[pivot_i];
	int left = 1; 
	int right = size - 1;
	while (left <= right) {
		if (arr[left] <= pivot) {
			left++;
		} else if (arr[right] >= pivot) {
			right--;
		} else {
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	swap(&arr[pivot_i], &arr[right]);
	pivot_i = right;
	quick_sort(arr, pivot_i);
	if (pivot_i >= size - 1) return ;
	quick_sort(arr + pivot_i + 1, size - 1 - pivot_i);
}

