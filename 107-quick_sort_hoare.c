#include "sort.h"


/**
 * quick_sort_hoare - a quick sort function that uses hoare partition method
 * @array: array to be partitioned
 * @size: size of the array
 * Decription: quick sort function that calls on sorted partition to execute
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_parti(array, size, 0, size - 1);
}


/**
 * sort_parti - function that sort partitioned array based on hoare partition
 * @array: array to be partitioned
 * @size: size of the array
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 */

void sort_parti(int *array, size_t size, int lb, int ub)
{
	int pos;

	if (ub - lb > 0)
	{
		pos = partition(array, size, lb, ub);
		sort_parti(array, size, lb, pos - 1);
		sort_parti(array, size, pos, ub);
	}
}


/**
 * partition - function that partition array based on hoare's partition
 * @array: array to be partitioned
 * @size: size of the array
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 * Return: the lower bound to serve as ne pivot after swapping
 */
int partition(int *array, size_t size, int lb, int ub)
{
	int l, h, pivot;

	pivot = array[ub];
	for (h = lb - 1, l = ub + 1; h < l;)
	{
		do {
			h++;
		} while (array[h] < pivot);

		do {
			l--;
		} while (array[l] > pivot);

		if (h < l)
		{
			swap(array + h, array + l);
			print_array(array, size);
		}
	}
	return (h);
}


/**
 * swap - function that swap two int variables
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
