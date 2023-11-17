#include "sort.h"

/**
 * bubble_sort - function to print arry by bubble sort
 * @array: the array well sorted
 * @size: the size of arry
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp = 0;
    int swapped = 1;
	if (!array || size <= 1)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
        int swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
                int swapped = 1;
			}
		}
	}
}
