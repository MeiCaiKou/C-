#pragma once

#include <assert.h>
using namespace std;
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		/*string()
			:_str(new  char[1])
			, _size(0)
			, _capacity(0)
		{}
		string(const char* str)
			:_str(new char[strlen(str)+1])
			,_size(strlen(str))
			,_capacity(strlen(str))
		{

		}*/

		const char* c_str()
		{
			return _str;
		}
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//s2(s1)
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		//s1 = s3
		string& operator=(const string& s)
		{
			char* tmp = new char[s._capacity + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//遍历
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			//扩容2倍
			/*if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';*/
			insert(_size, ch);
		}

		void append(const char* str)
		{
			/*size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;*/
			insert(_size, str);
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
		
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = end;
				--end;
			}*/
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			_size++;
			
		}
		//作业
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size == _capacity)
			{
				/*reserve(_capacity == 0 ? 4 : 2 * _capacity);*/
				reserve(_size + len);
			}
			
			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				end--;
			}
			/*for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = *str;
				*str++;
			}*/
			strncpy(_str+pos,str,len);
			_size = _size+len;

		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == pos || len >=_size -pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		void resize(size_t n,char ch='\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
				
			}
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		size_t find(char ch,size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0) const
		{
			const char* p = strstr(_str, sub);
			if (p)
			{
				return p - _str;
			}
			else
			{
				return npos;
			}
		}
		
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		static const int npos;

	};
	const int string::npos = -1;
	void test_string1()
	{
		string s1("hello world");
		
		//写
		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;//给原字符串的每个字符加1
		}
		cout << endl;
		//读
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout<<s1[i]<<" ";
		}
		cout << endl;

		const string s2("xxxxx");
		for (size_t i = 0; i < s2.size(); i++)
		{
			cout << s2[i] << " ";
		}
		cout << endl;
		

	}
	void test_string2()
	{
		string s1("hello world");
		string::iterator it1 = s1.begin();
		while (it1 != s1.end())
		{
			//*it1 -= 3;
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
		for(auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
		const string s2("xxxxx");
		string::const_iterator it2 = s2.begin();
		while (it2 != s2.end())
		{
			//*it1 -= 3;
			cout << *it2 << " ";
			++it2;
		}
		cout << endl;
		for (auto ch : s2)
		{
			cout << ch << " ";
		}

	}

	void test_string3()
	{
		string s3("hello world");
		s3.push_back('1');
		s3.push_back('2');

		cout << s3.c_str() << endl;

		s3 += 'x';
		s3 += "faye kou";
		cout << s3.c_str() << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		s1.erase(10, 7);
		cout<< s1.c_str() << endl;
		string s2("hello world");
		s2.resize(20,'j');
		cout << s2.c_str() << endl;
	}

	void test_string5()
	{
		//string s1("hello world"); 
		////拷贝构造
		//string s2(s1);

		//cout << s1.c_str() << endl;
		//cout << s2.c_str() << endl;
		//s2.append("faye");
		//cout <<"s2: "<< s2.c_str() << endl;
		//cout <<"s1: " << s1.c_str() << endl;


		string s3("uuuuuuuuu");
		string s1 = s3;
		//cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;
		cout << s3.size() << endl;//9
		cout << s3.capacity() << endl;
		s3.insert(0,"wwww");
		cout << s3.c_str() << endl;
		cout << s3.size() << endl;//13
		cout << s3.capacity() << endl;
	}
	void test_string6()
	{
		string s1("hello world");
		s1 += 'x';
		s1 += "yyyyy";
		cout << s1.c_str() << endl;
		s1.erase(0);
		cout << s1.size() << " " << s1.c_str() << endl;
		s1.insert(0, 'c');
		cout << s1.c_str() << endl;

	}
}
