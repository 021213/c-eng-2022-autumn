#include<iostream>

int main(int argc, char* argv[])
{
	int a = 5;
		
	std::cout << a << std::endl;
	for (a = 0; a < 10; ++a);
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;

	std::cout << a << std::endl;

	return EXIT_SUCCESS;
}