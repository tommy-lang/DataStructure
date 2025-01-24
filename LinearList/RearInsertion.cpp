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
void CreateList_R(LinkList& L,int n)
{
    L=new LNode;
    L->next=NULL;
    LNode* r=L;
    for(int i=0;i<n;i++)
    {
        LNode* p=new LNode;
        std::cin>>p->data;
        p->next=NULL;
        r->next=p;
    }
}
