//
// Created by Administrator on 2024/8/1.
//

#include <stdbool.h>
#include <stdio.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
}SqList;

void Printer(SqList *L) {
    for (int i=0;i<L->length;i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

void InitList(SqList *L) {
    for (int i=0;i<MaxSize;i++)
        L->data[i] = 0;
    L->length = 0;
}


bool ListInsert(SqList *L, int p, int v) {
    if (p<1 || p>L->length)
        return false;
    if (L->length >= MaxSize)
        return false;

    for (int i=L->length;i>=p;i--)
        L->data[i] = L->data[i-1];
    L->data[p-1] = v;
    L->length++;

    return true;
}


bool ListDelete(SqList *L, int p, int *v) {
    if (p<1 || L->length>MaxSize)
        return false;

    *v = L->data[p-1];
    for (int i=p;i<L->length;i++)
        L->data[i-1] = L->data[i];
    L->data[L->length-1] = 0;
    L->length--;

    return true;
}

int main() {
    SqList L;

    InitList(&L);

    for (int i=1;i<=MaxSize;i++)
        ListInsert(&L, i, i);

    Printer(&L);

    int delete_v;
    ListDelete(&L, 5, &delete_v);
    printf("%d 已被删除", delete_v);

    return 0;
}
