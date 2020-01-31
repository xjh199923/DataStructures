#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int basesize = 30;
template <class T>
class Stack{
	private:
		T* elements;//存放栈中元素的数组
		int top;//栈顶元素的指针
		int maxSize;//栈的最大容纳元素个数
		void overflowProcess();//栈的溢出处理操作
	public:
		Stack(int size);//构造函数
		Stack();//无参构造函数
		~Stack(){delete []elements;}//析构函数，释放栈的空间
		
		void Push(const T& x);//元素x入栈
		
		bool Pop(T& x);//栈顶元素出栈
		
		bool isFull();//判满函数
		
		bool isEmpty();//判空函数
		
		int getMaxsize()//得到栈的最大体积
		{return maxSize;}
		
		T getTopelements();//得到栈顶元素
		
		int getTop()//得到栈的top指针的地址，因为是采用数组类型储存，因此top指针可以利用数组的下标得到
		{return top;}
		
		void print();//展示各种类型的数据，控制格式
};
template<class T> Stack<T>::Stack()   
{   
	this ->maxSize = 10;
	this ->top = -1;
	this ->elements = new T[this ->maxSize];
	if(elements==NULL){
			cout<<"动态分配错误！"<<endl;
		}
}
template <class T>
inline Stack<T>::Stack(int size)
{
	this ->maxSize = size;
		this ->top = -1;
		this ->elements = new T[this ->maxSize];
		if(elements==NULL){
				cout<<"动态分配错误！"<<endl;
			}
}
template <class T>
inline void Stack<T>::overflowProcess()
{
	this->maxSize = int (2*this->maxSize);
	T * temp = new T [this->maxSize];
	for(int i = 0; i <= this->top ; i++){
		temp[i] = this->elements[i];
	}
	delete []elements;       //释放原来的空间
	this ->elements = temp;
}
//如果栈isFull(),则进行溢出处理，否则将其插入到栈顶
template <class T>
inline void Stack<T>::Push(const T &x)
{
	if(isFull()==true){
		cout<<"The stack is full , so need to enlarge 2x!"<<endl;
		overflowProcess();//溢出处理，调整空间大小
		elements[++top]=x;
	}
	
	else{
		elements[++top]=x;//将x入栈
	}
}
//判断栈是否满，如果满返回true,未满返回false
template <class T>
inline bool Stack<T>::isFull()
{
	if(this->getTop()<this->getMaxsize()-1){
		return false;
	}
	else{
		return true;
	}
}
//判断栈是否空，如果满返回true,未满返回false
template <class T>
inline bool Stack<T>::isEmpty()
{
	if(this->getTop()==-1){
		return true;
	}
	else{
		return false;
	}
}
//栈顶元素出栈，如果栈为空返回false;若栈不为空，栈顶元素出栈，top指针减一
template <class T>
inline bool Stack<T>::Pop(T& x)
{
	if(isEmpty())return false;
	
	else{
		
		x=getTopelements();
		
		top--;
		return true;
	}
}
template <class T>
inline void Stack<T>::print()
{
	if(isEmpty()){
		
		cout<<"This Stack is empty!"<<endl;
	}
	cout<<"栈的元素为："<<endl;
	for(int i=0;i<getTop();i++)
	{
		cout<<"["<<elements[i]<<"]<-";
	}	
	cout<<"["<<elements[getTop()]<<"]"<<endl;
		
}
template <class T>
inline T Stack<T>::getTopelements()
{
		return elements[getTop()];
}
