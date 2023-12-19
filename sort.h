#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list done
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *a);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void splt_merge(size_t strt, size_t end, int *array, int *sorted);
void merge(size_t strt, size_t midd, size_t end, int *right, int *left);
void heapify(int *array, size_t size, size_t n, size_t x);
void heap_sort(int *array, size_t size);
void swap_heap(int *arr, int *siz);
void count_sort(int *array, size_t size, int digit);
void radix_sort(int *array, size_t size);
int find_max(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bit_sorting(char dir, int *array, size_t size, size_t q);
void bit_merge(char dir, int *array, size_t size);
void bit_comp(char dir, int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void hoare_quic_sort(int *array, ssize_t low, ssize_t high, size_t size);
size_t hoare_part(int *array, ssize_t low, ssize_t high, size_t size);

#endif  /* SORT_H */
