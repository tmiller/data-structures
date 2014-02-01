#include <stdio.h>

#define MAX 5

struct node {
	int value;
	struct node *next;
};

int main()
{
	int a = MAX;
	struct node *a, *b;
	a->value = 1;
	a->next = b;

	printf("A: %d B: %d", 5, 3)

	free(a);
	return 0;
}

