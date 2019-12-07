#include <stdio.h>

void main() {
	int a[] = { 10, 5, 7, 12, 9, 16, 1, 3 };
	int length = sizeof(a) / sizeof(int);

	printf("정렬 전 : ");
	for (int i = 0; i < length; i++)
		printf("%3d", a[i]);
	puts("");

	for (int i = 0; i < length - 1; i++) {
		int min = i;
		int temp;
		//int min = a[i]; int index = i;
		for (int j = i + 1; j < length; j++)
			if (a[min] > a[j]) { //min > a[j]
				min = j; //min = a[j]; index = j;
			}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		//a[index] = a[i];
		//a[i] = min;
	}

	printf("정렬 후 : ");
	for (int i = 0; i < length; i++)
		printf("%3d", a[i]);
	puts("");
}