#include <stdio.h>
#include <string.h>

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN + 1];
    int length;
} SString;

// S 是主串，T 是子串
int Index_BF(SString S, SString T, int pos);

int main() {
    SString S, T;

    // 初始化 S 和 T
    strcpy(S.ch, "aldolfhans");
    S.length = strlen(S.ch);

    strcpy(T.ch, "dolf");
    T.length = strlen(T.ch);

    printf("%d\n", Index_BF(S, T, 1));
    return 0;
}

int Index_BF(SString S, SString T, int pos) {
    int i = pos - 1; // 将用户输入的 1-based 下标转为 0-based
    int j = 0;

    while (i < S.length && j < T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == T.length)
        return i - T.length + 1; // 返回 1-based 位置
    return 0;
}
