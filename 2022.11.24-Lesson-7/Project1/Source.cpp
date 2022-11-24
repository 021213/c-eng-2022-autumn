#include<iostream>

void printSum(int, int);

void printDiff(int, int);

void printMult(int, int);

int sum(int, int);

int diff(int, int);

int mult(int, int);

int main(int argc, char* argv[])
{
	int (*oper)(int, int);
	oper = sum;
	std::cout << oper(4, 2) << std::endl;

	int(*ops[3])(int, int) = { sum, diff, mult };
	for (int i = 0; i < 3; ++i)
	{
		std::cout << ops[i](6, 4) << std::endl;
	}

	void (*opsP[3])(int, int) = { printSum, printDiff, printMult };
	
	for (int i = 0; i < 3; ++i)
	{
		opsP[i](6, 4);
	}

	return EXIT_SUCCESS;
}

void printSum(int a, int b)
{
	std::cout << a << " + " << b << " = " << a + b << std::endl;
}

void printDiff(int a, int b)
{
	std::cout << a << " - " << b << " = " << a - b << std::endl;
}

void printMult(int a, int b)
{
	std::cout << a << " * " << b << " = " << a * b << std::endl;
}

int sum(int a, int b)
{
	return a + b;
}

int diff(int a, int b)
{
	return a - b;
}

int mult(int a, int b)
{
	return a * b;
}
