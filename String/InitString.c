//
// Created by Administrator on 2024/8/16.
// 串的基本操作(未完成)

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MaxLen 255


// 定义串
typedef struct {
    char ch[MaxLen];
    int length;
} SString;


// 初始化
void InitString(SString *S) {
    S->length = 0;
}


// 获取子串
bool SubString(SString *Sub, SString S, int pos, int len) {
    if (pos+len > S.length)
        return false;
    for (int i=pos;i<=pos+len;i++) {
        Sub->ch[i-pos+1] = S.ch[i];
    }
    Sub->length = len;
    return true;
}


// 比较串
bool StrCompare(SString S, SString T) {
    for (int i=1;i<=S.length && i<=T.length;i++) {
        if (S.ch[i] != T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    return S.length-T.length;
}


// 匹配字符串
int Index(SString S, SString T) {
    int i=1, m=S.length, n=T.length;
    SString Sub;
    while (i < m-n+1) {
        SubString(&Sub, S, i, n);
        if (StrCompare(Sub, T) != 0)
            i++;
        else
            return i;
    }
    return 0;
}


