#pragma once
#include<vector>
#include<list>
namespace Faye
{
	template<class T,class Container = vector<T>>
	class stack
	{
	public:
		void pop()
		{
			_con.pop_back();
		}
		void push(const T& x)
		{
			_con.push_back(x);
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		const T& top()
		{
			return _con.back();
		}
	private:
		Container _con;
	};

}
