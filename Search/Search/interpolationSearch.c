#include <stdio.h>

int interpolation(int a[], int n, int key) {
	int left = 0, right = n - 1, index;
	while (left <= right) {
		if (a[left] == a[right]) index = left;
		else {
			index = left + (right - left) * (key - a[left]) / (a[right] - a[left]);
			if (index < left) index = left;
			if (index > right) index = right;
		}
		if(key == a[index]) return index;
		else if (key > a[index]) left = index + 1;
		else right = index - 1;
	}
	return -1;
}

void main() {
	int a[] = { 10, 22, 43, 44, 56, 58, 66, 76, 92, 111, 344, 627, 833, 972 };
	int n = sizeof(a) / sizeof(int);
	int index, key;
	printf("찾을 값 : ");
	scanf_s("%d", &key);

	index = interpolation(a, n, key);
	if (index > -1)
		printf("a[%d] : %d\n", n, key);
	else
		printf("값을 찾을 수 없습니다.\n");
}