#include "sort.h"

/**
 * counting_sort - sort algorithm as counting
 * @array: the array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k, *cu, *co, i;

	if (array == NULL || size < 2)
	{
		return;
	}
	co = malloc(sizeof(int) * size);
	if (co == NULL)
	{
		return;
	}
	k = sort(array, size) + 1;
	cu = malloc(sizeof(int) * k);
		if (cu == NULL)
		{
			free(co);
			return;
		}
	for (i = 0; i < k; i++)
		cu[i] = 0;
	for (i = 0; i < (int) size; i++)
		cu[array[i]]++;
	for (i = 1; i < k; i++)
		cu[i] += cu[i - 1];
	print_array(cu, k);
	for (i = 0; i < (int) size; i++)
		co[cu[array[i]] - 1] = array[i], cu[array[i]]--;
	for (i = 0; i < (int) size; i++)
		array[i] = co[i];
	free(cu);
	free(co);
}

/**
*sort - function
*@array: the array i well use
*@size: the array size
Return: alwas int
*/
int sort(int *array, size_t size)
{
	int ar;

	ar = array[size - 1];
	while (size - 1 > 0)
	{
		if (ar < array[size])
			ar = array[size];
	}
	return (ar);
}
