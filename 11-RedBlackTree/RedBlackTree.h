#pragma once
#include<vector>
enum Colour
{
	RED,
	BLACK
};
template<class K,class V>
struct RBNode
{
	RBNode<K,V>* _left;
	RBNode<K,V>* _right;
	RBNode<K,V>* _parent;
	pair<K, V> _kv;
	Colour _col;

	RBNode(const pair<K,V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_kv(kv)
		,_col(RED)
	{}

};
template<class K, class V>
class RedBlackTree
{
	typedef RBNode<K, V> Node;
public:

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;

		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* ppNode = parent->_parent;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_right == parent)
			{
				ppNode->_right = subR;
			}
			else
			{
				ppNode->_left = subR;
			}
			subR->_parent = ppNode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;

		Node* ppNode = parent->_parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		RotateL(parent->_left);
		RotateR(parent);
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		RotateR(subR);
		RotateL(parent);
	}
	bool Insert(const pair<K,V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		while(parent && parent->_col == RED)
		{ 
			Node* grandfather = parent->_parent;
			if (parent== grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//叔红，叔父爷变色，爷爷变插入结点
				if (uncle && uncle->_col == RED)
				{
					uncle->_col = BLACK;
					parent->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						RotateLR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					uncle->_col = BLACK;
					parent->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						RotateRL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}

		_root->_col = BLACK;
		return true;
	}

	
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	bool IsBalance()
	{
		if (_root->_col == RED)
		{
			return false;
		}
		return Check(_root);
	}
private:
	bool Check(Node* root)
	{
		if (root->_parent == nullptr)
			return true;

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "存在连续的红色结点" << endl;
			return false;
		}
		return Check(root->_left)
			&& Check(root->_right);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}
private:
	Node* _root=nullptr;
	
};

void TestRBTree1()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14,8, 3, 1, 10, 6, 4, 7, 14, 13 };
	RedBlackTree<int, int> t1;
	for (auto e : a)
	{
		if (e == 10)
		{
			int i = 0;
		}
		  
		// 1、先看是插入谁导致出现的问题
		// 2、打条件断点，画出插入前的树
		// 3、单步跟踪，对比图一一分析细节原因
		t1.Insert({ e,e});

		cout << "Insert:" << e << "->" << t1.IsBalance() << endl;
	}

	t1.InOrder();
	

	cout << t1.IsBalance() << endl;

}
