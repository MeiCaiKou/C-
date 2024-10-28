#include<iostream>

using namespace std;

class Date
{
public:
	//初始化列表
	Date(int year, int month, int day,int n)
		:_year(year)
		,_month(month)
		,_day(day)
		,_n(n)
	{}


	//初始化列表是每个成员变量定义初始化的位置
	//能用初始化列表就用初始化列表
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		,_n(1)
	{

	}

	//构造函数
	/*Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		
	}*/
private:
	int _year;
	int _month;
	int _day;

	const int _n;
};

int main()
{
	Date d1(2024, 10, 11);

	return 0;
}