#include "sort.h"

void sorted_array(int *array, int *buf, size_t l_idx, size_t r_idx);
void merge(int *array, int *buf, size_t l_idx, size_t mid, size_t r_idx);

/**
 * merge_sort - function that sorts and merge an array using merge sort
 * @array: array to sort and merge
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	sorted_array(array, buf, 0, size);

	free(buf);
}


/**
 * sorted_array - function that divides array into sub-arrays
 * @array: array to be divided
 * @buf: buffer to store divided arrays
 * @l_idx: left index of the array
 * @r_idx: right index of the array
 * Description: recursive function that divides array into single sorted array
 */

void sorted_array(int *array, int *buf, size_t l_idx, size_t r_idx)
{
	size_t mid;

	if (l_idx < r_idx)
		mid = (l_idx + r_idx) / 2;

	if (r_idx - l_idx > 1)
	{
		sorted_array(array, buf, l_idx, mid);
		sorted_array(array, buf, mid, r_idx);
		merge(array, buf, l_idx, mid, r_idx);
	}
}


/**
 * merge - function that merges single sorted array
 * @array: array to be divided
 * @buf: buffer to store divided arrays
 * @l_idx: left index of the array
 * @mid: middle index of the array
 * @r_idx: right index of the array
 * Description: merge and sort the arrays in ascending order
 */

void merge(int *array, int *buf, size_t l_idx, size_t mid, size_t r_idx)
{
	size_t l, m, i = 0;

	l = l_idx;
	m = mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l_idx, mid - l_idx);

	printf("[right]: ");
	print_array(array + mid, r_idx - mid);

	while (l < mid && m < r_idx)
	{
		if (array[l] < array[m])
			buf[i++] = array[l++];
		else
			buf[i++] = array[m++];
	}

	while (l < mid)
		buf[i++] = array[l++];

	while (m < r_idx)
		buf[i++] = array[m++];

	for (l = l_idx, i = 0; l < r_idx; l++)
		array[l] = buf[i++];

	printf("[Done]: ");
	print_array(array + l_idx, r_idx - l_idx);
}
