#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	bool CheckInvalid() const ;
	Date(int year=1 ,int month=1 ,int day =1 );
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day) const;
	Date& operator++();//ǰ��++
	Date operator++(int);//����++
	Date& operator--();//ǰ��--
	Date operator--(int);//����--

	int operator-(const Date& d) const;//���������
	void Print() const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	/*void operator<<(ostream& out)
	{
		out << _year << "��" << _month << "��" << _day << "��" << endl;
	}*/
	
	int GetMonthDay(int year,int month) const
	{
		assert(month > 0 && month < 13);
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return monthDays[month];
	}
	//��Ԫ����
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
		
private:
	int _year;
	int _month;
	int _day;
};
//ȫ�ֺ���
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);

