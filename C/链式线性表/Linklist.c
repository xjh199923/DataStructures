#include <stdio.h>
#include <stdlib.h>

typedef struct Linklist{
	int  elem;//代表数据域
	struct Linklist *next;//代表指针域，指向直接后继元素
}Linklist; //link为节点名，每个节点都是一个 link 结构体
Linklist * initLinklist();
//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
Linklist * insertElem(Linklist * p,int elem,int add);
//删除结点的函数，p代表操作链表，add代表删除节点的位置
Linklist * delElem(Linklist * p,int add);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(Linklist * p,int elem);
//更新结点的函数，newElem为新的数据域的值
Linklist *updateElem(Linklist * p,int add,int newElem);
void display(Linklist *p);

int main() {
	//初始化链表（1，2，3，4）
	printf("初始化链表为：\n");
	Linklist *p=initLinklist();
	display(p);
  
	printf("在第4的位置插入元素5：\n");
	p=insertElem(p, 5, 4);
	display(p);
  
	printf("删除元素3:\n");
	p=delElem(p, 3);
	display(p);
  
	printf("查找元素2的位置为：\n");
	int address=selectElem(p, 2);
	if (address==-1) {
		printf("没有该元素");
	}else{
		printf("元素2的位置为：%d\n",address);
	}
	printf("更改第3的位置上的数据为7:\n");
	p=updateElem(p, 3, 7);
	display(p);
  
	return 0;
}

Linklist * initLinklist(){
	Linklist * p=(Linklist*)malloc(sizeof(Linklist));//创建一个头结点
	Linklist * temp=p;//声明一个指针指向头结点，用于遍历链表
	//生成链表
	for (int i=1; i<5; i++) {
		Linklist *a=(Linklist*)malloc(sizeof(Linklist));
		a->elem=i;
		a->next=NULL;
		temp->next=a;
		temp=temp->next;
	}
	return p;
}
Linklist * insertElem(Linklist * p,int elem,int add){
	Linklist * temp=p;//创建临时结点temp
	//首先找到要插入位置的上一个结点
	for (int i=1; i<add; i++) {
		if (temp==NULL) {
			printf("插入位置无效\n");
			return p;
		}
		temp=temp->next;
	}
	//创建插入结点c
	Linklist * c=(Linklist*)malloc(sizeof(Linklist));
	c->elem=elem;
	//向链表中插入结点
	c->next=temp->next;
	temp->next=c;
	return  p;
}

Linklist * delElem(Linklist * p,int add){
	Linklist * temp=p;
	//遍历到被删除结点的上一个结点
	for (int i=1; i<add; i++) {
		temp=temp->next;
	}
	Linklist * del=temp->next;//单独设置一个指针指向被删除结点，以防丢失
	temp->next=temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
	free(del);//手动释放该结点，防止内存泄漏
	return p;
}
int selectElem(Linklist * p,int elem){
	Linklist * t=p;
	int i=1;
	while (t->next) {
		t=t->next;
		if (t->elem==elem) {
			return i;
		}
		i++;
	}
	return -1;
}
Linklist *updateElem(Linklist * p,int add,int newElem){
	Linklist * temp=p;
	temp=temp->next;//tamp指向首元结点
	//temp指向被删除结点
	for (int i=1; i<add; i++) {
		temp=temp->next;
	}
	temp->elem=newElem;
	return p;
}
void display(Linklist *p){
	Linklist* temp=p;//将temp指针重新指向头结点
	//只要temp指针指向的结点的next不是Null，就执行输出语句。
	while (temp->next) {
		temp=temp->next;
		printf("%d ",temp->elem);
	}
	printf("\n");
}