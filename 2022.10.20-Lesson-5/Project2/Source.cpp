#include<iostream>

int main(int argc, char* argv[])
{
	int* a = nullptr; //NULL
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;

	std::cout << &b << std::endl;
	std::cout << &c << std::endl;
	std::cout << &d << std::endl;
	std::cout << &e << std::endl;
	a = &c; //a points to c
	printf("%d %d %d %d\n", b, c, d, e);
	a = a + 3; //a points to b
	(*a) = 5;
	printf("%d %d %d %d\n", b, c, d, e);

	return EXIT_SUCCESS;
}