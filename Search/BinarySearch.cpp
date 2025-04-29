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

//使用递归的折半查找
int BinarySearchRecursive(SeqTable st, ElemType et, int low, int high)
{
    if(low>high)
        return ERROR;
    int mid=(low+high)/2;
    if(st.elem[mid-1].key==et.key)
    {
        return mid;
    }
    else
    {
        if(st.elem[mid-1].key>et.key)
        {
            return BinarySearchRecursive(st,et,low,mid-1);
        }
        else
        {
            return BinarySearchRecursive(st,et,mid+1,high);
        }
    }
}

int BinarySearch(SeqTable st, ElemType et)
{
    return BinarySearchRecursive(st, et, 1, st.length);
}

//非递归版本的折半查找
int BinarySearchNo(SeqTable st,ElemType et)
{
    int low=1;
    int high=st.length;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(st.elem[mid-1].key==et.key)
        {
            return mid;
        }
        else
        {
            if(st.elem[mid-1].key>et.key)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    }
    return ERROR;
}