#include<iostream>
using namespace std;
#include<queue>
#include<list>
#include"priority_queue.h"
void test_priority_queue1()
{
	Faye::priority_queue<int> pq1;
	//priority_queue<int> pq1;
	//priority_queue<int,vector<int>,greater<int>> pq1;
	pq1.push(2);
	pq1.push(1);
	pq1.push(3);
	pq1.push(8);
	pq1.push(5);
	

	//异常捕获
	/*try {
		while (true)
		{
			cout << pq1.top() << " ";
			pq1.pop();
		}
	}
	catch (const std::out_of_range& e) {
		std::cerr << "\nException caught: " << e.what() << std::endl;
	}*/


	while (!pq1.empty())
	{
		cout << pq1.top() << " ";
		pq1.pop();
	}

	/*pq1.pop();
	while (!pq1.empty())
	{
		cout << pq1.top() << " ";
		pq1.pop();
	}*/
}

void test_sort()
{
	vector<int> v;
	v.push_back(4);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	sort(v.begin(),v.end(),greater<int>());
	vector<int>::iterator it2 = v.begin();
	while (it2 != v.end())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;

	sort(v.begin(),v.end());
	vector<int>::iterator it3 = v.begin();
	while (it3 != v.end())
	{
		cout << *it3 << " ";
		it3++;
	}
	cout << endl;

	list<int> li;
	li.push_back(1);
	li.push_back(3);
	li.push_back(2);
	li.push_back(4);
	//li.sort();默认升序
	li.sort(greater<int>());
	list<int>::iterator it4 = li.begin();
	while (it4 != li.end())
	{
		cout << *it4 << " ";
		it4++;
	}
	cout << endl;

}

int main()
{
	test_priority_queue1();
	//test_sort();
}
