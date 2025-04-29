#include <stdio.h>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
#define MAXSIZE 100

typedef int Status;

// linear search based on sequential list
typedef struct ElemType
{
    int key;
} ElemType;

typedef struct
{
    ElemType elem[MAXSIZE];
    int length;
} SeqTable;

int SeqSearch(SeqTable s, int k)
{
    int i;
    for (i = 0; i < s.length; i++)
    {
        if (s.elem[i].key == k)
            return i; // 返回找到的元素下标
    }
    return -1; // 找不到返回-1
}

int SeqSearch_gai(SeqTable s, int k)
{
    int n, i = 0;
    n = s.length;

    // 设置监视哨
    s.elem[n].key = k;

    // 顺序查找
    while (s.elem[i].key != k)
        i++;

    // 判断是否找到真正的元素
    if (i == n)
        return -1; // 如果最后是哨兵，说明没有找到
    else
        return i; // 返回找到的位置
}

int main()
{
    SeqTable s;
    s.length = 5;
    s.elem[0].key = 10;
    s.elem[1].key = 20;
    s.elem[2].key = 30;
    s.elem[3].key = 40;
    s.elem[4].key = 50;

    int key = 30;
    int pos = SeqSearch(s, key);
    if (pos != -1)
        printf("Element %d found at index %d\n", key, pos);
    else
        printf("Element %d not found\n", key);

    key = 60;
    pos = SeqSearch_gai(s, key);
    if (pos != -1)
        printf("Element %d found at index %d\n", key, pos);
    else
        printf("Element %d not found\n", key);

    return 0;
}
