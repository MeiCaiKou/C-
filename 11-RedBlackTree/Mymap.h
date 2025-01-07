#pragma once
namespace Faye
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT {
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RedBlackTree<K, pair<const K,V>, MapKeyOfT>::Iterator iterator;

		iterator begin()
		{
			return _t.Begin();
		}
		iterator end()
		{
			return _t.End();
		}
		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

	private:
		RedBlackTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
	void test_map()
	{
		map<string, int> m;
		m.insert({"苹果",1});
		m.insert({ "香蕉",2 });
		m.insert({ "草莓",3 });
		m.insert({ "梨",6 });
		map<string, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it.operator->()->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}
