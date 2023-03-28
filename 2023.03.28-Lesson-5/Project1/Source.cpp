#include<iostream>
#include<iostream>
#include<ostream>
#include<fstream>

template<class T>
struct Point {
	T x;
	T y;
};

int main(int argc, char* argv[])
{
	Point<int> p;
	p.x = 4;
	p.y = 7;
	std::cout << p.x << " " << p.y << std::endl;
	return EXIT_SUCCESS;
}