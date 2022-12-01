#include<iostream>
#include<iomanip>

int f(int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n < 0)
	{
		return 0;
	}
	return n * f(n - 1);
}

int C(int n, int k)
{
	if (k < 0 || k > n)
	{
		return 0;
	}
	if (k == 0 || k == n)
	{
		return 1;
	}
	return C(n - 1, k - 1) + C(n - 1, k);
}

const int N = 100;
int c[N][N];

int CC(int n, int k)
{
	if (k < 0 || k > n)
	{
		return 0;
	}
	if (c[n][k] == 0)
	{
		if (k == 0 || k == n)
		{
			c[n][k] = 1;
		}
		else
		{
			c[n][k] = CC(n - 1, k - 1) + CC(n - 1, k);
		}
	}
	return c[n][k];
}

int main(int argc, char* argv[])
{
	std::cout << f(5) << std::endl;
	std::cout << C(5, 2) << std::endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			c[i][j] = 0;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cout << std::setw(4) << CC(i, j) << " ";
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}