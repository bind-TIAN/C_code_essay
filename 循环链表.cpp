#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//#define max 8
/*β�巨����˫��ѭ������*/

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
	head->llink = tail;				//������Ϊ����ͷָ���ѭ��˫����
	//p->llink->rlink = p->rlink;
	//p->rlink->llink = p->llink;		//ɾ��˫�������е�һ���ڵ�
	q = (struct node *)malloc(sizeof(struct node));
	strcpy(q->data, shuzu[4]);
	p->llink->rlink = q;
	q->llink = p->llink;
	q->rlink = p;
	p->llink = q;						//����˫�������е�һ���ڵ�
	for (i = 0;i < 12;i++)
	{
		printf("%s\n", p->data);
		p = p->llink;				//ͷ�巨�ĳ�rlink��β�巨�ĳ�llink
	}
}


/*ͷ�巨����˫��ѭ������*/

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
	head->llink = head->rlink = NULL;		//��ʼ��һ��ͷ�ڵ㣬����ͷ�ڵ㸳��һ���ַ���
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
		p->llink = head;			//����ͷ���뷨����˫������
	}
	for (i = 0;i < 2;i++)
	{
		p = p->rlink;
	}							//��λp��λ��
	p->rlink = head;
	head->llink = p;				//��ͷ�ڵ����ӵ�˫�������У��Ӷ�����ѭ��˫������
	//p->llink->rlink = p->rlink;
	//p->rlink->llink = p->llink;		//ɾ��˫�������е�һ���ڵ�
	q = (struct node *)malloc(sizeof(struct node));
	strcpy(q->data, shuzu[4]);
	p->llink->rlink = q;
	q->llink = p->llink;
	q->rlink = p;
	p->llink = q;						//����˫�������е�һ���ڵ�
	for (i = 0;i < 12;i++)
	{
		printf("%s\n", p->data);	//ѭ����ӡ˫�������е�Ԫ��
		p = p->rlink;				//ͷ�巨�ĳ�rlink��β�巨�ĳ�llink
	}
}