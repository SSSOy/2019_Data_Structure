#include <stdio.h>

int main() {
	int n = 100;
	int *a = (int *)malloc(sizeof(int) * n);
	a[0] = 5; 
	printf("%d\n", a[0]);
	free(a);
	return 0;
}