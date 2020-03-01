/*
 Created by xjh on 2019/02/29.
*/
#include<iostream>
#include <iomanip>
using namespace std;
template<class T>
class chainQueve;
//定义了一个结点类，并把队列设置为该结点的友元类，以至于可以直接运用这个结点来创建队列。
template <class T>
class LinkNode
{
   friend class chainQueve<T>;
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
class chainQueve
{
      
   private:
         LinkNode<T> * _head;
   public:
      chainQueve()
      {_head = NULL;}
      LinkNode<T>* _CreateNode(const T& x);//创建一个新的结点
      void clear(LinkNode<T>* &cur);//删除一个结点
      bool isEmpty();//判断是否为空
      void EnQueve(const T& x);//将x加入到队列当中
      bool DeQueve(T& x);//队头元素出列
      bool getFront(T& x);//取队列头部的值
      int Length();//队列的长度
      void Print();// 输出
};
template<class T>
void chainQueve<T>::Print()
{
   LinkNode<T>  *tmp = _head;
   while (tmp != NULL)
   {
      cout << tmp->_data << "-->";
      tmp = tmp->_next;
   }
   cout << "NULL" << endl;
}
template<class T>
bool chainQueve<T>::isEmpty()
{
   if(_head==NULL)
   {
      return true;
   }
   else{
      return false;
   }
}
template<class T>
bool chainQueve<T>::getFront(T &x)
{
   if(isEmpty()){
      return false;
   }
   else{
      x=_head->_data;
      return true;
   }
}
template <class T>
LinkNode<T>* chainQueve<T>:: _CreateNode(const T& x)
{
   LinkNode<T>* tmp = new LinkNode<T>(x);
   return tmp;
}
template<class T>
void chainQueve<T>::clear(LinkNode<T> *&cur)
{
      cur->_next = NULL;
      delete  cur;
      cur = NULL;
}
template<class T>
int chainQueve<T> ::Length()
{
   
   int len=0;
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
   return len;
}
template <class T>
void chainQueve<T> ::EnQueve(const T& x)		
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
template <class T>
bool chainQueve<T> ::DeQueve(T& x)				
{
      if (_head == NULL)
      {
         return false;
      }
      else if (_head ->_next == NULL)
      {
         x=_head->_data;
         clear(_head);
          return true;
      }
      else
      {
         LinkNode<T> * tmp = _head;
         x=_head->_data;
         _head = _head->_next;
         clear(tmp);
         tmp = NULL;
         return true;
   }
}
