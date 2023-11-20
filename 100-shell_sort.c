#include "sort.h"

/**
 *shell_sort - function to sort array like shell sorting
 *@array: the array we well sort
 * @size: the size of array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;
	
	for (gap = size/2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i += 1)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
