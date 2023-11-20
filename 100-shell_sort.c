#include "sort.h"

/**
 *shell_sort - function to sort array like shell sorting
 *@array: the array we well sort
 * @size: the size of array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size <= 1)
		return;
	while (gap < size)
		gap = gap * 3 + 1;

	for (gap = gap / 3; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
