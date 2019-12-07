#include <stdio.h>

void main() {
	int a[10000] = { 0 };
	a[0] = 5;
	printf("%d\n", a[0]);
}