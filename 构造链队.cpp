#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
/*构造链队*/

typedef struct node
{
	char data[21];
	struct node *next;
} *Qlink;			//此处的Qlink几乎不起任何作用（除非换成下面两条语句）
void main()
{
	int i;
	struct node *front, *rear, *p, *q;
	char shuzu[5][21] = { {"hello"},{"hi"},{"my name is"},{"tbd"},{"yes"} };
	char cunchu[1][21] = { {"except"} };
	front = rear = (struct node *)malloc(sizeof(struct node));	//或换成front = rear = (Qlink)malloc(sizeof(Qlink));
	front = rear = NULL;
	for (i = 0;i < 3;i++)
	{
		p = (struct node *)malloc(sizeof(struct node));		//或换成p = (Qlink)malloc(sizeof(Qlink));
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
	}									//进队操作

	//p = front;							//把队头节点赋给一个节点p，以便操作节点p
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
	//}									//删除队列中的元素并输出--方法一
	q = front;
	for (i = 0;i < 3;i++)
	{
		printf("%s\n", q->data);
		q = q->next;
	}									//删除队列中的元素并输出--方法二
}