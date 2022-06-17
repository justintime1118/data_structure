#include "sort.h"

void quick_sort(int *arr, int left, int right)
{
	// 재귀호출 종료조건
	if (left >= right)
		return ;
	// 피봇 기준 좌우 정렬
	int pivot = arr[left];
	int l_cursor = left;
	int r_cursor = right;
	while (l_cursor < r_cursor)
	{
		while (arr[r_cursor] >= pivot && r_cursor > l_cursor)
			r_cursor--;
		arr[l_cursor] = arr[r_cursor];
		while (arr[l_cursor] <= pivot && l_cursor < r_cursor)
			l_cursor++;
		arr[r_cursor] = arr[l_cursor];
	}
	arr[l_cursor] = pivot; // 마지막에 반드시 잃어버렸던 pivot 값을 넣어줘야 함!
	// 분할 및 다음 재귀문 호출
	// 재귀문 두개를 호출할 때, 둘 다 l_cursor를 동일하게 그대로 넘겨줘서 segfault 떠가지고 고치느라 시간 좀 걸림
	quick_sort(arr, left, l_cursor - 1);
	quick_sort(arr, l_cursor + 1, right);
}

int main(void)
{
	int n;
	int *arr;
    
	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
