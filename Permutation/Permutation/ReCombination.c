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
void ReCombination(int a[], int r, int n, int ii) {
	int i;
	if (r == R) Com();
	else
		for (i = ii; i < n; i++) {
			b[r] = a[i];
			ReCombination(a, r + 1, n, i);
		}
}
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	ReCombination(a, 0, n, 0);
	printf("\ncnt : %d\n", cnt);
	return 0;
}