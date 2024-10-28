#include"Date.h"

Date::Date(int year , int month , int day )
{
	_year = year;
	_month = month;
	_day = day;

	if (!CheckInvalid())
	{
		cout << "��������ڷǷ�" << endl;
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
			_month = 1;//ע���Ǹ�ֵ���ţ�������ȷ���
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
//ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//����++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}
//ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//����--
Date Date::operator--(int)
{
	Date tmp = *this ;
	*this -= 1;
	return tmp;
}
//���������
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	
	if (*this < d)
	{
		max = d;
		min = *this;
		int flag = -1;//�����������򣬴Ӷ��������ֵ��Ϊ��ֵ
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
//��ȫ�ֺ������޷���.�����ʶ��󣬽���취��1.get��set��2. ��Ԫ����
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "����������������:>";
		in >> d._year >> d._month >> d._day;
		
		if (!d.CheckInvalid())
		{
			cout << "��������Ч���ڣ�����������" << endl;
		}
		else
		{
			break;
		}
	}
	return in;
}