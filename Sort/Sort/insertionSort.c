#include <stdio.h>

void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (key >= a[j])  break;
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
		for (int p = 0; p < n; p++)
			printf("%3d", a[p]);
		puts("");
	}
}

void main() {
	int a[] = { 10, 21, 15, 7, 11, 20, 10, 4, 19 };
	int n = sizeof(a) / sizeof(int);
	insertionSort(a, n);
}