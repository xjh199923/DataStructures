#include "chainQueve.h"
void Menu()
{
	cout<<"+===========================================+"<<endl;
	cout<<"|    1.测试元素入队      2.测试元素出队         |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    3.得到队头元素      4.判断队列是否为空      |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    5.打印队列元素      6.队列的长度           |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|    0.退出                                  |"<<endl;
	cout<<"+===========================================+"<<endl;

}
int main() 
{
	chainQueve<int> que;
	for(int i=0;i<10;i++)
	{
		que.EnQueve(i+1);
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
				cout<<"请输入你要进队的元素：";
				cin>>tmp;
				que.EnQueve(tmp);
			}
			break;
		case 2:
			{
			  int x;
			if(que.DeQueve(x)==false){
				cout<<"该队列为空！"<<endl;
			}
			else{
				cout<<"出队的元素为："<<x<<endl;
			}
			}
			break;
		case 3:
			{
				int x1;
				que.getFront(x1);
				cout<<"队头元素为："<<x1<<endl;
			}
			break;
		case 4:
			if(que.isEmpty() == true){
				cout<<"该队列为空！"<<endl;
			}
			else{
				cout<<"该队列不为空！"<<endl;
			}
			break;
		case 5:
			cout<<"队列的元素为:"<<endl;
			que.Print();
			break;
		case 6:
			cout<<"该队列的长度为："<<que.Length()<<endl;
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
