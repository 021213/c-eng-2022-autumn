#include<iostream>
#include"BTree.h"

int main(int argc, char* argv[])
{
	BTree<int> tree;
	tree.Insert(8);
	tree.Insert(4);
	tree.Insert(12);
	tree.Insert(2);
	tree.Insert(6);
	tree.Insert(10);
	tree.Insert(14);
	std::cout << "COUNT " << tree.Size() << std::endl;
	std::cout << "HEIGHT " << tree.Height() << std::endl;
	std::cout << tree << std::endl;
	return EXIT_SUCCESS;
}