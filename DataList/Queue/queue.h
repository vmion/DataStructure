#pragma once
typedef int item;
struct Node
{
    int data;
    Node* pPrev;
    Node* pNext;
};

class QueueList
{
public:
    Node* pHead;
    Node* pTail;
public:
    QueueList();
    ~QueueList();

    void PushData(item pszData);
    int IsEmpty();
    int PopData(Node* pPopNode);
    void PushFront(item data);
    void Enqueue(item pszData);
    int Dequeue(Node* node);
    void PushBack(item data);
};