#include "sort.h"

void shell_sort(int *arr, int n)
{
	int c = 0;
    int key, j, i = 0;
    int gap = n / 2;

    while (TRUE)
	{
        if (gap % 2 == 0)
            gap++;
        for (i = gap; i < n; i++)
		{
            key = arr[i];
            for (j = i - gap; j >= 0; j = j - gap)
			{
                if (key < arr[j])
                    arr[j + gap] = arr[j];
                else
                    break;
            }
        arr[j + gap] = key;
        }
        if (gap == 1)
            break;
        gap = gap / 2;
    }
}
