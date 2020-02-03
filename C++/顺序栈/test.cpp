#include "Stack.h"
void Menu()
{
	cout<<"+===========================================+"<<endl;
	cout<<"|    1.测试元素进栈      2.测试元素出栈         |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    3.得到栈顶元素      4.打印元素            |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    0.退出                                 |"<<endl;
	cout<<"+===========================================+"<<endl;
}
int main() 
{
	Stack<int> stackint(4);//创建一个最大空间为20的栈
	stackint.Push(1);
	stackint.Push(2);
	stackint.Push(3);
	stackint.Push(4);
	Menu();
	int choose=1;
	int tmp;
	while(choose){
		cout<<"请输入你的选择："<<endl;
		cin>>choose;
	switch (choose) {
		
		case 1:
			{
				cout<<"请输入你要进栈的元素：";
				cin>>tmp;
				stackint.Push(tmp);
			}
			break;
		case 2:
			{
				int x;
				stackint.Pop(x);
				cout<<"出栈的元素为："<<x<<endl;
			}
			break;
		case 3:
			{
				cout<<"栈顶元素为："<<stackint.getTopelements()<<endl;
			}
			break;
		case 4:
			stackint.print();
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
