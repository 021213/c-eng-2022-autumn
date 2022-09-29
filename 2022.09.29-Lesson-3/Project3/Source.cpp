#include<iostream>
#define BANANA 40

typedef unsigned long long ullong;

int main(int argc, char* argv[])
{
	std::cout << "CHAR : " << sizeof(char) << " bytes" << std::endl;
	std::cout << "SHORT : " << sizeof(short) << " bytes" << std::endl;
	std::cout << "FLOAT : " << sizeof(float) << " bytes" << std::endl;
	std::cout << "UINT : " << sizeof(unsigned int) << " bytes" << std::endl;
	std::cout << "LONG LONG : " << sizeof(long long) << " bytes" << std::endl;
	std::cout << "UNSIGNED LONG LONG : " << sizeof(ullong) << " bytes" << std::endl;
	std::cout << "DOUBLE: " << sizeof(double) << " bytes" << std::endl;

	std::cout << BANANA;

	return EXIT_SUCCESS;
}