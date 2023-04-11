#include<iostream>

int max(float a, float b)
{
	return (a > b ? a : b);
}

int max(int a, int b)
{
	return (a > b ? a : b);
}

int max(int a, int b, int c)
{
	return max(max(a, b), c);
}

int main()
{
	std::cout << max(1, 2) << std::endl;
	std::cout << max(1, 2, 3) << std::endl;
	std::cout << max(1.f, 2.f) << std::endl;
	return EXIT_SUCCESS;
}