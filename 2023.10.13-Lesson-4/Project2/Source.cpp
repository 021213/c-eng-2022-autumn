#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<ostream>

std::ostream& operator<<(std::ostream& stream, std::list<int>& l)
{
	for (auto it = l.cbegin(); it != l.cend(); it++)
	{
		stream << *it << " ";
	}
	return stream;
}

std::ostream& operator<<(std::ostream& stream, std::vector<int>& vect)
{
	for (auto it = vect.cbegin(); it != vect.cend(); it++)
	{
		stream << *it << " ";
	}
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const std::set<int>& col)
{
	//std::set<int>::iterator
	for (auto it = col.cbegin(); it != col.cend(); it++)
	{
		stream << *it << " ";
	}
	return stream;
}

int main(int argc, char* argv[])
{
	{
		std::cout << "VECTOR" << std::endl;
		std::vector<int> vect{ 1, 2, 3, 4, 5 };
		vect.push_back(6);
		vect.push_back(7);
		vect[3] = 44;
		for (int i = 0; i < vect.size(); ++i)
		{
			std::cout << vect[i] << " ";
		}
		std::cout << std::endl;

		for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		for (auto it = vect.begin(); it != vect.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << vect << std::endl;

		for (auto it = vect.begin(); it != vect.end(); it++)
		{
			*it = rand() % 10;
		}
		std::cout << vect << std::endl;

		for (auto it = vect.rbegin(); it != vect.rend(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		for (auto it = vect.crbegin(); it != vect.crend(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	{
		std::cout << "SET" << std::endl;
		std::set<int> keys;
		keys.insert(10);
		keys.insert(9);
		keys.insert(1);
		keys.insert(1);
		keys.insert(6);
		keys.insert(3);
		std::cout << keys << std::endl;
	}

	{
		std::cout << "LIST OPERATIONS" << std::endl;
		std::list<int> l;
		for (int i = 0; i < 20; ++i)
		{
			l.push_back(rand() % 90 + 10);
		}
		std::cout << l << std::endl;

		std::set<int> todel;
		for (auto it = l.begin(); it != l.end(); it++)
		{
			if (*it % 2 == 0)
			{
				todel.insert(*it);
			}
		}
		for (auto it = todel.cbegin(); it != todel.cend(); it++)
		{
			l.remove(*it);
		}
		std::cout << l << std::endl;
	}

	return EXIT_SUCCESS;
}