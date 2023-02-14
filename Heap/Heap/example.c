#include "arrayheap.h"
#include <cstddef>

int main(int argc, char* argv[])
{
	int maxHeapSize = 20;

	ArrayMaxHeap* pHeap1 = NULL;

	HeapNode* pNode = NULL;
	HeapNode e1 = { 10 };
	HeapNode e2 = { 40 };
	HeapNode e3 = { 30 };
	HeapNode e4 = { 20 };
	HeapNode e5 = { 50 };

	pHeap1 = createArrayMaxHeap(maxHeapSize);
	if (pHeap1 != NULL)
	{
		insertMaxHeapAH(pHeap1, e1);
		insertMaxHeapAH(pHeap1, e2);
		insertMaxHeapAH(pHeap1, e3);
		insertMaxHeapAH(pHeap1, e4);
		insertMaxHeapAH(pHeap1, e5);

		printf("Max Heap:\n");
		displayArrayHeap(pHeap1);

		pNode = deleteMaxHeapAH(pHeap1);
		if (pNode != NULL)
		{
			printf("deleteMaxHeapAH()-[%d]\n", pNode->key);
			free(pNode);
		}

		printf("Max Heap:\n");
		displayArrayHeap(pHeap1);

		deleteArrayMaxHeap(pHeap1);
	}
	return 0;
}