#include <iostream>
using namespace std;
const int defaultSize = 100;
template <class T>
class SeqList
{
	private:
		T *data;//存放数据的动态数组
		int maxSize;//最大可容纳表项的项数
		int last; //当前已存表项的最后位置（从0开始）
		void reSize(int newSize);	//改变数组空间大小
		
	public:
		SeqList(int sz);          //构造函数
		SeqList(SeqList<T>& L);	           //复制构造函数
		~SeqList() {delete[ ] data;}	        //析构函数
		int Size(){//求表最大容量
			return maxSize;
			}	 
		int Length() {//计算表长度
			return last+1;
			}        
		int Search(T x);//搜索x在表中位置，函数返回表项序号	
		int Locate(int i);//定位第i个表项，函数返回表项序号
		bool Insert(int i, T& x);//插入x在第i个表项之后
		bool Remove(int i, T& x);//删除第i个表项之后，通过x返回表项的值
		bool GetData(int i,T& x);//取第i个表项的值，以x引用返回
		bool SetData(int i,T& x);//用x修改第i个表项的值
		bool IsEmpty(){//判断表是否空否，是返回true，否返回false
			return (last==-1) ? true : false;
		}
		bool IsFull(){//判读表是否满否，是返回true，否返回false
			return (last = maxSize - 1) ? true : false;
		}
		void input();//输入数据
		void output();//打印数据
};
template <class T>
inline SeqList<T>::SeqList(int sz)
{
	if (sz > 0) {
		maxSize = sz;  last = -1;
		data = new T[maxSize];	   //创建表存储数组
		if (data == NULL)		   //动态分配失败
		{ 
			cout<<"储存分配错误！"<<endl;
		}
	}
}
template <class T>
inline SeqList<T>::SeqList(SeqList<T>& L)
{
	//复制构造函数，用参数表中给出的已有顺序表初始化新建的顺序表
	maxSize = L.Size();
	last = L.Length()-1;
	T value;
	data = new T[maxSize];//创建顺序表储存数组
	if(data == NULL){
		cout<<"动态分配错误！"<<endl;
	}
	for(int i =1;i<=last-1;i++){
		L.GetData(i, value);
		data[i-1] = value;
	}
	
}
template <class T>
inline void SeqList<T>::reSize(int newSize){
	//私有函数，扩充顺序表的储存数组空间的大小，新数组的元素个数为newSize.
	if(newSize <= 0){
		cout<<"无效数组的大小！"<<endl;
	}
	if(newSize != maxSize){
		T *newarray = new T[newSize];
		if(newarray == NULL){
			cout<<"储存分配错误！"<<endl;
		}
		int n = last+1;
		T *srcptr = data;//源数组的首地址
		T *desptr = newarray;//目的数组的首地址
		while(n--){//复制
			*desptr++ = *srcptr++;
		}
		delete []data;//删除老数组
		data = newarray;
		maxSize = newSize;//复制新数组
	}
}
template <class T>
inline int SeqList<T>::Search(T x)
{
	//搜索函数：在表中顺序搜索与给定值x匹配的表项，找到则函数返回该表项是第几个元素
	//否则返回0，表示搜索失败
	for(int i=0;i<=last;i++){
		if(data[i] == x)
		return i+1;
	}
	return 0;
}
template <class T>
inline int SeqList<T>::Locate(int i)
{
	//定位函数:返回第i(1<=i<=lat+1)个表项的位置，否则函数返回0，表示定位失败
	if(i>=1 && i<last+1){
		return i;
	}
	else return 0;
}
template <class T>
inline bool SeqList<T>::Insert(int i, T& x)//插入x在第i个表项之后
{
	//将新元素x插入到第i（0<=i<=last+1）个表项之后。函数返回插入成功的信息，若插入成功返回true,否则返回false.
	//i=0时虚拟的，实际上是插入到第1个元素的位置。
	if(last == maxSize - 1){
		return false;//表满，不能插入
	}
	if(i<0 || i > last+1)
	{
		return false;//参数i不合理，不能插入
	}
	for(int j=last;j>=i;j--)
	{
		data[j+1]=data[j];//一次后移，空出第i号位置
	}
	data[i] = x;//插入
	last++;//最后位置加一
	return true;
}
template <class T>
inline bool SeqList<T>::Remove(int i, T& x)//删除第i个表项之后，通过x返回表项的值
{
	//从表中删除第i（0<=i<=last+1）个表项，通过引用型参数x返回删除的元素值。函数返回删除成功的信息，删除成功返回true,删除失败返回false
	if(last == -1){
		return false;//表空，不能删除
	}
	if(i<1 || i>last+1){
		return false;//参数i不合理，不能删除
	}
	x=data[i];//储存删除的元素
	for(int j=i;j<=last;j++)
	{
		data[j-1] = data[j];//依次前移，填补
	}
	last--;//最后位置减一
	return true;
}
template <class T>
inline bool SeqList<T>::GetData(int i,T& x)//取第i个表项的值，以x引用返回
{
	if(last == -1){
		return false;//表空
	}
	if(i<1 || i>last+1){
		return false;//参数i不合理
	}
	x=data[i];//储存返回的元素
	return true;
}
template <class T>
inline bool SeqList<T>::SetData(int i,T& x)
{
	if(last == -1){
		return false;//表空
	}
	if(i<1 || i>last+1){
		return false;//参数i不合理
	}
	data[i]=x;//用x修改第i个表项的值
	return true;

}
template <class T>
inline void SeqList<T>::input()
{
	//从标准输入(键盘)逐个输入，建立顺序表
	cout<<"开始建立顺序表，请输入表中的元素个数："<<endl;
	while(1){
		int num;
		cin>>num;
		last=num-1;
		if(num<=maxSize-1)break;
		cout<<"表元素个数输入有误，范围不能超过"<<maxSize-1<<endl;
	}
	for(int i=0;i<=last;i++)
	{
		cout<<"请输入顺序表的第"<<i+1<<"个元素:"<<endl;
		cin>>data[i];
	}
}
template <class T>
inline void SeqList<T>::output()
{
	cout<<"顺序表："<<endl;
	for(int i=0;i<=last;i++)
	{
		cout<<data[i]<<" ";
	}
}
