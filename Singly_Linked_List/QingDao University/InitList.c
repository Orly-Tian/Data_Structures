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


// 清空链表(释放除头指针与头节点的所有节点)
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


// 返回表长(返回不含头节点的所有数据节点的个数)
int ListLength(LinkList L) {
    int count = 0;
    LNode *p = L->next;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}


// 按位查找
bool GetElem(LinkList *L, int i, int *e) {
    LNode *p = *L;
    int j = 0;
    while (p && j<i) {
        p = p->next;
        j++;
    }
    if (!p || j>i)
        return false;
    *e = p->data;
    return true;
}


// 按值查找
int LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    int count = 1;
    while (p && p->data!=e) {
        p = p->next;
        count++;
    }
    if (p)
        return count;
    return 0;
}


// 插入节点
bool ListInsert(LinkList *L, int i, int e) {
    LNode *p = *L;
    int j = 0;
    while (p && j<i-1) {
        p = p->next;
        j++;
    }
    if (!p || j>i-1)
        return false;

    LNode *temp = (LNode *)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
    return true;
}


// 删除节点
bool ListDelete(LinkList *L, int i, int *e) {
    LNode *p = *L;
    int j = 0;
    while (p && j<i-1) {
        p = p->next;
        j++;
    }
    if (!(p->next) || j>i-1)
        return false;

    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
}


// 建立链表(头插法)
bool CreatList(LinkList *L, int n) {
    // 通过头指针建立头节点
    *L = (LNode *)malloc(sizeof(LNode));
    (*L)->next = NULL;

    for (int i=0;i<n;i++) {
        // 输入数据放入新节点
        LNode *p = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &p->data);

        // 将新节点插入头节点后
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return true;
}


// 建立链表(尾插法)
bool CreatList_2(LinkList *L, int n) {
    // 通过头指针建立头节点
    *L = (LNode *)malloc(sizeof(LNode));
    (*L)->next = NULL;
    // 初始化空链表的尾指针指向头节点
    LNode *r = *L;

    for (int i=0;i<n;i++) {
        // 输入数据放入新节点
        LNode *p = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &p->data);

        // 通过尾指针将新节点插入至最后一个元素，并将尾指针指向新节点
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return true;
}


int main() {
    
    LinkList L;
    InitList(&L);

    return 0；
}
