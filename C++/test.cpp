#include "SequenceTable.h"
void Menu();
int main()
{
	
	SeqList<int> list(10);
	list.input();
	int select = 1;
	int x,i;
	Menu();
	while (select)
	{
		cout << "Please select:			          " << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout<<"顺序表当前最大容纳元素个数为："<<list.Size()<<endl;break;
		case 2:
			cout<<"顺序表当前元素最后位置为："<<list.Length()<<endl;break;
		case 3:
			cout<<"请输入您要搜索的值："<<endl;
			cin>>x;
			cout<<x<<"的"<<"序号为"<<list.Search(x)<<endl;
			break;
		case 4:
			cout<<"请输入您要定位的值："<<endl;
			cin>>x;
			cout<<x<<"的"<<"序号为"<<list.Locate(x)<<endl;
			break;
		case 5:
			cout<<"请输入您要插入在其后的序号："<<endl;
			cin>>i;
			cout<<"请输入您要插入的值："<<endl;
			cin>>x;
			if(list.Insert(i, x)==true){
				cout<<"插入成功！"<<endl;
			}
			else{
				cout<<"插入失败！"<<endl;
			}
			break;
		case 6:
			cout<<"请输入您要删除元素的序号："<<endl;
			cin>>i;
			if(list.Remove(i, x)==true){
				cout<<"删除的元素为："<<x<<endl;
			}
			else{
				cout<<"删除失败！"<<endl;
			}
			break;
		case 7:
			cout<<"请输入您要取的元素的序号："<<endl;
			cin>>i;
			if(list.GetData(i, x)==true){
				cout<<"取出的元素为："<<x<<endl;
			}
			break;
		case 8:
			cout<<"请输入您要修改的元素的序号："<<endl;
			cin>>i;
			cout<<"请输入您要修改元素的值："<<endl;
			cin>>x;
			if(list.SetData(i, x)==true){
				cout<<"修改成功！"<<x<<endl;
			}
			else{
				cout<<"修改失败！"<<endl;
			}
			break;
		case 9:
			list.output();break;
		case 0:
			break;
		default:
			break;
		}
		cout << endl;
		Menu();
	}
	return 0;
}
void Menu()
{
	cout << "	* * * * * welcome to use SequenceTable* * * * * * " << endl;
	cout << "	*	1. 顺序表最大容量	   2. 顺序表当前长度      *" << endl;
	cout << "	*	3. 搜索x在表中位置   4. 定位第i个表项       *" << endl;
	cout << "	*	5. 插入元素	   6. 删除元素           *" << endl;
	cout << "	*	7. 取第i个表项的值	   8. 修改第i个表项的值    *" << endl;
	cout << "        *       9. 打印顺序表        0.退出               *" << endl;
	cout << "	* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
}
