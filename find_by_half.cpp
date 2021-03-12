#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

//find by half
int find_point(int a[], int start, int end, int k)
{
	int low, high, mid;
	low = start;
	high = end - 1;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (k == a[mid])
		{
			return mid;
		}
		else if (k < a[mid])
		{
			find_point(a, low, mid, k);
			printf("%d ", a[mid]);
		}
		else
		{
			low = mid + 1;
			find_point(a, low, end, k);
			printf("%d ", a[mid]);
		}
	}
}
void main()
{
	int data[20] = { 2,3,10,15,20,25,28,29,30,35,41 }, value = 0;
	value = find_point(&data, 0, 11, 20);
	//printf("%d", value);
	return;
}