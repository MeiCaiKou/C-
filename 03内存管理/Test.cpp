//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0) 
//		:_a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	//int* p1 = (int*)operator new(10 * 4);
//	A* ptr1 = new A;//operator new + 1次构造
//	A* ptr2 = new A[10];//operator new + 10次构造
//
//
//	delete ptr1;//1次析构 +operator delete
//	delete[] ptr2;//10次析构 + operator delete[]
//
//	int* t1 = new int;
//	int* t2 = new int(10);
//	int* t3 = new int[10];
//	delete t1;
//	delete t2;
//	delete[] t3;
//	return 0;
//}

//==========================模板===========================
#include<iostream>
using namespace std;

template<typename T>
class A
{
public:
	A(T value)
		:_value(value)
	{

	}
	T ReGet() {
		return _value;
	}
private:
	T _value;
};

template<typename T>
void Swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 1, b = 2;
	Swap(a, b);
	double a1 = 2.0, b2 = 1.1;
	Swap(a1, b2);
	cout << a <<" "<< b << endl;
	cout << a1 << " " << b2 << endl;
	A<int> intA(2024);
	cout << intA.ReGet() << endl;
	A<double> doubleA(2.24);
	cout << doubleA.ReGet() << endl;
	return 0;
}