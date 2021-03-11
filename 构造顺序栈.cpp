#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
/*构造顺序栈*/

struct node
{
	int top;
	char shuzu[20];
};
void main()
{
	int i, number = 0;
	char item;
	char chuan[20] = { "helloolleh" };
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	p->top = -1;				//初始化栈的下标元素
	for (i = 0;i < 20;i++)
	{
		if (chuan[i] != '\0')
		{
			p->shuzu[++(p->top)] = chuan[i];
		}
	}
	for (i = 9;i >=0;i--)
	{
		item = p->shuzu[(p->top)--];
		if (item == chuan[i])
		{
			number += 1;
		}
	}
	printf("%d\n", number);
}