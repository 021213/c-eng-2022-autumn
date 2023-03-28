#include<iostream>

template<class T>
class ArrayList {
private:
	T* data;
	
	int capacity;
	
	int count;
	
	void copy(T* source, T* destination, int count)
	{
		for (int i = 0; i < count; ++i)
		{
			destination[i] = source[i];
		}
	}
	
	int expand()
	{
		T* newData = new T[capacity * 2];
		if (newData == nullptr)
		{
			return 0;
		}
		copy(data, newData, capacity);
		delete[] data;
		data = newData;
		capacity *= 2;
		return 1;
	}
	
	int capacityFits()
	{
		return (count < capacity || expand());
	}

public:
	ArrayList(int capacity = 2) :
		data(new T[capacity]),
		capacity(capacity),
		count(0)
	{}
	
	ArrayList(const ArrayList<T>& list) :
		data(new T[list.capacity]),
		capacity(list.capacity),
		count(list.count)
	{
		copy(list.data, data, list.count);
	}
	
	~ArrayList()
	{
		delete[] data;
	}
	
	int append(T element)
	{
		if (!capacityFits())
		{
			return 0;
		}
		data[count] = element;
		++count;
		return 1;
	}
	
	ArrayList& operator=(const ArrayList<T>& list)
	{
		if (data != nullptr)
		{
			delete[] data;
		}
		data = new T[list.capacity];
		capacity = list.capacity;
		count = list.count;
		copy(list.data, data, list.count);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, const ArrayList<T>& list)
	{
		stream << "[" << list.count << "/" << list.capacity << "] { ";
		for (int i = 0; i < list.count; ++i)
		{
			stream << list.data[i] << " ";
		}
		stream << "}";
		return stream;
	}
};

int main(int argc, char* argv[])
{
	ArrayList<int> list1;
	list1.append(1);
	list1.append(2);

	ArrayList<int> list2;
	list2 = list1;
	list2.append(3);
	list2.append(4);

	ArrayList<int> list3 = list2;
	list3.append(5);
	list3.append(6);

	ArrayList<ArrayList<int>> list;
	list.append(list1);
	list.append(list2);
	list.append(list3);

	std::cout << list1 << std::endl;
	std::cout << list2 << std::endl;
	std::cout << list3 << std::endl;
	std::cout << list << std::endl;

	return EXIT_SUCCESS;
}