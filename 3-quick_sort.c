#include "sort.h"

/**
 * operation - function to make the swap operation
 * @array: the
 * @start: start
 * @end: end
 * Return: the pivote
 */

int Lomuto(int *array, size_t size, size_t start, size_t end)
{
	int pivote = array[end], temp;
	size_t i = start - 1, j;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < pivote)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	i++;
	temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	if (array[i] != temp)
		print_array(array, size);
	return (i);
}

/**
 * quick_reco - function to sort bye quick sort
 * @size: the size of arry
 * @array: the array
 * @start: the first area
 * @end: the last erea
 *Return: void
 */

void quick_reco(int *array, size_t start, size_t end, size_t size)
{
        int pivote;
        if (end <= start)
        {
                return;
        }
        pivote = Lomuto(array, size, start, end);
        quick_reco(array, size, start, pivote - 1);
        quick_reco(array, size, pivote + 1, end);
}

/**
 * quick_sort - function to sort array
 * @array: array we well sort
 * @size: the size of array
 */

void quick_sort(int *array, size_t size)
{
        if (!array || size <= 1)
        {
                return;
        }
        quick_reco(array, 0, size - 1, size);
}
