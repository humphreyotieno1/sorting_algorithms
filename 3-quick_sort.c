#include "sort.h"
/**
 * quick_sort - Quick sort array of ints
 * @array: Array of ints
 * @size: Size of the array of ints
 */
void quick_sort(int *array, size_t size)
{
	q_sort(array, 0, size - 1, size);
}

/**
 * q_sort - Implement of quick sort
 * @array: Array of ints
 * @l: Lower index
 * @h: Higher index
 * @size: Size of array of ints
 */
void q_sort(int *array, int l, int h, size_t size)
{
	int part;

	if (l < h)
	{
		part = partition(array, l, h, size);
		q_sort(array, l, part - 1, size);
		q_sort(array, part + 1, h, size);
	}
}

/**
 * partition - Partition function implementation
 * @array: Array of ints
 * @l: Lower index
 * @h: Higher index
 * @size: Size of array of ints
 * Return: Index after partition
 */
size_t partition(int *array, int l, int h, size_t size)
{
	int aux, pivot = array[h];
	int a = l - 1, b;

	for (b = l; b < h; b++)
	{
		if (array[b] <= pivot)
		{
			a++;
			if (a != b)
			{
				aux = array[a];
				array[a] = array[b];
				array[b] = aux;
				print_array(array, size);
			}
		}
	}
	if (a + 1 != h)
	{
		aux = array[a + 1];
		array[a + 1] = array[h];
		array[h] = aux;
		print_array(array, size);
	}
	return (a + 1);
}
