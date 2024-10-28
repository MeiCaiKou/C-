#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	Date(int year=1,int month=1,int day=1);
	~Date();
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date& operator+=(int day);//�ı�������Ĵ�С
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	Date& operator++();//ǰ��++
	Date operator++(int);//����++
	Date& operator--();//ǰ��--
	Date operator--(int);//����--

	int operator-(const Date& d);

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//�����жϣ�����һ�򣬰��겻���İ���һ��
		if (month == 2 &&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return monthDays[month];
	}

	void Print();
private:
	int _year;
	int _month;
	int _day;
};

