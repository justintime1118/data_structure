#include "sort.h"

void merge_sort(int *arr, int *ret, int left, int right)
{
	// 재귀호출 종료조건
	if (left >= right)
		return ;

	// 분할
	int m = (left + right) / 2;
	merge_sort(arr, ret, left, m);
	merge_sort(arr, ret, m + 1, right);

	// 투포인터 정렬
	int l_cursor = left;
	int r_cursor = m + 1;
	int idx = left;
	
	while (l_cursor <= m || r_cursor <= right)
	{
		// if문으로 조건을 적절하게 걸어주는 거에서 고생을 많이 했음. 왜 이렇게 어려웠을까?
		if (l_cursor <= m && (arr[l_cursor] < arr[r_cursor] || r_cursor > right))
			ret[idx++] = arr[l_cursor++];
		else
			ret[idx++] = arr[r_cursor++];
	}
	for (int i = left; i <= right; i++)
		arr[i] = ret[i];
}

int main(void) {

	int n;
	int *arr;
	int	*ret;

	scanf("%d", &n);
	arr = malloc(n * sizeof(int));
	ret = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	merge_sort(arr, ret, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", ret[i]);
}
