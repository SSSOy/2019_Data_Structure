#include <stdio.h>
#define SIZE 8

enum boolean{false, true};
int queue[SIZE];
int front = 0, rear = -1;

enum boolean add(int data) {
	if (rear == SIZE - 1) {
		printf("Queue is full!\n");
		return false;
	}
	queue[++rear] = data;
	return true;
}

int delete() {
	if (front > rear) {
		printf("Queue is empty!\n");
		return -1;
	}
	return queue[front++];
}

void main() {
	for (int i = 1; i <= SIZE + 1; i++)
		add(5 * i);
	for (int i = 1; i <= SIZE + 1; i++)
		printf("%d\n", delete());
}