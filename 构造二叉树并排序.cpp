#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *lchild, *rchild;
}BTnode, *btree;
btree st[21];
void delete_p(btree tt)
{
	btree q;
	q = tt;
	tt = tt->rchild;
	free(q);
}
int delete_point(btree t, int k)
{
	if (t != NULL)
	{
		if (k == t->data)
		{
			delete_p(t);
			return 1;
		}
		else if (k < t->data)
		{
			delete_point(t->lchild, k);
		}
		else if (k > t->data)
		{
			delete_point(t->rchild, k);
		}
	}
	else
	{
		return 0;
	}
}
int find(btree t, int k)
{
	if (t != NULL)
	{
		if (k == t->data)
		{
			return 1;
		}
		else if (k < t->data)
		{
			find(t->lchild, k);
		}
		else if (k > t->data)
		{
			find(t->rchild, k);
		}
	}
	else
	{
		return 0;
	}
}
void visit(btree t)
{
	printf("%d ", t->data);
}
void paixu(btree t)
{
	if (t != NULL)
	{
		paixu(t->lchild);
		visit(t);
		paixu(t->rchild);
	}
}
void func(btree t, int index, int shu, int flag)
{
	btree p;
	if (flag == 1)
	{
		t->lchild = t->rchild = NULL;
	}
	if (shu > t->data)
	{
		if (t->rchild == NULL)
		{
			p = (btree)malloc(sizeof(BTnode));
			t->rchild = p;
			p->data = shu;
			p->lchild = p->rchild = NULL;
			index = index + 1;
			if (index == 8)
			{
				return;
			}
			func(st[0], index, st[index]->data, 0);
		}
		else
		{
			func(t->rchild, index, st[index]->data, 0);
		}
	}
	else if (shu <= t->data)
	{
		if (t->lchild == NULL)
		{
			p = (btree)malloc(sizeof(BTnode));
			t->lchild = p;
			p->data = shu;
			p->lchild = p->rchild = NULL;
			index = index + 1;
			if (index == 8)
			{
				return;
			}
			func(st[0], index, st[index]->data, 0);
		}
		else
		{
			func(t->lchild, index, st[index]->data, 0);
		}
	}
}
void main()
{
	btree p;
	int top = 0, i, find_dian = 0, delete_dian = 0;
	int data[8] = { 15,17,12,15,23,14,20,1 };
	for (i = 0;i < 8;i++)
	{
		p = (btree)malloc(sizeof(BTnode));
		st[top] = p;
		p->data = data[i];
		top = top + 1;
	}
	func(st[0], 1, st[1]->data, 1);
	paixu(st[0]);
	//find_dian = find(st[0], 24);
	//if (find_dian == 1)
	//{
	//	printf("find");
	//}
	//else if (find_dian == 0)
	//{
	//	printf("not find");
	//}													//查找值为k的节点


}