#pragma once
class Date
{
private:
//public:
	//C++��ϰ���ڳ�Ա����ǰ��_���������βκͳ�Ա�������Է�������Ҳ�����ڳ�Ա����ǰ��ʹ��this
	int _year;
	int _month;
	int _day;

public:
	void Init(int year, int month, int day);
	void Print();
};
