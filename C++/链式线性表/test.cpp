#include "LinkList.h"
#include "point.h"
//测试point时候用
void point_();
//测试int时候用
void int_();
void Menu()
{
	cout << "	* * * * * * * welcome to use SeqList* * * * * * * * *" << endl;
	cout << "	*	1. 后插建立链表		2. 前插建立链表       *" << endl;
	cout << "	*	3. 删除开始数据		4. 删除最后数据       *" << endl;
	cout << "	*	5. 插入元素之前		6. 插入元素之后       *" << endl;
	cout << "	*	7. 当前位置插入	        8.删除指定位置元素     *" << endl;
	cout << "	*	9. 删除指定元素	        10.查 找             *" << endl;
	cout << "	*	11. 输出长度	        12.显示数据           *" << endl;
	cout << "	*	13. 定位指定元素位置	14.保存数据           *" << endl;
	cout << "	*	15. 更新指定元素数据    0.退出                  *" << endl;
	cout << "	*        		    			     *" << endl;
	cout << "	* * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	
	/*
	cout << "	* * * * * * * * * * * * * * * *welcome to use SeqList* * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "	*	1. Post-insertion		             2. Pre-plugging                         *" << endl;
	cout << "	*	3. Delete start data		             4. Delete last data                     *" << endl;
	cout << "	*	5. Before inserting an element		     6. After inserting the element          *" << endl;
	cout << "	*	7.Current position insertion	             8.Delete specified location element     *" << endl;
	cout << "	*	9.Delete specified element	             10.Search                               *" << endl;
	cout << "	*	11. Output length	                     12.Display Data                         *" << endl;
	cout << "	*	13. Locate the specified element location    14.Save data                            *" << endl;
	cout << "	*	15. Update specified element data            0.Drop out                              *" << endl;
	cout << "	*        		    			                                              *" << endl;
	cout << "	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	*/	
}
int main()	
{
	//point_();
	int_();
	return 0;
}
void point_(){
	Point temp;
	temp.setdata(0,0);
	Point Item;
	LinkList<Point> mylist;
		int select = 1;
		int pos;
		Menu();
		while (select)
		{
			cout << "Please select:			          " << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				if(mylist.readlen()!=0)
				{
					ifstream readfile("point.txt");
						int length,x,y;
						readfile>>length;
						Point temp[length];
						for(int i=0;i<length;i++)
						{
							readfile>>x;
							readfile>>y;
							temp[i].setdata(x,y);
						}
						for(int i=0;i<length;i++)
						{
							mylist.PushBack(temp[i]);
						}
				}
				break;
			case 2:
				if(mylist.readlen()!=0)
				{
				
					ifstream readfile("point.txt");
						int length,x,y;
						readfile>>length;
						Point temp[length];
						for(int i=0;i<length;i++)
						{
							readfile>>x;
							readfile>>y;
							temp[i].setdata(x,y);
						}
						for(int i=0;i<length;i++)
						{
							mylist.PushFront(temp[i]);
						}
				}
				break;
			case 3:
				mylist.PopFront();
				break;
			case 4:
				mylist.PopBack();
				break;
			case 5:
				cout << "请输入要插入的位置:"<<endl;
				cin >> pos;
				cout << "请输入要插入的值:"<<endl;
				cin >> Item;
				mylist.Insert_left(pos,Item);
				break;
			case 6:
				cout << "请输入要插入的位置:"<<endl;
				cin >> pos;
				cout << "请输入要插入的值:"<<endl;
				cin >> Item;
				mylist.Insert_right(pos, Item);
				break;
			case 7:
				cout << "请输入要插入的位置:"<<endl;
				cin >> pos;
				cout << "请输入要插入的值:"<<endl;
				cin >> Item;
				mylist.Insert_cur(pos,Item);
				break;
				case 8:
				cout << "请输入要删除的位置:"<<endl;
				cin >> pos;
				mylist.Delete_pos(pos);
				break;
			case 9:
				cout << "请输入要删除的值:"<<endl;
				cin >> Item;
				mylist.Delete_val(Item);
				break;
			case 10:
				cout << "请输入要查找的值:"<<endl;
				cin >> Item;
				mylist.Find(Item);
				break;
			case 11:
				cout<<"该线性表的长度为："<<mylist.Length()<<endl;
				break;
			case 12:
				mylist.Print();
				break;
			case 13:
				cout << "请输入要查找的值:"<<endl;
				cin >> Item;
				int che;
				che=mylist.located(Item);
				if(che>=0){
					cout<<"该元素的序号为："<<mylist.located(Item)<<endl;
				}
				else{
					cout<<"该元素不存在!"<<endl;
				}
				break;
			case 14:
				mylist.writeToFile();
				break;
			case 15:
				cout << "请输入要更新的值:"<<endl;
				cin >> Item;
				cout << "请输入要更新为:"<<endl;
				cin >> temp;
				mylist.reset(Item,temp);
				break;
			case 0:
				exit(0);
			default:
				break;
			}
			cout << endl;
			Menu();
		}

}
void int_()
{
	int temp=-1;
	int Item;
	LinkList<int> mylist;
		int select = 1;
		int pos;
		Menu();
		while (select)
		{
			cout << "Please select:			          " << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				if(mylist.readlen()!=0)
				{
				
					int *sum = mylist.readFromFile();
						for(int i=0;i<mylist.Length();i++)
						{
							mylist.PushBack(sum[i]);
						}
						delete []sum;
				}
				else{			
					cout << "请输入要后插的值(-1结束):"<<endl;;
					while (cin >> Item)
					{
						if(Item==temp)break;
						mylist.PushBack(Item);
					}
				}
				break;
			case 2:
				if(mylist.readlen()!=0)
				{
				
					int *sum = mylist.readFromFile();
						for(int i=0;i<mylist.Length();i++)
						{
							mylist.PushFront(sum[i]);
						}
						delete []sum;
				}
				else {
				cout << "请输入要头插的值(-1结束):"<<endl;;
				while (cin >> Item)
				{
					if(Item==temp)break;
					mylist.PushFront(Item);
				}
				}
				break;
			case 3:
				mylist.PopFront();
				break;
			case 4:
				mylist.PopBack();
				break;
			case 5:
				cout << "请输入要插入的位置:"<<endl;
				cin >> pos;
				cout << "请输入要插入的值:"<<endl;
				cin >> Item;
				mylist.Insert_left(pos,Item);
				break;
			case 6:
				cout << "请输入要插入的位置:"<<endl;
				cin >> pos;
				cout << "请输入要插入的值:"<<endl;
				cin >> Item;
				mylist.Insert_right(pos, Item);
				break;
			case 7:
				cout << "请输入要插入的位置:"<<endl;
				cin >> pos;
				cout << "请输入要插入的值:"<<endl;
				cin >> Item;
				mylist.Insert_cur(pos,Item);
				break;
				case 8:
				cout << "请输入要删除的位置:"<<endl;
				cin >> pos;
				mylist.Delete_pos(pos);
				break;
			case 9:
				cout << "请输入要删除的值:"<<endl;
				cin >> Item;
				mylist.Delete_val(Item);
				break;
			case 10:
				cout << "请输入要查找的值:"<<endl;
				cin >> Item;
				mylist.Find(Item);
				break;
			case 11:
				cout<<"该线性表的长度为："<<mylist.Length()<<endl;
				break;
			case 12:
				mylist.Print();
				break;
			case 13:
				cout << "请输入要查找的值:"<<endl;
				cin >> Item;
				int che;
				che=mylist.located(Item);
				if(che>=0){
					cout<<"该元素的序号为："<<mylist.located(Item)<<endl;
				}
				else{
					cout<<"该元素不存在!"<<endl;
				}
				break;
			case 14:
				mylist.writeToFile();
				break;
			case 15:
				cout << "请输入要更新的值:"<<endl;
				cin >> Item;
				cout << "请输入要更新为:"<<endl;
				cin >> temp;
				mylist.reset(Item,temp);
				break;
			case 0:
				exit(0);
			default:
				break;
			}
			cout << endl;
			Menu();
		}
}