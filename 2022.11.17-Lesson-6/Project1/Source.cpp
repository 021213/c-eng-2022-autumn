#include<iostream>

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		std::cout << i << " -> " << argv[i] << "\n";
	}
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	std::cout << a << " + " << b << " = " << a + b << "\n";
	return EXIT_SUCCESS;
}