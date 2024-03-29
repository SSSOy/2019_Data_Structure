#include <stdio.h>
#define M 20
#define N 30
#define MAX M*N

enum boolean { false, true };

int top = -1;
int stack[MAX][3] = { 0, };

enum boolean push(int r, int c, int d) {
	if (top >= MAX - 1) {
		printf("stack overflow\n");
		return false;
	}
	top = top + 1;
	stack[top][0] = r;
	stack[top][1] = c;
	stack[top][2] = d;
	return true;
}

enum boolean pop(int *r, int *c, int *d) {
	if (top == -1) {
		printf("stack underflow\n");
		return false;
	}
	*r = stack[top][0];
	*c = stack[top][1];
	*d = stack[top][2];
	top = top - 1;
	return true;
}

enum boolean mazeSearch(int maze[M][N]) {
	int current_r, current_c, out_r, out_c;
	int view_r, view_c;
	int d = 0; // d는 이동할 수 있는 0~8 방향 중 하나로 0에서 출발
			   //0방향은 우, 1방향은 우하, 2방향은 하, 3방향은 좌하, 4방향은 좌, 5방향은 좌상, 6방향은 상, 7방향은 우상
	int move[8][2] = { { 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 },{ -1,0 },{ -1,1 } };

	printf("출발 행: "); scanf_s("%d", &current_r);
	printf("출발 열: "); scanf_s("%d", &current_c);
	printf("도착 행: "); scanf_s("%d", &out_r);
	printf("도착 열: "); scanf_s("%d", &out_c);

	while (1) {
		while (d < 8) {
			view_r = current_r + move[d][0];
			view_c = current_c + move[d][1];
			if (view_r >= 0 && view_r < M && view_c >= 0 && view_c < N && maze[view_r][view_c] == 1) {
				maze[current_r][current_c] = 9; // 미로 표시
				if (!push(current_r, current_c, d + 1)) return false;
				current_r = view_r;
				current_c = view_c;
				if (current_r == out_r && current_c == out_c) {
					maze[current_r][current_c] = 9;
					return true;
				}
				d = 0;
			}
			else d++;
		}
		maze[current_r][current_c] = 2; // 돌아온 경로 표시
		if (!pop(&current_r, &current_c, &d)) return false;
	}
}

int main(void) {
	// 0은 벽, 1은 갈 수 있는 통로
	int maze[M][N] = { { 1,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,0 },
	{ 0,0,1,0,1,0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1 },
	{ 0,1,0,0,0,1,1,0,1,1,0,0,0,0,1,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0 },
	{ 1,0,0,1,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0 },
	{ 0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,1,0,1,0,0,1,0,1 },
	{ 0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,0,0,0,1 },
	{ 1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0 },
	{ 1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,0 },
	{ 1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1 },
	{ 0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1 },
	{ 1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,1,1,0,0,1,0,0,1,0,0,0,1,0,1,0 },
	{ 1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,1,0,0,1,0,0,0,1,0,1,0,1 },
	{ 0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,1,0,0,1,0,1,1,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,1,0 },
	{ 1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1 },
	{ 1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,1,0 },
	{ 1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,1 },
	{ 0,1,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,1,0,0,1,0 },
	{ 0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1 },
	{ 1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1 } };
	int i, j;

	if (mazeSearch(maze) == false) printf("출구까지 미로 없음!!\n\n");
	else {
		printf("\n미로 찾기 완료\n");
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++)
				if (maze[i][j] == 9) printf("* "); // 미로이면  * 출력
				else printf("%d ", maze[i][j] == 0 ? 0 : 1); //미로 아니면 초기 데이터 출력
				printf("\n");
		}
	}
	printf("\n");

	return 0;
}