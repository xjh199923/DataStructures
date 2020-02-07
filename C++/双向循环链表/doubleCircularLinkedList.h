#include <iostream>
using namespace std;
template<class T> 
class doubleCircularLinkedList;//声明一下双向循环链表，以免定义友元时报错
template <class T>
class doubleCircularLinkedListNode
{
	private:
		doubleCircularLinkedListNode<T> *prior;//双向结点前驱指针指向该结点的前驱结点
		T data;//储存结点数据
		doubleCircularLinkedListNode<T> *next;//双向结点的后驱指针指向该结点的后继结点
		//将双向循环链表类定义为结点的友元类
		friend  class doubleCircularLinkedList<T>;
	public:
		//结点的无参构造函数,将结点指针域初始化为NULL
		doubleCircularLinkedListNode()
		{
			prior = NULL;
			next = NULL;
		}
		//结点的有参构造函数，初始化指针域和数据域
		doubleCircularLinkedListNode(T _data,doubleCircularLinkedListNode<T> *_prior = NULL,doubleCircularLinkedListNode<T> *_next = NULL)
		{
			prior = _prior;//初始化前驱指针
			data = _data;//初始化数据域
			next = _next;//初始化后继指针
		}
		~doubleCircularLinkedListNode()
		{
			prior = NULL;
			next = NULL;
		}
};
template <class T>
class doubleCircularLinkedList
{
	private:
		doubleCircularLinkedListNode<T> *headNode;//双向循环链表的头指针
		int length;//双向循环链表的长度
	public:
		//双向循环链表的构造函数，链表产生新头结点
		doubleCircularLinkedList()
		{
			headNode = new doubleCircularLinkedListNode<T>();//链表产生头结点，带头结点的双向循环链表的实现
			//满足双向循环链表的头结点初始化，头结点的首指针和尾指针都指向自身
			headNode->prior = headNode;//头节点的首指针指向其本身
			headNode->next = headNode;//头节点的尾指针指向其本身
			length =0;//长度初始化为0
		}
		//双向循环链表的析构函数，链表删除头节点
		~doubleCircularLinkedList()
		{
			delete headNode;
		}
		//双向循环链表插入结点----头插法
		bool insertNodeByhead(T item);
		//双向循环链表插入结点----尾插法
		bool insertNodeBytail(T item);
		//在第i个结点插入T类型item
		bool insertNode(T item,int n);
		//寻找给定数值的结点
		bool findData(T item);
		//删除第i个结点的数据
		bool deleteData(int n);
		//获取双向循环链表长度
		int getLength();
		//修改指定位置元素，被修改元素以引用返回
		bool changeListElements(int n,T item,T &x);
		//打印双向循环链表
		void printLinkedlist();
};
template<class T>
int doubleCircularLinkedList<T>::getLength()
{
	doubleCircularLinkedListNode<T> *pMove = headNode->next;  //设置游标指针
	int length=0;
	//遍历链表，计算结点数
	while(pMove != headNode)
	{
		pMove = pMove->next;  //游标指针后移
		length++;       //计算length
	}
	return length;
}
template<class T>
bool doubleCircularLinkedList<T>::insertNode(T item,int n)
{
	if(n<1){
		cout<<"输入的非有效位置！"<<endl;
		return false;
	}
	doubleCircularLinkedListNode<T>* pMove = headNode;//创建一个新的指针，设置为游标指针
	//首先找到插入位置
	for(int i=1;i<n;i++)
	{
		pMove = pMove->next;
		if(pMove == NULL && i<=n)
		{
			cout<<"插入位置无效！"<<endl;
			return false;
		}
	}
	//创建一个新的结点
	doubleCircularLinkedListNode<T>* newNode = new doubleCircularLinkedListNode<T>(item);
	if (newNode == NULL){
		cout << "内存分配失败，新结点无法创建" << endl;
		return false;
	}
	//插入新的结点
	newNode->next = pMove->next;   
	if (pMove->next != headNode)
	{
		pMove->next->prior = newNode;
	}
	newNode->prior = pMove;
	pMove->next = newNode;
	return true;
}
template<class T>
bool doubleCircularLinkedList<T>::insertNodeByhead(T item)
{
	//创建一个新的结点
	doubleCircularLinkedListNode<T>* newNode = new doubleCircularLinkedListNode<T>(item);
	if (newNode == NULL){
		cout << "内存分配失败，新结点无法创建" << endl;
		return false;
	}
	else{
		newNode->prior = headNode;
		newNode->next = headNode->next;
		headNode->next->prior=newNode;
		headNode->next = newNode;
		return true;
	}
}
template<class T>
bool doubleCircularLinkedList<T>::insertNodeBytail(T item)
{
	//创建一个新的结点
	doubleCircularLinkedListNode<T>* newNode = new doubleCircularLinkedListNode<T>(item);
	if (newNode == NULL){
		cout << "内存分配失败，新结点无法创建" << endl;
		return false;
	}
	//首先找到最后一个结点
	doubleCircularLinkedListNode<T>* lastNode = headNode;
	while(lastNode->next != headNode)
	{
		lastNode = lastNode->next;//没找到就一直循环
	}
	//找到之后调整四个指针
	headNode->prior = newNode;
	newNode->next = headNode;
	lastNode->next = newNode;
	newNode->prior = lastNode;
	return true;
}
template<class T>
void doubleCircularLinkedList<T>::printLinkedlist()
{
	//从第二个结点开始打印，表头不含数据
	doubleCircularLinkedListNode<T>* pMove = headNode->next;
	while(pMove !=headNode)//如果pMove->next != headNode这样写，最后一个结点是不会打印的
	{
		cout<<pMove->data<<" ";
		pMove = pMove->next;//移动指针
	}
	cout<<endl;
}
template<class T>
bool doubleCircularLinkedList<T>::findData(T item)
{
	doubleCircularLinkedListNode<T> *pMove = headNode->next; //设置游标指针
	doubleCircularLinkedListNode<T> *pMoveprior = headNode;//指定结点前一个结点的指针
	//找到指定位置
	while(pMove->data != item)
	{
		pMoveprior = pMove;
		pMove = pMoveprior->next;
		//如果没有找到特殊处理
		if(pMove == headNode)
		{
			return false;
		}
	}
	return true;
}
template<class T>
bool doubleCircularLinkedList<T>::deleteData(int n)
{
	if (n<1||n>getLength())
	{
		cout << "输入非有效位置" << endl;
		return false;
	}
	doubleCircularLinkedListNode<T> * pMove = headNode;//设置游标指针
	doubleCircularLinkedListNode<T> * pDelete;             
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
bool doubleCircularLinkedList<T>::changeListElements(int n,T item,T &x)
{
	if (n<1||n>getLength())
	{
		cout << "输入非有效位置" << endl;
		return false;
	}
	doubleCircularLinkedListNode<T> *pMove = headNode->next;  //设置游标指针
	for(int i=1;i<n;i++)//找到指定位置1
	{
		pMove = pMove->next;
	}
	x = pMove->data;
	pMove->data = item;
	return true;
}
