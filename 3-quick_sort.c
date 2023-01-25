#include "sort.h"

/**
 * quick_sort - function that sorts arrays based on quick sort algorithm
 * @array: array to sort
 * @size: size of array
 * Description: sorts array using lomuto partition
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_parti(array, size, 0, size - 1);
}

/**
 * sort_parti - function that sort array into partition
 * @array: array to sort
 * @size: size of array
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 * Description: stores the lower bound returned value in position as next pivot
 */

void sort_parti(int *array, size_t size, int lb, int ub)
{
	int pos;

	if (ub - lb > 0)
	{
		pos = partition(array, size, lb, ub);
		sort_parti(array, size, lb, pos - 1);
		sort_parti(array, size, pos + 1, ub);
	}
}


/**
 * partition - function that partitions an array per lomuto partitioning
 * @array: array to partition
 * @size: size of array
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 * Return: lower bound of the array as next pivot
 */

int partition(int *array, size_t size, int lb, int ub)
{
	int i, j, *pivot;

	pivot = array + ub;
	i = lb;

	for (j = lb; j < ub; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
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
