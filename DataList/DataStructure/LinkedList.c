#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct ListNode
{
	item data;
	struct ListNode* link;
} ListNode;
void insert_node(ListNode** phead, ListNode* new_node)
{
	new_node->link = *phead;
	*phead = new_node;
}
void removeData(ListNode** phead, int value)
{
	ListNode *curr, *prev = NULL;

	curr = *phead;
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->link;
	}
}
ListNode* create_node(item data, ListNode* link)
{
	ListNode* new_node;
	new_node = malloc(sizeof(ListNode));
	if (new_node == NULL)
	{
		fprintf(stderr, "메모리 할당 에러\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}
void insert_first(ListNode** phead, ListNode* node)
{
	if (*phead == NULL)
	{
		*phead = node;
		node->link = node;
	}
	else
	{
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}
void insert_last(ListNode** phead, ListNode* node)
{
	if (*phead == NULL)
	{
		*phead = node;
		node->link = node;
	}
	else
	{
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}
void display(ListNode* head)
{
	ListNode* p;
	if (head == NULL) return;
	else head = head->link;

	printf("( ");
	p = head;
	do
	{
		printf("%d", p->data);
		p = p->link;
		if (p != head) printf(", ");
	} while (p != head);
	printf(") \n");
}
int main()
{
	ListNode* list = NULL;

	insert_first(&list, create_node(10, NULL));
	display(list);

	insert_first(&list, create_node(20, NULL));
	display(list);

	insert_first(&list, create_node(30, NULL));
	display(list);

	return 1;
}