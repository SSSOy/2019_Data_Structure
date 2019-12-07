#include <stdio.h>

void main() {
	int a[5] = { 1000, 3667, 1500, 3000, 2975 };
	for (int i = 0; i < 5; i++) {
		if (a[i] != 1500 && a[i] != 3000 && a[i] != 5000) {
			printf("%d\n", a[i]);
		}
	}
}