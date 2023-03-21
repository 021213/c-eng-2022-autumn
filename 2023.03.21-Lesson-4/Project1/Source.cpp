#include<iostream>
#include<ostream>
#include<fstream>

class ArrayListInt {
private:
	int capacity;
	int count;
	int* data;
	void copy(int* source, int* destination, int count)
	{
		for (int i = 0; i < count; ++i)
		{
			destination[i] = source[i];
		}
	}
	int expand()
	{
		int* newData = new int[capacity * 2];
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
	ArrayListInt(int capacity = 10) :
		capacity(capacity),
		count(0),
		data(new int[capacity]) {}
	ArrayListInt(const ArrayListInt& list) :
		capacity(list.capacity),
		count(list.count),
		data(new int[list.capacity])
	{
		copy(list.data, data, list.count);
	}
	~ArrayListInt()
	{
		delete[] data;
	}
	int append(int element)
	{
		if (!capacityFits())
		{
			return 0;
		}
		/*
			capacity 10
			count 2
			1 3 0 0 0 0 0 0 0 0
		*/
		data[count] = element;
		++count;
		return 1;
	}
	void print(std::ostream& stream)
	{
		stream << "[" << count << "/" << capacity << "] { ";
		for (int i = 0; i < count; ++i)
		{
			stream << data[i] << " ";
		}
		stream << "}" << std::endl;
	}

	ArrayListInt& operator+=(int element)
	{
		append(element);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, const ArrayListInt& list);

	friend void friendCountPrint(ArrayListInt& list);
};

void friendCountPrint(ArrayListInt& list)
{
	std::cout << list.count << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const ArrayListInt& list)
{
	stream << "[" << list.count << "/" << list.capacity << "] { ";
	for (int i = 0; i < list.count; ++i)
	{
		stream << list.data[i] << " ";
	}
	stream << "}";
	return stream;
}

int main(int argc, char* argv[])
{
	std::ofstream file("1.txt", std::ios_base::ate); //std::ios_base::app
	ArrayListInt list(2);
	list.print(std::cout);
	file << list << std::endl;
	list.append(1);
	list.print(std::cout);
	file << list << std::endl;
	list.append(2);
	list.append(3);
	list.append(4);
	list.print(std::cout);
	file << list << std::endl;
	((list += 5) += 6) += 7;
	std::cout << list << std::endl;
	file << list << std::endl;
	file.close();
	return EXIT_SUCCESS;
}