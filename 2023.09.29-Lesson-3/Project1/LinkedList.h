#pragma once

#include "List.h"

template<class T>
struct Node {
	T data;
	Node* next;
	Node(const T& data, Node<T>* next = nullptr);
	void ClearNext();
};

template<class T>
class LinkedList : public List<T>
{
public:
	LinkedList();
	~LinkedList();
	void PushForward(const T& e) override;
	void PushBackward(const T& e) override;
	void Insert(const T& e, int pos) override;
	T PopForward() override;
	T PopBackward() override;
	T Extract(int pos) override;
	size_t Size() override;
	bool IsEmpty() override;
	/*
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& list)
	{
		stream << "[" << list.size_ << "] ";
		Node<T>* temp = list.head_;
		while (temp != nullptr)
		{
			stream << temp->data << " ";
			temp = temp->next;
		}
		stream << std::endl;
		return stream;
	}
	*/

private:
	Node<T>* head_;
	size_t size_;
};
