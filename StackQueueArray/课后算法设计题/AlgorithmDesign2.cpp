#include <iostream>
#include <string>

#define MAXSIZE 100

typedef struct
{
    char* base;
    char* top;
    int StackSize;
    int CurrentSize;
} SqStack;

// 初始化栈
void InitStack(SqStack& S)
{
    S.base = new char[MAXSIZE];
    S.top = S.base;
    S.StackSize = MAXSIZE;
    S.CurrentSize=0;
}

// 压栈操作
bool Push(SqStack& S, char c)
{
    if (S.top - S.base == S.StackSize)
        return false;  // 栈满
    *(S.top) = c;
    S.top++;
    S.CurrentSize++;
    return true;
}

// 弹栈操作
bool Pop(SqStack& S, char& c)
{
    if (S.top == S.base)
        return false;  // 栈空
    S.top--;
    c = *(S.top);
    S.CurrentSize--;
    return true;
}

// 判断字符串是否为回文
bool isPalindrome(const std::string& str)
{
    SqStack S;
    InitStack(S);

    // 1. 将字符串压入栈
    for (int i = 0; i < str.length(); i++)
    {
        Push(S, str[i]);
    }

    // 2. 从栈中弹出字符并组成新字符串
    std::string reversedStr = "";
    char stackChar;
    while (Pop(S, stackChar))
    {
        reversedStr =reversedStr+ stackChar;  // 拼接字符形成新字符串
    }

    // 3. 比较原字符串和新字符串
    return str == reversedStr;
}

int main()
{
    std::string str = "madam";
    if (isPalindrome(str))
    {
        std::cout << str << " is a palindrome." << std::endl;
    }
    else
    {
        std::cout << str << " is not a palindrome." << std::endl;
    }

    return 0;
}
