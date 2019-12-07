#include <stdio.h>
#include <stdlib.h>

void radixSort(int a[], int n) {
	int digit_cnt[10] = { 0 };
	int *bucket = (int *)malloc(sizeof(int) * n);
	int max = a[0];
	int digit_base = 1;
	int i;

	for (int i = 1; i < n; i++)
		if (max < a[i])
			max = a[i];

	while (digit_base <= max) {
		for (i = 0; i < n; i++) 
			digit_cnt[a[i] / digit_base % 10]++;
		for (i = 1; i < 10; i++) 
			digit_cnt[i] += digit_cnt[i - 1];
		for (i = n - 1; i >= 0; i--) 
			bucket[--digit_cnt[a[i] / digit_base % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = bucket[i];
		for (i = 0; i < 10; i++)
			digit_cnt[i] = 0;
		digit_base *= 10;
	}

	free(bucket);
}

void main() {
	int a[] = { 134, 506, 627, 33, 82, 921, 1004, 666, 211, 425, 326, 1127 };
	int n = sizeof(a) / sizeof(int);
	radixSort(a, n);

	printf("\n<<RadixSort>>\n\n");
	for (int i = 0; i < n; i++)
		printf("%-6d", a[i]);
	puts("\n\n\n\n\n\n\n\n");
}