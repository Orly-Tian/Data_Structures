//
// Created by Administrator on 2024/7/14.
// 顺序表--静态分配


#include <stdio.h>
// 顺序表长度
#define MaxSize 10

// 定义顺序表
typedef struct {
    // 定义数组
    int data[MaxSize];
    // 定义长度
    int length;
}SqList;

// 初始化顺序表
void InitList(SqList &L) {
    // 将顺序表内所有元素初始化为0
    for (int i=0;i<MaxSize;i++)
        L.data[i]=0;
    // 顺序表长度初始化为0
    L.length=0;
}

int main() {

    printf("Hello! Data Structures!");

    // 声明顺序表
    SqList L;
    // 初始化
    InitList(L);

    return 0;
}

