#include <iostream>
using namespace std;
template<class T> 
class doubleLinkedList;//声明一下双向链表，以免定义友元时报错
template <class T>
class doubleLinkedListNode
{
	private:
		doubleLinkedListNode<T> *prior;//双向结点前驱指针指向该结点的前驱结点
		T data;//储存结点数据
		doubleLinkedListNode<T> *next;//双向结点的后驱指针指向该结点的后继结点
		//将双向链表类定义为结点的友元类
		friend  class doubleLinkedList<T>;
	public:
		//结点的无参构造函数,将结点指针域初始化为NULL
		doubleLinkedListNode()
		{
			prior = NULL;
			next = NULL;
		}
		//结点的有参构造函数，初始化指针域和数据域
		doubleLinkedListNode(T _data,doubleLinkedListNode<T> *_prior = NULL,doubleLinkedListNode<T> *_next = NULL)
		{
			prior = _prior;//初始化前驱指针
			data = _data;//初始化数据域
			next = _next;//初始化后继指针
		}
		~doubleLinkedListNode()
		{
			prior = NULL;
			next = NULL;
		}
};
template <class T>
class doubleLinkedList
{
	private:
		doubleLinkedListNode<T> *head;//双向链表的头指针
		int length;//双向链表的长度
	public:
		//双向链表的构造函数，链表产生新头结点
		doubleLinkedList()
		{
			head = new doubleLinkedListNode<T>();//链表产生新头结点
			length = 0;
		}
		//双向链表的构造函数，链表产生新头结点
		doubleLinkedList(doubleLinkedListNode<T> *note)
		{
			head = note;
			length = 0;
		}
		//双向链表的析构函数，链表删除头节点
		~doubleLinkedList()
		{
			delete head;
		}
		//双链表插入结点----头插法
		bool insertNodeByhead(T item);
		//双向链表插入结点----尾插法
		bool insertNodeBytail(T item);
		//在第i个结点插入T类型item
		bool insertNode(T item,int n);
		//寻找给定数值的结点
		bool findData(T item);
		//删除第i个结点的数据
		bool deleteData(int n);
		//获取双向链表长度
		int getLength();
		//修改指定位置元素，被修改元素以引用返回
		bool changeListElements(int n,T item,T &x);
		//打印双向链表
		void printLinkedlist();
};
template<class T>
int doubleLinkedList<T>::getLength()
{
	doubleLinkedListNode<T> *pMove = head->next;  //设置游标指针
	int length=0;
	//遍历链表，计算结点数
	while(pMove!=NULL)
	{
		pMove = pMove->next;  //游标指针后移
		length++;       //计算length
	}
	return length;
}
template<class T>
bool doubleLinkedList<T>::insertNode(T item,int n)
{
	if(n<1){
		cout<<"输入的非有效位置！"<<endl;
		return false;
	}
	doubleLinkedListNode<T>* pMove = head;//创建一个新的指针，设置为游标指针
	//首先找到插入位置
	for(int i=1;i<n;i++)
	{
		pMove = pMove->next;
		if(pMove == NULL&& i<=n)
		{
			cout<<"插入位置无效！"<<endl;
			return false;
		}
	}
	//创建一个新的结点
	doubleLinkedListNode<T>* newNode = new doubleLinkedListNode<T>(item);
	if (newNode == NULL){
		cout << "内存分配失败，新结点无法创建" << endl;
		return false;
	}
	//插入新的结点
	newNode->next = pMove->next;   
	if (pMove->next != NULL)
	{
		pMove->next->prior = newNode;
	}
	newNode->prior = pMove;
	pMove->next = newNode;
	return true;
}
template<class T>
bool doubleLinkedList<T>::insertNodeByhead(T item)
{
	//创建一个新的结点
	doubleLinkedListNode<T>* newNode = new doubleLinkedListNode<T>(item);
	if (newNode == NULL){
		cout << "内存分配失败，新结点无法创建" << endl;
		return false;
	}
	//分两种情况，head的next是否为NULL,然后处理四个指针
	if(head->next == NULL)
	{
		head->next = newNode;
		newNode->prior = head;
		return true;
	}
	else{
		newNode->next = head->next;
		head->next->prior = newNode;
		newNode->prior = head;
		head->next = newNode;
		return true;
	}
}
template<class T>
bool doubleLinkedList<T>::insertNodeBytail(T item)
{
	//创建一个新的结点
	doubleLinkedListNode<T>* newNode = new doubleLinkedListNode<T>(item);
	if (newNode == NULL){
		cout << "内存分配失败，新结点无法创建" << endl;
		return false;
	}
	//首先找到最后一个结点
	doubleLinkedListNode<T>* lastNode = head;
	while(lastNode->next != NULL)
	{
		lastNode = lastNode->next;//没找到就一直循环
	}
	//找到调整指针
	lastNode->next = newNode;
	newNode->prior = lastNode;
	return true;
}
template<class T>
void doubleLinkedList<T>::printLinkedlist()
{
	//从第二个结点开始打印，表头不含数据
	doubleLinkedListNode<T>* pMove = head->next;
	while(pMove)
	{
		cout<<pMove->data<<" ";
		pMove = pMove->next;//移动指针
	}
	cout<<endl;
}
template<class T>
bool doubleLinkedList<T>::findData(T item)
{
	doubleLinkedListNode<T> *pMove = head->next;  //设置游标指针
	if(pMove == NULL)//链表为空
	{
		return false;
	}
	while(pMove)//遍历链表
	{
		if(pMove->data == item){
			return true;
		}
		pMove = pMove->next;
	}
	return false;
}
template<class T>
bool doubleLinkedList<T>::deleteData(int n)
{
	if (n<1||n>getLength())
	{
		cout << "输入非有效位置" << endl;
		return false;
	}
	doubleLinkedListNode<T> * pMove = head;//设置游标指针
	doubleLinkedListNode<T> * pDelete;             
	//查找删除结点的位置
	for (int i = 1; i <= n; i++)
	{
		pMove = pMove->next;                                         //游标指针后移
	}
	//删除结点
	pDelete = pMove;      
	pMove->prior->next = pDelete->next;
	pMove->next->prior = pDelete->prior;
	delete pDelete;//释放空间
	return true;
}
template<class T>
bool doubleLinkedList<T>::changeListElements(int n,T item,T &x)
{
	if (n<1||n>getLength())
	{
		cout << "输入非有效位置" << endl;
		return false;
	}
	doubleLinkedListNode<T> *pMove = head->next;  //设置游标指针
	for(int i=1;i<n;i++)//找到指定位置1
	{
		pMove = pMove->next;
	}
	x = pMove->data;
	pMove->data = item;
	return true;
}
