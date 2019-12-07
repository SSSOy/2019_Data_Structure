#include <stdio.h>

void bubbleSort(int a[], int n) {
	int chk = 1;
	int i = n - 1;
	int temp;

	while (chk == 1) {
		chk = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				chk = 1;
			}
		}
		i--;
		for (int p = 0; p < n; p++)
			printf("%3d", a[p]);
		puts("");
	}
}

void main() {
	int a[] = { 10, 21, 15, 7, 11, 20, 10, 4, 19 };
	int n = sizeof(a) / sizeof(int);
	bubbleSort(a, n);
}