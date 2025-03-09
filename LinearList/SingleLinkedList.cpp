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

Status InitList(LinkList& L)//等价于LNode** L
{
    L=new LNode;//allocate memory.
    L->next= nullptr;
    return OK;
}

Status ListInsert(LinkList& L,int i,int e)
{
    LNode* p=L;//头指针L的值赋值给p,则p现在指向第一个结点
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
    while(p&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||(j>i-1))//插入位置非法
        return ERROR;
    LNode* q=p->next;
    p->next=q->next;
    delete q;
    return OK;
}

Status GetElem(const LinkList& L,int i,int& e)//取值函数:获取第i个结点的数据域的值，然后把这个值赋值给e
{
    LNode* p=L->next;//现在把p指向首元节点.
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;
    e=p->data;
    return OK;
}

LNode* LocateElem(const LinkList& L,int e)
{
    LNode* p=L->next;
    while(p&&p->data!=e)
        p=p->next;
    return p;
}

void DeleteNodeByValue(LinkList& L, int v)
{
    LNode* p = L;
    while (p != nullptr && p->next != nullptr)
    {
        if (p->next->data == v)
        {
            LNode* q = p->next;
            p->next = q->next;
            delete q;
        }
        else
        {
            p = p->next;  // 只有在没有删除节点时，才移动到下一个节点
        }
    }
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


