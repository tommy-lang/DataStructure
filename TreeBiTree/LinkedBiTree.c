#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
} BiTNode, *BiTree;

Status InitBiTree(BiTree* T) {
    *T = NULL;  // 置为空树
    return OK;
}

Status InsertBiTree(BiTree* T, int key) {
    if (*T == NULL) {
        // 创建新节点
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        if (*T == NULL)
            return OVERFLOW; // 内存分配失败
        (*T)->data = key;
        (*T)->lchild = (*T)->rchild = NULL;
        return OK;
    }

    if (key < (*T)->data) {
        return InsertBiTree(&((*T)->lchild), key);
    } else if (key > (*T)->data) {
        return InsertBiTree(&((*T)->rchild), key);
    } else {
        return ERROR; // 已存在该值，插入失败
    }
}

void InOrderTraverse(const BiTree T) { // 中序遍历
    if (T != NULL) {
        InOrderTraverse(T->lchild);
        printf("%d ", T->data);
        InOrderTraverse(T->rchild);
    }
}

void PreOrderTraverse(const BiTree T) { // 先序遍历
    if (T != NULL) {
        printf("%d ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(const BiTree T) { // 后序遍历
    if (T != NULL) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d ", T->data);
    }
}

int main() {
    BiTree T;
    InitBiTree(&T);

    int keys[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        InsertBiTree(&T, keys[i]);
    }

    printf("InOrder: ");
    InOrderTraverse(T);
    printf("\n");

    printf("PreOrder: ");
    PreOrderTraverse(T);
    printf("\n");

    printf("PostOrder: ");
    PostOrderTraverse(T);
    printf("\n");

    return 0;
}