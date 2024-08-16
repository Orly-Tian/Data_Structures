//
// Created by Administrator on 2024/8/16.
// 朴素模式匹配算法(暴力求匹配字符串)

#include <stdio.h>

#define MaxLen 255


typedef struct {
    char ch[MaxLen];
    int length;
} SString;


// 传入主串S，模式串T
int Index(SString S, SString T) {
    // 初始化主串与模式串索引为1
    int i=1, j=1;

    // 当索引超出字符串长度时跳出循环
    while (i<=S.length && j<=T.length) {
        // 比较字符是否相等
        if (S.ch[i] == T.ch[j]) {
            // 若相等则比较下个字符
            i++;
            j++;
        }
        else {
            // 若不相等，则
            //      将主串索引回归至所比较子串的第2个位置
            //      将格式串索引回归至1
            i = i-j+2;
            j = 1;
        }
    }

    // 若格式串索引大于其长度，说明已将格式串与子串比较完成并j++
    if (j > T.length)
        // 返回主串中子串的0索引的位置
        return i-T.length;
    else
        return 0;
}


/*
 *  朴素模式匹配算法：
 *      1.双指针分别控制主串与格式串，比较值是否相同
 *      2.若不相同，则将主串中子串指针返回索引2处，格式串指针返回索引1处
 *      3.匹配成功返回子串首索引在主串中的索引
 *
 *  时间复杂度：
 *      最坏：O(mn)
 *
 */
