#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>


//采用顺序表构造队(一维数组)

typedef struct
{
	char data[20];
	int front, rear;
} StType;
void main()
{
	int i;
	char shuzu[20] = { "hellohello" };
	StType st;
	st.front = st.rear = -1;
	for (i = 0;i < 3;i++)
	{
		st.data[++(st.rear)] = shuzu[i];
	}
	for (i = 0;i <3;i++)
	{
		printf("%c", st.data[++(st.front)]);
	}

}