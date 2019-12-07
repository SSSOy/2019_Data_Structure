#include <stdio.h>

int binarySearch(int a[], int key, int n) {
	int left = 0, right = n - 1, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (key > a[mid]) left = mid + 1;
		else if (key < a[mid]) right = mid - 1;
		else return mid;
	}
	return -1;
}

int main() {
	int a[] = { 3, 7, 11, 19, 25, 33, 49, 51, 67, 85, 100 };
	int n = sizeof(a) / sizeof(int);
	int key;

	printf("찾을 값 : ");
	scanf_s("%d", &key);
	int index = binarySearch(a, key, n);

	if (index < 0) printf("\n찾는 값이 존재하지 않습니다.\n");
	else printf("\n%d를 %d에서 찾음\n", key, index);
	return 0;
}