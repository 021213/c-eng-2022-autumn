#include<iostream>
#include"BTree.h"

void test(BTree& tree)
{
	while (tree.RotateLeft(tree.root));

	Node* temp = tree.root;
	while (temp->left != nullptr)
	{
		while (tree.RotateLeft(temp->left));
		temp = temp->left;
	}
	std::cout << tree << std::endl;

	tree.RotateRight(tree.root);
	tree.RotateRight(tree.root);
	std::cout << tree << std::endl;
	tree.RotateRight(tree.root);
	tree.RotateLeft(tree.root->right);

	std::cout << tree << std::endl;

}

int main(int argc, char* argv[])
{
	BTree tree;
	tree.Insert(8);
	tree.Insert(4);
	tree.Insert(12);
	tree.Insert(2);
	tree.Insert(6);
	tree.Insert(10);
	tree.Insert(14);
	std::cout << tree << std::endl;
	//tree.Remove(4);
	//tree.Remove(10);
	//tree.Remove(8);
	//tree.Remove(12);
	//tree.Remove(6);
	//std::cout << tree << std::endl;
	test(tree);
	return EXIT_SUCCESS;
}