#include<iostream>

int main(int argc, char* argv[])
{
	const int n = 4;
	int a[n] = { 0 };
	
	std::cout << a << " ";
	a[0] = 0;
	*a = 6;
	std::cout << a[0] << std::endl;
	
	std::cout << a + 1 << " ";
	a[1] = 3;
	*(a + 1) = 8;
	std::cout << a[1] << std::endl;
	
	std::cout << a + 2 << " ";
	a[2] = 2;
	*(a + 2) = 7;
	std::cout << a[2] << std::endl;
	
	for(int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	} //6 8 7 0
	std::cout << std::endl;
	
	
	return EXIT_SUCCESS;
}