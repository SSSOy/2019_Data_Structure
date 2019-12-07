#include <stdio.h>
#include <stdlib.h>

void mergeSort(int a[], int left, int mid, int right) {
	int *arr = (int *)malloc(sizeof(int) * (right - left + 1));
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (a[i] < a[j]) 
			arr[k++] = a[i++];
		else
			arr[k++] = a[j++];
	}
	if (i > mid)
		while (j <= right)
			arr[k++] = a[j++];
	else
		while (i <= mid)
			arr[k++] = a[i++];

	k = 0;
	for (i = left; i <= right; i++)
		a[i] = arr[k++];

	free(arr);
}

void divide(int a[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		divide(a, left, mid);
		divide(a, mid + 1, right);
		mergeSort(a, left, mid, right);
	}
}

void main() {
	int a[] = { 6, 27, 56, 9, 21, 4, 8, 5, 99 };
	int n = sizeof(a) / sizeof(int);
	divide(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%4d", a[i]);
	puts("");
}