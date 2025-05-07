#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef struct
{
    int key;
}ElemType;

typedef struct BSTNode
{
    ElemType data;
    struct BSTNode* lchild,*rchild;
}BSTNode,*BSTree;

BSTree SearchBST(BSTree T, int key)
{
    if (!T || key == T->data.key)
    {
        return T;
    }

    if (key < T->data.key)
    {
        return SearchBST(T->lchild, key);
    }
    return SearchBST(T->rchild, key);
}

