#include <stdio.h>
#define R 3

int  b[R];
int cnt = 0;

void Com() {
	for (int i = 0; i < R; i++)
		printf("%5d", b[i]);
	puts("");
	cnt++;
}
void Combination(int a[], int r, int n, int ii) {
	int i;
	if (r == R) Com();
	else
		for (i = ii + 1; i < n; i++) {
			b[r] = a[i];
			Combination(a, r + 1, n, i);
		}
}
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	Combination(a, 0, n, -1);
	printf("\ncnt : %d\n", cnt);
	return 0;
}