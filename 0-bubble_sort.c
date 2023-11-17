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
 * bubble_sort - sort array ascendingly
 * @array: array of integers
 * @size: array length
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
size_t i, j;

if (!array || size == 0)
return;

for (i = 0; i < size; i++)
{
for (j = 0; j < size  - 1 - i; j++)
{
if (array[j] > array[j + 1])
{
swp(&array[j], &array[j + 1]);
print_array(array, size);
}
}
}
}
