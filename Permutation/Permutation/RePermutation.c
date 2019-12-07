#include <stdio.h>
#define R 3

int  b[R];
int cnt = 0;

void RePer() {
	for (int i = 0; i < R; i++)
		printf("%5d", b[i]);
	puts("");
	cnt++;
}
void RePermutation(int a[], int r, int n) {
	int i;
	if (r == R) RePer();
	else 
		for (i = 0; i < n; i++) {
			b[r] = a[i];
			RePermutation(a, r + 1, n);
		}
}
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	RePermutation(a, 0, n);
	printf("\ncnt : %d\n", cnt);
	return 0;
}