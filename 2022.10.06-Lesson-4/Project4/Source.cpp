#include<iostream>

int main(int argc, char* argv)
{
	const int n = 2;
	const int m = 3;
	int a[n][m] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> a[i][j];
		}
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < n * m; ++i)
	{
		std::cin >> (((int*)a)[i]);
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}