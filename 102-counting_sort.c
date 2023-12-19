#include "sort.h"
/**
 * get_max - This gets the maximum value in an array of integers
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: the maximum integer in the array
 *
 */
int get_max(int *array, int size)
{
	int max, k;

	for (max = array[0], k = 1; k < size; k++)
	{
		if (array[k] > max)
			max = array[k];
	}

	return (max);
}

/**
 * counting_sort - This sorts an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: This prints the counting array after
 * setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		cnt[i] = 0;
	for (i = 0; i < (int)size; i++)
		cnt[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		cnt[i] += cnt[i - 1];
	print_array(cnt, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[cnt[array[i]] - 1] = array[i];
		cnt[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(cnt);
}
