#include<iostream>
#include<set>
#include<map>
using namespace std;

void test_map()
{
	map<string,string> dict;
	pair<string, string> kv1("sort","排序");
	
	dict.insert(kv1);
	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(make_pair("right", "右边"));

	dict.insert({ "test", "测试" });//隐式类型转换

	map<string, string> dict2 = { {"left","左边"},{"right","右边"} };//initializer_list

	map<string, string>::iterator it = dict.begin();
	while (it!=dict.end())
	{
		//cout << (*it).first << ":"<<(*it).second<<endl;
		cout << it->first << ":" << it->second << endl;
		//cout<<it.operator->()->first<<":"<<it.operator()->second<<endl;
		++it;
	}
	cout << endl;
}
void test_map2()
{
	string arr[] = { "苹果","香蕉","草莓","西瓜","苹果" ,"苹果" ,"西瓜" ,"西瓜" ,"草莓" ,"香蕉" };
	map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
		/*auto it = countMap.find(e);
		if (it != countMap.end())
		{
			it->second++;
		}
		else
		{
			countMap.insert({ e,1 });
		}*/
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

}

void test_map3()
{
	map<string, string> dict;
	dict.insert({"left","左边"});
	//插入(一般不使用)
	dict["right"];
	//插入+修改
	dict["test"] = "测试";
	//查找
	cout << dict["left"] << endl;
	//修改
	dict["right"] = "右边";
	//dict.insert({"rightl","右"});
	cout << dict.count("right") << endl;
}

void test_set3()
{
	multiset<int> s = { 1,2,3,4,1,2,2,1,3 };
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	multiset<int>::iterator pos1 = s.find(1);
	while (pos1!=s.end( )&& *pos1 == 1)
	{
		cout << *pos1 << " ";
		pos1++;
	}
	cout << endl;
	
	multiset<int>::iterator pos2 = s.find(2);
	while (pos2 != s.end() && *pos2 == 2)
	{
		cout << *pos2 << " ";
		pos2++;
	}
	cout << endl;
	multiset<int>::iterator pos3 = s.find(2);
	while (pos3 != s.end())
	{
		cout << *pos3 << " ";
		pos3++;
	}
	cout << endl;
	cout << s.count(3) << endl;
}
void test_set2()
{
	set<int> s = {10,30,80,60,50,20};
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	auto a = s.lower_bound(20);
	while (a != s.end())
	{
		cout << *a << " ";
		a++;
	}
	cout << endl;
	auto b = s.upper_bound(20);
	while (b != s.end())
	{
		cout << *b << " ";
		b++;
	}

	cout << endl;
}

void test_set1()
{
	//key模型搜索
	//排序+去重
	set<string> s1;
	s1.insert("test");
	s1.insert("set");
	s1.insert("Faye");
	s1.insert("Apple");
	s1.insert("apple");
	s1.insert("apple");
	set<string>::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	set<string> s2(s1.begin(), s1.end());
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;
	s2.erase("Apple");
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;
	s2.erase("blue");
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;
}
#include"AVLTree.h"

int main()
{
	//test_map2();
	//test_set3();
	TestAVLTree1();
	return 0;
}
