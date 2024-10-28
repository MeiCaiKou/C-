#include"Date.h"

Date::Date(int year , int month , int day )
{
	_year = year;
	_month = month;
	_day = day;

	if (!CheckInvalid())
	{
		cout << "构造的日期非法" << endl;
	}
}
bool Date::operator<(const Date& d) const
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
		else if(_month ==d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator<=(const Date& d) const
{ 

	return *this < d || *this == d;
}
bool Date::operator>(const Date& d) const
{

	return !(*this <= d);
}
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}
bool Date::operator==(const Date& d) const
{

	return _year == d._year
		&& _month == d._month
		&& _day == d._day;

}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
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
			_month = 1;//注意是赋值符号，不是相等符号
		}
	}
	return *this;
}
Date Date::operator+(int day) const
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day < 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day = _day + GetMonthDay(_year, _month);
	}
	return *this;
}
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}
//前置++
Date& Date::operator++()
{
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
//前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//后置--
Date Date::operator--(int)
{
	Date tmp = *this ;
	*this -= 1;
	return tmp;
}
//两日期相减
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	
	if (*this < d)
	{
		max = d;
		min = *this;
		int flag = -1;//用来调换方向，从而算出来的值都为正值
	}
	int n = 0;
	while (min != max)
	{
		n++;
		++min;
	}
	return n * flag;
}


bool Date::CheckInvalid() const
{
	if (_year <= 0
		|| _month < 1
		|| _month > 12
		|| _day < 1
		|| _day > GetMonthDay(_year, _month))
	{
		return false;
	}
	else
	{
		return true;
	}

}
//在全局函数中无法用.来访问对象，解决办法：1.get，set；2. 友元声明
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "请依次输入年月日:>";
		in >> d._year >> d._month >> d._day;
		
		if (!d.CheckInvalid())
		{
			cout << "输入了无效日期，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	return in;
}