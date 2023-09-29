#include<iostream>
#include<exception>
#include<ostream>

class ListException : public std::exception
{
public:
	const char* what() const throw() override
	{
		return "Wrong operation with list";
	}
};

template<class T>
class List
{
public:
	virtual ~List() {};
	virtual void PushForward(const T& e) = 0;
	virtual void PushBackward(const T& e) = 0;
	virtual void Insert(const T& e, int pos) = 0;
	virtual T PopForward() = 0;
	virtual T PopBackward() = 0;
	virtual T Extract(int pos) = 0;
	virtual size_t Size() = 0;
	virtual bool IsEmpty() = 0;
};

template<class T>
class LinkedList : public List<T>
{
public:
	LinkedList() : head_(nullptr), size_(0) {}
	~LinkedList()
	{
		head_->ClearNext();
		delete head_;
	}
	void PushForward(const T& e) override
	{
		head_ = new Node<T>(e, head_);
		++size_;
	}
	void PushBackward(const T& e) override
	{
		Insert(e, size_);
	}
	void Insert(const T& e, int pos) override
	{
		if (pos < 0 || pos > size_)
		{
			throw ListException();
		}
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
	T PopForward() override
	{
		if (size_ == 0)
		{
			throw ListException();
		}
		--size_;
		Node<T>* temp = head_;
		T res = head_->data;
		head_ = head_->next;
		delete temp;
		return res;
	}
	T PopBackward() override
	{
		return Extract(size_ - 1);
	}
	T Extract(int pos) override
	{
		if (pos < 0 || pos >= size_)
		{
			throw ListException();
		}
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
	size_t Size() override
	{
		return size_;
	}
	bool IsEmpty() override
	{
		return size_ == 0;
	}
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

private:
	template<class T>
	struct Node {
		T data;
		Node* next;
		Node(const T& data, Node<T>* next = nullptr) : data(data), next(next) {}
		void ClearNext()
		{
			while (next != nullptr)
			{
				Node<T>* temp = next;
				next = next->next;
				delete temp;
			}
		}
	};

	Node<T>* head_;
	size_t size_;
};

int main(int argc, char* argv[])
{
	LinkedList<int> list;
	list.PushForward(1);
	list.PushBackward(4);
	list.Insert(2, 1);
	list.Insert(0, 0);
	list.Insert(3, 3);
	std::cout << list;
	return EXIT_SUCCESS;
}