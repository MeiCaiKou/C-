#pragma once
namespace Faye {

	template<class T>
	struct ListNode
	{
		 ListNode<T>* _next;
		 ListNode<T>* _prev;
		 T _data;

		 ListNode(const T& x=T())
			 :_next(nullptr)
			 ,_prev(nullptr)
			 ,_data(x)
		 {}

	};

	template<class T,class Ref,class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T,Ref,Ptr> Self;
		Node* _node;

		ListIterator(Node* node)
			:_node(node)
		{}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator !=(const Self& it)
		{
			return _node != it._node;
		}
		bool operator ==(const Self& it)
		{
			return _node == it._node;
		}
	};

	/*template<class T>
	struct ListConstIterator
	{
		typedef ListNode<T> Node;
		typedef ListConstIterator<T> Self;
		Node* _node;

		ListConstIterator(Node* node)
			:_node(node)
		{}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		const T& operator*()
		{
			return _node->_data;
		}
		const T* operator->()
		{
			return &_node->_data;
		}
		bool operator !=(const Self& it)
		{
			return _node != it._node;
		}
		bool operator ==(const Self& it)
		{
			return _node == it._node;
		}
	};*/

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		
	public:
		/*typedef ListIterator<T> iterator;
		typedef ListConstIterator<T> const_iterator;*/
		
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
			 
		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}
		list()
		{
			empty_init();
		}
		//拷贝构造
		list(const list<T>& It)
		{
			empty_init();
			for (auto& e : It)
			{
				push_back(e);
			}
		}

		void swap(list<T>& It)
		{
			std::swap(_head,It._head);
			std::swap(_size, It._size);
		}
		//赋值构造
		list<T>& operator=(list<T> It)
		{
			swap(It);
			return *this;
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			_head->_prev = newnode;
			newnode->_next = _head;

			_size++;*/
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos,const T& val)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(val);
			Node* prev = cur->_prev;


			prev->_next = newnode;
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			_size++;
		}
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete[] cur;
			_size--;
			return iterator(next);
		}
		void size() const
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
	private:
		Node* _head;
		size_t _size;
	};

	void test_list1()
	{
		list<int> It;
		It.push_back(1);
		It.push_back(2);
		It.push_back(3);
		It.push_back(4);

		list<int>::iterator it1 = It.begin();
		while (it1 != It.end())
		{
			cout << *it1 << " ";
			it1++;
		}

		cout << endl;
		It.pop_back();
		It.pop_front();

		list<int>::iterator it2 = It.begin();
		while (it2 != It.end())
		{
			cout << *it2 << " ";
			it2++;
		}
		cout << endl;

		It.push_front(0);
		It.push_back(1);

		list<int>::iterator it3 = It.begin();
		while (it3 != It.end())
		{
			cout << *it3 << " ";
			it3++;
		}
		cout << endl;
		
	}

	struct A
	{
		int _a1;
		int _a2;

		A(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}
	};

	void test_list2()
	{
		list<A> lt;
		A aa1(1, 1);
		A aa2 = { 1, 1 };
		lt.push_back(aa1);
		lt.push_back(aa2);
		lt.push_back(A(2, 2));
		lt.push_back({ 3, 3 });
		lt.push_back({ 4, 4 });

		A* ptr = &aa1;
		(*ptr)._a1;
		ptr->_a1;

		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it += 10;
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			cout << it->_a1 << ":" << it->_a2 << endl;
			cout << it.operator->()->_a1 << ":" << it.operator->()->_a2 << endl;

			++it;
		}
		cout << endl;
	}

	void PrintList(const list<int>& clt)
	{
		list<int>::const_iterator it = clt.begin();
		while (it != clt.end())
		{
			//*it += 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		PrintList(lt);

		list<int> lt1(lt);
		cout << "lt1:";
		PrintList(lt1);

		list<int> lt2 = lt;
		cout << "lt2:";
		PrintList(lt2);
	}

}
