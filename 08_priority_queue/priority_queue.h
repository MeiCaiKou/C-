#pragma once
#include<list>
#include<deque>
namespace Faye {
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x< y;
		}
	};
	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		void adjust_up(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com( _con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		void adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
			
		}
		void pop()
		{
			/*if (_con.empty())
			{
				throw std::out_of_range("PriorityQueue is empty");
			}*/
			swap(_con[0], _con[_con.size()-1]);
			_con.pop_back();
			adjust_down(0);
		}
		size_t size() const
		{
			return _con.size();
		}
		const T& top() const
		{
		/*	if (_con.empty())
			{
				throw std::out_of_range("PriorityQueue is empty");
			}*/
			return _con[0];
		}
		bool empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
