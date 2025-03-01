#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;
typedef struct DuLNode
{
    int data;
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode,*DuLinkList;

