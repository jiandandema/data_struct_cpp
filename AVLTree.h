#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_
#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
class AVLTree
{
public:
	AVLTree();			//构造函数
	~AVLTree();			//析构函数

	void preOrder();	//前序遍历AVL树
	void InOrder();		//中序遍历AVL树
	void postOrder();	//后序遍历AVL树

	void print();		//打印AVL树
	void destory();		//销毁AVL树

	void insert(T key);	//插入指定值的节点
	void remove(T key);	//移除指定值的节点

	AVLNode<T>* search_recurse(T key);	//利用递归算法进行指定值的查找
	AVLNode<T>* search_iterator(T key);	//利用迭代算法进行指定值的查找
	T minimum();		//返回AVL中的最小值
	T maximum();		//返回AVL中的最大值

	int height();		//返回树的高度

private:
	AVLNode<T>* _root;	//AVL树的根节点

private:
	void preOrder(AVLNode<T>* pnode) const;
	void inOrder(AVLNode<T>* pnode) const;
	void postOrder(AVLNode<T>* pnode) const;

	void print(AVLNode<T>* pnode,T key, int direction) const;
	void destory(AVLNode<T>* & pnode);

	int height(AVLNode<T>* pnode) ;
	int max(int a, int b);

	AVLNode<T>* insert(AVLNode<T>* &pnode, T key);
	AVLNode<T>* remove(AVLNode<T>* & pnode, T key); //删除AVL树中节点pdel，并返回被删除的节点

	AVLNode<T>* minimum(AVLNode<T>*pnode)const;
	AVLNode<T>* maximum(AVLNode<T>*pnode)const;

	AVLNode<T>* search_recurse(AVLNode<T>* pnode, T key) const;
	AVLNode<T>* search_iterator(AVLNode<T>* pnode, T key) const;

	AVLNode<T>* leftRotation(AVLNode<T>* pnode);		//单旋:左旋操作
	AVLNode<T>* rightRotation(AVLNode<T>* pnode);		//单旋:右旋操作
	AVLNode<T>* leftRightRotation(AVLNode<T>* pnode);	//双旋:先左旋后右旋操作
	AVLNode<T>* rightLeftRotation(AVLNode<T>* pnode);	//双旋:先右旋后左旋操作

};

/*构造函数*/
template <typename T>
AVLTree<T>::AVLTree()
:_root(nullptr){};

/*析构函数*/
template <typename T>
AVLTree<T>::~AVLTree()
{
	destory(_root);
}

/*返回两者中的较大者*/
template<typename T>
int AVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
};

/*返回树中最大节点值*/
template <typename T>
AVLNode<T>* AVLTree<T>::maximum(AVLNode<T>* pnode)const
{
	if (pnode != nullptr)
	{
		while (pnode->_right != nullptr)
			pnode = pnode->_right;
		return pnode;
	}
	return nullptr;
};

template<typename T>
T AVLTree<T>::maximum()
{
	AVLNode<T>* presult = maximum(_root);
	if (presult != nullptr)
		return presult->_value;
};

/*返回树中最小节点值*/
template <typename T>
AVLNode<T>* AVLTree<T>::minimum(AVLNode<T>* pnode)const
{
	if (pnode != nullptr)
	{
		while (pnode->_left != nullptr)
			pnode = pnode->_left;
		return pnode;
	}
	return nullptr;
};

template<typename T>
T AVLTree<T>::minimum()
{
	AVLNode<T>* presult = minimum(_root);
	if (presult != nullptr)
		return presult->_value;
};

/*返回一棵树的高度*/
template <typename T>
int AVLTree<T>::height(AVLNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		return pnode->_height;
	}
	return 0;																//如果是空树，高度为0
};

template <typename T>
int AVLTree<T>::height()
{
	return height(_root);
};

/*左旋转操作*/
/*pnode为最小失衡子树的根节点*/
/*返回旋转后的根节点*/
template<typename T>
AVLNode<T>* AVLTree<T>::leftRotation(AVLNode<T>* proot)
{
	AVLNode<T>* prchild = proot->_right;
	proot->_right = prchild->_left;
	prchild->_left = proot;

	proot->_height = max(height(proot->_left),height(proot->_right))+1;     //更新节点的高度值
	prchild->_height = max(height(prchild->_left), height(prchild->_right)) + 1; //更新节点的高度值

	return prchild;
};

/*右旋转操作*/
/*pnode为最小失衡子树的根节点*/
/*返回旋转后的根节点*/
template <typename  T>
AVLNode<T>* AVLTree<T>::rightRotation(AVLNode<T>*proot)
{
	AVLNode<T>* plchild = proot->_left;
	proot->_left = plchild->_right;
	plchild->_right = proot;

	proot->_height = max(height(proot->_left), height(proot->_right)) + 1;     //更新节点的高度值
	plchild->_height = max(height(plchild->_left), height(plchild->_right)) + 1; //更新节点的高度值

	return plchild;
};

/*先左后右做旋转*/
/*参数proot为最小失衡子树的根节点*/
/*返回旋转后的根节点*/
template <typename T>
AVLNode<T>* AVLTree<T>::leftRightRotation(AVLNode<T>* proot)
{
	proot->_left= leftRotation(proot->_left);
	return rightRotation(proot);
};
/*先右旋再左旋*/
/*参数proot为最小失衡子树的根节点*/
/*返回旋转后的根节点*/
template<typename T>
AVLNode<T>* AVLTree<T>::rightLeftRotation(AVLNode<T>* proot)
{
	proot->_right = rightRotation(proot->_right);
	return leftRotation(proot);
};

/*插入操作*/
/*递归地进行插入*/
/*返回插入后的根节点*/
template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* &pnode, T key)
{
	if (pnode == nullptr)	//寻找到插入的位置
	{
		pnode = new AVLNode<T>(key, nullptr, nullptr);
	}
	else if (key > pnode->_value)	//插入值比当前结点值大，插入到当前结点的右子树上
	{
		pnode->_right = insert(pnode->_right, key);
		if (height(pnode->_right) - height(pnode->_left) == 2) //插入后出现失衡
		{
			if (key > pnode->_right->_value) //情况一：插入右子树的右节点，进行左旋
				pnode=leftRotation(pnode);
			else if (key < pnode->_right->_value)  //情况三：插入右子树的左节点,进行先右再左旋转
				pnode=rightLeftRotation(pnode);
		}
	}
	else if (key < pnode->_value) //插入值比当前节点值小，插入到当前结点的左子树上
	{
		pnode->_left = insert(pnode->_left, key);
		if (height(pnode->_left) - height(pnode->_right) == 2) //如果插入导致失衡
		{
			if (key < pnode->_left->_value)		//情况二：插入到左子树的左孩子节点上，进行右旋
				pnode = rightRotation(pnode);
			else if (key>pnode->_left->_value)
				pnode = leftRightRotation(pnode);//情况四：插入到左子树的右孩子节点上，进行先左后右旋转
		}
	}
	pnode->_height = max(height(pnode->_left), height(pnode->_right)) + 1;
	return pnode;
};

template <typename T>
void AVLTree<T>::insert(T key)
{
	insert(_root, key);
};


/*递归查找指定元素*/
template <typename T>
AVLNode<T>* AVLTree<T>::search_recurse(T key)
{
	return search_recurse(_root,key);
};
template <typename T>
AVLNode<T>* AVLTree<T>::search_recurse(AVLNode<T>* pnode, T key) const
{
	if (pnode != nullptr)
	{
		if (key == pnode->_value)
			return pnode;
		if (key > pnode->_value)
			return search_recurse(pnode->_right,key);
		else
			return search_recurse(pnode->_left,key);
	}
	return nullptr;
};

/*非递归查找指定元素*/
template <typename T>
AVLNode<T>* AVLTree<T>::search_iterator(T key)
{
	return search_iterator(_root, key);
};
template <typename T>
AVLNode<T>* AVLTree<T>::search_iterator(AVLNode<T>* pnode, T key) const
{
	while (pnode != nullptr)
	{
		if (pnode->_value == key)
			return pnode;
		else if (key > pnode->_value)
			pnode = pnode->_right;
		else
			pnode = pnode->_left;
	}
	return nullptr;
};


/*删除指定元素*/
template<typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* & pnode, T key)
{
	if (pnode != nullptr)
	{
		if (key == pnode->_value)			//找到删除的节点
		{
			//因AVL也是二叉排序树，删除节点要维护其二叉排序树的条件
			if (pnode->_left != nullptr&&pnode->_right != nullptr)		//若左右都不为空
			{
				if (height(pnode->_left) > height(pnode->_right))		//左子树比右子树高
				{
					//使用左子树最大节点来代替被删节点，而删除该最大节点
					AVLNode<T>* ppre = maximum(pnode->_left);		//左子树最大节点
					pnode->_value = ppre->_value;								//将最大节点的值覆盖当前结点
					pnode->_left = remove(pnode->_left, ppre->_value);	//递归地删除最大节点
				}
				else
				{
					//使用最小节点来代替被删节点，而删除该最小节点
					AVLNode<T>* psuc = minimum(pnode->_right);		//右子树的最小节点
					pnode->_value = psuc->_value;								//将最小节点值覆盖当前结点
					pnode->_right = remove(pnode->_right, psuc->_value);	//递归地删除最小节点
				}

			}
			else
			{
				AVLNode<T> * ptemp = pnode;
				if (pnode->_left != nullptr)
					pnode = pnode->_left;
				else if (pnode->_right != nullptr)
					pnode = pnode->_right;
				delete ptemp;
				return nullptr;
			}

		}
		else if (key > pnode->_value)		//要删除的节点比当前节点大，则在右子树进行删除
		{
			pnode->_right =  remove(pnode->_right, key);
			if (height(pnode->_left) - height(pnode->_right) == 2) //删除右子树节点导致不平衡:相当于情况二或情况四
			{
				if (height(pnode->_left->_right)>height(pnode->_left->_left))
					pnode = leftRightRotation(pnode);				//相当于情况四
				else
					pnode = rightRotation(pnode);					//相当于情况二
			}
		}
		else if (key < pnode->_value)		//要删除的节点比当前节点小，则在左子树进行删除
		{
			pnode->_left= remove(pnode->_left, key);
			if (height(pnode->_right) - height(pnode->_left) == 2)  //删除左子树节点导致不平衡：相当于情况三或情况一
			{
				if (height(pnode->_right->_left)>height(pnode->_right->_right))
					pnode = rightLeftRotation(pnode);
				else
					pnode = leftRotation(pnode);
			}
		}
		return pnode;
	}
	return nullptr;
};
template<typename T>
void AVLTree<T>::remove(T key)
{
	_root =remove(_root, key);
};
/*中序遍历*/
template<typename T>
void AVLTree<T>::inOrder(AVLNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
		inOrder(pnode->_left);
		cout << pnode->_value << endl;
		inOrder(pnode->_right);
	}
};

template<typename T>
void AVLTree<T>::InOrder()
{
	inOrder(_root);
};

/*前序遍历*/
template<typename T>
void AVLTree<T>::preOrder(AVLNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
		cout << pnode->_value << endl;
		inOrder(pnode->_left);
		inOrder(pnode->_right);
	}
};
template<typename T>
void AVLTree<T>::preOrder()
{
	preOrder(_root);
};

/*后列遍历*/
template<typename T>
void AVLTree<T>::postOrder(AVLNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
		inOrder(pnode->_left);
		inOrder(pnode->_right);
		cout << pnode->_value << endl;
	}
}
template<typename T>
void AVLTree<T>::postOrder()
{
	postOrder(_root);
};


/*销毁AVL树*/
template<typename T>
void AVLTree<T>::destory(AVLNode<T>* & pnode)
{
	if (pnode != nullptr)
	{
		destory(pnode->_left);
		destory(pnode->_right);
		delete pnode;
		pnode = nullptr;
	}
};
template<typename T>
void AVLTree<T>::destory()
{
	destory(_root);
}
#endif