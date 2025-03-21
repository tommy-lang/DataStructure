#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

Status InitList(LinkList* L) {
    *L = (LNode*)malloc(sizeof(LNode));
    if (*L == NULL) return OVERFLOW;
    (*L)->next = NULL;
    return OK;
}

Status ListInsert(LinkList L, int i, int e) {
    LNode* p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) return OVERFLOW;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList L, int i) {
    LNode* p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p->next || j > i - 1) return ERROR;
    LNode* q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

Status GetElem(LinkList L, int i, int* e) {
    LNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    *e = p->data;
    return OK;
}

int* LocateElem(LinkList L, int v, int* count) {
    if (!L || !L->next) {
        *count = 0;
        return NULL;
    }
    LNode* p = L->next;
    *count = 0;
    int index = 1;
    while (p) {
        if (p->data == v) (*count)++;
        p = p->next;
    }
    if (*count == 0) return NULL;
    int* result = (int*)malloc((*count) * sizeof(int));
    if (result == NULL) return NULL;
    p = L->next;
    index = 1;
    int i = 0;
    while (p) {
        if (p->data == v) {
            result[i++] = index;
        }
        p = p->next;
        index++;
    }
    return result;
}

void FreeArray(int* arr) {
    free(arr);
}

void DeleteNodeByValue(LinkList L, int v) {
    LNode* p = L;
    while (p->next != NULL) {
        if (p->next->data == v) {
            LNode* q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

void TraverseList(LinkList L) {
    LNode* p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    LinkList L;
    InitList(&L);
    ListInsert(L, 1, 11);
    ListInsert(L, 2, 22);
    ListInsert(L, 3, 33);
    ListInsert(L, 4, 44);
    ListInsert(L, 5, 55);
    TraverseList(L);
    return 0;
}
