#include "sort.h"
#include "arrayqueue.h"

int calculateMaxLen(int *arr, int n)
{
	int maxLen = 0;
	int tmpLen;
	int num;

	// arr을 순회하면서 가장 길이가 긴 정수의 길이를 구해서 리턴함
	for (int i = 0; i < n; i++)
	{
		tmpLen = 0;
		num = arr[i];
		while (num > 0)
		{
			tmpLen++;
			num /= 10;
		}
		if (tmpLen > maxLen)
			maxLen = tmpLen;
	}
	return (maxLen);
}

int radix_sort(int *arr, int n)
{
	ArrayQueue **pQueues;
	ArrayQueueNode element;

	pQueues = (ArrayQueue **)malloc(sizeof(ArrayQueue *) * 10);

	for (int i = 0; i < 10; i++)
		pQueues[i] = createArrayQueue(n);

	int maxLen = calculateMaxLen(arr, n);
	int idx;

	// 가장 큰 자릿수에 맞춰서 반복한다
	for (int i = 0, div = 10; i < maxLen; i++, div *= 10)
	{
		// 배열을 훑으면서 버킷에 넣어줌
		for (int j = 0; j < n; j++)
		{
			element.data = arr[j];
			 // 정확히 자릿수에 맞는 버킷에 딱 넣도록 해줘야 함
			enqueueAQ(pQueues[(arr[j] % div) / (div / 10)], element);
		}
		// 큐를 훑으면서 다시 배열에 넣어줘야 함
		idx = 0;
		for (int k = 0; k < 10; k++)
		{
			while (pQueues[k]->currentElementCount > 0)
				arr[idx++] = dequeueAQ(pQueues[k])->data;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}

int main(void)
{
	int size;
	int *arr;
    
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    radix_sort(arr, size);
	
	// 아무 문제없이 정렬은 잘되는데 bus error가 계속남..뭐지??
	// for (int i = 0; i < size; i++)
	// 	printf("%d ", arr[i]);
	// printf("\n");
	return (0);
}
