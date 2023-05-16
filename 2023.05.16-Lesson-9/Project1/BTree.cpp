#include "BTree.h"

void BTree::Clear(Node*& node)
{
	if (node == nullptr) return;
	Clear(node->left);
	Clear(node->right);
	delete node;
}

void BTree::Insert(Node*& node, Node* dataNode)
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

void BTree::Insert(int data)
{
	Insert(root, new Node(data));
}

void BTree::Print(Node*& node, std::ostream & stream)
{
	if (node == nullptr)
	{
		return;
	}
	Print(node->left, stream);
	stream << node->data << " ";
	Print(node->right, stream);
}

void BTree::PrintH(Node*& node, std::ostream & stream, int depth)
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

void BTree::PrintV(Node *& node, std::ostream & stream)
{

}

BTree::~BTree() {
	Clear(root);
	root = nullptr;
}

std::ostream & operator<<(std::ostream & stream, BTree& tree)
{
	stream << "print" << std::endl;
	tree.Print(tree.root, stream);

	stream << std::endl << "print horizontal" << std::endl;
	tree.PrintH(tree.root, stream);

	stream << std::endl << "print vertical" << std::endl;
	tree.PrintV(tree.root, stream);

	return stream;
}