//#include<iostream>
//#include"Date.h"
//using namespace std;


//�ṹ�嶨����,����classҲ����

//struct Stack
//{
//	//��Ա����
//	int* a;
//	int top;
//	int capacity;
//
//	void Init(int n = 4)
//	{
//		a = (int*)malloc(sizeof(int) * n);
//		if (nullptr == a)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		capacity = n;
//		top = 0;
//
//	}
//
//	void Push(int x)
//	{
//		a[top++] = x;
//	}
//
//	int Pop()
//	{
//		int e;
//		if (top >= 1)
//		{
//			e = a[top - 1];
//			top--;
//			return e;
//		}
//		else
//		{
//
//			cout << "ջ��";
//			return 0;
//		}
//	
//	}
//};

//class Date
//{
//
//	int year;
//	int month;
//	int day;
//
//	void Init(int year, int month, int day)
//	{
//		this->year = year;
//		this->month = month;
//		this->day = day;
//	}
//
//};

	//void Date::Init(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	//void Date::Print()
	//{
	//	cout << "������" << _year << "��";
	//	cout << _month << "��" << _day << "��" << endl;
	//}


//int main()
//{
//	//class Date today;
//	Date today;//���壬����ʵ����
//	//Date::_year++;//���ܵ��ã���Ϊ��ֻ������
//	//today._year++;
//	cout << sizeof(today) << endl;
//	cout << endl;
//	today.Init(2024,9,23);
//	today.Print();
//	return 0;
//}
//int main()
//{
//	//struct Stack st2;//C���Ե�ʹ��
//	Stack st1;
//	st1.Init();
//	st1.Push(1);
//	st1.Push(4);
//	st1.Push(7);
//
//	cout << st1.Pop() << endl;
//	cout << st1.Pop() << endl;
//	cout << st1.Pop() << endl;
//	cout << st1.Pop() << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//struct A
//{
//private:
//	int _a;
//	char _i;
//public:
//
//	void Init()
//	{
//	
//	}
//
//};
//struct B
//{
//private:
//	char _i;
//	int _a;
//
//};
//int main()
//{
//
//	cout << sizeof(A)<<endl;
//	cout << sizeof(B) << endl;
//	return 0;
//}

#include<iostream>
using namespace std;


//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//
//public:
//	/*void Init(int year,int month,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//	
//	}*/
//
//	//���캯��
//	/*Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}*/
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	//ȫȱʡ�ıȽϺ���
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	~Date()
//	{
//		cout << "~Date()" <<_year<<"��"<<_month<<"��"<<_day<<"��" << endl;
//	}
//
//	void Print()
//	{
//
//		cout << "������";
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//
//	}
//	//��������
//	/*Date(Date& d)
//	{
//		_year = 1;
//		_month =1;
//		_day = 1;
//		cout << "��������";
//	
//	}*/
//	Date(const Date& d)
//	{
//		_year =d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//};

//��������/��������  int/char/double/ָ��
//�Զ������� struct/class
//Ĭ�����ɵĹ��캯���������������Ͳ��������Զ������ͻ�ȥ��������Ĭ�Ϲ���
//int main()
//{
//	Date d1;
//	//d1.Init(2024, 9, 25);
//	d1.Print();
//
//	Date d2(2024,9,25);
//	d2.Print();
//
//	Date d3(2024);
//	d3.Print();
//
//	Date d4(d1);
//}
//��ֵ����Ҫ���ÿ���
//void func1(Date d)//�Ƚ��뿽�����죬�ٽ��뺯����Ȼ���ٽ�����������
//{
//	cout << "func1()";
//}
//void func2(Date& rd)//���뺯������,�ٽ�����������
//{
//	cout << "func2()";
//}
//int main()
//{
//	Date d1(2024,9,26);
//	func1(d1);
//	func2(d1);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int& b = a;
//	b++;
//	//Ȩ����С��c��a��ֻ��
//	const int& c = a;
//	
//	const int x = 10;
//	//Ȩ�޷Ŵ�ȡ�������ܷŴ�Ȩ��
//	int& y = x;
//
//	const int& y = x;
//
//	const int& z = 10;
//	const int& m = a + x;
//
//	return 0;
//}

//int main()
//{
//	double d = 1.1;
//	int i = d;
//	int& ri = d;
//
//	const int& r1 = d;
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator==(const Date& y)
	{
		return _year == y._year
			&& _month == y._month
			&& _day == y._day;

	}

	bool operator<(const Date& y)
	{
		if (_year < y._year)
		{
			return true;
		}
		else if (_year == y._year)
		{
			if (_month < y._month)
			{
				return true;
			}
			else if (_month == y._month)
			{
				if (_day < y._day)
				{
					return true;
				}
			}
		}
		return false;

	}
private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d1(2024,9,26);
	Date d2(2024, 8, 29);
	cout<<d1.operator==(d2)<<endl;
	cout <<(d2< d1) << endl;
	return 0;
}