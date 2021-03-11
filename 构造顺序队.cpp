#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

/*构造顺序队*/

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
	p->front = -1;								//初始化队的下标元素
	p->rear = -1;
	for (i = 0;i < 20;i++)
	{
		if (chuan[i] != '\0')
		{
			p->shuzu[++(p->rear)] = chuan[i];	//进队操作
		}
	}
	for (i = 9;i >= 0;i--)
	{
		item = p->shuzu[++(p->front)];			//出队操作
		printf("%c", item);
	}
}