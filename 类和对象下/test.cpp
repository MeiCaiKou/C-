#include<iostream>

using namespace std;

class Date
{
public:
	//��ʼ���б�
	Date(int year, int month, int day,int n)
		:_year(year)
		,_month(month)
		,_day(day)
		,_n(n)
	{}


	//��ʼ���б���ÿ����Ա���������ʼ����λ��
	//���ó�ʼ���б���ó�ʼ���б�
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		,_n(1)
	{

	}

	//���캯��
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