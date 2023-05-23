#include<iostream>

struct Node {
	int data;
	Node(int data) : data(data) {};
};

class BTree
{
private:
	Node** data;
	int capacity;
	int nan;

	void Expand()
	{
		Node** newData = new Node*[capacity * 2];
		for (int i = 0; i < capacity; ++i)
		{
			newData[i] = data[i];
			data[i] = nullptr;
		}
		delete[] data;
		capacity *= 2;
		data = newData;
	}

	void Insert(Node*& node, int ind)
	{
		while (ind >= capacity)
		{
			Expand();
		}
		if (data[ind] == nullptr)
		{
			data[ind] = node;
		}
		else if (data[ind]->data > node->data)
		{
			Insert(node, 2 * ind + 1);
		}
		else
		{
			Insert(node, 2 * ind + 2);
		}
	}
public:
	BTree() :data(new Node*[64]), capacity(64), nan(0)
	{
		for (int i = 0; i < capacity; ++i)
		{
			data[i] = nullptr;
		}
	};

	void Insert(int data)
	{
		Node* node = new Node(data);
		Insert(node, 0);
	}

	friend std::ostream & operator<<(std::ostream & stream, BTree& tree)
	{
		for (int i = 0; i < tree.capacity; ++i)
		{
			if (tree.data[i] != nullptr)
			{
				stream << tree.data[i]->data << " ";
			}
		}
		return stream;
	}

};

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



	return EXIT_SUCCESS;
}