#include <stdio.h>
#include <limits.h>

void heapSort(int a[], int n) {
	int i, value, parent, child;
	for (i = n / 2; i > 0; i--) {
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
	}
	while (n > 1) {
		value = a[n];
		a[n--] = a[1];
		parent = 1;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
	}
}

void main() {
	int a[] = { INT_MIN, 56, 7, 8, 10, 39, 21, 18, 28,20, 67, 2, 4 };
	int size = sizeof(a) / sizeof(int);
	heapSort(a, size - 1);
	printf("<< Èü Á¤·Ä °á°ú >>\n");
	for (int i = 1; i < size; i++)
		printf("%3d", a[i]);
	puts("");
}