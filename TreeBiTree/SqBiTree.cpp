#include<iostream>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

class SqBiTree
{
public:
    int elem[MAXSIZE];
    int n;
    SqBiTree();
    ~SqBiTree();
    void CreateBiTree(int m);
    int LeftChild(int i);
    int RightChild(int i);
    int Parent(int i);
};


