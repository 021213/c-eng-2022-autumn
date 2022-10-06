#include<iostream>

union Banana
{
	int i;
	float f;
};

void printBits(int n)
{
	int s = sizeof(int) * 8;
	for (int i = 0; i < s; i++)
	{
		if (i % 8 == 0 && i > 0)
		{
			std::cout << " ";
		}
		std::cout << ((n >> (s - i)) & 1);
	}
	std::cout << std::endl;
}

int main(int argc, char* argv)
{
	Banana data;

	data.f = 5.5;
	std::cout << "int: " << data.i << std::endl;
	std::cout << "flt: " << data.f << std::endl;
	printBits(data.i);
	std::cout << std::endl;
	
	data.i = 4;
	std::cout << "int: " << data.i << std::endl;
	std::cout << "flt: " << data.f << std::endl;
	printBits(data.i);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}