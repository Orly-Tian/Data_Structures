//
// Created by Administrator on 2024/7/18.
// 顺序表--动态分配

#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef struct {
    int *data;
    int MaxSize;
    int length;
}SqList;

void InitList(SqList L) {
    L.data = (int *)malloc(sizeof(int)*InitSize);
    L.length=0;
    L.MaxSize=InitSize;
}

void IncreaseSize(SqList L, int len) {
    int *p=L.data;
    L.data=(int *)malloc((L.MaxSize+len) * sizeof(int));
    for (int i=0;i<L.length;i++) {
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
}

int main() {
    SqList L;
    InitList(L);
    IncreaseSize(L, 5);
}
