//#include<iostream>
//#include <string>
//using namespace std;

//int main()
//{
//	int a = 1;
//	int b = 8;
//	swap(a, b);
//	cout << "a:" << a << endl;
//	cout << "b:" << b << endl;
//	return 0;
//}
//===============================================================================
//模板类：栈
//template<class T>
//class Stack
//{
//public:
//    Stack(int capacity = 10)
//        : _capacity(capacity)
//        , _top(-1)
//    {
//        _a = new T[_capacity];
//    }
//
//    ~Stack()
//    {
//        delete[] _a;
//    }
//
//    void push(const T& x)
//    {
//        if (_top >= _capacity - 1)
//        {
//            resize();
//        }
//        _a[++_top] = x;
//    }
//
//    void pop(T& e)
//    {
//        if (_top < 0)
//        {
//            throw std::out_of_range("Stack is empty");
//        }
//        e = _a[_top--];
//    }
//
//    void print()
//    {
//        for (int i = 0; i <= _top; ++i)
//        {
//            std::cout << _a[i] << " ";
//        }
//        std::cout << std::endl;
//    }
//
//private:
//    void resize()
//    {
//        _capacity *= 2;
//        T* newArray = new T[_capacity];
//        for (int i = 0; i <= _top; ++i)
//        {
//            newArray[i] = _a[i];
//        }
//        delete[] _a;
//        _a = newArray;
//    }
//    T* _a;
//    int _top;
//    int _capacity;
//};
//
//int main()
//{
//	Stack<int> st1;
//	st1.push(2);
//	st1.print();
//	Stack<double> st2;
//	return 0;
//}
// ===================================================================
//String的遍历
//void testString()
//{
//	string s1;
//	string s2("Faye Kou");
//	string s3(s2);
//	string s4(s2, 2, 8);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	string s5(10, '#');
//	cout << s5 << endl;
//	string s6(s2.begin(), s2.begin()+3);
//	cout << s6 << endl;
//	s2.resize(20,'h');
//	cout << s2 << endl;
//}
//void testString2()
//{
//	string s1 = "hello world";
// //范围for
//	for (auto e :  s1)
//	{
//		cout << e << " ";
//	}
//	/*string::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		*it1 += 3;
//		it1++;
//	}
//	it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		cout << *it1 << " ";
//		it1++;
//	}
//	cout << endl;
//	cout << typeid(it1).name() << endl;*/
//	/*for (size_t i = 0; i < s1.length(); i++)
//	{
//		cout << s1[i]<<" ";
//	}
//	cout << endl;*/
//}
//int main()
//{
//	//testString();
//	testString2();
//	return 0;
//}


//====================================================================
//#include<iostream>
//#include<string>
//using namespace std;
//
//void test_string1()
//{
//	string s1("hello world==========");
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	//只有当reserve的数字大于capacity时才会进行扩容
//	//vs扩容机制：第一次2倍扩容，后面都是1.5倍扩容；g++一直都是2倍扩容
//	s1.reserve(48);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	s1.resize(24,'w');
//	cout << s1 << endl;
//		/*string::reverse_iterator rit1 = s1.rbegin();
//	while (rit1 != s1.rend())
//	{
//		cout << *rit1 << " ";
//		rit1++;
//	}
//	cout << endl;
//	const string s2("hello world");
//	string::const_reverse_iterator rit2 = s2.rbegin();
//	while (rit2 != s2.rend())
//	{
//		cout << *rit2 << " ";
//		rit2++;
//	}
//	cout << endl;*/
//}
// void test_string2()
//{
//	string s1 = "hello world";
//	cout << s1[3] << endl;
//	cout << s1.at(3) << endl;
//}
//void test_string3()
//{
//	string s1("hello world");
//	//加一个字符
//	s1.push_back('k');
//	cout << s1 << endl;
//	//加字符串
//	s1.append("Faye Kou");
//	cout << s1 << endl;
//
//	s1.append("Faye Kou",2,3);
//	cout << s1 << endl;
//}
//void test_string4()
//{
//	string s1("hello Faye Kou");
//	cout << s1 << endl;
//	//直接对空间进行覆盖，可能会涉及到扩容
//	s1.assign("xxxx");
//	cout << s1 << endl;
//}
//void test_string5()
//{
//	string s1("hello Faye");
//	s1.insert(0,"kkk");
//	cout << s1 << endl;
//}
//void test_string6()
//{
//	string s1("fffffyyyyyyy");
//	s1.erase(5,2);
//	cout << s1 << endl;
//}
//void test_string7()
//{
//	string s1("fffffyyyyyyy");
//	s1.replace(9, 3,"k");//从第九个位置开始，将3个位置的字符串替换为k
//	cout << s1 << endl;
//	string s2("2024 10 19");
//	size_t pos = s2.find(' ');
//	while (pos != string::npos)
//	{
//		s2.replace(pos, 1, "/");
//		pos = s2.find(' ');
//	}
//	cout << sizeof(size_t) << endl;
//	cout << s2 << endl;
//}
//void test_string8()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//}
//void test_string9()
//{
//	string s1("file.cpp");
//	string s2("file.c.tar.zip");
//	size_t pos = s2.rfind('.');//rfind从后往前找
//	if (pos != string::npos)
//	{
//		string suffix = s2.substr(pos);
//		cout << suffix << endl;
//	}
//	else
//	{
//		cout << "没有后缀" << endl;
//	}
//	string url1("https://cplusplus.com/reference/string/basic_string/");
//	string url2("https://www.baidu.com/");
//	string protocol, domain, uri;
//	size_t i1 = url1.find(':');
//	size_t i2 = url1.find('/',i1+3);
//	if (i1 != string::npos)
//	{
//		protocol = url1.substr(0, i1 - 0);
//		cout << protocol << endl;
//		domain = url1.substr(i1 + 3, i2 - (i1 + 3));
//		cout << domain << endl;
//		uri = url1.substr(i2+1);
//		cout << uri << endl;
//	}
//}
////计算字符串最后一个单词的长度
//int string_num(string s)
//{
//	size_t i = s.rfind(' ');
//	int num = s.size() - (i + 1);
//	return num;
//
//}
//
//int main()
//{
//
//	string s;
//	
//	//getline(cin, s);
//
//	//cout << string_num(s) << endl;
//	char buff[] = "吃饭";
//	cout << sizeof(buff) << endl;
//	return 0;
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include"string.h"
using namespace std;
int main()
{
	//int i = 2024;
	//double d = 11.2;
	//string s1 = to_string(i);
	//string s2 = to_string(d);
	//
	//string s3 = ("19.26");
	//int i2 = stoi(s3);//将该字符串转换成int型
	//double d3 = stod(s3);//将该字符串转换成double型

	bit::test_string6();
	return 0;
}
