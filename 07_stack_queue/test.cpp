#include<iostream>
#include<stack>
#include<queue>

using namespace std;
#include"stack.h"

void test_stack1()
{
	Faye::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
#include"queue.h"
void test_queue1()
{
	Faye::queue<int> qu1;
	qu1.push(1);
	qu1.push(2);
	qu1.push(3);
	qu1.push(4);

	while (!qu1.empty())
	{
		cout << qu1.front()<< " ";
		qu1.pop();
	}
	cout << endl;
}

int main()
{

	test_stack1();
	test_queue1();
	return 0;
}
