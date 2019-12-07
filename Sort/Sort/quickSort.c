#include <stdio.h>

void quickSort(int a[], int n, int m) {
	int i = n, j = m, temp, key = a[n];
	if (n < m) {
		while (i < j) {
			while (a[i] <= key && i < m) i++;
			while (a[j] >= key && j > n) j--;
			if (i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		a[n] = a[j];
		a[j] = key;
		quickSort(a, n, j - 1);
		quickSort(a, j + 1, m);
	}
}

void main() {
	int a[] = { 23, 5, 37, 1, 30, 11, 52, 48, 20 };
	int n = sizeof(a) / sizeof(int);
	quickSort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%3d", a[i]);
	puts("");
}