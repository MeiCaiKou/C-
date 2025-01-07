#pragma once

enum Colour {
	Red,
	Black
};

template<class T>
struct RBNode
{
	RBNode<T>* _left;
	RBNode<T>* _right;
	RBNode<T>* _parent;
	T _data;
	Colour _col;

	RBNode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_col(Red)
	{}

};

template<class T,class Ref,class Ptr>
struct __RBTreeIterator
{
	typedef RBNode<T> Node;
	typedef __RBTreeIterator<T,Ref, Ptr> Self;
	Node* _node;
	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}
	bool operator !=(const Self& s)
	{
		return _node != s._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			Node* leftMin = _node->_right;
			while (leftMin->_left)
			{
				leftMin = leftMin->_left;
			}
			_node = leftMin;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
};

template<class K, class T, class KeyOfT >
class RedBlackTree
{
	typedef RBNode<T> Node;
	
public:
	typedef __RBTreeIterator<T, T&, T*> Iterator;

	Iterator Begin()
	{
		Node* leftMin = _root;
		while (leftMin && leftMin->_left)
		{
			leftMin = leftMin->_left;
		}
		return Iterator(leftMin);
	}
	Iterator End()
	{
		return Iterator(nullptr);
	}


	void RotateLeft(Node* node)
	{
		Node* rightChild = node->_right;
		node->_right = rightChild->_left;
		if (rightChild->_left)
		{
			rightChild->_left->_parent = node;
		}
		rightChild->_parent = node->_parent;
		if (node->_parent == nullptr)
		{
			_root = rightChild;
		}
		else if (node == node->_parent->_left)
		{
			node->_parent->_left = rightChild;
		}
		else
		{
			node->_parent->_right = rightChild;
		}
		rightChild->_left = node;
		node->_parent = rightChild;
	}
	void RotateRight(Node* node)
	{
		Node* leftChild = node->_left;
		node->_left = leftChild->_right;
		if (leftChild->_right)
		{
			leftChild->_right->_parent = node;
		}
		leftChild->_parent = node->_parent;
		if (node->_parent == nullptr)
		{
			_root = leftChild;
		}
		else if (node == node->_parent->_left)
		{
			node->_parent->_left = leftChild;
		}
		else
		{
			node->_parent->_right = leftChild;
		}
		leftChild->_right = node;
		node->_parent = leftChild;
	}
	bool Insert(const T& data)
	{
		
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = Black;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		KeyOfT kot;
		//定位插入的位置
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}

		cur = new Node(data);
		cur->_col = Red;
		if (kot(parent->_data) <kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;
		//----------------以上是二叉搜索树的插入，下面是红黑树的调整--------------

		while (cur->_parent && cur->_parent->_col == Red)
		{
			Node* parent = cur->_parent;
			Node* grandParent = parent->_parent;
			if (parent == grandParent->_left)//父亲是爷爷的左
			{
				Node* uncle = grandParent->_right;
				if (uncle && uncle->_col == Red)//红叔
				{
					parent->_col = Black;
					uncle->_col = Black;
					grandParent->_col = Red;
					cur = grandParent;
				}
				else//黑叔
				{
					if (cur == parent->_right)
					{
						cur = parent;
						RotateLeft(cur);//左旋父结点
						
					}
					RotateRight(grandParent);
					parent->_col = Black;
					grandParent ->_col = Red;

				}
			}
			else//父亲是爷爷的右
			{
				Node* uncle = grandParent->_left;
				if (uncle && uncle->_col == Red)//红叔
				{
					parent->_col = Black;
					uncle->_col = Black;
					grandParent->_col = Red;
					cur = grandParent;
				}
				else//黑叔
				{
					if (cur == parent->_left)
					{
						cur = parent;
						RotateRight(cur);//右旋父结点

					}
					RotateLeft(grandParent);
					parent->_col = Black;
					grandParent->_col = Red;

				}
			}
		}
		_root->_col = Black;
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	bool IsBalance()
	{
		if (_root->_col == Red)
		{
			return false;
		}
		return Check(_root);
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << kot(root->_data) << endl;
		_InOrder(root->_right);
	}

	bool Check(Node* root)
	{
		if (root->_parent == nullptr)
			return true;

		if (root->_col == Red && root->_parent->_col == Red)
		{
			cout << kot(root)<< "存在连续的红色结点" << endl;
			return false;
		}
		return Check(root->_left)
			&& Check(root->_right);
	}
private:
	Node* _root = nullptr;

};

//void TestRBTree1()
//{
//	int a1[] = {17,18,23,34,27,15,9,6,8,5,25};
//	RedBlackTree<int,int,> t1;
//	for (auto e: a1)
//	{
//		t1.Insert({e,e});
//		cout << "Insert:" << e << "->" << t1.IsBalance() << endl;
//	}
//	t1.InOrder();
//
//	cout << "IsBalance：" << t1.IsBalance() << endl;
//}
