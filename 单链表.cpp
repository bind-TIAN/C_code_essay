#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>


/*���쵥��������ַ���*/

struct node
{
	char data[21];
	struct node *next, *llink;
};
void main()
{
	int i;
	struct node *head, *q, *p, *r, *x, *y;
	char shuzu[5][21] = { {"hello"},{"hi"},{"my name is"},{"tbd"},{"yes"} };
	char cunchu[1][21] = { {"except"} };
	head = q = (struct node *)malloc(sizeof(struct node));
	q->data[0] = '\0';
	for (i = 0;i < 3;i++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->data[0] = '\0';
		q->next = p;
		q = p;
	}
	p->next = head;
	p = head;		//��������4��Ԫ�ص�ѭ������
	p->next = p->next->next;			//ɾ��һ���ڵ�
	for (i = 0;i < 4;i++)
	{
		if (shuzu[i] != NULL)
		{
			strcpy(p->data, shuzu[i]);
			p = p->next;
		}
	}

	for (i = 0;i < 4;i++)
	{
		if (p->data[0] != '\0')
		{
			printf("%s\n", p->data);
		}
		p = p->next;
	}
}


struct node
{
	char data[21];
	struct node *next, *llink;
};
void main()
{
	int i;
	struct node *head, *q, *p, *r, *x, *y;
	char shuzu[5][21] = { {"hello"},{"hi"},{"my name is"},{"tbd"},{"yes"} };
	char cunchu[1][21] = { {"except"} };
	head = q = (struct node *)malloc(sizeof(struct node));
	q->data[0] = '\0';
	for (i = 0;i < 3;i++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->data[0] = '\0';
		q->next = p;
		q = p;
	}
	p->next = head;
	p = head;		//��������4��Ԫ�ص�ѭ������
	r = (struct node *)malloc(sizeof(struct node));
	r->next = p->next;
	p->next = r;				//����һ���ڵ�
	for (i = 0;i < 4;i++)
	{
		if (shuzu[i] != NULL)
		{
			strcpy(p->data, shuzu[i]);
			p = p->next;
		}
	}

	for (i = 0;i < 4;i++)
	{
		if (p->data[0] != '\0')
		{
			printf("%s\n", p->data);
		}
		p = p->next;
	}
}