//#include <iostream>
//using namespace std; //�����ռ�,չ������
//using std::cout;//չ��ĳһ��
//using std::endl;
//using std::cin;
//
//#define Day 7 //c++�ų��ú궨��
//
//namespace kfy
//{
//	namespace k_0910
//	{
//		void Push()
//		{
//			cout << "kfy" << endl;
//		}
//	}
//
//}
//
//int x = 0;
//
//namespace bit1
//{
//	
//}
//
//int main()
//{
//
//	const int a = 10;
//	int x = 10;
//
//	std::cout << "x = " << ::x << endl;
//	cout << "x = " << x << endl;
//
//	kfy::k_0910::Push();
//	system("pause");
//
//	return 0;

//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	
//	int a = 10;
//	//1.����
//	a = a << 1;
//	//2.������,�Զ�ʶ������
//	cout<< a << endl;//enl=endline,�൱�ڻ��з�
//	int b;
//	//1.����
//	b >> 2;
//	//2.����ȡ
//	cin >> b;
//	cout << "b: " << b <<endl;
//	const char* str = "hhhhh";
//	cout << &str << endl;
//	cout << str << endl;
//	cout << &b << endl;
//	//printf("%.2lf",b);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void Func(int a = 5,int b = 10, int c =20)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//int main()
//{
//	Func(1,2);
//	Func();
//	return 0;
//}

//����

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	//b����a�ı���
//	int& b = a;
//	int* c = &a;
//	b++;
//	cout << &b << endl;
//	cout << b << endl;
//	a++;
//	
//	cout << &a << endl;
//	cout << c << endl;
//	
//	cout << a << endl;
//
//	int& d = b;
//	cout << &d << endl;
//	return 0;
//}

//������
//#include<iostream>
//using namespace std;
//
//void Swap(int* a, int* b)//a��x�Ľ�����...
//{
//
//}
//void Swap(int& a, int& b)//a��x�ı���.....
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int x = 0, y = 1;
//	Swap(&x,&y);
//
//	Swap(x,y);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int& func()
//{
//	int a = 0;
//	return a;
//}
//int& fx()
//{
//	int b = 1;
//	return b;
//}
//inline int ADD(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	/*int& ret = func();
//	cout << ret << endl;
//	fx();
//	cout << ret << endl;*/
//	int ret1 = ADD(3, 4);
//	cout << ret1 << endl;
//	return 0;
//}

//============================================
//auto���÷�

//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//
//void func(int a,int b)
//{
//
//}
//
//auto func2(int a,int b)
//{
//	return a + b;
//
//}
//int main()
//{
//
//	int i = 0;
//	int j = 1;
//	auto k = i;
//	//auto x;
//	auto p1 = &i;
//	auto* p2 = &i;
//	//auto* p3 = i;
//	auto& r = i;
//	cout << p1 << endl;
//	cout << p2 << endl;
//	cout << *p2 << endl;
//	cout<<sizeof(k)<<endl;
//
//
//	void(*pf1)(int, int) = func;//func�ĺ���ָ��
//	auto pf2 = func;
//	cout << typeid(pf1).name() << endl;
//	cout << typeid(pf2).name() << endl;
//
//
//	std::map<std::string, std::string> dict;
//	//std::map<std::string, std::string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	auto ret = func2(2,3);
//	cout << ret << endl;
//
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int array[] = {1,1,4,2,5,6};
//	for (auto x : array)
//	{
//		x *= 2;
//	}
//	cout << endl;
//	for (auto x : array)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	/*for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
//	{
//		cout << array[i] << " ";
//	}
//	cout << endl;*/
//	return 0;
//}


#include<iostream>
using namespace std;

void f(int i)
{
	cout << "f(int)" << endl;
}
void f(int* i)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	f(nullptr);
	return 0;
}