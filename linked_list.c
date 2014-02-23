#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

#define NODE_SIZE sizeof(struct node)

void apply(struct node *head, void (*fn)(struct node *));
struct node *create_list(int num);
void print(struct node *item);
void free_list(struct node *item);

int main()
{
	struct node *list = create_list(1024);

	apply(list, &print);

	free_list(list);
	return 0;
}

void apply(struct node *head, void (*fn)(struct node *))
{
	struct node *item = head;
	while(item) {
		fn(item);
		item = item->next;
	}
}

struct node *create_list(int num)
{
	if(num > 0) {
		int i;
		struct node *head, *curr, *next;
		head = calloc(1, NODE_SIZE);
		head->value = 0;
		curr = head;
		for(i = 0; i < num; i++) {
			next = calloc(1, NODE_SIZE);
			next->value = i;
			curr->next = next;
			curr = next;
		}
		return head;
	} else {
		return NULL;
	}
}

void print(struct node *item)
{
	printf("%d\n", item->value);
	if(item->next == NULL)
		printf("No more nodes.\n");
}

void free_list(struct node *head)
{
	struct node *tmp;

	while(head) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
