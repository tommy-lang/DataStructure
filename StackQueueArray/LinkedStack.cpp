#include <iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;

//链栈的top指针指向栈顶结点，以单链表的表头作为栈顶
typedef struct StackNode
{
    int data;
    struct StackNode* next;
}StackNode,*LinkedStack;

Status InitStack(LinkedStack& S)
{
    S=nullptr;
    return OK;
}

Status Push(LinkedStack& S,int e)//头部插入
{
     StackNode* p=new StackNode;
     p->data=e;
     p->next=S;
     S=p;
     return OK;
}

Status Pop(LinkedStack& S,int& e)//头部删除
{
    if(S==nullptr)
        return ERROR;
    e=S->data;
    StackNode* p=S;
    S=S->next;
    delete p;
    return OK;
}

int GetTop(const LinkedStack& S)
{
    if(S==nullptr)
        return ERROR;
    return S->data;
}

void PrintStack(const LinkedStack& S)
{
    if(S==nullptr)
        std::cout<<"no elements in Stack."<<std::endl;
    StackNode* p=S;
    while(p!=nullptr)
    {
        std::cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    LinkedStack S;
    InitStack(S);
    Push(S,4);
    Push(S,3);
    Push(S,2);
    Push(S,1);
    PrintStack(S);
    std::cout<<std::endl;
    return 0;
}