#include <stdio.h>
#include <stdlib.h>

struct NODE //연결 리스트의 노드 구조체
{
	struct NODE* next; //다음 노드의 주소를 저장할 포인터
	int data; 	//데이터를 저장할 공간
};
/*
int main()
{
	struct NODE* head = malloc(sizeof(struct NODE));

	struct NODE* node1 = malloc(sizeof(struct NODE));
	head -> next = node1;
	node1 -> data = 10;

	struct NODE* node2 = malloc(sizeof(struct NODE));
	node1->next = node2;
	node2 -> data = 20;

	node2 -> next = NULL;

	struct NODE* curr = head->next;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	free(node2);
	free(node1);
	free(head);

	return 0;
}
*/