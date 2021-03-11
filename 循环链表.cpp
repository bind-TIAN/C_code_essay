#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//#define max 8
/*尾插法构造双向循环链表*/

struct node
{
	char data[21];
	struct node *llink, *rlink;
};
void main()
{
	int i;
	char shuzu[5][21] = { {"hello"},{"hi"},{"my name is"},{"tbd"},{"yes"} };
	struct node *head, *p, *q, *r, *tail;
	head = (struct node *)malloc(sizeof(struct node));
	tail = head;
	strcpy(head->data, shuzu[3]);
	for (i = 0;i < 3;i++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		strcpy(p->data, shuzu[i]);
		tail->rlink = p;
		p->llink = tail;
		tail = p;
	}
	tail->rlink = head;
	head->llink = tail;				//本构造为带有头指针的循环双链表
	//p->llink->rlink = p->rlink;
	//p->rlink->llink = p->llink;		//删除双向链表中的一个节点
	q = (struct node *)malloc(sizeof(struct node));
	strcpy(q->data, shuzu[4]);
	p->llink->rlink = q;
	q->llink = p->llink;
	q->rlink = p;
	p->llink = q;						//插入双向链表中的一个节点
	for (i = 0;i < 12;i++)
	{
		printf("%s\n", p->data);
		p = p->llink;				//头插法改成rlink，尾插法改成llink
	}
}


/*头插法构造双向循环链表*/

struct node
{
	char data[21];
	struct node *llink, *rlink;
};
void main()
{
	int i;
	char shuzu[5][21] = { {"hello"},{"hi"},{"my name is"},{"tbd"},{"yes"} };
	struct node *head, *p, *q, *r, *tail;
	head = (struct node *)malloc(sizeof(struct node));
	head->llink = head->rlink = NULL;		//初始化一个头节点，并给头节点赋予一个字符串
	strcpy(head->data, shuzu[3]);
	for (i = 0;i < 3;i++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		strcpy(p->data, shuzu[i]);
		p->rlink = head->rlink;
		if (head->rlink != NULL)
		{
			head->rlink->llink = p;
		}
		head->rlink = p;
		p->llink = head;			//采用头插入法构造双向链表
	}
	for (i = 0;i < 2;i++)
	{
		p = p->rlink;
	}							//定位p的位置
	p->rlink = head;
	head->llink = p;				//把头节点链接到双向链表中，从而构成循环双向链表
	//p->llink->rlink = p->rlink;
	//p->rlink->llink = p->llink;		//删除双向链表中的一个节点
	q = (struct node *)malloc(sizeof(struct node));
	strcpy(q->data, shuzu[4]);
	p->llink->rlink = q;
	q->llink = p->llink;
	q->rlink = p;
	p->llink = q;						//插入双向链表中的一个节点
	for (i = 0;i < 12;i++)
	{
		printf("%s\n", p->data);	//循环打印双向链表中的元素
		p = p->rlink;				//头插法改成rlink，尾插法改成llink
	}
}