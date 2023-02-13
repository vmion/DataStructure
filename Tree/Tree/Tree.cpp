﻿// Tree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int number = 15;
//하나의 노드 정보 선언
typedef struct node* treePointer;
typedef struct node
{
    int data;
    treePointer leftChild, rightChild;
} node;

//전위 순회
void preorder(treePointer ptr)
{
    if (ptr)
    {
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);        
    }   
}
//중위 순회
void inorder(treePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';        
        inorder(ptr->rightChild);        
    }    
}
//후위 순회
void postorder(treePointer ptr)
{
    if (ptr)
    {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';        
    }    
}
int main()
{
    node* nodes = new node[number + 1];    
    for (int i = 1; i <= number; i++)
    {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    for (int i = 1; i <= number; i++)
    {
        if (i % 2 == 0)
        {
            nodes[i / 2].leftChild = &nodes[i];
        }
        else
        {
            nodes[i / 2].rightChild = &nodes[i];
        }
    }
    cout << "전위 순회" << endl;
    preorder(&nodes[1]);
    cout << " " << endl;
    cout << "중위 순회" << endl;
    inorder(&nodes[1]);
    cout << " " << endl;
    cout << "후위 순회" << endl;
    postorder(&nodes[1]);
    cout << " " << endl;

    return 0;
}