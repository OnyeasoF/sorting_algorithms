#include "sort.h"

/**
 * max_value - function to get the maximum value from an array
 * @array: array to get maximum value from
 * @size: size of the array
 * Return: maximum value in the array
 */

int max_value(int *array, int size)
{
	int max = array[0], i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}


/**
 * counting_sort - function for counting sort
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Description: prints the counting array
 */

void counting_sort(int *array, size_t size)
{
	int max, *count, *sorted, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = max_value(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	/* initialize count array with zero values */
	for (i = 0; i < (max + 1); count[i] = 0, i++)
		;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++; /* stores counted values in array */

	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1]; /* sums the counts per value pos */
	print_array(count, max + 1);

	/* gets the exact index pos of sorted values based on count array */
	for (i = size - 1; i >= 0; i--)
	{
		sorted[--count[array[i]]] = array[i];
		/*decrement count value by 1 to get exact position of value*/
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
