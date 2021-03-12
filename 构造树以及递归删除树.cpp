#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//构造树以及递归删除树

int k_num = 0;
int queue_shuzu[10] = { 0 };
int queue_shuzu_index = 0;
typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}BTnode, *btree;

void knumber_queue(btree t, int h, int k)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (h < k)
		{
			knumber_queue(t->lchild, h + 1, k);
			knumber_queue(t->rchild, h + 1, k);
		}
		else if (h == k)
		{
			k_num = k_num + 1;
			queue_shuzu[queue_shuzu_index] = k_num;
		}
	}
}
void knumber(btree t,int h,int k)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (h < k)
		{
			knumber(t->lchild, h + 1, k);
			knumber(t->rchild, h + 1, k);
		}
		else if (h == k)
		{
			k_num = k_num + 1;
		}										//后序序列打印
	}
}
int zero_degree(btree t)
{
	if (t == NULL)
	{
		return 0;
	}
	else if (t->lchild == NULL && t->rchild == NULL)
	{
		return 1 + zero_degree(t->lchild) + zero_degree(t->rchild);
	}
	else
	{
		return zero_degree(t->lchild) + zero_degree(t->rchild);
	}
}
int single_degree(btree t)
{
	if (t == NULL)
	{
		return 0;
	}
	else if ((t->lchild == NULL && t->rchild != NULL)||(t->lchild!=NULL&&t->rchild==NULL))
	{
		return 1 + single_degree(t->lchild) + single_degree(t->rchild);
	}
	else
	{
		return single_degree(t->lchild) + single_degree(t->rchild);
	}
}
int double_degree(btree t)
{
	if (t == NULL)
	{
		return 0;
	}
	else if (t->lchild != NULL && t->rchild != NULL)
	{
		return double_degree(t->lchild) + double_degree(t->rchild) + 1;
	}
	else
	{
		return double_degree(t->lchild) + double_degree(t->rchild);
	}
}
int point_and_depth(btree t, char x, int n)
{
	int l;
	if (t==NULL)
	{
		return 0;
	}
	else if (t->data == x)
	{
		return n;
	}
	else
	{
		l = point_and_depth(t->lchild, x, n + 1);
		if (l == 0)
		{
			return point_and_depth(t->rchild, x, n + 1);
		}
		else
		{
			return l;
		}
	}
}
int cnt_leaves(btree t)
{
	int left_leaves, right_leaves;
	if (t == NULL)
	{
		return 0;
	}
	else if(t->lchild==NULL&&t->rchild==NULL)
	{
		return 1;
	}
	else
	{
		left_leaves = cnt_leaves(t->lchild);
		right_leaves = cnt_leaves(t->rchild);
		return left_leaves + right_leaves;
	}
}
int cnt_point(btree t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return cnt_point(t->lchild) + cnt_point(t->rchild) + 1;
	}
}																		//计算二叉树中节点的个数
void visit(btree t)
{
	printf("%c", t->data);
}
void level_transfer(btree t)
{
	btree p, queue[10];
	int front = 0, rear = 0;
	rear = rear + 1;
	queue[rear] = t;
	while (rear > front)
	{
		p = queue[++front];
		printf("%c", p->data);
		if (p->lchild != NULL)
		{
			queue[++rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			queue[++rear] = p->rchild;
		}
	}
}																				//层次遍历
void qian_transfer(btree t)
{
	if (t != NULL)
	{
		visit(t);
		qian_transfer(t->lchild);
		qian_transfer(t->rchild);
	}
}
void zhong_transfer(btree t)
{
	if (t != NULL)
	{
		zhong_transfer(t->lchild);
		visit(t);
		zhong_transfer(t->rchild);
	}
}
void houxu_transfer(btree t)
{
	if (t != NULL)
	{
		houxu_transfer(t->lchild);
		houxu_transfer(t->rchild);
		visit(t);
	}
}
btree find_point(btree t,char x)
{
	btree p;
	if (t == NULL)
	{
		return NULL;
	}
	else if(t->data==x)
	{
		return t;
	}
	else
	{
		p = find_point(t->lchild, x);
		if (p != NULL)
		{
			return p;
		}
		else
		{
			return find_point(t->rchild, x);
		}
	}
}																//查找树中的某一个节点
int depth_tree(btree t)
{
	int left_depth, right_depth;
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		left_depth = depth_tree(t->lchild);
		right_depth = depth_tree(t->rchild);
		return ((left_depth > right_depth) ? (left_depth + 1) : (right_depth + 1));
	}
}																//计算树的深度
void delete_tree(btree t)
{
	if (t != NULL)
	{
		delete_tree(t->lchild);
		delete_tree(t->rchild);
		free(t);
	}
}																//递归删除一个树的节点
void main()
{
	btree b = NULL, p, st[21], R;
	char ch, shuzu[22] = { 'A','(','B','(','D',',','E','(','G',')',')',',','C','(','F','(',',','H',')',')',')' };
	int j = 0, flag, top = -1, depth = 0, cnt, cnt_leaf, find_point_depth, double_du, single_du, zero_du, k, i;
	p = NULL;
	ch = shuzu[0];
	while (1)
	{
		while (ch != '\0')
		{
			switch (ch)
			{
			case '(':
				st[++top] = p;
				flag = 1;
				break;
			case ')':
				top = top - 1;
				break;
			case ',':
				flag = 2;
				break;
			default:
				p = (btree)malloc(sizeof(BTnode));
				p->data = ch;
				p->lchild = NULL;
				p->rchild = NULL;
				if (b == NULL)
				{
					b = p;
					//printf("%c", p->data);
				}
				else if (flag == 1)
				{
					st[top]->lchild = p;
					//printf("%c", p->data);
				}
				else
				{
					st[top]->rchild = p;
					//printf("%c", p->data);
				}
			}
			j++;
			ch = shuzu[j];
		}
		if (ch == '\0')
		{
			break;
		}
	}

	printf("前序遍历\n");
	qian_transfer(st[0]);
	printf("\n");
	printf("中序遍历\n");
	zhong_transfer(st[0]);
	printf("\n");
	printf("后序遍历\n");
	houxu_transfer(st[0]);
	printf("\n");
	printf("层次遍历\n");
	level_transfer(st[0]);
	printf("\n");

	k = 1;
	knumber_queue(st[0], 1, k);
	printf("%d\n", queue_shuzu[queue_shuzu_index]);			//数组存放第k层节点的个数
	knumber(st[0], 1, k);										//统计第k层节点的个数
	printf("%d\n", k_num);
	zero_du = zero_degree(st[0]);
	printf("%d\n", zero_du);									//统计度为0的节点的个数
	single_du = single_degree(st[0]);
	printf("%d\n", single_du);								//统计度为1的节点的个数
	double_du = double_degree(st[0]);
	printf("%d\n", double_du);								//统计度为2的节点的个数
	find_point_depth = point_and_depth(st[0], 'H', 1);			//查找对应节点（如‘H’）的深度
	printf("%d\n", find_point_depth);
	cnt_leaf = cnt_leaves(st[0]);								//计算二叉树中叶子节点的个数
	printf("%d\n", cnt_leaf);
	cnt = cnt_point(st[0]);										//计算二叉树中节点的个数
	printf("%d\n", cnt);
	R = find_point(st[0], 'G');									//查找'G'的节点并输出
	printf("%c\n", R->data);
	depth = depth_tree(st[0]);									//计算树的深度
	printf("%d\n", depth);
	delete_tree(st[0]);											//删除树的节点的调用函数
	st[0] = NULL;
}