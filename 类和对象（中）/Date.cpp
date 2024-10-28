#include"Date.h"

//只用实现一个<和一个=，其余均可以复用，或者实现一个>和一个=
bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;

	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;//*this不能传，但是可以在内部使用
}
bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
	//return *this > d || *this == d;
}
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
//构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day = _day - GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day)//不能使用引用返回
{
	Date tmp(*this);//拷贝构造
	tmp += day;
	return tmp;
}
//Date Date::operator+(int day)//不能使用引用返回
//{
//	Date tmp(*this);//拷贝构造
//	tmp._day += day;
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day = tmp._day - GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//		if (tmp._month == 13)
//		{
//			tmp._year++;
//			tmp._month = 1;
//		}
//	}
//	return tmp;
//}
////已知+，如何复用+去实现+=
//Date& Date::operator+=(int day)
//{
//	*this = *this + day;
//	return *this;
//}


Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month == 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

//前置++
Date& Date::operator++()
{
	/*_day += 1;
	if (_day > GetMonthDay(_year, _month))
	{
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
		_day = 1;
	}*/
	*this += 1;
	return *this;
}
//后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
//两个日期相减
int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;

	if (*this < d)
	{
		int flag = -1;
		max = d;
		min = *this;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}
//析构函数
Date::~Date()
{
	
}
void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}