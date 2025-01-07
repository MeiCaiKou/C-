#pragma once
namespace Faye {
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		
		typedef typename RedBlackTree<K,const K, SetKeyOfT>::Iterator iterator;

		iterator begin()
		{
			return _t.Begin();
		}
		iterator end()
		{
			return _t.End();
		}
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RedBlackTree<K,const K, SetKeyOfT> _t;
	};

	void test_set()
	{
		set<int> s;
		s.insert(4);
		s.insert(2);
		s.insert(5);
		s.insert(15);
		s.insert(7);
		s.insert(1);
		s.insert(5);
		s.insert(7);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			//*it += 5;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		
	}
}
