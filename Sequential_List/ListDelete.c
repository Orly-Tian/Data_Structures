//
// Created by Administrator on 2024/7/27.
// 顺序表的删除操作

#include <stdbool.h>
#include <stdio.h>
#define MaxSize 10


typedef struct {
    int data[MaxSize];
    int length;
}SqList;


void InitList(SqList *L) {
    for (int i=0;i<MaxSize;i++)
        L->data[i] = 0;
    L->length = 0;
}


bool ListInsert(SqList *L, int p, int v) {
    if (p<1 || p>L->length+1)
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
    if (p<1 || p>L->length)
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

    for (int i=1;i<=5;i++)
        ListInsert(&L, i, i);

    for (int i=0;i<L.length;i++)
        printf("%d ", L.data[i]);
    printf("\n");

    int value;
    if (ListDelete(&L, 3, &value))
        printf("删除成功，被删除的元素为 %d .", value);
    else
        printf("ERROR!\n请输入合法位序！");

    printf("\n");
    for (int i=0;i<L.length;i++)
        printf("%d ", L.data[i]);

    return 0;
}


