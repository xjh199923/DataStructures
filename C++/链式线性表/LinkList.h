/*
Perform some basic operations on the linear table of the chained storage structure. mainly includes:
(1) Insert: The operation mode is to insert before the specified element, insert after the specified element, and insert at the specified position.
(2) Delete: The operation mode can be divided into deleting the specified element, deleting the element of the specified position, and the like, and attempting to implement the logical deletion operation.
(3) Display data
(4) Find: Query the specified element (can complete the query operation according to a certain data member)
(5) Positioning operation: locating the serial number of the specified element
(6) Update: modify the data of the specified element
(7) Read and write operations of data files, etc.
Other operations can be supplemented according to specific needs.
The linear table is required to use the definition of the class, the type of the data object is defined by itself, and the experimental single linked list and the doubly linked list are selected by themselves.
*/
#include<iostream>
#include <fstream>
using namespace std;
template<class T>
class LinkList;
template <class T>
/*Define a friend class to facilitate direct manipulation of data*/
class LinkNode
{
	friend class LinkList<T>;
	private:
			T _data;
			LinkNode<T>  *_next;
	public:
		LinkNode(T x ) 
		{
			_data = x;
			_next = NULL;
		}
};
template <class T>
class LinkList
{
		
	private:
			LinkNode<T> * _head;
	public:
	LinkList()
	{_head = NULL;}
	LinkNode<T>* _CreateNode(const T& x);//Create a new node
	void clear(LinkNode<T>* &cur);//Delete a new node
	void PushBack(const T& x);//tail insertion to create a linked list
	void PushFront(const T& x);//Head insertion to create a linked list
	void PopBack();	//Remove an element from the tail
	void PopFront();//Remove an element from the head
	int Length();//Find the length of the linear table
	LinkNode<T>* Find(T x);//Find a number
	void Insert_right(int pos, const T& x);//Insert after the nth
	void Insert_cur(int pos, const T& x);//Insert at the specified location
	void Insert_left(int pos, const T& x);//Insert in front of the nth
	void Delete_pos(int pos);//Delete the nth element
	void Delete_val(const T& x);//Delete specified element
	void reset(const T &x,const T &y);//Update an element
	int located(const T &x);//Locate the serial number of the specified element
	void Print();// Print linear table
	bool writeToFile();//Write file
	T* readFromFile();//Read in data file
	int readlen();
};
template<class T>
void LinkList<T>::Print()
{
	LinkNode<T>  *tmp = _head;
	while (tmp != NULL)
	{
		cout << tmp->_data << "-->";
		tmp = tmp->_next;
	}
	cout << "NULL" << endl;
}
//创建一个新的结点，并为其分配空间
//Create a new node and allocate space for it
template <class T>
LinkNode<T>* LinkList<T>:: _CreateNode(const T& x)
{
	LinkNode<T>* tmp = new LinkNode<T>(x);
	return tmp;
}
//清除某一个节点，释放空间
//Clear a node and free up space
template<class T>
void LinkList<T>::clear(LinkNode<T> *&cur)
{
		cur->_next = NULL;
		delete  cur;
		cur = NULL;
}
//获得链表的长度
//Get the length of the linked list
template<class T>
int LinkList<T> ::Length()
{
	
	int len = readlen();/*调用一个读文件的函数，来判别链表状态，Call a function that reads the file to determine the state of the linked list*/
	if(len>0){
		return len;
	}
	else {
	len=0;
	if (_head == NULL)
	{
		return 0;
	}
	else
	{
		LinkNode<T> * begin = _head;
		while (begin != NULL)
		{
			begin = begin->_next;
			len++;
		}
	}
	}
	return len;
}
/*前插法建立链表
从一个空表开始，重复读入数据，执行以下两步
（1）生成新的结点，将读入数据存放在新节点的的_data域中
（2）将该节点插入到链表的前端，直到读入到结束符为止。
Start with an empty table, read the data repeatedly, and perform the following two steps.
(1) Generate a new node and store the read data in the _data field of the new node.
(2) Insert the node into the front end of the linked list until the end character is read.
*/
template <class T>
void LinkList<T> :: PushFront(const T& x)	
{
	if (_head == NULL)
	{
		_head = _CreateNode(x);
	}
	else
	{
		LinkNode<T>  * prev = _CreateNode(x);
		prev->_next = _head;
		_head = prev;
	}
}
/*用后插法建立链表，需要设置一个尾部指针end,总是指向新链表的最后一个节点，新节点链接到它所指链尾节点的后面。end最初要置于附加头节点位置
To build a linked list with post-insertion, you need to set a tail pointer end, always pointing to the last node of the new linked list, and the new node is linked to the end of the chain end node it refers to. End is initially placed at the location of the additional head node
*/
template <class T>
void LinkList<T> ::PushBack(const T& x)		
{
	if (_head == NULL)
	{
		_head = _CreateNode(x);
	}
	else
	{
		LinkNode<T> * end = _head;
		while (end->_next != NULL)
		{
			end = end->_next;
		}
		end->_next = _CreateNode(x);
	}
}
/*从尾部删除一个数据，考虑只有一个节点情况，多个结点的情况。
多个结点，首先找到尾部元素，然后调用clear()函数，清理掉尾部第一个元素
Remove a data from the tail, considering the case of only one node, multiple nodes.
Multiple nodes, first find the tail element, then call the clear() function to clean up the first element of the tail*/
template <class T>
void LinkList<T> :: PopBack()			
{
	if (_head == NULL)
	{
		cout << "The List is empty!!!" << endl;
		return;
	}
	else if (_head->_next == NULL)
	{
		clear(_head);
	}
	else
	{
		LinkNode<T> * temp = _head;
		LinkNode<T> * end = _head;
		while (end->_next != NULL)
		{
			temp = end;
			end = end->_next;
		}
		temp->_next = NULL;
		clear(end);
	}
}
/*从头部删除一个元素，实现方法和从尾部删除一个元素基本相似，不多加以解释
Deleting an element from the head, the implementation method is basically similar to deleting an element from the tail, not much explanation*/
template <class T>
void LinkList<T> ::PopFront()				
{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
			return;
		}
		else if (_head ->_next == NULL)
		{
			clear(_head);
		}
		else
		{
			LinkNode<T> * tmp = _head;
			_head = _head->_next;
			clear(tmp);
			tmp = NULL;
	}
}
/*查找某一个元素，遍历整个链表，并将其数据_data与x进行比对，如果是其他类型就需要重载运算符==
Find an element, traverse the entire list, and compare its data _data with x. If it is another type, you need to overload the operator ==*/
template <class T>
LinkNode<T>* LinkList<T> ::Find (T x)
{
	if (_head == NULL)
	{
		cout << "List is empty,not found!!!" << endl;
		return NULL;
	}
	else if(_head->_data==x)
	{
		return _head;
	}
	else
	{
		LinkNode<T> * n = _head ;
		while (n->_next != NULL && n->_data != x )
		{
			n = n->_next;
			if (n->_data == x)
			{
				return n;
			}
		}
	}
	return NULL;
}
/*在第pos个元素后插入一个新元素，创建一个新的结点，通过移动begin指针，pos控制指针最终位置，将新元素插入到之后
Insert a new element after the pos element, create a new node, by moving the begin pointer, pos controls the final position of the pointer, inserting the new element after*/
template <class T>
void LinkList<T> ::Insert_right(int pos,const T& x)
{
	int len = Length();
	if (pos <= len)
	{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
			return;
		}
		else
		{
			LinkNode<T> * begin = _head;
			LinkNode<T> * tmp = _CreateNode(x);
			while (--pos)
			{
				if (begin->_next != NULL)
				{
					begin = begin->_next;
				}
			}
			tmp->_next = begin->_next;
			begin->_next = tmp;
		}
	}
	else
	{
		cout << "Input Error!!!" << endl;
	}
}
/*在第pos个元素插入一个新元素，因为写了一个在后面插入的函数，为了偷懒，就直接调用了Insert_right()这个函数
Insert a new element in the pos element, because a function inserted later is written. In order to be lazy, the function Insert_right() is called directly.
*/
template <class T>
void LinkList<T> ::Insert_cur(int pos,const T& x)
{
	int len = Length();
	if (pos <= len)
	{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
			return;
		}
		else
		{
			Insert_right(pos-1, x);
		}
	}
	else
	{
		cout << "Input Error!!!" << endl;
	}
}
/*在第pos个元素前插入一个新元素，创建一个新的结点，通过移动begin指针，pos控制指针最终位置，将新元素插入到之前，与插入之后实现方法基本类似，只是需要注意pos的控制
Insert a new element in front of the pos element, create a new node, by moving the begin pointer, pos controls the final position of the pointer, inserting the new element before, and the implementation method is basically similar to the method after inserting, just need to pay attention to the control of pos
*/
template <class T>
void LinkList<T> ::Insert_left(int pos,const T& x)
{
	int len = Length();
	int temp=pos-1;
	if (pos <= len)
	{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
			return;
		}
		else
		{
			LinkNode<T> * begin = _head;
			LinkNode<T> * tmp = _CreateNode(x);
			while (--temp)
			{
				if (begin->_next != NULL)
				{
					begin = begin->_next;
				}
			}
			tmp->_next = begin->_next;
			begin->_next = tmp;
		}
	}
	else
	{
		cout << "Input Error!!!" << endl;
	}
}
/*删除第pos个元素，依旧利用pos控制指针位置，然后删除就ok
Delete the pos element, still use pos to control the pointer position, then delete it ok
*/
template <class T>
void LinkList<T> ::Delete_pos(int pos)		
{
	int len = Length();
	if (pos <= len)
	{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
		}
		else if (_head->_next == NULL)
		{
			clear(_head);
		}
		else
		{
			LinkNode<T> * begin = _head->_next;
			LinkNode<T> * temp = _head;
			pos = pos - 1;
			while (--pos)
			{
				if (begin->_next != NULL)
				{
					begin = begin->_next;
					temp = temp->_next;
				}
			}
			temp->_next = begin->_next;
			begin->_next = temp;
		}
	}
	else
	{
		cout << "Input Error!!!" << endl;
	}
}
/*查找某一个元素位置，并返回其位置，用一个temp进行计数，遍历整个链表，一一进行比对其——data数据（若是其它类型就需要重载运算符“=”，后面的函数提到比对的都需要实现，才能进行比对）比对成功就返回，其它类的实现依然需要重载
Find a certain element position, and return its position, use a temp to count, traverse the entire linked list, one by one than it - data data (if other types need to overload the operator "=", the latter function mentioned The comparison needs to be implemented in order to compare. If the comparison is successful, it will return. The implementation of other classes still needs to be overloaded.
*/
template <class T>
int LinkList<T> ::located(const T &x)
{
	if (_head == NULL)
	{
		cout << "List is empty,not found!!!" << endl;
		return -1;
	}
	else if(_head->_data==x)
	{
		return 1;
	}
	else
	{
		LinkNode<T> * n = _head ;
		int temp=0;
		while (n->_next != NULL && n->_data != x )
		{
			n = n->_next;
			temp++;
			if (n->_data == x)
			{
				return temp+1;
			}
		}
	}
	return -1;
}
/*删除指定的元素，遍历链表，一一比对，找到就调用chear()函数删除并清理空间
Delete the specified element, traverse the linked list, compare one by one, find the call to the chear () function to delete and clean up the space*/
template <class T>
void LinkList<T> ::Delete_val(const T &x)
{
	if (_head == NULL)
	{
		cout << "List is empty!!!" << endl;
		return;
	}
	else if (_head->_next == NULL && _head->_data == x)
	{
		clear(_head);
		return;
	}
	else
	{
		if(_head->_data==x){
			while(1){
				if(_head->_data!=x)break;
				PopFront();
			}
		}
		else
		{
			while(1)
			{
				LinkNode<T> * n = Find(x);
				if(n==NULL)break;
				else{
					LinkNode<T> * begin = _head;
					while (begin->_next != n && begin->_next != NULL)
					{
						begin = begin->_next;
					}
					begin->_next = n->_next;
					clear(n);
				}
				
			}
			return ;
		}
	}
	return;
}
/*更新指定元素的值，遍历链表，一一比对（前面提到了重载的），找到要更新的元素后就将新的值赋值给它
Update the value of the specified element, traverse the linked list, one-to-one comparison (above mentioned overloaded), find the element to be updated and assign the new value to it
*/
template <class T>
inline void LinkList<T>::reset(const T &x,const T &y)
{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
			return ;
		}
		else
		{
			while(1)
			{
				LinkNode<T> * n = Find(x);
				if(n==NULL)break;
				else{
					n->_data=y;
				}
			}
		}
}
/*将链表的数据写入文件，能实现所有数据的储存，但是如果是其他类，写入没有问题，如果想从同一个文件中读入之前写的数据，遇到一些困难没有实现，但是基本数据类型是ok的,测试函数就表现出来了的（其它类的读入需要重载输入流，输出流）
Write the data of the linked list to the file, which can store all the data, but if it is other classes, there is no problem in writing. If you want to read the previously written data from the same file, some difficulties are not realized, but the basic data. The type is ok, the test function is shown。(Reading of other classes requires overloading the input stream, output stream)
*/
template <class T>
inline bool LinkList<T>::writeToFile()
{
	ofstream writefile("data.txt");
	int len;
	len=Length();
	writefile<<len<<endl;
	LinkNode<T> * begin=_head;
	while(begin!=NULL)
	{
		writefile<<begin->_data<<endl;
		begin=begin->_next;
	}
	return true;
}
/*从文件读入先前写入的数据，上面有提到只能满足基本数据类型
Read the previously written data from the file, mentioned above only can meet the basic data type
*/
template <class T>
inline T* LinkList<T>::readFromFile()
{
	ifstream readfile("data.txt");
	int length;
	readfile>>length;
	T *temp=new T[length];
	for(int i=0;i<length;i++)
	{
		readfile>>temp[i];
	}
	return temp;
}
/*为了更好的操作，测试相关函数的功能，写了这样一个函数来从文件得到链表长度的函数
For better operation, test the function of the related function, write a function that gets the length of the linked list from the file.
*/
template <class T>
inline int LinkList<T>::readlen()
{
	ifstream readfile("data.txt");
	int length;
	readfile>>length;
	return length;
}