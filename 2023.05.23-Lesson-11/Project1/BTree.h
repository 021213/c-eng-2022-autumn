#pragma once
#include<ostream>

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data, Node* left = nullptr, Node* right = nullptr) :
		data(data), left(left), right(right) {}
	~Node()
	{
		//data = T();
		left = nullptr;
		right = nullptr;
	}
};

class BTree
{
private:
	Node* root;

	void Clear(Node*& node);

	void Insert(Node*& node, Node* dataNode);

	void Print(Node*& node, std::ostream& stream);

	void PrintH(Node*& node, std::ostream & stream, int depth = 0);

	Node*& Find(Node*& node, int data);

	Node* Extract(Node*& node);

	Node* Extract1(Node*& node);

	bool RotateRight(Node*& node);

	bool RotateLeft(Node*& node);

public:
	BTree() : root(nullptr) {};

	~BTree();

	void Insert(int data);

	void Remove(int data);

	bool RotateLeft(int data);

	bool RotateRight(int data);

	friend void test(BTree& tree);

	friend std::ostream & operator<<(std::ostream & stream, BTree& tree);
};
