#include "arrayheap.h"
#include <cstddef>

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount)
{
	ArrayMaxHeap *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0)
	{
		pReturn = (ArrayMaxHeap*)malloc(sizeof(ArrayMaxHeap));
		if (pReturn != NULL)
		{
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = (HeapNode*)malloc(sizeof(HeapNode) * (maxElementCount + 1));
			if (pReturn->pElement == NULL)
			{
				printf("����, 2��° �޸� �Ҵ�, createArrayList()\n");
				free(pReturn);
				return NULL;
			}
			memset(pReturn->pElement, 0, sizeof(HeapNode) * (maxElementCount + 1));
		}
		else
		{
			printf("����, �޸� �Ҵ�, createArrayList()\n");
		}
	}
	else
	{
		printf("�ִ� ���� ������ 0���� Ŀ�� �մϴ�.\n");
	}
	return pReturn;
}

void deleteArrayMaxHeap(ArrayMaxHeap* pHeap)
{
	if (pHeap != NULL)
	{
		if (pHeap->pElement != NULL)
		{
			free(pHeap->pElement);
		}
		free(pHeap);
	}
}

void insertMaxHeapAH(ArrayMaxHeap* pHeap, HeapNode element)
{
	int i = 0;
	if (pHeap != NULL)
	{
		if (pHeap->currentElementCount == pHeap->maxElementCount)
		{
			printf("����, ������ ���� á���ϴ�[%d], insertMaxHeapAH()\n",
				pHeap->maxElementCount);
			return;
		}
		pHeap->currentElementCount++;
		i = pHeap->currentElementCount;
		while ((i != 1) && (element.key > pHeap->pElement[i / 2].key))
		{
			pHeap->pElement[i] = pHeap->pElement[i / 2];
			i /= 2;
		}
		pHeap->pElement[i] = element;
	}
}

HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pHeap)
{
	HeapNode* pReturn = NULL;
	HeapNode* pTemp = NULL;

	int i = 0;
	int parent = 0, child = 0;

	if (pHeap != NULL && pHeap->currentElementCount > 0)
	{
		pReturn = (HeapNode*)malloc(sizeof(HeapNode));
		if (pReturn == NULL)
		{
			printf("����, �޸� �Ҵ�, deleteMaxHeapAH()\n");
			return NULL;
		}
		*pReturn = pHeap->pElement[1];

		i = pHeap->currentElementCount;
		pTemp = &(pHeap->pElement[i]);
		pHeap->currentElementCount--;

		parent = 1;
		child = 2;
		while (child <= pHeap->currentElementCount)
		{
			if ((child < pHeap->currentElementCount)
				&& pHeap->pElement[child].key < pHeap->pElement[child + 1].key)
			{
				child++;
			}
			if (pTemp->key >= pHeap->pElement[child].key)
			{
				break;
			}
			//end - of - while			
		}
		pHeap->pElement[parent] = *pTemp;
	}
	return pReturn;
}