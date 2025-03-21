#include <stdio.h>

int m = 0;

void move(char A, int n, char C);
void Hanoi(int n, char A, char B, char C);

int main() {
    return 0;
}

void move(char A, int n, char C) {
    printf("%d,%d,%c,%c\n", ++m, n, A, C);
}

void Hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        move(A, 1, C);
    } else {
        Hanoi(n - 1, A, C, B);
        move(A, n, C);
        Hanoi(n - 1, B, A, C);
    }
}