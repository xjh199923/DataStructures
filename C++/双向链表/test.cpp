#include "DoubleLinkedList.h"
void Menu()
{
	cout<<"+===========================================+"<<endl;
	cout<<"|    1.测试头部插入元素      2.测试尾部插入元素  |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    3.指定位置插入元素      4.测试双向链表长度  |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    5.指定位置修改元素      6.指定位置删除元素  |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    7.打印双向链表         0.退出            |"<<endl;
	cout<<"+===========================================+"<<endl;
}
int main() 
{
	doubleLinkedListNode<int> node;
	doubleLinkedList<int> list;
	for(int i=1;i<10;i++)
	{
		list.insertNodeBytail(i);
	}
	Menu();
	int choose=1;
	int tmp,n;
	while(choose){
		cout<<"请输入你的选择："<<endl;
		cin>>choose;
	switch (choose) {
		case 1:
			{
				cout<<"请输入你要插入的元素：";
				cin>>tmp;
				list.insertNodeByhead(tmp);
			}
			break;
		case 2:
			{
				cout<<"请输入你要插入的元素：";
				cin>>tmp;
				list.insertNodeBytail(tmp);
			}
			break;
		case 3:
			{
				cout<<"请输入你要插入的位置："<<endl;
				cin>>n;
				cout<<"请输入你要插入的元素：";
				cin>>tmp;
				list.insertNode(tmp,n);
			}
			break;
		case 4:
			{
				cout<<"双向链表的长度为："<<list.getLength()<<endl;
			}
			break;
		case 5:
			{
				int x;
				cout<<"请输入你要修改的位置："<<endl;
				cin>>n;
				cout<<"请输入你要修改的元素：";
				cin>>tmp;
				list.changeListElements(n,tmp, x);
				cout<<"你将"<<n<<"号位置的元素"<<x<<"修改成了元素"<<tmp<<endl;
			}
			break;
		case 6:
			{
				cout<<"请输入你要删除的位置："<<endl;
				cin>>n;
				list.deleteData(n);
			}
			break;
		case 7:
			{
				list.printLinkedlist();
			}
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		cout << endl;
		Menu();
	}
	cout<<endl;
	Menu();
	}

	return 0;
}