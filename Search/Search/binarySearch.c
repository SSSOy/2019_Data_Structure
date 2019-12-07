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

	printf("ã�� �� : ");
	scanf_s("%d", &key);
	int index = binarySearch(a, key, n);

	if (index < 0) printf("\nã�� ���� �������� �ʽ��ϴ�.\n");
	else printf("\n%d�� %d���� ã��\n", key, index);
	return 0;
}