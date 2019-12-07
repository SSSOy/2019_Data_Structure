#include <stdio.h>
#define SIZE 6

int stack[SIZE];
int top = -1;

int push(int data) {
	if (top > SIZE ) {
		printf("Stack is full!\n");
		return -1;
	}
	stack[++top] = data;
	return 0;
}

int pop() {
	if (top <= -1) {
		printf("Stack is empty!\n");
		return -1;
	}
	return stack[top--];
}
void main() {
	push(5);
	push(10);
	push(15);
	push(20);
	

	for(int i = 0; i < 6; i ++)
		printf("%d\n", pop());
}
