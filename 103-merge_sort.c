#include "sort.h"

/**
 * msg_start - prints splitted arrays before merge
 * @tmp_ar: helper array
 * @x: start index of tmp_arr first part
 * @y: start index of tmp_arr second part
 * @n1: no. tmp_arr of first part elements
 * @n2: no. tmp_arr of second part elements
 * Return: nothing
 */

void msg_start(int *tmp_ar, size_t x, size_t y, size_t n1, size_t n2)
{
/* set in order original array */
size_t i;

printf("Merging...\n");
printf("[left]: ");
for (i = x; i < n1; i++)
{
if (i == x)
{
printf("%d", tmp_ar[i]);
}
else
{
printf(", %d", tmp_ar[i]);
}
}
printf("\n");

printf("[right]: ");
for (i = y; i < n2; i++)
{
if (i == y)
{
printf("%d", tmp_ar[i]);
}
else
{
printf(", %d", tmp_ar[i]);
}
}
printf("\n");
}

/**
 * msg_mrg_end - prints meged arrays after merge
 * @array: original array
 * @l: given start index of array
 * @r: given end index of array
 * Return: nothing
 */

void msg_mrg_end(int *array, size_t l, size_t r)
{
size_t i;
printf("[Done]: ");
for (i = l; i <  r + 1 ; i++)
{
if (i == l)
{
printf("%d", array[i]);
}
else
{
printf(", %d", array[i]);
}
}
printf("\n");
}


/**
 * sorter - sorts splitted arrays
 * @tmp_ar: helper array
 * @array: original array
 * @l: given start index of array
 * @m: middle index of array
 * @r: given end index of array
 * @size: size of array
 * Return: nothing
 */

void sorter(int *array, int *tmp_ar, size_t l, size_t m, size_t r, size_t size)
{
size_t i, z, n1, n2, x = 0, y = 0;
x = l;
y = m + 1;
z = l;
n1 = m - l + 1 + x;
n2 = r - m + y;
msg_start(tmp_ar, x, y, n1, n2);
while (x < n1 && y < n2)
{
if (tmp_ar[x] <= tmp_ar[y])
{
array[z] = tmp_ar[x];
x++;
}
else
{
array[z] = tmp_ar[y];
y++;
}
z++;
}
while (x < n1)
{
array[z] = tmp_ar[x];
x++;
z++;
}
while (y < n2)
{
array[z] = tmp_ar[y];
y++;
z++;
}
msg_mrg_end(array, l, r);
for (i = 0; i < size; i++)
tmp_ar[i] = array[i];
}

/**
 * recursor - loop to spit original array to subarrays
 * @array: original array
 * @tmp_ar: helper array
 * @l: given start index of array
 * @r: given end index of array
 * @size: size of array
 * Return: nothing
 */

void recursor(int *array, int *tmp_ar, size_t l, size_t r, size_t size)
{
size_t m;

if (l < r)
{
/*left array shall be less right array*/
m = (l + r - 1) / 2;

recursor(array, tmp_ar, l, m, size);
recursor(array, tmp_ar, m + 1, r, size);

sorter(array, tmp_ar, l, m, r, size);
}
}

/**
 * merge_sort - uses merge sort concept for array
 * @array: original array
 * @size: size of array
 * Return: nothing
 */

void merge_sort(int *array, size_t size)
{
int *tmp_ar;
size_t i;

/* calling malloc is allowed 1 time only*/
tmp_ar = malloc(sizeof(int) * size);
if (!tmp_ar)
return;

for (i = 0; i < size; i++)
tmp_ar[i] = array[i];

recursor(array, tmp_ar, 0, size - 1, size);

free(tmp_ar);
}
