#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct SqList
{
    int* elem;
    int length;
}SqList;

Status InitList(SqList* L)
{
    L->elem=(int*)malloc(MAXSIZE*sizeof(int));
    if(!L->elem)
    {
        printf("Memory Allocation Failed.\n");
        exit(OVERFLOW);
    }
    return OK;
}

int GetValue(int i,SqList*L)
{
    if(i<1||i>L->length)
        return ERROR;
    return L->elem[i-1];
}

int SearchValue(int v,SqList*L)
{
    int index;
    for(int i=0;i<L->length;i++)
    {
        if(L->elem[i]==v)
        {
            index = i + 1;
            return index;
        }
    }
    return ERROR;
}

int InsertValue(int v,int i,SqList*L)
{
    if(i<1||i>L->length+1)
        return ERROR;
    if(L->length==MAXSIZE)
        return ERROR;
    for(int j=L->length-1;j>=i-1;j--)
    {
        L->elem[j+1]=L->elem[j];
    }
    L->elem[i-1]=v;
    ++L->length;
    return OK;
}

int DeleteValue(int i,SqList* L)
{
    if(i<1||i>L->length)
        return ERROR;
    for(int j=i-1;j<L->length-1;j++)
    {
        L->elem[j]=L->elem[j+1];
    }
    --L->length;
    return OK;
}

int main()
{
    SqList L;
    InitList(&L);
    InsertValue(33,1,&L);
    InsertValue(34,2,&L);
    InsertValue(35,3,&L);
    InsertValue(36,4,&L);
    InsertValue(37,5,&L);
    DeleteValue(5,&L);
    for(int i=0;i<L.length;i++)
    {
        printf_s("%d ",L.elem[i]);
    }
    free(L.elem);
    return 0;
}