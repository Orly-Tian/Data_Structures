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
}SqStack;


void InitStack(SqStack *S) {
    // 将空栈的栈顶索引指向第1个元素-1
    S->top = -1;
}


bool StackEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    else
        return false;
}


bool GetTop(SqStack S, int *x) {
    if (S.top == -1)
        return false;
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

    // 出栈成功(逻辑删除)
    return true;
}


int main() {
    SqStack S;

    InitStack(&S);

    return 0;
}


