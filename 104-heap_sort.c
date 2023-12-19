#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - This swaps two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_heapify - This turns a binary tree into a complete
 * binary heap.
 * @array: array of integers representing a binary tree.
 * @size: the size of the array/tree.
 * @base: the index of the base row of the tree.
 * @root: the root node of the binary tree
 *
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - This sorts an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: Thhs implements the sift-down heap sort
 * algorithm. This prints the array after each swap
 *
 */
void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = (size / 2) - 1; k >= 0; k--)
		max_heapify(array, size, size, k);

	for (k = size - 1; k > 0; k--)
	{
		swap_ints(array, array + k);
		print_array(array, size);
		max_heapify(array, size, k, 0);
	}
}
