#include <iostream>
using namespace std;
template <class T>
struct chainStackNode
{
	T data;//链式栈储存结点的数据
	chainStackNode<T> *next;//链式栈指向下一结点的指针
};
template <class T>
class chainStack
{
	private:
		chainStackNode<T> *top;//将链式栈的头部指针封装为私有成员
	public:
		chainStack();//链式栈的构造函数--初始化栈
		~chainStack();//析构函数
		bool Push(T newData);//栈的基本操作--进栈
		bool Pop(T &x);//出栈，以引用的方式返回出栈元素
		bool getTop(T &x);//以引用的方式返回栈顶元素
		bool isEmpty();//判断栈是否为空
		void printChainStackData();//打印链式栈的数据
};
template <class T>
inline chainStack<T>::chainStack()
{
	top = new chainStackNode<T>;//创建一个新的结点
	top->next = NULL;//将top的next指针指向空
}
template <class T>
inline chainStack<T>::~chainStack()
{
	delete []top;//释放top指针的空间，析构函数的作用-->回收空间
}
template <class T>
inline bool chainStack<T>::Push(T newData)
{
	chainStackNode<T> *newNode = new chainStackNode<T>;
	if(!newNode){
		cout<<"分配内存失败！"<<endl;
		return false;
	}
	newNode->data = newData;//修改指针，添加元素
	newNode->next = top->next;
	top->next = newNode;
	return true;
}
template <class T>
inline bool chainStack<T>::Pop(T &x)
{
	chainStackNode<T> *temporaryNode;//创建一个临时指针指向删除结点
	if(isEmpty() == true){
		cout<<"该栈为空！"<<endl;
		return false;
	}
	else
	{
		temporaryNode = top->next;
		x = temporaryNode->data;//以引用返回
		top->next = temporaryNode->next;
		delete temporaryNode;//释放空间
		return true;
	}
}
template <class T>
inline bool chainStack<T>::isEmpty()
{
	if(top->next == NULL){//top指针的下一结点是否为空，以此来判断是否为空
		return true;
	}
	else{
		return false;
	}
}
template <class T>
inline  bool chainStack<T>::getTop(T &x)
{
	if(isEmpty() == true){
		return false;
	}
	else{
		x = top->next->data;
		return true;
	}
}
template <class T>
inline  void chainStack<T>::printChainStackData()
{
	chainStackNode<T> *pMove;
	pMove = top->next;
	while(pMove->next != NULL){
		cout<<"["<<pMove->data<<"]->";
		pMove = pMove->next;
	}
	cout<<"["<<pMove->data<<"]"<<endl;
}
