//
// Created by Administrator on 2024/8/10.
// 栈的初始化及其基本操作

#include <stdbool.h>
#include <stdio.h>

#define MaxSize 10


typedef struct {
    // 存放栈数据
    int data[MaxSize];
    // 栈顶索引
    int top;
    int size;
}SqStack;


void InitStack(SqStack *S) {
    // 将空栈的栈顶索引指向第1个元素-1
    S->top = -1;
    S->size = 0;
}


bool StackEmpty(SqStack S) {
    // 栈顶索引为-1则栈空
    if (S.top == -1)
        return true;
    else
        return false;
}


bool GetTop(SqStack S, int *x) {
    // 栈空返回false
    if (S.top == -1)
        return false;
    // 返回栈顶元素
    *x = S.data[S.top];
    return true;
}


bool Push(SqStack *S, int x) {
    // 栈满则返回false
    if (S->top == MaxSize-1)
        return false;

    // S->data[++S->top] = x;
    // 等价于下两行，栈顶索引++并赋值
    S->top++;
    S->data[S->top] = x;

    S->size++;
    // 进栈成功
    return true;
}


bool Pop(SqStack *S, int *x) {
    // 栈空则返回false
    if (S->top == -1)
        return false;
    // *x = S.data[S.top--];
    // 等价于下两行，将栈顶元素赋值给指针x后栈顶索引--
    *x = S->data[S->top];
    S->top--;

    S->size--;
    // 出栈成功(逻辑删除)
    return true;
}


bool PrintStatck(SqStack S) {
    for (int i=0;i<S.size;i++)
        printf("%d ", S.data[i]);
    printf("\n");
    return true;
}


int main() {
    SqStack S;

    InitStack(&S);

    printf("%d\n", StackEmpty(S));
    for (int i=1;i<20;i++)
        Push(&S, i);
    PrintStatck(S);
    int x;
    Pop(&S, &x);
    PrintStatck(S);

    return 0;
}


