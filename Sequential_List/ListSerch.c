//
// Created by Administrator on 2024/8/1.
// 顺序表的查找操作

#include <stdbool.h>
#include <stdio.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
}SqList;


void Printer(SqList *L) {
    printf("\n");
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
    if (p<1 || p>MaxSize)
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


// 按位查找
int GetElem(SqList *L, int p) {
    return L->data[p-1];
}


// 按值查找
int LocateElem(SqList *L, int v) {
    for (int i=0;i<L->length;i++)
        if (L->data[i] == v)
            return i+1;
    return 0;
}

int main() {

    // 定义顺序表
    SqList L;

    // 初始化
    InitList(&L);

    // 从1~10的位置插入值1~10
    for (int i=1;i<=MaxSize;i++)
        ListInsert(&L, i, i);

    Printer(&L);

    // 删除第5个元素
    int delete_v;
    ListDelete(&L, 5, &delete_v);
    printf("%d 已被删除", delete_v);

    Printer(&L);

    printf("所查找的第 5 个元素的值为： %d\n", GetElem(&L, 5));
    printf("所查找的值为 8 的位序为： %d\n", LocateElem(&L, 8));

    return 0;
}
