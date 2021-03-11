#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

/*构造链栈*/

struct node
{
	char data[21];
	struct node *next;
};
void main()
{
	int i;
	struct node *head, *p, *q, *r;
	char shuzu[5][21] = { {"hello"},{"hi"},{"my name is"},{"tbd"},{"yes"} };
	char cunchu[1][21] = { {"except"} };
	head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;					//初始化栈
	for (i = 0;i < 3;i++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		strcpy(p->data, shuzu[i]);
		p->next = head->next;				//这里的head|q|r是同一个节点
		head->next = p;
	}									//进栈操作
	//printf("%s\n", p->data);			//栈顶元素
	for (i = 0;i < 3;i++)
	{
		p = head->next;
		printf("%s\n", p->data);
		head->next = p->next;
		free(p);
	}									//退栈操作
}