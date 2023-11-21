#include "sort.h"

/**
 * partition_srt - sort array with hoare sort concept
 * @arr: array required to be sorted
 * @low: array first element
 * @high: array last element
 * @size: array length
 * Return: element idex to split array
 */

int partition_srt(int arr[], size_t low, size_t high, size_t size)
{
int temp, pivot = arr[high];
size_t i = low - 1, j = high + 1;
while (1)
{
do {
i++;
} while (arr[i] < pivot);
do {
j--;
} while (arr[j] > pivot);
if (i >= j)
{
return (j);
}
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
print_array(arr, size);
}
}

/**
 * quickSrt - sort array and create subarrays
 * @arr: array required to be sorted
 * @low: array first element
 * @high: array last element
 * @size: array length
 * Return: nothing
 */

void quickSrt(int arr[], size_t low, size_t high, size_t size)
{
if (low < high)
{
int pi = partition_srt(arr, low, high, size);

quickSrt(arr, low, pi, size);
quickSrt(arr, pi + 1, high, size);
}
}

/**
 * quick_sort_hoare - sort array with quick sort hoare
 * @array: array required to be sorted
 * @size: array length
 * Return: nothing
 */

void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quickSrt(array, 0, size - 1, size);
}
