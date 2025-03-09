#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

// 归并两个有序链表，结果链表仍使用原来两个链表的存储空间
LinkList MergeSortedLists(LinkList L1, LinkList L2)
{
    if (!L1) return L2; // 若 L1 为空，直接返回 L2
    if (!L2) return L1; // 若 L2 为空，直接返回 L1

    LinkList head = NULL, tail = NULL; // 头指针 & 尾指针

    // 选择头结点
    if (L1->data < L2->data)
    {
        head = tail = L1;
        L1 = L1->next;
    }
    else
    {
        head = tail = L2;
        L2 = L2->next;
    }

    // 归并过程
    while (L1 && L2)
    {
        if (L1->data < L2->data)
        {
            tail->next = L1;
            L1 = L1->next;
        }
        else
        {
            tail->next = L2;
            L2 = L2->next;
        }
        tail = tail->next;
    }

    // 连接剩余部分
    tail->next = L1 ? L1 : L2;

    return head;
}

// 创建链表（头插法）
LinkList CreateList(int arr[], int n)
{
    LinkList head = NULL, newNode;
    for (int i = n - 1; i >= 0; i--)
    {
        newNode = (LNode*)malloc(sizeof(LNode));
        newNode->data = arr[i];
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// 打印链表
void PrintList(LinkList L)
{
    while (L)
    {
        printf("%d -> ", L->data);
        L = L->next;
    }
    printf("NULL\n");
}

// 释放链表
void FreeList(LinkList L)
{
    while (L)
    {
        LinkList temp = L;
        L = L->next;
        free(temp);
    }
}

// 测试函数
int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    LinkList L1 = CreateList(arr1, 4);
    LinkList L2 = CreateList(arr2, 4);

    printf("L1: ");
    PrintList(L1);
    printf("L2: ");
    PrintList(L2);

    LinkList merged = MergeSortedLists(L1, L2);
    printf("Merged: ");
    PrintList(merged);

    FreeList(merged);
    return 0;
}
