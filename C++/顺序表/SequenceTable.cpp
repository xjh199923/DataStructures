/*****************************************/
//Seqlist.h
#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define MAX 10
typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	int sz;
}SeqList, *pSeqList;


//初始化 
void InitSeqList(pSeqList pSeq);
//打印
void PrintSeqList(pSeqList pSeq);
//尾部插入 
void PushBack(pSeqList pSeq, DataType d);
//尾部删除 
void PopBack(pSeqList pSeq);
//头部插入 
void PushFront(pSeqList pSeq, DataType d);
//头部删除 
void PopFront(pSeqList pSeq);
//查找指定元素 
int Find(pSeqList pSeq, DataType d);
//指定位置插入 
void Insert(pSeqList pSeq, int pos, DataType d);
//删除指定位置元素 
void Erase(pSeqList pSeq, int pos);
//删除指定元素 
void Remove(pSeqList pSeq, DataType d);
//删除所有的指定元素 
void RemoveAll(pSeqList pSeq, DataType d);
//返回顺序表的大小 
int Size(pSeqList pSeq);
//判断顺序表是否为空 
int Empty(pSeqList pSeq);
//冒泡排序 
void BubbleSort(pSeqList pSeq);
//选择排序 
void SelectSort(pSeqList pSeq);
//选择排序的优化 
void SelectSortOP(pSeqList pSeq);
//二分查找 
int BinarySearch(pSeqList pSeq, DataType d);
//二分查找递归写法 
int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d);

//初始化 
void InitSeqList(pSeqList pSeq)
{
	assert(pSeq);
	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}

//打印
void PrintSeqList(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}

//尾部插入 
void PushBack(pSeqList pSeq, DataType d)
{
	assert(pSeq);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满，无法插入元素!\n");
		return;
	}
	pSeq->data[pSeq->sz] = d;
	pSeq->sz++;
}

//尾部删除 
void PopBack(pSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无元素可删!\n");
		return;
	}
	pSeq->sz--;
}

//头部插入 
void PushFront(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满，无法插入元素！\n");
		return;
	}
	for (i = pSeq->sz-1; i >= 0 ; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = d;
	pSeq->sz++;
}

//头部删除 
void PopFront(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无元素可删!\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

//查找指定元素 
int Find(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无元素可查！\n");
		return -1;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}

//指定位置插入 
void Insert(pSeqList pSeq, int pos, DataType d)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满，无法插入元素！\n");
		return;
	}
	for (i = pSeq->sz-1; i >= pos; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[pos] = d;
	pSeq->sz++;
}

//删除指定位置元素 
void Erase(pSeqList pSeq, int pos)
{
	int i = 0;
	assert(pSeq && pos >= 0 && pos < pSeq->sz);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无元素可删!\n");
		return;
	}
	for (i = pos; i < pSeq->sz; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

//删除指定元素 
void Remove(pSeqList pSeq, DataType d)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无元素可删!\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
			break;
	}
	if (i == pSeq->sz)
	{
		printf("未找到该元素！\n");
	}
	for (j = i; j < pSeq->sz; j++)
	{
		pSeq->data[j] = pSeq->data[j + 1];
	}
	pSeq->sz--;
}

//删除所有的指定元素 
void RemoveAll(pSeqList pSeq, DataType d)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空，无元素可删!\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] != d)
		{
			pSeq->data[j] = pSeq->data[i];
			j++;
		}
	}
	pSeq->sz = j;
}

//返回顺序表的大小 
int Size(pSeqList pSeq)
{
	assert(pSeq);
	return pSeq->sz;
}

//判断顺序表是否为空 
int Empty(pSeqList pSeq)
{
	assert(pSeq);
	return pSeq->sz == 0;
}

//冒泡排序 
void BubbleSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz; i++)
	{
		flag = 0;
		for (j = 0; j < pSeq->sz - i - 1; j++)
		{
			if (pSeq->data[j] > pSeq->data[j + 1])
			{
				int tmp = pSeq->data[j];
				pSeq->data[j] = pSeq->data[j + 1];
				pSeq->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (0 == flag)
			return;
	}
}

void Swap(DataType *x, DataType *y)
{
	DataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//选择排序 
void SelectSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->sz-1; i++)
	{
		int tmp = 0;
		for (j = 1; j < pSeq->sz - i; j++)
		{
			if (pSeq->data[tmp] < pSeq->data[j])
			{
				tmp = j;
			}
		}
		if (tmp != pSeq->sz - 1 - i)
		{
			Swap(pSeq->data + tmp, pSeq->data + pSeq->sz - 1 - i);
		}
	}
}

//选择排序的优化 
void SelectSortOP(pSeqList pSeq)
{
	int i = 0;
	int start = 0;
	int end = pSeq->sz - 1;
	assert(pSeq);
	while (start < end)
	{
		int min = start;
		int max = start;
		for (i = start; i < end; i++)
		{
			if(pSeq->data[max] < pSeq->data[i])
			{
				max = i;
			}
			if (pSeq->data[min] > pSeq->data[i])
			{
				min = i;
			}
		}
		if (min != start)
		{
			Swap(pSeq->data + min, pSeq->data + start);
		}
		if (max == start)
		{
			max = min;
		}
		if (max != end)
		{
			Swap(pSeq->data + max, pSeq->data + end);
		}
		start++;
		end--;
	}
}

//二分查找
int BinarySearch(pSeqList pSeq, DataType d)
{
	assert(pSeq);
	int left = 0;
	int right = pSeq->sz - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (pSeq->data[mid] < d)
		{
			left = mid + 1;
		}
		else if (pSeq->data[mid] > d)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

//二分查找递归写法 
int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d)
{
	assert(pSeq);   
	int mid = left + (right - left) / 2;
	if (left > right)
	{
		return -1;
	}
	if (pSeq->data[mid] < d)
	{
		return BinarySearch_R(pSeq, mid + 1, right, d);
	}
	else if (pSeq->data[mid] > d)
	{
		return BinarySearch_R(pSeq, left, mid-1, d);
	}
	else
	{
		return mid;
	}
}


/*****************************************/
//test.c

#include "SeqList.h"

void TestPushBack()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
}

void TestPushFront()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
}

void TestFind()
{
	int temp = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	temp = Find(&seq, 3);
	if (temp == -1)
	{
		printf("未找到！\n");
	}
	else
	{
		printf("找到了，下标为%d\n", temp);
	}
}

int TestInsert()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	Insert(&seq, 2, 5);
	PrintSeqList(&seq);
}

void TestErase()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	Erase(&seq, 2);
	PrintSeqList(&seq);
}

void TestRemove()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	Remove(&seq, 3);
	PrintSeqList(&seq);
}

TestRemoveAll()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 2);
	PrintSeqList(&seq);
	RemoveAll(&seq, 2);
	PrintSeqList(&seq);
}
int TestSize()
{
	int count = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	count = Size(&seq);
	printf("顺序表的大小=%d\n", count);
}

void TestEmpty()
{
	int tmp;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	tmp = Empty(&seq);
	if (tmp == 1)
	{
		printf("顺序表为空！\n");
	}
	else
	{
		printf("顺序表不为空\n");
	}
}

void TestBubbleSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 6);
	PushBack(&seq, 7);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 2);
	PrintSeqList(&seq);
	BubbleSort(&seq);
	PrintSeqList(&seq);
}

void TestSelectSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 6);
	PushBack(&seq, 7);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 2);
	PrintSeqList(&seq);
	SelectSort(&seq);
	PrintSeqList(&seq);
}

void TestSelectSortOP()
{

	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 6);
	PushBack(&seq, 7);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 2);
	PrintSeqList(&seq);
	SelectSortOP(&seq);
	PrintSeqList(&seq);
}

void TestBinarySearch()
{
	int tmp = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 6);
	PushBack(&seq, 7);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 2);
	PrintSeqList(&seq);
	tmp = BinarySearch(&seq, 4);
	if (-1 == tmp)
	{
		printf("未找到该元素！\n");
	}
	else
	{
		printf("找到了，下标为： %d\n", tmp);
	}
}

void TestBinarySearch_R()
{
	int tmp = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 6);
	PushBack(&seq, 7);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 2);
	PrintSeqList(&seq);
	tmp = BinarySearch_R(&seq, 0, seq.sz-1, 3);
	if (-1 == tmp)
	{
		printf("未找到该元素！\n");
	}
	else
	{
		printf("找到了，下标为： %d\n", tmp);
	}
}
int main()
{
	//TestPushBack();
	//TestPushFront();
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	//TestRemoveAll();
	//TestSize(); 
	//TestEmpty();
	//TestBubbleSort();
	//TestSelectSort();
	//TestSelectSortOP();
	//TestBinarySearch();
	TestBinarySearch_R();
	system("pause");
	return 0;
}