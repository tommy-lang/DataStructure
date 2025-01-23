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
Status InitList(LinkList& L)//传进去的是一个指向LNode型变量的指针
{
    L=new LNode;//动态分配内存生成一个头指针，该指针指向头结点，L:LNode* L,头指针无数据域，它是一个LNode型指针
    L->next=nullptr;//头结点指针域置空，等价于（*L）.next
    return OK;
}
Status GetElem(LinkList L,int i,int& e)//输入位置，获取该位置的元素
{
    LNode* p = L->next;//p指向首元结点
    int j=1;//计数器
    while(p&&j<i)//从首元节点开始
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;
    e=p->data;
    return OK;
}
LNode* LocateElem(LinkList L,int e)
{
    LNode* p=L->next;//指向首元节点
    while(p&&p->data!=e)
        p=p->next;
    return p;
}
Status ListInsert(LinkList& L,int i,int e)//插入元素
{
    LNode* p=L;//头结点
    int j=0;
    while(p&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
        return ERROR;
    LNode* s=new LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}
Status ListDelete(LinkList& L,int i)
{
    LNode* p=L;
    int j=0;
    while((p->next)&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||(j>i-1))
        return ERROR;
    LNode* q=p->next;
    p->next=q->next;
    delete q;
    return OK;
}
int main()
{
    LinkList L;

    // Initialize the list
    if (InitList(L) == OK)
    {
        std::cout << "List initialized successfully.\n";
    }
    else
    {
        std::cout << "List initialization failed.\n";
    }

    // Insert elements into the list
    if (ListInsert(L, 1, 10) == OK)
    {
        std::cout << "Inserted 10 at position 1.\n";
    }
    else
    {
        std::cout << "Insertion failed.\n";
    }
    if (ListInsert(L, 2, 20) == OK)
    {
        std::cout << "Inserted 20 at position 2.\n";
    }
    else
    {
        std::cout << "Insertion failed.\n";
    }
    if (ListInsert(L, 3, 30) == OK)
    {
        std::cout << "Inserted 30 at position 3.\n";
    }
    else
    {
        std::cout << "Insertion failed.\n";
    }

    // Get element at position 2
    int e;
    if (GetElem(L, 2, e) == OK)
    {
        std::cout << "Element at position 2: " << e << "\n";
    }
    else
    {
        std::cout << "Failed to get element at position 2.\n";
    }

    // Locate element with value 20
    LNode* node = LocateElem(L, 20);
    if (node)
    {
        std::cout << "Element 20 found in the list.\n";
    }
    else
    {
        std::cout << "Element 20 not found in the list.\n";
    }

    // Delete element at position 2
    if (ListDelete(L, 2) == OK)
    {
        std::cout << "Deleted element at position 2.\n";
    }
    else
    {
        std::cout << "Failed to delete element at position 2.\n";
    }

    // Try to get the element again at position 2
    if (GetElem(L, 2, e) == OK)
    {
        std::cout << "Element at position 2: " << e << "\n";
    }
    else
    {
        std::cout << "Failed to get element at position 2.\n";
    }
    return 0;
}