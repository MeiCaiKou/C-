//#include<iostream>
//using namespace std;
//#include<vector>
//
//int main()
//{
//	/*vector<int > v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);*/
//
//
//	//vector<int> v1(10, 0);                                                   
//	//vector<int> v2(v1);
//	//v1.push_back(1);
//	//v1.push_back(2);
//	//v1.push_back(3);
//	//v1.push_back(4);
//	//v1.push_back(5);
//	//vector<int> v3 = v1;
//	//cout << v1.max_size() << endl;
//	//cout << v1.size() << endl;
//	//
//	////遍历
//	//cout << "范围for的遍历:";
//	//for (auto ch : v2)
//	//{
//	//	cout << ch << " ";
//	//}
//	//cout << endl;
//
//	//cout << "operator[]遍历：";
//	//for (size_t i = 0; i < v1.size(); i++)
//	//{
//	//	cout << v1[i] << " ";
//	//}
//	//cout << endl;
//
//	//cout << "迭代器遍历：";
//	//vector<int>::iterator it1 ; 
//	//for (it1= v1.begin(); it1 != v1.end(); it1++)
//	//{
//	//	cout << *it1 << " ";
//	//}
//	//cout << endl;
//
//	return 0;
//}



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void test_vector1()
{
	/*vector<int > v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);*/

	vector<int> v1(10, 0);                                                   
	vector<int> v2(v1);
	/*v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);*/

	vector<int> v3 = v1;
	cout << v1.max_size() << endl;
	cout << v1.size() << endl;
	
	//遍历
	cout << "范围for的遍历:";
	for (auto ch : v2)
	{
		cout << ch << " ";
	}
	cout << endl;

	cout << "operator[]遍历：";
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	cout << "迭代器遍历：";
	vector<int>::iterator it1 ; 
	for (it1= v1.begin(); it1 != v1.end(); it1++)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	cout << "反向迭代器：";
	vector<int> v5 = {1,2,3,4,5};
	vector<int>::reverse_iterator it2;
	for (it2 = v5.rbegin(); it2 != v5.rend(); ++it2)
	{
		cout << *it2 << " ";
	}
	cout << endl;
	
	
	cout << "const迭代器:";
	const vector<int> v6={2,0,2,0,0,3,2,8,2,6};
	vector<int>::const_iterator it3;
	for (it3 = v6.cbegin(); it3 != v6.cend(); it3++)
	{
		cout << *it3<< " ";
	}
	cout << endl;

	cout << "const_reverse迭代器：";
	const vector<string> v7 = { "hello"," world" };
	vector<string>::const_reverse_iterator it4;
	for (it4 = v7.crbegin(); it4 != v7.crend(); it4++)
	{
		cout << *it4<< " ";
	}
	cout << endl;
	
	
}

void test_vector2()
{
	vector<int> v1;
	size_t sz;
	//v1.reserve(100);
	sz = v1.capacity();
	cout << "making v1 growing:\n";
	for (int i = 0; i < 100; ++i)
	{
		v1.push_back(i);
		if (sz != v1.capacity())
		{
			sz = v1.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}

	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.reserve(10);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;

	cout << "=====================" << endl;
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.resize(10);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;

	cout << "=====================" << endl;
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.shrink_to_fit();
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;

}
void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//在3前面插入30
	//vector<int>::iterator pos = find(v.begin(),v.end(),3);
	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		v.insert(pos, 30);
	}
	//头插
	v.insert(v.begin(), 50);

	v.insert(v.begin()+1, 100);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	string s("abcd");
	v.insert(v.begin(),s.begin(),s.end());

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int>::iterator pos1 = v.begin();
	vector<int>::iterator pos2 = v.end();
	//擦除pos1到pos2之间的所有元素
	v.erase(pos1,pos2);
	//擦除pos1的元素
	v.erase(pos1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector4()
{
	//对象数组
	vector<string> v;
	string s1("苹果");
	v.push_back(s1);//有名对象

	v.push_back(string("香蕉"));//匿名对象

	v.push_back("草莓");

	vector<vector<int>> vv;  
}

#include"vector.h"
int main()
{
	//test_vector1();

	//test_vector2();

	//test_vector3();

	Faye::test_vector4();
	return 0;
}
