#include "LinkedList.h"

template<class T>
Node<T>::Node(const T & data, Node<T>* next)
{
	this->data = data;
	this->next = next;
}

template<class T>
void Node<T>::ClearNext()
{
	while (next != nullptr)
	{
		Node<T>* temp = next;
		next = next->next;
		delete temp;
	}
}

template<class T>
LinkedList<T>::LinkedList()
{
	head_ = nullptr;
	size_ = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	head->ClearNext();
	delete head;
}

template<class T>
void LinkedList<T>::PushForward(const T& e)
{
	head_ = new Node<T>(e, head);
	++size_;
}

template<class T>
void LinkedList<T>::PushBackward(const T& e)
{
	Insert(e, size_);
}

template<class T>
void LinkedList<T>::Insert(const T& e, int pos)
{
	if (pos == 0)
	{
		return PushForward(e);
	}
	Node<T>* temp = head_;
	for (int i = 0; i < pos - 1; ++i)
	{
		temp = temp->next;
	}
	temp->next = new Node<T>(e, temp->next);
	++size_;
}

template<class T>
T LinkedList<T>::PopForward()
{
	--size_;
	Node<T>* temp = head_;
	T res = head_->data;
	head_ = head->next;
	delete temp;
	return res;
}

template<class T>
T LinkedList<T>::PopBackward()
{
	return Extract(size_ - 1);
}

template<class T>
T LinkedList<T>::Extract(int pos)
{
	if (pos == 0)
	{
		return PopForward();
	}
	--size_;
	Node<T>* temp = head_;
	for (int i = 0; i < pos - 1; ++i)
	{
		temp = temp->next;
	}
	Node<T>* ttemp = temp->next;
	T res = temp->data;
	temp->next = temp->next->next;
	delete ttemp;
	return res;
}

template<class T>
size_t LinkedList<T>::Size()
{
	return size_;
}

template<class T>
bool LinkedList<T>::IsEmpty()
{
	return size_ == 0;
}
