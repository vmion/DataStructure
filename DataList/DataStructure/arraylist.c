#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(int argc, char* argv[])
{
	int i = 0;
	int arrayCount = 0;
	ArrayList *pList = NULL;
	ArrayListNode* pValue = NULL;

	pList = createArrayList(6);
	if (pList != NULL)
	{
		ArrayListNode node;
		//����Ʈ �ʱ�ȭ 1,3,5 �߰�
		node.data = 1;
		addALElement(pList, 0, node);
	}
}