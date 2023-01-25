#include "sort.h"

void max_heapify(int *array, size_t size, size_t b_idx, size_t root);
void swap(int *a, int *b);

/**
 * heap_sort - function that sorts array using heap sort algorithm
 * @array: array to sort
 * @size: size of the arrayi
 *
 * Description: heap sort algorithm that implements the sift-down method
 *		prints the array after each swap
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}

/**
 * max_heapify - a recursive function that compares and swap heap tree values
 * @array: array to sort and organise
 * @size: sie of the array
 * @b_idx: the base/leaf index of the tree
 * @root: largest value on the max heap tree which is the root
 */

void max_heapify(int *array, size_t size, size_t b_idx, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < b_idx && array[left] > array[largest])
		largest = left;
	if (right < b_idx && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(array + root, array + largest);
		print_array(array, size);
		max_heapify(array, size, b_idx, largest);
	}
}


/**
 * swap - function that swaps integers
 * @a: pointer to the first variable
 * @b: pointer to the second variable
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
