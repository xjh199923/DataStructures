#include <string>
#include<stdio.h>
#include <iostream>
using namespace std;
class Point
{
	private:
		double x;
		double y;
	public:
		Point(double x=0.0,double y=0.0)
		{this->x=x,this->y=y;}
		void setdata(double a,double b)
		{this->x=a;this->y=b;}
		Point operator=(Point a);//重载运算符“=”
		int operator==(Point a);//重载运算符“==”
		int operator!=(Point a);
		double getx()
		{return x;}
		double gety()
		{return y;}
		//重载输入流
		friend istream &operator>>(istream &is,Point &p)
		{
			is>>p.x;
			is>>p.y;
			return is;
		}//重载输出流
		friend ostream &operator<<(ostream &os,Point p)
		{
			os<<"("<<p.x<<","<<p.y<<")";
			return os;
		}
};

inline Point Point::operator=(Point a)
{
	this->x=a.x;
	this->y=a.y;
	return *this;
}
inline int Point::operator==(Point a)
{
	if(this->x==a.getx()&&this->y==a.gety())
	{
		return 1;
	}
	else {
		return 0;
	}
}
inline int Point::operator!=(Point a)
{
	if(this->x!=a.getx()&&this->y!=a.gety())
	{
		return 1;
	}
	else if(this->x!=a.getx()||this->y!=a.gety()){
		return 1;
	}
	else {
		return 0;
	}
}

