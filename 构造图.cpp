#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

//¹¹ÔìÍ¼

int visited[20] = { 0 }, graph_data[20][20];
int data_queue[30] = { 1,3,4,0,2,3,1,3,4,0,1,2,4,0,2,3 };
int data_queue_index = 0, graph_data_index = 0, graph_data_index_find = 0;

typedef struct anode
{
	struct anode *next;
	int info;									//adjvex
}arcnode;
typedef struct bnode
{
	int data;									//vertex
	arcnode *first;
}brcnode;
typedef struct
{
	brcnode adjlist[20];
	int n, e;
}CV, *graph;
typedef struct
{
	int point_number;
	int parent;
}Queue;


void shortpath(graph g, int start, int end)
{
	arcnode *p;
	int w, i;
	Queue qu[20];
	int front = -1, rear = -1;
	rear += 1;
	qu[rear].point_number = start;
	qu[rear].parent = -1;
	visited[start] = 1;
	while (front != rear)
	{
		front += 1;
		w = qu[front].point_number;
		if (w == end)
		{
			i = front;
			while (qu[i].parent != -1)
			{
				printf("%d ", qu[i].point_number);
				i = qu[i].parent;
			}
			printf("%d ", qu[i].point_number);
			break;
		}
		p = g->adjlist[w].first;
		while (p != NULL)
		{
			if (visited[p->info] == 0)
			{
				visited[p->info] = 1;
				rear += 1;
				qu[rear].point_number = p->info;
				qu[rear].parent = front;
			}
			p = p->next;
		}
	}
}
void existpath(graph g, int start, int end, int has)
{
	arcnode *p;
	int w;
	visited[start] = 1;
	if (start == end)
	{
		printf("find path!");
		printf("\n");
		graph_data_index_find += 1;
		graph_data_index = 0;
		//return;
	}
	p = g->adjlist[start].first;
	while (p != NULL)
	{
		w = p->info;
		if (visited[w] == 0)
		{
			graph_data[graph_data_index_find][graph_data_index] = w;
			graph_data_index += 1;
			existpath(g, w, end, has);
		}
		p = p->next;
	}
	visited[start] = 0;
}
void create_head(graph g, int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		g->adjlist[i].data = i;
		g->adjlist[i].first = NULL;
	}
}
void create_another(graph g, int n, int shunxu)
{
	int k, point;
	arcnode *p, *q;
	for (k = 0;k < n;k++)
	{
		//scanf("%d\n", &point);
		point = data_queue[data_queue_index];
		data_queue_index = data_queue_index + 1;
		p = (arcnode *)malloc(sizeof(arcnode));
		p->info = point;
		p->next = NULL;
		if ((g->adjlist[shunxu].first) == NULL)
		{
			g->adjlist[shunxu].first = p;
		}
		else
		{
			q = g->adjlist[shunxu].first;
			while (q->next)
			{
				q = q->next;
			}
			q->next = p;
		}
	}
}
void DFS(graph g, int v)
{
	arcnode *p;
	int w;
	visited[v] = 1;
	printf("%d ", v);
	p = g->adjlist[v].first;
	while (p != NULL)
	{
		w = p->info;
		if (visited[w] == 0)
		{
			DFS(g, w);
		}
		p = p->next;
	}
}
void BFS(graph g, int v)
{
	arcnode *p;
	int w;
	int queue[20], front = 0, rear = 0;
	visited[v] = 1;
	printf("%d ", v);
	rear = rear + 1;
	queue[rear] = v;
	while (front != rear)
	{
		front = front + 1;
		w = queue[front];
		p = g->adjlist[w].first;
		while (p != NULL)
		{
			if (visited[p->info] == 0)
			{
				printf("%d ", p->info);
				visited[p->info] = 1;
				rear = rear + 1;
				queue[rear] = p->info;
			}
			p = p->next;
		}
	}
}
void main()
{
	int j, i, queue_ha[5] = { 3,3,3,4,3 }, data[20] = { 0 };
	graph g;
	g = (graph)malloc(sizeof(CV));
	create_head(g, 5);
	for (j = 0;j < 5;j++)
	{
		create_another(g, queue_ha[j], j);
	}

	//DFS(g, 2);																	//deep transfer	
	//BFS(g, 2);																	//extent transfer

	//for (i = 0;i < 20;i++)
	//{
	//	for (j = 0;j < 20;j++)
	//	{
	//		graph_data[i][j] = 0;
	//	}
	//}
	//existpath(g, 2, 4, 0);														//find path
	//for (i = 0;i < graph_data_index_find;i++)
	//{
	//	for (j = 0;j < 20;j++)
	//	{
	//		printf("%d ", graph_data[i][j]);
	//	}
	//	printf("\n");
	//}
	//shortpath(g, 2, 4);														//find shortest path and print it

}