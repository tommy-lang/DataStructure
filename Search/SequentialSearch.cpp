#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
#define MAXSIZE 100

typedef int Status;

// linear search based on sequential list
typedef struct ElemType
{
    int key;
}ElemType;

typedef struct
{
    ElemType elem[MAXSIZE];
    int length;
}SeqTable;

int SeqSearch(SeqTable s,int k)
{
    int i;
    for(int i=0;i<s.length;i++)
    {
        if(s.elem[i].key==k)
            return i;
    }
    return -1;
}

//设置监视哨的顺序查找
int SeqSearch_gai(SeqTable s,int k)
{
    int n,i=0;
    n=s.length;
    s.elem[n].key=k;
    while(s.elem[i].key!=k)
        i++;
    if(i==n)
        return -1;
    else
        return i;
}