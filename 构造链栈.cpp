#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

/*������ջ*/

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
	head->next = NULL;					//��ʼ��ջ
	for (i = 0;i < 3;i++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		strcpy(p->data, shuzu[i]);
		p->next = head->next;				//�����head|q|r��ͬһ���ڵ�
		head->next = p;
	}									//��ջ����
	//printf("%s\n", p->data);			//ջ��Ԫ��
	for (i = 0;i < 3;i++)
	{
		p = head->next;
		printf("%s\n", p->data);
		head->next = p->next;
		free(p);
	}									//��ջ����
}