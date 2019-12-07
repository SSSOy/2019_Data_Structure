#include <stdio.h>

void main() {
	struct node {
		char data;
		struct node *link;
	};

	struct node *p = (struct node *)malloc(sizeof(struct  node));
	struct node *del;

	p->data = 'A';
	p->link = (struct node *)malloc(sizeof(struct  node));
	p->link->data = 'B';
	p->link->link = (struct node *)malloc(sizeof(struct  node));
	p->link->link->data = 'C';
	p->link->link->link = NULL;

	del = p;

	while (p != NULL) {
		printf("%c\n", p->data);
		p = p->link;
		free(del);
		del = p;
	}
}