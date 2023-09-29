#pragma once

struct Node {
	int data;
	Node* next;
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node() { next = nullptr; }
};

class CycleList
{
private:
	Node* tail;

	int IndexValid(int pos)
	{
		return (pos >= 0 && pos < len());
	}
	void removeData(Node* node);
	Node* copyData(Node* node) const;
	int nan = 0;

public:
	CycleList() :tail(nullptr) {};
	//LinkedList(const LinkedList& list);
	//~LinkedList();
	CycleList& push_forward(int el)
	{
		if (tail == nullptr)
		{
			tail = new Node(el);
			tail->next = tail;
		}
		else
		{
			tail->next = new Node(el, tail->next);
		}
		return *this;
	}
	CycleList& push_back(int el)
	{
		push_forward(el);
		tail = tail->next;
		return *this;
	}
	CycleList& insert(int el, int pos)
	{
		if (pos == 0)
		{
			return push_forward(el);
		}
		if (IndexValid(el))
		{
			Node* temp = tail;
			while (pos > 1)
			{
				temp = temp->next;
				--pos;
			}
			temp->next = new Node(el, temp->next);
		}
		return *this;
	}
	int extract_forward()
	{
		int res = -1;
		if (tail != nullptr)
		{
			if (tail->next != tail)
			{
				Node* extracted = tail->next;
				tail->next = tail->next->next;
				res = extracted->data;
				delete extracted;
			}
			else
			{
				res = tail->data;
				delete tail;
				tail = nullptr;
			}
		}
		return res;
	}
	int extract_back();
	int extract(int pos);
	CycleList& remove_forward()
	{
		extract_forward();
		return *this;
	}
	CycleList& remove_back();
	CycleList& remove(int pos);
	void clear();
	LinkedList& operator=(LinkedList& list);
	int& operator[](int index);
	int len()
	{
		int res = 0;
		Node* temp = tail;
		do
		{
			++res;
			temp = temp->next;
		} while (temp != tail);
		return res;	
	};
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);
};