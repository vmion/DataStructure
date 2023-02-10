// Queue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "queue.h"
using namespace std;

QueueList::QueueList()
{
    pHead = new Node;
    pTail = new Node;
    pHead->pNext = pTail;
    pHead->pPrev = pHead;
    pTail->pNext = pTail;
    pTail->pPrev = pHead;
}
QueueList::~QueueList()
{
    delete pHead;
    delete pTail;
}
void QueueList::Enqueue(item pszData)
{
    return PushBack(pszData);
}

//제거
int QueueList::Dequeue(Node* node)
{
    return PopData(node);
}

//무조건 꼬리부분에 생성
void QueueList::PushBack(item _data)
{
    Node* pNewNode = new Node;
    pNewNode->data = _data;
    pNewNode->pPrev->pNext = pNewNode;
    pNewNode->pPrev = pTail->pPrev;
    pNewNode->pPrev = pTail;
    pTail->pPrev = pNewNode;
}

int main()
{
    
}