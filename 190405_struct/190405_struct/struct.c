#include <stdio.h>

void main() {
	struct Student {
		char id[5];
		char name[9];
		int age;
		char tel[14];
	}a;
	
	a.age = 18;
	//a.id = "2202";
	scanf_s("%s", a.id, 5);

	printf("%s\n", a.id);
}
