#include<iostream>
#include<stack>
#include<ostream>

template<class T>
class Set{
public:
	void Insert(const T& data);
	int Size();
	friend std::ostream& operator<<(
		std::ostream& stream,
		const Set<T>& set);
private:
	Node<T>* _root;
	template<class T>
	struct Node {
		T data;
		Node<T>* right;
		Node<T>* left;
		Node(T data, Node<T>* left = nullptr, Node<T>* right = nullptr) :
			data(data), left(left), right(right) {}
		~Node() {}
	};
	void print(ostream& stream);
	void insert(Node<T>*& node, const T& data);
	int size(Node<T>*& node);
};

int main(int argc, char* argv[])
{
	return EXIT_SUCCESS;
}

template<class T>
void Set<T>::Insert(const T & data)
{
	insert(_root, data);
}

template<class T>
int Set<T>::Size()
{
	return size(_root);
}

template<class T>
void Set<T>::print(ostream & stream)
{
	std::stack<Node<T>*> s;
	Node<T>* temp = _root;
	stream << "[" << Size() << "] ";
	while (temp != nullptr || !s.empty())
	{
		while (temp != nullptr)
		{
			s.push(temp);
			temp = temp->left;
		}
		temp = s.top();
		s.pop();
		stream << temp->data << " ";
		temp = temp->right;
	};
	stream << std::endl;
}

template<class T>
void Set<T>::insert(Node<T>*& node, const T & data)
{
	if (node == nullptr)
	{
		node = new Node<T>(data);
	}
	Node<T>* temp = node;
	while (temp->data != data)
	{
		if (temp->data < data)
		{
			if (temp->right == nullptr) {
				temp->right = new Node<T>(data);
			}
			temp = temp->right;
		}
		else
		{
			if (temp->left == nullptr) {
				temp->left = new Node<T>(data);
			}
			temp = temp->left;
		}
	}
}

template<class T>
int Set<T>::size(Node<T>*& node)
{
	int res = 0;
	std::stack<Node<T>> s;
	s.push(node);
	while (!s.empty())
	{
		Node<T>* t = s.top();
		s.pop();
		++res;
		t = t->left;
		while (t) {
			s.push(t);
		}
	}
	return res;
}

template<class T>
std::ostream & operator<<(std::ostream & stream, const Set<T>& set)
{
	set.print(stream);
	return stream;
}
