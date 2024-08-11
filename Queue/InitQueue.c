//
// Created by Administrator on 2024/8/11.
// 队列的初始化及其基本操作

#include <stdbool.h>
#include <stdio.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    // 定义队头索引和队尾索引
    int front, rear;
} SqQueue;


void InitQueue(SqQueue *Q) {
    // 将对头队尾索引初始化为0
    Q->front = 0;
    Q->rear = 0;
}


bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}


// 队尾入队
bool EnQueue(SqQueue *Q, int x) {
    // 循环队列中，队尾等于队头-1则队满，返回false
    if (Q->rear == Q->front-1)
        return false;
    // 队尾存入x
    Q->data[Q->rear] = x;
    // 队尾++，并且循环队列
    Q->rear = (Q->rear + 1) % MaxSize;
    return true;
}


// 对头出队，并返回被删除的元素
bool DeQueue(SqQueue *Q, int *x) {
    // 队头==队尾，则空队列返回false
    if (Q->front == Q->rear)
        return false;
    // 被删除的元素返回给指针x
    *x = Q->front;
    // 队头索引++并循环队列
    Q->front = (Q->front + 1) % MaxSize;
    return true;
}


// 获取队头元素
bool GetHead(SqQueue Q, int *x) {
    if (Q.rear == Q.front-1)
        return false;
    *x = Q.data[Q.front];
    return true;
}


bool PrintQueue(SqQueue Q) {
    if (Q.rear == Q.front)
        return false;
    // for (int i=Q.front;i<Q.rear;i=(i+1)%MaxSize)
    //     printf("%d ", Q.data[i]);
    int i = Q.front;
    while (i != Q.rear) {
        printf("%d ", Q.data[i]);
        i = (i + 1) % MaxSize;
    }
    printf("\n");
    return true;
}


int main() {
    SqQueue Q;
    InitQueue(&Q);

    printf("Empty : %d\n", QueueEmpty(Q));
    for (int i=1;i<11;i++)
        EnQueue(&Q, i);
    PrintQueue(Q);
    int x;
    DeQueue(&Q, &x);
    PrintQueue(Q);
    printf("Empty : %d\n", QueueEmpty(Q));


    return 0;
}

