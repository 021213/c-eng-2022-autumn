#pragma once
#include<ostream>
#include<queue>

template<class T>
struct Node
{
	T data;
	Node* left;
	Node* right;
	Node(T data, Node* left = nullptr, Node* right = nullptr) :
		data(data), left(left), right(right) {}
	~Node()
	{
		//data = T();
		left = nullptr;
		right = nullptr;
	}
};

template<class T>
class BTree
{
private:
	Node<T>* root;

	void Clear(Node<T>*& node);

	void Insert(Node<T>*& node, Node<T>* dataNode);

	void Print(Node<T>*& node, std::ostream& stream);

	void PrintH(Node<T>*& node, std::ostream & stream, int depth = 0);

	void PrintV(Node<T>*& node, std::ostream & stream);

	int Count(Node<T>*&node);

	int Height(Node<T>*&node);

	int Depth(Node<T>*&node);

	void TravelHLR(Node<T>*& node, std::queue<Node<T>*> &q)
	{
		if (node == nullptr)
		{
			return;
		}
		q.push(node);
		TravelHLR(node->left, q);
		TravelHLR(node->right, q);
	}

public:
	BTree<T>() : root(nullptr) {};

	~BTree<T>() { Clear(root); }

	void Insert(T data) { Insert(root, new Node<T>(data)); }

	int Size() { return Count(root); }

	int Height() { return Height(root); }

	friend std::ostream & operator<<(std::ostream & stream, BTree& tree)
	{
		stream << "print" << std::endl;
		tree.Print(tree.root, stream);

		stream << std::endl << "print horizontal" << std::endl;
		tree.PrintH(tree.root, stream);

		stream << std::endl << "print vertical" << std::endl;
		tree.PrintV(tree.root, stream);

		return stream;
	}
};

template<class T>
inline void BTree<T>::Clear(Node<T>*& node)
{
	if (node == nullptr) return;
	Clear(node->left);
	Clear(node->right);
	delete node;
}

template<class T>
inline void BTree<T>::Insert(Node<T>*& node, Node<T>* dataNode)
{
	if (node == nullptr)
	{
		node = dataNode;
	}
	else if (node->data < dataNode->data)
	{
		Insert(node->right, dataNode);
	}
	else if (node->data > dataNode->data)
	{
		Insert(node->left, dataNode);
	}
	else
	{
		delete dataNode;
	}
}

template<class T>
inline void BTree<T>::Print(Node<T>*& node, std::ostream& stream)
{
	if (node == nullptr)
	{
		return;
	}
	Print(node->left, stream);
	stream << node->data << " ";
	Print(node->right, stream);
}

template<class T>
inline void BTree<T>::PrintH(Node<T>*& node, std::ostream & stream, int depth)
{
	if (node == nullptr)
	{
		return;
	}
	PrintH(node->right, stream, depth + 1);
	for (int i = 0; i < depth; ++i)
	{
		stream << "\t";
	}
	stream << node->data << std::endl;
	PrintH(node->left, stream, depth + 1);
}

template<class T>
inline void BTree<T>::PrintV(Node<T>*& node, std::ostream & stream)
{
	std::queue<Node<T>*> q;
	TravelHLR(node, q);
	
	while (!q.empty()) {
		stream << '\t' << q.front()->data;
		q.pop();
	}
}

template<class T>
inline int BTree<T>::Count(Node<T>*& node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return 1 + Count(node->left) + Count(node->right);
}

template<class T>
inline int BTree<T>::Height(Node<T>*& node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int leftH = Height(node->left);
	int rightH = Height(node->right);
	return (leftH < rightH ? rightH : leftH) + 1;
}

template<class T>
inline int BTree<T>::Depth(Node<T>*& node)
{
	return Height(root) - Height(node);
}
