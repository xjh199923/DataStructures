#include <stdio.h>
#include <stdlib.h>
//链表中的节点结构
typedef struct QNode{
	int data;
	struct QNode * next;
}QNode;
//创建链式队列的函数
QNode * initQueue(){
	//创建一个头节点
	QNode * queue=(QNode*)malloc(sizeof(QNode));
	//对头节点进行初始化
	queue->next=NULL;
	return queue;
}
QNode* enQueue(QNode * rear,int data){
	QNode * enElem=(QNode*)malloc(sizeof(QNode));
	enElem->data=data;
	enElem->next=NULL;
	//使用尾插法向链队列中添加数据元素
	rear->next=enElem;
	rear=enElem;
	return rear;
}
QNode* DeQueue(QNode * top,QNode * rear){
	if (top->next==NULL) {
		printf("\n队列为空");
		return rear;
	}
	QNode * p=top->next;
	printf("出队的元素是：%d \n",p->data);
	top->next=p->next;
	if (rear==p) {
		rear=top;
	}
	free(p);
	return rear;
}
//队列的长度
int QueueLength(QNode * top)
{
	int length=0;
	QNode * pMove = top;
	if(pMove->next==NULL){//头指针指向空，长度为0
		return length;
	}
	while (pMove->next !=NULL) {//头指针不为空，移动指针计算长度
		pMove = pMove->next;
		length++;
	}
	return length;
}
void printQueue(QNode * top)
{
	QNode * pMove = top->next;
	if(pMove->next==NULL){
		printf("该队列为空！\n");
	}
	while (pMove!=NULL) {
		printf("%d ",pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
int main() {
	QNode * queue,*top,*rear;
	queue=top=rear=initQueue();//创建头结点
	//向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
	for(int i=0;i<10;i++)
	{
		rear = enQueue(rear, i+1);
	}
	printQueue(top);
	printf("队列的长度为：%d\n",QueueLength(top));
	//入队完成，所有数据元素开始出队列
	rear=DeQueue(top, rear);
	rear=DeQueue(top, rear);
	return 0;
}