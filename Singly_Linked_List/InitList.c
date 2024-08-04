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
// 形参为节点指针的指针
bool InitList_1(LinkList *L) {
    // 解引用L为节点指针，赋值为申请的节点大小的内存空间首地址
    (*L) = (LNode *)malloc(sizeof(LNode));
    // 内存不足，初始化失败
    if (*L == NULL)
        return false;
    // 通过节点指针*L将节点内部的next设置为NULL
    (*L)->next = NULL;
    // 初始化成功
    return true;
}


// 初始化(不带头节点)
bool InitList_2(LinkList *L) {
    // 设置节点指针为NULL
    *L = NULL;
    return true;
}


// 判断链表是否为空
// 判空操作不需要修改实参，所以不需要传入指针
bool Empty(LinkList L) {
    // 链表未初始化或链表仅有头节点
    if (L==NULL || L->next==NULL)
        return true;
    return false;
}


int main() {
    LinkList L;
    InitList_1(&L);

    printf("%d", Empty(L));

    return 0;
}
