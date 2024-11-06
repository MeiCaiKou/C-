//#include<iostream>
//#include<list>
//using namespace std;
//
//int main()
//{
//	list<int> li1 = { 1,9,3,4,5 };
//	li1.push_back(6);
//	li1.begin();
//	list<int> li2 = { 7,8,9,10 };
//	list<int>::iterator it3 = li2.begin();
//	list<int>::iterator it4 = li2.end() ;
//	list<int>::iterator it1 = li1.begin();
//	list<int> ::iterator it2 = li1.end();
//
//	li2.push_back(3);
//	li2.push_back(4);
//	li2.push_back(1);
//	li2.push_back(7);
//	li1.sort();
//	li2.sort();
//	li1.merge(li2);
//	//li1.splice(li1.end(),li1,li1.begin());
//	//li1.splice(it1,li2,it3,it4);
//	
//	for (auto e : li1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	li1.unique();
//	for (auto e : li1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	li1.reverse();
//
//	for (auto e : li1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	/*list<int>::iterator it2 = li1.end();
//	li1.splice(it2, li2);
//	for (auto e : li1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;*/
//	return 0;
//}

#include<iostream>
using namespace std;
#include "list.h"

int main()
{
	Faye::test_list3();
	return 0;
}
