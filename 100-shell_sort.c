#include "sort.h"

void swap(int *a, int *b);


/**
 * shell_sort - function that sorts a array in ascending order
 * @array: array to sort
 * @size: size of array
 * Description: sort array using shell sort algorithm
 * gap: uses knuth sequence spacing
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < (size / 3))
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			i = j;
			while (i >= gap && array[i - gap] > array[i])
			{
				swap(array + i, array + (i - gap));
				i -= gap;
			}
		}
		print_array(array, size);
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
