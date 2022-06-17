#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int selection_sort(int n, int *arr)
{
	int min_idx;

	for (int i = 0; i < n; i++)
	{
        min_idx = i;
        for (int j = i + 1; j < n; j++)
		{
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
	for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
	return SUCCESS;
}