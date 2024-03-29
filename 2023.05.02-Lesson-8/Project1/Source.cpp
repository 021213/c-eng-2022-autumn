#include<iostream>
#include"LinkedList.h"

void printList(LinkedList list)
{
	LinkedList b;
	b = list;
	std::cout << "copy and assign" << b << std::endl;
}

void swap(int& a, int& b)
{
	a ^= b ^= a ^= b;
}

void reverse(LinkedList& list)
{
	for (int i = 0; i < list.len() / 2; ++i)
	{
		swap(list[i], list[list.len() - 1 - i]);
	}
}

int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list << std::endl;
	list.push_forward(1);
	std::cout << list << std::endl;
	list.push_back(5).push_back(6);
	std::cout << list << std::endl;
	list.insert(3, 1).insert(2, 1).insert(4, 3);
	std::cout << list << std::endl;
	std::cout << "EXTRACT FORWARD    : " << list.extract_forward() << " " << list << std::endl;
	std::cout << "EXTRACT BACKWARD   : " << list.extract_back() << " " << list << std::endl;
	std::cout << "EXTRACT FROM POS 2 : " << list.extract(2) << " " << list << std::endl;
	std::cout << "EXTRACT FROM POS 2 : " << list.extract(2) << " " << list << std::endl;
	std::cout << "EXTRACT FROM POS 2 : " << list.extract(2) << " " << list << std::endl;
	std::cout << "EXTRACT FROM POS 0 : " << list.extract(0) << " " << list << std::endl;
	std::cout << "EXTRACT FORWARD    : " << list.extract_forward() << " " << list << std::endl;

	printList(list);

	list.push_back(0).push_back(1).push_back(2).push_back(3).push_back(4).push_back(5).push_back(6);
	std::cout << list << std::endl;
	for (int i = 0; i < list.len(); ++i)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;

	reverse(list);
	std::cout << list << std::endl;

	return EXIT_SUCCESS;
}

/*
1. Implement a method that swaps two elements of the list (change only pointers)
private: extractHeadNode, extractTailNode, extractNode
         insertHeadNode, insertTailNode, insertNode
	void swap(int i, int j)
	{
		if (!IndexValid(i) || !IndexValid(j)) return;
		if (i > j) return swap(j, i);
		Node second = extractNode(j);
		Node first = extractNode(i);
		insertNode(second, i);
		insertNode(first, j);
	}

2. Implement a function that merges two lists. You might need some new methods.
3. Implement Merge Sort algorithm for linked list.
8|6|4|9|3|5|1|7 - eight sorted lists
6 8|4 9|3 5|1 7 - four sorted lists
4 6 8 9|1 3 5 7 - two sorted lists
1 3 4 5 6 7 8 9 - one sorted list

*/