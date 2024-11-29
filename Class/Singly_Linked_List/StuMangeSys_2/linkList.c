// 数据结构 实验7
// Created by Administrator on 2024/11/29.
// 链表实现学生管理系统

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


typedef struct LNode {
	int no;
	int score;
	struct LNode *next;
} LNode, *LinkList;


// 初始化
LinkList InitList() {
	LNode *L;
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}


// 判空函数
int ListEmpty(LinkList L) {
	if (L->next == NULL)
		return TRUE;
	else
		return FALSE;
}


// 头插法创建链表
LinkList CreatList(LinkList L) {
	LNode *p;
	p = (LNode *)malloc(sizeof(LNode));
	printf("请逆序输入学生的学号与成绩!(格式如:101 98)\n");
	scanf("%d %d", &p->no, &p->next);
	while (p->no != 0) {
		p->next = L->next;
		L->next = p;
		p = (LNode *)malloc(sizeof(LNode));
		scanf("%d %d", &p->no, &p->score);
	}

	return L;
}
// 循环前的单独处理第一个节点是否冗余,能否加入到循环内操作
// 不可以,因为循环条件需要通过节点接收的值来判断,需单独操作第一个节点
// LinkList CreatList(LinkList L) {
// 	printf("请逆序输入学生的学号与成绩!(格式如:101 98)");
// 	while ()
// }


// 输出单链表
void PrintList(LinkList L) {
	LNode *p;
	p = L->next;
	printf("\n学生的成绩为:\n");
	printf("学号\t成绩\n");
	while (p->next != NULL) {
		printf("%d\t%d\n", p->no, p->score);
		p = p->next;
	}
}


// 插入元素
LinkList ListInsert(LinkList L, int i, int no, int score) {
	LNode *p;
	p = L;
	int j = 0;

	// 寻找插入位置的前一个节点
	// 通过位置遍历
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p && j > i + 1) {
		printf("插入位置非法!");
		return L;
	}

	// 分配新节点
	LNode *s;
	s = (LNode *)malloc(sizeof(LNode));
	s->no = no;
	s->score = score;
	s->next = p->next;
	p->next = s;

	return L;
}


// 通过学号删除节点
LinkList DeleteNo(LinkList L, int no) {
	LNode *p, *q;
	p = L;
	q = L->next;

	// 通过学号寻找节点,并同时记录被删除节点与前一个节点
	while (q != NULL && q->no != no && q->next != NULL) {
		p = q;
		q = q->next;
	}

	if (q->no == no) {
		p->next = q->next;
		free(q);
		printf("%d号学生已经被成功删除!", no);
	} else {
		printf("没有找到该学生!");
	}

	return L;
}


int main() {
	LinkList L;
	int i, no, score;
	L = InitList();
	L = CreatList(L);
	PrintList(L);

	// 按位置插入学生信息
	printf("\n插入操作,请输入学生的学号与成绩:(格式如:101 98)\n");
	scanf("%d %d", &no, &score);
	printf("请输入所想要插入的位置:");
	scanf("%d", &i);
	L = ListInsert(L, i, no, score);
	PrintList(L);

	// 按学号删除学生信息
	printf("\n删除操作\n");
	if (ListEmpty(L))
		printf("数据库为Null,无法删除!");
	else {
		printf("请输入被删除学生的学号:");
		scanf("%d", &no);
		L = DeleteNo(L, no);
		PrintList(L);
	}

	return 0;
}

