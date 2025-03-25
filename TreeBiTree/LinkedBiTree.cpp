#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct BiTNode
{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;

Status InitBiTree(BiTree& T)
{
    T = nullptr;  // 置为空树
    return OK;
}

Status InsertBiTree(BiTree& T, int key)
{
    if (T == nullptr)
    {
        // 创建新节点
        T = new BiTNode;
        if (T == nullptr)
            return OVERFLOW; // 内存分配失败
        T->data = key;
        T->lchild = T->rchild = nullptr;
        return OK;
    }

    if (key < T->data)
    {
        return InsertBiTree(T->lchild, key);
    }
    else if (key > T->data)
    {
        return InsertBiTree(T->rchild, key);
    }
    else
    {
        return ERROR; // 已存在该值，插入失败
    }
}

void InOrderTraverse(const BiTree& T)//中序遍历
{
    if(T!=nullptr)
    {
        InOrderTraverse(T->lchild);
        std::cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}

void PreOrderTraverse(const BiTree& T)//先序遍历
{

}

void PostOrderTraverse(const BiTree& T)//后序遍历
{

}