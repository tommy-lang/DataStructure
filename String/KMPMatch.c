#include <stdio.h>
#include <string.h>
#define MAXLEN 255

typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

// 计算 next 数组（0-based）
void get_next(const SString* T, int next[])
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < T->length - 1)
    {
        if (j == -1 || T->ch[i] == T->ch[j])
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
int Index_KMP(const SString* S, const SString* T, int pos, int next[])
{
    int i = pos;
    int j = 0;
    while (i < S->length && j < T->length)
    {
        if (j == -1 || S->ch[i] == T->ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == T->length)
        return i - T->length;
    return -1;
}

// 计算 nextval 数组（0-based）
void get_nextval(const SString* T, int next[], int nextval[])
{
    int length = T->length;
    nextval[0] = -1;
    for (int i = 1; i < length; ++i)
    {
        if (next[i] == -1)
        {
            nextval[i] = -1;
        }
        else if (T->ch[i] == T->ch[next[i]])
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
    SString S, T;

    // 初始化 S 和 T
    strcpy(S.ch, "ababcabcacbab");
    S.length = strlen(S.ch);

    strcpy(T.ch, "abcabaa");
    T.length = strlen(T.ch);

    int next[MAXLEN];
    int nextval[MAXLEN];

    get_next(&T, next);
    get_nextval(&T, next, nextval);

    printf("next array: ");
    for (int i = 0; i < T.length; ++i)
    {
        printf("%d ", next[i]);
    }
    printf("\n");

    printf("nextval array: ");
    for (int i = 0; i < T.length; ++i)
    {
        printf("%d ", nextval[i]);
    }
    printf("\n");

    int pos = 0;
    int result = Index_KMP(&S, &T, pos, next);

    if (result != -1)
        printf("Match success, location: %d\n", result);
    else
        printf("Match fails\n");

    return 0;
}

