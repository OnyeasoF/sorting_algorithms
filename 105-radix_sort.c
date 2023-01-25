#include "sort.h"


void radix_count_sort(int *array, size_t size, int pos, int *buf);
int max_value(int *array, int size);

/**
 * radix_sort - function that uses radix algorithm to sort integers
 * @array: array to sort
 * @size: size of the array
 *
 * Description: implement the LSD radix sort algorithm
 */

void radix_sort(int *array, size_t size)
{
	int max, pos, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	max = max_value(array, size);
	for (pos = 1; max / pos > 0; pos *= 10)
	{
		radix_count_sort(array, size, pos, buf);
		print_array(array, size);
	}

	free(buf);
}


/**
 * radix_count_sort - function for radix count subroutine
 * @array: the array to be sorted
 * @size: size of the array
 * @pos: index position of digit starting at the least value in digit
 * @buf: buffer to store sorted array
 */

void radix_count_sort(int *array, size_t size, int pos, int *buf)
{
	int count[10] = {0};
	size_t i;


	for (i = 0; i < size; i++)
		++count[(array[i] / pos) % 10];

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1]; /* sums the counts per value pos */

	/* gets the exact index pos of sorted values based on count array */
	for (i = size - 1; (int)i >= 0; i--)
	{
		buf[--count[(array[i] / pos) % 10]] = array[i];
		/*decrement count value by 1 to get exact position of value*/
	}

	for (i = 0; i < size; i++)
		array[i] = buf[i];
}


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
