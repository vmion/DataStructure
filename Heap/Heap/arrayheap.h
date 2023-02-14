#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

typedef struct HeapElementType
{
	int key;
	char data;
} HeapNode;

typedef struct ArrayHeapType
{
	int maxElementCount; //�ִ� ��� ����
	int currentElementCount; //���� ��� ����
	HeapNode* pElement; //��� ������ ���� 1���� array
} ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);
void deleteArrayMaxHeap(ArrayMaxHeap* pArrayHeap);
void insertMaxHeapAH(ArrayMaxHeap* pArrayHeap, HeapNode element);
HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pArrayHeap);

#endif // !_ARRAY_HEAP_

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE	1
#define FALSE	0

#endif // ! _COMMON_TREE_DEF_
