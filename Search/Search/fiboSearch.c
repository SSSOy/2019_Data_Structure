#include <stdio.h>

int fiboSearch(int a[], int key, int n) {
	int fibo[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	int index = 0, pos, k = 0;

	while (fibo[k] < n) k++;
	while (k > 0) {
		pos = index + fibo[--k];
		if (pos >= n || key < a[pos]);
		else if (key > a[pos]) {
			index = pos;
			k--;
		}
		else {
			return pos;
		}
	}
	return -1;
}

void main() {
	int a[] = { 1, 4, 5, 21, 25, 33, 37, 41, 46, 49, 52, 56, 60, 69 };
	int n = sizeof(a) / sizeof(int);
	int key;
	
	printf("ã�� �� : ");
	scanf_s("%d", &key);

	int index = fiboSearch(a, key, n);

	if (index == -1) printf("���� ã�� �� �����ϴ�.\n");
	else
		printf("%d�� %d��°���� ã�ҽ��ϴ�.\n", key, index);

}