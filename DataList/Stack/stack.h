#pragma once
typedef int item;
struct Node
{
    int data;
    Node* pPrev;
    Node* pNext;
};

class StackList
{
public:
    Node* pHead;
    Node* pTail;
public:
    StackList();
    ~StackList();

    void PushData(item pszData);
    int IsEmpty();
    int PopData(Node* pPopNode);
    void PushFront(item data);
};