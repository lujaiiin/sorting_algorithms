#include "sort.h"


/**
 * swp - exchange values of 2 variables
 * @x: pointer to integer
 * @y: pointer to integer
 * Return: nothing
 */

void swp(int *x, int *y)
{
int tmp;
tmp = *x;
*x = *y;
*y = tmp;
}


/**
 * selection_sort - sort array ascendingly
 * @array: array of integers
 * @size: array length
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
size_t i, j, idx;
for (i = 0; i < size -1; i++)
{
idx = i;
for (j = i + 1; j < size; j++)
{
if (array[idx] > array[j])
{
idx = j;
}
}
if (idx != i)
{
swp(&array[idx], &array[i]);
print_array(array, size);
}
}
}
