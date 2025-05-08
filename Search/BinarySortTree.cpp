#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
#define ENDFLAG 10

typedef struct
{
    int key;//关键字项
}ElemType;//每个结点的数据域的类型

typedef struct BSTNode
{
    ElemType data;
    struct BSTNode* lchild,*rchild;//左右孩子指针
}BSTNode,*BSTree;

//二叉排序树的查找
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

//二叉排序树的插入
void InsertBST(BSTree& T,ElemType e)
{
    if (!T)//equals to T==nullptr
    {
        BSTNode* S=new BSTNode;
        S->data=e;
        S->lchild=S->rchild=nullptr;
        T=S;
    }//若二叉排序树为空，则将待插入结点*S作为根结点插入空树
    else//若二叉排序树非空，则将key与根结点的关键字T->data.key进行比较
    {
        if (e.key<T->data.key)
        {
            InsertBST(T->lchild,e);
        }
        else
        {
            if (e.key>T->data.key)
            {
                InsertBST(T->rchild,e);
            }
        }
    }
}

//重载>>运算符
std::istream& operator>>(std::istream& in,ElemType& e)
{
    in>>e.key;
    return in;
}

//二叉排序树的创建
void CreateBST(BSTree& T)
{
    T=nullptr;
    ElemType e;
    std::cin>>e;
    while (e.key!=ENDFLAG)
    {
        InsertBST(T,e);
        std::cin>>e;
    }
}

int main()
{
    BSTree T;
    std::cout << "put a few integer numbers to create BST " << ENDFLAG << " end:" << std::endl;
    CreateBST(T); // 创建 BST

    std::cout << "input key word to search:" << std::endl;
    int searchKey;
    std::cin >> searchKey;

    BSTree result = SearchBST(T, searchKey);
    if (result)
    {
        std::cout << "search successes,key is:" << result->data.key << std::endl;
    }
    else
    {
        std::cout << "search failed ,not exists." << std::endl;
    }

    return 0;
}
