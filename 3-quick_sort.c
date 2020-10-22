#include "sort.h"

/**
 * partition - reorder the array so that all elements with values less than
 * the pivot come before the pivot, while all elements with values greater than
 * the pivot come after it
 * @array: array
 * @low: lower index
 * @high: higher index
 * @size: total size of the full array
 *
 * Return: pivot final index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}

	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);

}

/**
 * lomuto_q_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @low: lower index
 * @high: higher index
 * @size: size of the full array
 *
 */
void lomuto_q_sort(int *array, int low, int high, size_t size)
{
	int idx_pivot;

	if (low < high)
	{
		idx_pivot = partition(array, low, high, size);
		lomuto_q_sort(array, low, idx_pivot - 1, size);
		lomuto_q_sort(array, idx_pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: array's size
 *
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	lomuto_q_sort(array, 0, size - 1, size);
}
