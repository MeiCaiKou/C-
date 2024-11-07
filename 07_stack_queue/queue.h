#pragma once
#include<vector>
#include<list>
namespace Faye
{
	template<class T>
	class queue
	{
	public:
		void pop()
		{
			_con.pop_front();
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
		T& back()
		{
			return _con.back();
		}
		const T& back() const
		{
			return _con.back();
		}
		T& front()
		{
			return _con.front();
		}
		const T& front() const
		{
			return _con.front();
		}
	private:
		std::list<T> _con;
	};

}
