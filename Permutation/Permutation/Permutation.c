#include <stdio.h>
#define R 3

int  b[R];

void RePer() {
	for (int i = 0; i < R; i++)
		printf("%5d", b[i]);
	puts("");
}
void Swap(int *p1, int *p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void Permutation(int a[], int r, int n) {
	int i;
	if (r == R) RePer();
	else
		for (i = r; i < n; i++) {
			Swap(&a[r], &a[i]);
			b[r] = a[r];
			Permutation(a, r + 1, n);
			Swap(a + r, a + i);
		}
}
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	Permutation(a, 0, n);
	return 0;
}