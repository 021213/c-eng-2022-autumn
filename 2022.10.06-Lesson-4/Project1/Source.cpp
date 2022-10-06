#include<iostream>
#define NN 10

int main(int argc, char* argv[])
{
	//static arrays
	int a[4] = { 0 };
	int b[4] = { 1, 4, 5, 2 };
	int c[3] = { 1, 3 };
	int d[3] = { 1, 3, 5, 3, 2 };
	const int N = 10;
	int e[N] = { 0 };
	int f[NN] = { 0 };

	int size = sizeof(a) / sizeof(int);
	for (int i = 0; i < size; ++i)
	{
		std::cin >> a[i];
	}

	for (int i = 0; i < size; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}