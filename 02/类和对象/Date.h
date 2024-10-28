#pragma once
class Date
{
private:
//public:
	//C++中习惯在成员变量前加_用来区分形参和成员变量，以防混淆，也可以在成员变量前面使用this
	int _year;
	int _month;
	int _day;

public:
	void Init(int year, int month, int day);
	void Print();
};
