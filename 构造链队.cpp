#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
/*��������*/

typedef struct node
{
	char data[21];
	struct node *next;
} *Qlink;			//�˴���Qlink���������κ����ã����ǻ�������������䣩
void main()
{
	int i;
	struct node *front, *rear, *p, *q;
	char shuzu[5][21] = { {"hello"},{"hi"},{"my name is"},{"tbd"},{"yes"} };
	char cunchu[1][21] = { {"except"} };
	front = rear = (struct node *)malloc(sizeof(struct node));	//�򻻳�front = rear = (Qlink)malloc(sizeof(Qlink));
	front = rear = NULL;
	for (i = 0;i < 3;i++)
	{
		p = (struct node *)malloc(sizeof(struct node));		//�򻻳�p = (Qlink)malloc(sizeof(Qlink));
		strcpy(p->data, shuzu[i]);
		p->next = NULL;
		if (front == NULL)
		{
			front = p;
		}
		else
		{
			rear->next = p;
		}
		rear = p;
	}									//���Ӳ���

	//p = front;							//�Ѷ�ͷ�ڵ㸳��һ���ڵ�p���Ա�����ڵ�p
	//for (i = 0;i < 3;i++)
	//{
		//printf("%s\n", p->data);
		//p = p->next;
	//}

	//for (i = 0;i < 3;i++)
	//{
		//q = front;
		//printf("%s\n", q->data);
		//front = q->next;
		//free(q);
	//}									//ɾ�������е�Ԫ�ز����--����һ
	q = front;
	for (i = 0;i < 3;i++)
	{
		printf("%s\n", q->data);
		q = q->next;
	}									//ɾ�������е�Ԫ�ز����--������
}