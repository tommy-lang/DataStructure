#include <iostream>
#define MAXLEN 255

typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

// 计算 next 数组（0-based）
void get_next(const SString& T, int next[])
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < T.length - 1)
        {
        if (j == -1 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

// KMP 主过程（0-based）
int Index_KMP(const SString& S, const SString& T, int pos, int next[])
{
    int i = pos;
    int j = 0;
    while (i < S.length && j < T.length)
        {
        if (j == -1 || S.ch[i] == T.ch[j])
            {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == T.length)
        return i - T.length; // 返回匹配位置
    return -1; // 未匹配
}

// 计算 nextval 数组（0-based）
void get_nextval(const SString& T, int next[], int nextval[])
{
    int length = T.length;
    nextval[0] = -1;
    for (int i = 1; i < length; ++i)
    {
        if (next[i] == -1)
        {
            nextval[i] = -1;
        }
        else if (T.ch[i] == T.ch[next[i]])
        {
            nextval[i] = nextval[next[i]];
        }
        else
        {
            nextval[i] = next[i];
        }
    }
}


int main()
{
    SString S = { "ababcabcacbab", 13 };
    SString T = { "ababaa", 6 };

    int next[MAXLEN];
    int nextval[MAXLEN];

    get_next(T, next);
    get_nextval(T, next, nextval);

    std::cout << "next array: ";
    for (int i = 0; i < T.length; ++i)
    {
        std::cout << next[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "nextval array: ";
    for (int i = 0; i < T.length; ++i)
    {
        std::cout << nextval[i] << " ";
    }
    std::cout << std::endl;

    int pos = 0;
    int result = Index_KMP(S, T, pos, next);

    if (result != -1)
        std::cout << "Match success, location: " << result << std::endl;
    else
        std::cout << "Match fails" << std::endl;

    return 0;
}
