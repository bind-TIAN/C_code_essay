#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
/*����ѭ����*/

struct node
{
	int front, rear;
	char shuzu[20];
};
void main()
{
	int i, number = 0;
	char item;
	char chuan[20] = { "hellohello" };
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	p->front = -1;										//��ʼ���ӵ��±�Ԫ��
	p->rear = -1;
	for (i = 0;i < 20;i++)
	{
		if (chuan[i] != '\0')
		{
			p->shuzu[(++(p->rear)) % 3] = chuan[i];		//ѭ�����Ӳ���
		}
	}
	for (i = 9;i >= 0;i--)
	{
		item = p->shuzu[(++(p->front)) % 3];			//ѭ�����Ӳ���
		printf("%c", item);
	}
}