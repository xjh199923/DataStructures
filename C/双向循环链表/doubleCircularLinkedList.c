#include <stdio.h>
#include <stdlib.h>
struct doubleCircularLinkedList
{
	struct doubleCircularLinkedList* prior;//结点的前驱指针
	int data;//结点的数据项
	struct doubleCircularLinkedList* next;//结点的后继指针
};
//创建一个带表头的双向循环链表
struct doubleCircularLinkedList* createList()
{
	//创建一个头结点，数据差异化当作表头
	struct doubleCircularLinkedList* headNode = (struct doubleCircularLinkedList*)malloc(sizeof(struct doubleCircularLinkedList));
	//循环链表，所以初始化头指针，尾指针都是指向自身的，data数据域不做初始化
	headNode->prior = headNode;//头结点指向自身
	headNode->next = headNode;//尾结点指向自身
	return headNode;
}
//创建一个新的结点，为插入准备
struct doubleCircularLinkedList* createNode(int data)
{
	//动态申请内存malloc+free c语言的特点
	struct doubleCircularLinkedList* newNode = (struct doubleCircularLinkedList*)malloc(sizeof(struct doubleCircularLinkedList));
	//创建结点过程相当于初始化过程
	newNode->data = data;//传入data数值初始化数据域
	newNode->prior = NULL;//初始化头结点为null
	newNode->next = NULL;//初始化尾结点为null
	return newNode;
}
//通过表头插入
void insertNodeByHead(struct doubleCircularLinkedList* headNode,int data)
{
	//创建一个新的结点，调用创建新结点的函数
	struct doubleCircularLinkedList* newNode = createNode(data);
	//修改四个指针变量
	newNode->prior = headNode;
	newNode->next = headNode->next;
	headNode->next->prior=newNode;
	headNode->next = newNode;
}
//通过表尾部插入
void insertNodeBynext(struct doubleCircularLinkedList* headNode,int data)
{
	struct doubleCircularLinkedList* newNode = createNode(data);
	//首先找到最后一个结点的位置
	struct doubleCircularLinkedList* lastNode = headNode;
	while(lastNode->next != headNode)
	{
		lastNode = lastNode->next;
	}
	//找到之后调整四个指针
	headNode->prior = newNode;
	newNode->next = headNode;
	lastNode->next = newNode;
	newNode->prior = lastNode;
}
//指定位置删除结点
void SpecifyLocationToDelete(struct doubleCircularLinkedList* headNode,int posData)
{
	struct doubleCircularLinkedList* posNode = headNode->next;//指定结点指针
	struct doubleCircularLinkedList* posNodeprior = headNode;//指定结点前一个结点的指针
	//找到指定位置
	while(posNode->data != posData)
	{
		posNodeprior = posNode;
		posNode = posNodeprior->next;
		//如果没有找到特殊处理
		if(posNode->next == headNode)
		{
			printf("不存在指定位置，无法删除！\n");
			return;
		}
	}
	posNodeprior->next = posNode->next;
	posNode->next->prior=posNodeprior;
	free(posNode);//删除之后，释放空间
}
//搜索指定元素
void searchSpecifiedElement(struct doubleCircularLinkedList* headNode,int posData)
{
	struct doubleCircularLinkedList* posNode = headNode->next;//指定结点指针
	struct doubleCircularLinkedList* posNodeprior = headNode;//指定结点前一个结点的指针
	//找到指定位置
	while(posNode->data != posData)
	{
		posNodeprior = posNode;
		posNode = posNodeprior->next;
		//如果没有找到特殊处理
		if(posNode == headNode)
		{
			printf("不存在元素！\n");
			return ;
		}
	}
	printf("该元素存在！\n");
}
//修改指定的元素
void modifySpecifiedElement(struct doubleCircularLinkedList* headNode,int posData,int elem)
{
	struct doubleCircularLinkedList* posNode = headNode->next;//指定结点指针
		struct doubleCircularLinkedList* posNodeprior = headNode;//指定结点前一个结点的指针
		//找到指定位置
		while(posNode->data != posData)
		{
			posNodeprior = posNode;
			posNode = posNodeprior->next;
			//如果没有找到特殊处理
			if(posNode->next == headNode)
			{
				printf("不存在元素！\n");
			}
		}
		posNode->data = elem;
		printf("修改成功！\n");
}
void printList(struct doubleCircularLinkedList* headNode)
{
	//从第二个结点开始打印，表头不含数据
	//也可以通过前指针进行打印，只需将next改为prior即可
	struct doubleCircularLinkedList* pMove = headNode->next;
	while(pMove != headNode)//如果pMove->next != headNode这样写，最后一个结点是不会打印的
	{
		printf("%d ",pMove->data);
		pMove = pMove->next;//移动指针
	}
	printf("\n");
}
void Menu()
{
	printf("+===========================================+\n");
	printf("|    1.表头插入元素     3.表尾插入元素          |\n");
	printf("+===========================================+\n");
	printf("|    3.删除指定元素     4.修改指定元素          |\n");
	printf("+===========================================+\n");
	printf("|    5.搜索指定元素     6.打印双向链表          |\n");
	printf("+===========================================+\n");
	printf("|    0.退出                                  |\n");
	printf("+===========================================+\n");
}
int main() 
{
	struct doubleCircularLinkedList* list = createList();
	insertNodeByHead(list,1);
	insertNodeByHead(list,2);
	insertNodeByHead(list,3);
	insertNodeBynext(list,4);
	Menu();
	int choose=1;
	while(choose){
		printf("请输入你的选择：\n");
		scanf("%d",&choose);
		int tmp,temp;
	switch (choose) {
		case 1:{
			printf("请输入您要插入的元素：");
			scanf("%d",&tmp);
			insertNodeByHead(list,tmp);
		}break;
		case 2:{
			printf("请输入您要插入的元素：");
			scanf("%d",&tmp);
			insertNodeBynext(list,tmp);
		}break;
		case 3:{
			printf("请输入您要删除的元素：");
			scanf("%d",&tmp);
			SpecifyLocationToDelete(list,tmp);
		}break;
		case 4:{
			printf("请输入您要修改的元素：");
			scanf("%d",&tmp);
			printf("请输入新的元素：");
			scanf("%d",&temp);
			modifySpecifiedElement(list,tmp,temp);
		}break;
		case 5:{
			printf("请输入您要搜索的元素：");
			scanf("%d",&tmp);
			searchSpecifiedElement(list,tmp);
		}break;
		case 6:{
			printList(list);
		}break;
		default:
			break;
		printf("\n");
		Menu();
	}
	printf("\n");
	Menu();
	}
	return 0;
}