#pragma once
#include<assert.h>
namespace Faye {

	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}
		//v2(v1)
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector(initializer_list<T> li)
		{
			reserve(li.size());
			for (auto e : li)
			{
				push_back(e);
				
			}
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * old_size);
				delete[] _start;

				_start = tmp;
				_finish = tmp + old_size;
				_end_of_storage = tmp + n;
			}

		}
		void resize(size_t n, const T& val = T())
		{
			if (n > size())
			{
				//插入
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				//删除
				_finish = _start + n;
			}
		}
		T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		size_t capacity() const 
		{
			return _end_of_storage - _start;
		}
		void push_back(const T& val)
		{
			//if (_finish == _end_of_storage)
			//{
			//	/*size_t old_size = size();
			//	size_t newcapacity = capacity()== 0 ? 4 : capacity() * 2;
			//	T* tmp = new T[newcapacity];
			//	memcpy(tmp, _start, size() * sizeof(T));
			//	delete[] _start;

			//	_start = tmp; 
			//	_finish = tmp + old_size;
			//	_end_of_storage = tmp + newcapacity;*/
			//	reserve(capacity() == 0 ? 4 : capacity() * 2);
			//}
			//*_finish = val;
			//++_finish;
			insert(end(), val);
		}

		void pop_back()
		{
			/*assert(!empty());
			--_finish;*/
			erase(end());
			
		}

		bool empty()
		{
			return _start == _finish;
		} 
		void insert(iterator pos,const T& value )
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;//获取相对位置
				reserve(capacity()== 0 ? 4: capacity()*2);

				//如果发生扩容，pos要进行更新，否则会发生迭代器失效(pos为野指针)
				pos = _start + len;
			}
			iterator it = _finish - 1;
			while(it>=pos)
			{
				*(it + 1) = *it;
				--it;
			}
			*pos = value;
			++_finish;
		}
		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator it = pos ;
			while (it < _finish)
			{
				*it = *(it + 1);
				++it;
			}
			_finish--;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;


	};

	void print_vector(const vector<int>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}cout << endl;

		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	
	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		print_vector(v);
		v.insert(v.begin()+2, 9);
		print_vector(v);
		v.erase(v.begin());
		print_vector(v);
		/*for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;*/
	}
	void test_vector2()
	{
		int i = 3;
		int j = int();
		int k = int(6);
		cout << i << " " << j << " " << k << endl;
	}
	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		
		vector<int> v2(v1);
		vector<int> v3 = v1;
	}
	void test_vector4()
	{
		//单参数的构造函数，隐式类型转换
		string s1 = "1111";//构造+拷贝构造-》优化  直接构造

		//string& str = "1111";
		const string& str1 = "11111";//临时变量具有常性

		std::vector<int> v = {1,2,3,4};
		std::vector<int> v1({ 10,1,20,2 });
		vector<int> v4;
		v4.push_back(1);
		v4.push_back(2);
		v4.push_back(3);
		v4.push_back(4);
		v4.push_back(5);
		print_vector(v4);
		vector<int> v5(v4.begin()+1,v4.end()-1);
		print_vector(v4);
		cout << "========================" << endl;
		print_vector(v5);
		cout << "========================" << endl;
		vector<int> v6(10u,1);
		print_vector(v6);

		vector<int> v7({1,2,3,4});
		print_vector(v7);
		cout << "========================" << endl;
		vector<int> v8={ 1,2,3,4 };
		print_vector(v8);
	}
}
