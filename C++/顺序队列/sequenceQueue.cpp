/*
 Created by xjh on 2019/10/7.
用到了vector容器类
*/
#include <iostream>
using namespace std;
#include <iomanip>
#include <vector>
const int k=30;
template <class T>
class sequenceQueue 
{
	private:
		vector<T> data;
		int head;
		int tail;
		int size;
	public:
	sequenceQueue() {
		data.resize(k);
		head = -1;
		tail = -1;
		size = k;
	}
	bool setsize(int k);
	bool enQueue(const T& value); 	
	bool deQueue(T& x);	
	T getFront() ;//取队列头部元素	
	T getRear();//取队列位尾部元素
	bool isEmpty();//判断是否为空	
	bool isFull();//判断是否为满
};
template <class T>
inline bool sequenceQueue<T>::setsize(int n)
{
	data.resize(n);
	this->size=n;
} 
/** Insert an element into the circular queue. Return true if the operation is successful. */
template <class T>
inline bool sequenceQueue<T>::enQueue(const T& value) {
		if (isFull()) {
			return false;
		}
		if (isEmpty()) {
			head = 0;
		}
		tail = (tail + 1) % size;
		data[tail] = value;
		return true;
}
/** Delete an element from the circular queue. Return true if the operation is successful. */
template <class T>
inline bool sequenceQueue<T>::deQueue(T& x) 
{
	x=data[head];
	if (isEmpty()) {
		return false;
	}
	if (head == tail) {
		head = -1;
		tail = -1;
		return true;
	}
	head = (head + 1) % size;
	return true;
}
/** Get the front item from the queue. */
template <class T>
inline T sequenceQueue<T>::getFront() 
{
	if (isEmpty()) {
		return -1;
	}
	return data[head];
}
/** Get the last item from the queue. */
template <class T>
inline T sequenceQueue<T>::getRear() 
{
		if (isEmpty()) {
			return -1;
		}
		return data[tail];
}
/** Checks whether the circular queue is empty or not. */
template <class T>
inline bool sequenceQueue<T>::isEmpty() 
{
	return head == -1;
}
/** Checks whether the circular queue is full or not. */
template <class T>
inline bool sequenceQueue<T>::isFull() 
{
	return ((tail + 1) % size) == head;
}

int main()
{
	sequenceQueue<int> queve;
		int temp=0,x;
		int n;
		cin>>n;
		int i=1,j,s=0,k=0,t=0,u;
		queve.enQueue(i);queve.enQueue(i);
		for(i=1;i<=n;i++)
		{
			cout<<endl;
			for (j = 1; j<=n - i ; j++)
			{
				cout<<setw(3)<<" ";
			}
			queve.enQueue(k);
			for(j=1;j<=i+2;j++)
			{
				queve.deQueue(t);
				u=s+t;
				queve.enQueue(u);
				s=t;
				if(j!=i+2){
					cout<<setw(6)<<s;
				}
			}
		}
		return 0;
}
