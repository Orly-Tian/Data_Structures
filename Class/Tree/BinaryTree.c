//
// Created by Administrator on 2024/11/15.
// 二叉树的基本操作1

#include <stdio.h>
#include <stdlib.h>

#define NULL 0
typedef char ElemType;


// 定义二叉树
typedef struct BiTNode {
    // 数据域
    ElemType data;
    // 左右子节点指针域
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


// 按先序遍历创建二叉树
void CreateBiTree(BiTree *T) {
    char ch = getchar();
    if (ch == '#')
        *T = NULL;
    else {
        // 分配此节点内存空间
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        // 存入数据
        (*T)->data = ch;

        // 递归分配子节点
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}


// 先序遍历二叉树
void preOrder(BiTree T) {
    if (T) {
        // 输出此节点数据
        printf("%c", T->data);
        // 递归输出子节点
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}


// 中序遍历二叉树
void inOrder(BiTree T) {
    if (T) {
        inOrder(T->lchild);
        printf("%c", T->data);
        inOrder(T->rchild);
    }
}


// 后序遍历二叉树
void postOrder(BiTree T) {
    if (T) {
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%c", T->data);
    }
}


// 二叉树深度
int Depth(BiTree T) {
    // 此树为空，则深度为0
    if (T == NULL)
        return 0;
    else {
        // 递归子树的深度
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        // 输出最大值
        if (m > n)
            return m + 1;
        else
            return n + 1;
    }
}


// 二叉树的节点数
int NodeCount(BiTree T) {
    if (T == NULL)
        return 0;
    else
        // 递归统计子树的节点数并加此节点
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}


int main() {
    // 创建二叉树
    BiTree T = NULL;
    printf("\n创建一棵二叉树\n");

    // 将二叉树补满，并用先序遍历写出，空节点用"#"替代
    // 如:AB#C##D##
    CreateBiTree(&T);

    printf("\n");
    printf("先序遍历序列：");
    preOrder(T);
    printf("\n");

    printf("中序遍历序列：");
    inOrder(T);
    printf("\n");

    printf("后序遍历序列：");
    postOrder(T);
    printf("\n");

    printf("\n二叉树的深度为：%d", Depth(T));
    printf("\n二叉树的节点数为：%d\n", NodeCount(T));

    return 0;
}

