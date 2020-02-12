#include "chainStack.h"
void Menu()
{
	cout<<"+===========================================+"<<endl;
	cout<<"|    1.测试元素进栈      2.测试元素出栈         |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    3.得到栈顶元素      4.判断栈是否为空       |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    5.打印栈元素        0.退出               |"<<endl;
	cout<<"+===========================================+"<<endl;
}
int main() 
{
	chainStack<int> intchainStack;
	for(int i=0;i<10;i++)
	{
		intchainStack.Push(i+1);
	}
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
				intchainStack.Push(tmp);
			}
			break;
		case 2:
			{
				int x;
				intchainStack.Pop(x);
				cout<<"出栈的元素为："<<x<<endl;
			}
			break;
		case 3:
			{
				int x1;
				intchainStack.getTop(x1);
				cout<<"栈顶元素为："<<x1<<endl;
			}
			break;
		case 4:
			if(intchainStack.isEmpty() == true){
				cout<<"该栈为空！"<<endl;
			}
			else{
				cout<<"栈不为空！"<<endl;
			}
			break;
		case 5:
			cout<<"栈的元素为:"<<endl;
			intchainStack.printChainStackData();
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
