#include "sort.h"

/**
 * count_srt - sort array with count sort concept
 * @arr: array required to be sorted
 * @n: array length
 * @exp: divisor for elements
 * Return: nothing
 */

void count_srt(int *arr, int n, int exp)
{
int i, *output;
int count[10] = {0};
output = malloc(sizeof(int) * n);
if (!output)
return;
/*fill repitative count of elements*/
for (i = 0; i < n; i++)
count[(arr[i] / exp) % 10]++;
/*cumulative count of elements*/
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
/* assign ordered elements*/
for (i = n - 1; i >= 0; i--)
output[--count[(arr[i] / exp) % 10]] = arr[i];
/*update arr*/
for (i = 0; i < n; i++)
arr[i] = output[i];
print_array(arr, n);
free(output);
}


/**
 * radix_sort - sort array with radix sort concept
 * @array: array required to be sorted
 * @size: array length
 * Return: nothing
 */

void radix_sort(int *array, size_t size)
{
int max;
size_t i, exp;
max = array[0];
for (i = 0; i < size; i++)
if (array[i] > max)
max = array[i];
for (exp = 1; max / exp > 0; exp *= 10)
count_srt(array, size, exp);
}
