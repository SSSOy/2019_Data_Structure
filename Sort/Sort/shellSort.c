#include <stdio.h>

void shellSort(int a[], int n) {
	int t, i, j, key;
	for (t = n / 2; t > 0; t /= 2) {
		for (i = t; i < n; i++) {
			key = a[i];
			for (j = i - t; j >= 0; j -= t) {
				if (key >= a[j]) break;
				a[j + t] = a[j];
			}
			a[j + t] = key;
		}
	}
}

void main() {
	int a[] = { 21, 10, 30, 25, 28, 1, 9, 18, 4, 1, 124, 17, 12 };
	int n = sizeof(a) / sizeof(int);
	shellSort(a, n);

	printf("<< Shell Sort >>\n\n");
	for (int p = 0; p < n; p++)
		printf("%-4d", a[p]);
	puts("\n");
}