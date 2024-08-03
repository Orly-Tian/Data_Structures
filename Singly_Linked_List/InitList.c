//
// Created by Administrator on 2024/8/3.
// 单链表的定义

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 定义单链表
typedef struct LNode{
    // 数据域
    int data;
    // 指针域
    struct LNode *next;
}LNode, *LinkList;
// LNode 强调节点
// *LinkList 强调单链表


// 初始化(带头节点)
bool InitList_1(LinkList *L) {

    // 申请一段节点大小的内存空间，以存放此节点
    L = (LNode *)malloc(sizeof(LNode));

    // 内存不足，分配失败
    if (L == NULL)
        return false;

    // 将空链表的指针域设置为Null
    (*L)->next = NULL;

    return true;
}


// 初始化(不带头节点)
bool InitList_2(LinkList *L) {
    L = NULL;
    return true;
}


bool Empty(LinkList L) {
    // 链表未初始化
    if (L == NULL)
        return true;
    if (L->next == NULL)
        return true;
    else
        return false;
}


int main() {
    LinkList L;
    InitList_1(&L);

    printf("%d", Empty(L));

    return 0;
}
