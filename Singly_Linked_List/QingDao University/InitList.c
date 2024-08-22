//
// Created by Administrator on 2024/8/22.
// 青岛大学-王卓老师  链表的基本操作

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10


typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;


// 初始化
bool InitList(LinkList *L) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
        return false;
    (*L)->next = NULL;
    return true;
}


// 判空操作
bool ListEmpty(LinkList L) {
    if (L->next == NULL)
        return true;
    return false;
}


// 销毁链表
bool DestroyList(LinkList *L) {
    LNode *p;
    while (*L) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return true;
}


// 清空链表
bool ClearList(LinkList *L) {
    LNode *p, *temp;
    p = (*L)->next;
    while (p) {
        temp = p->next;
        free(p);
        p = temp;
    }
    (*L)->next = NULL;
    return true;
}



int main() {
    LinkList L;
    InitList(&L);

}
