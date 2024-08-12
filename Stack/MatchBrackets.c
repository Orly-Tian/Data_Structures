//
// Created by Administrator on 2024/8/12.
// 括号匹配问题

#include <stdbool.h>
#include <stdio.h>

#define MaxSize 20

typedef struct {
    char data[MaxSize];
    int top;
} SqStack;


void InitStack(SqStack *S) {
    S->top = -1;
}


bool EmptyStack(SqStack S) {
    if (S.top == -1)
        return true;
    return false;
}


bool Push(SqStack *S, char x) {
    if (S->top >= MaxSize)
        return false;
    S->top++;
    S->data[S->top] = x;
    return true;
}


bool Pop(SqStack *S, char *x) {
    if (S->top == -1)
        return false;
    *x = S->data[S->top];
    S->top--;
    return true;
}


bool TopElem(SqStack S, char *x) {
    if (S.top == -1)
        return false;
    *x = S.data[S.top];
    return true;
}


bool BracketCheck(char str[], int length) {
    SqStack S;
    InitStack(&S);

    for (int i=0;i<length;i++) {
        if (str[i]=='(' || str[i]=='[' || str[i]=='{') {
            Push(&S, str[i]);
        }
        else if (str[i]==')' || str[i]==']' || str[i]=='}') {
            if (EmptyStack(S))
                return false;
            char top;
            Pop(&S, &top);
            if (str[i]==')' && top!='(')
                return false;
            if (str[i]=='[' && top!=']')
                return false;
            if (str[i]=='{' && top!='}')
                return false;
        }
    }
    return EmptyStack(S);
}


int main() {
    char str[20];
    gets(str);
    printf("%d", BracketCheck(str, 20));

    return 0;
}

