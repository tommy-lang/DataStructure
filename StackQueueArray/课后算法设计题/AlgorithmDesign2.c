#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

#define MAXSIZE 100

typedef struct {
    char* base;
    char* top;
    int StackSize;
    int CurrentSize;
} SqStack;

// 初始化栈
void InitStack(SqStack* S)
{
    S->base = (char*)malloc(MAXSIZE * sizeof(char));
    S->top = S->base;
    S->StackSize = MAXSIZE;
    S->CurrentSize = 0;
}

// 压栈操作
bool Push(SqStack* S, char c)
{
    if (S->top - S->base == S->StackSize)
        return false;  // 栈满
    *(S->top) = c;
    S->top++;
    S->CurrentSize++;
    return true;
}

// 弹栈操作
bool Pop(SqStack* S, char* c)
{
    if (S->top == S->base)
        return false;  // 栈空
    S->top--;
    *c = *(S->top);
    S->CurrentSize--;
    return true;
}

// 判断字符串是否为回文
bool isPalindrome(const char* str)
{
    SqStack S;
    InitStack(&S);

    // 1. 将字符串压入栈
    for (int i = 0; str[i] != '\0'; i++)
    {
        Push(&S, str[i]);
    }

    // 2. 从栈中弹出字符并组成新字符串
    char reversedStr[MAXSIZE];
    int i = 0;
    char stackChar;
    while (Pop(&S, &stackChar))
    {
        reversedStr[i] = stackChar;
        i++;
    }
    reversedStr[i] = '\0';  // 确保字符串结束

    // 3. 比较原字符串和新字符串
    return strcmp(str, reversedStr) == 0;
}

int main()
{
    const char* str = "madam";
    if (isPalindrome(str))
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}

