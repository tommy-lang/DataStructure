#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode,*LinkList;
