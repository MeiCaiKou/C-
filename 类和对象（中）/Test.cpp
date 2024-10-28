//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//	}
//	void Print()
//	{
//		cout << "今天是" << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//	//d1<d2
//	bool operator<(const Date& d)
//	{
//		if (_year < d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year)
//		{
//			if (_month < d._month)
//			{
//				return true;
//			}
//			else if (_month == d._month)
//			{
//				if (_day < d._day)
//				{
//					return true;
//				}
//			}
//		}
//			return false;	
//	}
//	//赋值
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	
//		return *this;
//	}
//	
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class MyClass
//{
//public:
//	MyClass();
//	~MyClass();
//
//private:
//
//};
//
//MyClass::MyClass()
//{
//}
//
//MyClass::~MyClass()
//{
//}
//
//int main()
//{
//	Date d1(2024, 10, 3);
//	Date d2(2024, 10, 3);
//	Date d3(2024, 10, 2);
//	cout << d1.operator<(d2) << endl;
//	cout << (d2< d3) << endl;
//	//d1.Print();
//
//	Date d4(d1);//拷贝构造
//	d4.Print();
//	d1 = d2 = d3;
//	d1.Print();
//	return 0;
//}
#include"Date.h"

int main()
{
	/*Date d1(2024,10,3);
	Date d2;
	d2 = d1 - 30;
	d2.Print();
	d1.Print();
	d1 += 1000;
	d1.Print();
	Date d3(2022, 10, 29);
	d3.operator++();
	d3.operator++();
	d3.operator++();
	d3.operator++();
	d3.Print();

	Date d4=d3.operator++(1);
	d4.Print();
	d3.Print();
	cout << "=====================" << endl;
	Date d5 = d3.operator--(1);
	d5.Print();
	d3.Print();
	d5.operator--(0);
	d5.Print();*/

	Date d1(2024, 10, 3);
	d1.Print();
	Date d2(2002, 9, 30);
	d2.Print();
	cout<<d2.operator-(d1)<<"天" << endl;
	cout << d2.operator-(d1) / 365 << "年" << endl;


	return 0;
}