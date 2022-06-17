#include "sort.h"

int insertion_sort(int n, int *arr)
{
	for (int i = 0; i < n; i++)
		scanf("%arr", &arr[i]);

	int temp;
	int j;

	for (int i = 0; i < n; i++) {
		temp = arr[i];
		j = i - 1;
		for (int j = i - 1; j >= 0; j--) {

			if (arr[j] < temp)
				break;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}