#include <stdio.h>
#define SIZE 8

enum boolean { false, true };
int cqueue[SIZE];
int front = 0, rear = -1;
int cnt = 0;

enum boolean add(int data) {
	if (cnt == SIZE) {
		printf("Queue is full!\n");
		return false;
	}
	cqueue[++rear % SIZE] = data;
	cnt++;
	return true;
}

int delete() {
	if (cnt == 0) {
		printf("Queue is empty!\n");
		return -1;
	}
	cnt--;
	return cqueue[front++ % SIZE];
}

void main() {
	for (int i = 1; i <= SIZE + 1; i++)
		add(5 * i);
	for (int i = 1; i <= SIZE + 1; i++)
		printf("%d\n", delete());
	add(55);
	add(60);
	add(65);
	for (int i = 0; i < 3; i++)
		printf("%d\n", delete());
}