//
// Created by Administrator on 2024/8/3.
// 单链表的插入操作

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;


// 遍历单链表(未完成)
void PrintList(LinkList L) {
    LNode *p = L;
    while (p->next != NULL) {
        printf("%d", p->data);
    }

}


bool InitList(LinkList *L) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
        return false;
    (*L)->next = NULL;
    return true;
}


// 按位插入
bool ListInsert(LinkList *L, int i, int e) {
    // 位序不合法
    if (i < 1)
        return false;
    // 定义节点指针p指向头节点
    LNode *p;
    p = L;
    // 循环变量控制需要插入的位置
    int j=0;
    // 插入的位置为第i-1个节点
    while (p!=NULL && j<i-1) {
        // 指向下一个节点
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    // 定义新节点并分配空间
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 所插入的数据存放到新节点
    s->data = e;
    // 新节点的后驱节点指向p的后驱节点
    s->next = p->next;
    // p的后驱节点指向新节点
    p->next = s;
    // 插入成功
    return true;
}


int main() {
    LinkList L;

    printf("%d", InitList(&L));

    for (int i=0;i<10;i++)
        ListInsert(&L, i, i);

    PrintList(L);

    return 0;
}
