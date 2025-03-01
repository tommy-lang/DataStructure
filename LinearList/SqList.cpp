#include <iostream>
#include <stdexcept>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

class SqList 
{
private:
    int* elem;
    int length;

public:
    // 构造函数，初始化顺序表
    SqList() : elem(nullptr), length(0) 
    {//有指针变量成员时使用参数列表化构造
        elem = new int[MAXSIZE];  // 动态分配内存
        if (!elem) 
        {
            throw std::bad_alloc();  // 内存分配失败
        }
    }

    // 析构函数，释放内存
    ~SqList() 
    {
        delete[] elem;  // 释放动态分配的内存
    }

    // 获取指定位置的元素
    Status GetElem(int i, int& e) const 
    {
        if (i < 1 || i > length) 
        {  // 越界检查
            return ERROR;
        }
        e = elem[i - 1];
        return OK;
    }

    // 查找元素的位次
    int LocateElem(int e) const 
    {
        for (int i = 0; i < length; ++i) 
        {
            if (elem[i] == e) 
            {
                return i + 1;
            }
        }
        return 0;
    }

    // 插入元素
    Status ListInsert(int i, int e) 
    {
        if (i < 1 || i > length + 1) 
        {  // 插入位置合法性
            return ERROR;
        }
        if (length == MAXSIZE) 
        {  // 超过最大长度
            return ERROR;
        }
        for (int j = length - 1; j >= i - 1; --j) 
        {
            elem[j + 1] = elem[j];
        }
        elem[i - 1] = e;
        ++length;
        return OK;
    }

    // 删除指定位置的元素
    Status ListDelete(int i) 
    {
        if (i < 1 || i > length) 
        {  // 删除位置合法性
            return ERROR;
        }
        for (int j = i; j < length; ++j) 
        {
            elem[j - 1] = elem[j];
        }
        --length;
        return OK;
    }

    // 输出顺序表
    void PrintList() const 
    {
        for (int i = 0; i < length; ++i) 
        {
            cout << elem[i] << " ";
        }
        cout << endl;
    }

    // 获取顺序表的当前长度
    int getLength() const 
    {
        return length;
    }
};

int main() 
{
    try {
        SqList L;  // 初始化顺序表

        // 插入元素
        L.ListInsert(1, 10);
        L.ListInsert(2, 20);
        L.ListInsert(3, 30);

        // 输出顺序表
        L.PrintList();

        // 查找元素位置
        int pos = L.LocateElem(20);
        cout << "Element 20 is at position: " << pos << endl;

        // 获取元素
        int elem;
        L.GetElem(2, elem);
        cout << "Element at position 2 is: " << elem << endl;

        // 删除元素
        L.ListDelete(2);

        // 输出顺序表
        L.PrintList();

    } catch (const std::bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
