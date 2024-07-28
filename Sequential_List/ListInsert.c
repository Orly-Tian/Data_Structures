//
// Created by Administrator on 2024/7/27.
// 顺序表的插入操作

#include <stdbool.h>
#include <stdio.h>
#define MaxSize 10

// 静态顺序表
typedef struct {
    int data[MaxSize];
    int length;
}SqList;

// 初始化
void InitList(SqList &L) {
    for (int i=0;i<MaxSize;i++)
        L.data[i] = 0;
    L.length = 0;
}

// 插入函数
bool ListInsert(SqList &L, int p, int v) {

    // 若位置小于1或位置大于数组长度则返回false
    if (p<1 || p>L.length+1)
        return false;
    // 若数组长度已达最大长度则返回false
    if (L.length >= MaxSize)
        return false;

    // 数组从实际长度的最后一位开始向后移动一位，直至所需插入的位置
    for (int i=L.length;i>=p;i--)
        L.data[i] = L.data[i-1];
    // 将所需插入的数据写入该位置
    L.data[p] = v;
    L.length++;

    // 插入超过，返回true
    return true;

}

int main() {
    SqList L;
    InitList(L);

    ListInsert(L, 3, 3);

    return 0;
}

