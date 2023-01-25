#include "sort.h"

/**
 * selection_sort - sorting function based on the selection algorithm
 * @array: array to sort
 * @size: size of array
 * Description: divides array into sorted an unsorted and loop through
 *		unsorted array to select and place them in sorted array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	if (size <= 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (array[i] != array[min])
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
