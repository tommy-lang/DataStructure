#include <stdio.h>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
#define MAXSIZE 100

typedef int Status;

// 定义元素类型
typedef struct ElemType {
    int key;
} ElemType;

// 顺序表定义
typedef struct {
    ElemType elem[MAXSIZE];
    int length;
} SeqTable;

int BinarySearch(SeqTable st, ElemType et)
{
    int low = 1;
    int high = st.length;
    int mid = (low + high) / 2;

    while (st.elem[mid - 1].key != et.key)
    {
        if (low > high)
        {
            return 0; // 查找失败，返回 0
        }

        if (st.elem[mid - 1].key > et.key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        mid = (low + high) / 2; // 更新 mid
    }

    return mid; // 查找成功，返回位置
}