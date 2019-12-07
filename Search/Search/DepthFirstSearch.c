#include <stdio.h>
#define SIZE 8

typedef enum{false, true} bool;
int top = -1;
int stack[SIZE];

bool push(int index) {
	if (top == SIZE ) return false;
	stack[++top] = index;
	return true;
}
int pop() {
	if (top == -1) return -1;
	return stack[top--];
}

void DFS(bool G[][SIZE], char V[]) {
	bool chk[SIZE] = { false };
	int i, j, startV;
	printf("출발 정점 : ");
	scanf_s("%c", &startV, 1);
	for (i = 0; i < SIZE; i++)
		if (startV == V[i]) break;
	printf("%c", startV);
	chk[i] = true;

	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && chk[j] == 0) {
				printf(" -> %c", V[j]);
				chk[j] = 1;
				push(i);
				i = j; 
				break;
			}
		}
		if (j == SIZE) i = pop();
	} while (i >= 0);
}

int main() {
	bool G[SIZE][SIZE] = {
		{0, 1, 0,1,0,0,0,0},
	{1,0,0,0,1,0,1,0},
	{0,0,0,0,1,1,0,0},
	{1,0,0,0,0,1,0,0},
	{0,1,1,0,0,0,1,0},
	{0,0,1,1,0,0,0,1},
	{0,1,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0} };

	char V[] = { 'A', 'B','C','D','E','F','G','H' };
	DFS(G, V);
	return 0;
}