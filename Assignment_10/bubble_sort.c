#include "sort.h"

void swap(int *a, int *b)
{
	int temp = *a;

    *a = *b;
    *b = temp;
}

int bubble_sort(int n, int *arr)
{
	for (int i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);

	for (int i = 0 ; i < n - 1 ; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}

	for (int i = 0 ; i < n ; i++)
		printf("%d ", arr[i]);

	return SUCCESS;
}