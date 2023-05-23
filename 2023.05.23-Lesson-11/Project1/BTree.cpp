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

void BTree::Remove(int data)
{
	Node*& node = Find(root, data);
	if (node != nullptr)
	{
		delete Extract(node);
	}
}

bool BTree::RotateLeft(int data)
{
	return RotateLeft(Find(root, data));
}

bool BTree::RotateRight(int data)
{
	return RotateRight(Find(root, data));
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

Node *& BTree::Find(Node *& node, int data)
{
	if (node == nullptr || node->data == data)
	{
		return node;
	}
	else if (node->data > data)
	{
		return Find(node->left, data);
	}
	else
	{
		return Find(node->right, data);
	}
}

Node* BTree::Extract(Node* &node)
{
	Node* res = node;
	if (node == nullptr)
	{

	}
	else if (node->left == nullptr && node->right == nullptr)
	{
		node = nullptr;
	}
	else if (node->left == nullptr)
	{
		node = node->right;
	}
	else if (node->right == nullptr)
	{
		node = node->left;
	}
	else if (node->left->right == nullptr)
	{
		node->left->right = node->right;
		node = node->left;
	}
	else if (node->right->left == nullptr)
	{
		node->right->left = node->left;
		node = node->right;
	}
	else
	{
		Node* temp = node->left;
		while (temp->right->right != nullptr)
		{
			temp = temp->right;
		}
		//Node* newRoot = Extract(temp->right); //1
		Node* newRoot = temp->right; //2
		temp->right = temp->right->left; //2

		newRoot->left = root->left;
		newRoot->right = root->right;
		root = newRoot;
	}
	return res;
}

Node* BTree::Extract1(Node* &node)
{
	Node* extracted = node;
	if (node->right != nullptr) {
		Node* temp = node->right;
		while (temp->left != nullptr) {
			temp = temp->left;
		}
		temp->left = node->left;
		node = node->right;
	}
	else {
		node = node->left;
	}
	return extracted;
}

bool BTree::RotateRight(Node* &node)
{
	if (node->left != nullptr)
	{
		Node* temp = node->left->right;
		node->left->right = node;
		node = node->left;
		node->right->left = temp;
		return true;
	}
	return false;
}

bool BTree::RotateLeft(Node* &node)
{
	if (node->right != nullptr)
	{
		Node* temp = node->right;
		node->right = temp->left;
		temp->left = node;
		node = temp;
		return true;
	}
	return false;
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

	return stream;
}