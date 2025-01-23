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
void CreateList_H(LinkList& L,int n)
{
    L=new LNode;//,L是头指针，创建一个头结点
    L->next=NULL;//下一个置空,表明目前没有任何数据节点
    for(int i=0;i<n;i++)
    {
        LNode* p=new LNode;//创建一个新节点
        std::cin>>(*p).data;//输入新节点的数据域的数据
        (*p).next=(*L).next;//对于第一个结点，新节点的下一个结点置空，头结点->null,头结点->p->null
        (*L).next=p;//更新头结点的指针域
    }
}