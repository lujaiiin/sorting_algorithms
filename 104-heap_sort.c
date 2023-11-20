#include "sort.h"

/**
 * heapify - function
 * @arr: the arr we well use
 * @size: the arr size
 * @i: the ii
 */

void heapify(int *arr, size_t size, size_t i)
{
	size_t lar = i, len = size;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	int temp;

	if (left < size && arr[left] > arr[lar])
		lar = left;
	if (right < size && arr[right] > arr[lar])
		lar = right;
	if (lar != i)
	{
		temp = arr[i];
		arr[i] = arr[lar];
		arr[lar] = temp;
		print_array(arr, len);
		heapify(arr, size, lar);
	}
}

/**
 * heap_sort - function to sort tree com
 * @array: the array we wel sort
 * @size: the size of array
 */

void heap_sort(int *array, size_t size)
{
	int temp;
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0);
	}
}
