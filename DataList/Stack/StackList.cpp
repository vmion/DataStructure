#include <iostream>
#include "stack.h"
using namespace std;

StackList::StackList()
{
	pHead = new Node;
	pTail = new Node;
	pHead->pNext = pTail;
	pHead->pPrev = pHead;
	pTail->pNext = pTail;
	pTail->pPrev = pHead;
}
StackList::~StackList()
{
	delete pHead;
	delete pTail;
}
void StackList::PushFront(item _data)
{
    Node* pNewNode = new Node;
    pNewNode->data = _data;
    //추가하려는 데이터노드의 우측의 연결관계를 먼저 정리
    //그래야만 head를 사용해서 연결관계를 정리 할 수 있다.
    pHead->pNext->pPrev = pNewNode;
    pNewNode->pNext = pHead->pNext;
    pNewNode->pPrev = pHead;
}

void StackList::PushData(item pszData)
{
    PushFront(pszData);
}

int StackList::PopData(Node* pPopNode)
{
    Node* sp = pHead->pNext;
    if (IsEmpty())
        return 0;

    memcpy(pPopNode, sp, sizeof(Node));
    free(sp);
    return 1;
}

int StackList::IsEmpty()
{
    if (pHead->pNext == NULL)
        return 1;

    return 0;
}