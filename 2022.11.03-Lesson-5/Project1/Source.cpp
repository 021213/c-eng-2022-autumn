#include<iostream>

void printNumbersV(int a, int b)
{
	if (a == b)
	{
		return;
	}
	if (a < b)
	{
		for (int i = a; i <= b; ++i)
		{
			std::cout << i << " ";
		}
	}
	else
	{
		for (int i = a; i >= b; --i)
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

int printNumbers(int a, int b)
{
	if (a == b)
	{
		std::cout << a << std::endl;
		return 0;
	}
	else if (a < b)
	{
		for (int i = a; i <= b; ++i)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		return 1;
	}
	else
	{
		for (int i = a; i >= b; --i)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		return -1;
	}
}

int calcSum(int a, int b)
{
	int result = 0;
	if (a > b)
	{
		a ^= b ^= a ^= b;
		/*
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
		*/
	}
	for (int i = a; i <= b; ++i)
	{
		result += i;
	}
	return result;
}

int processPrintNumbers(int res)
{
	switch (res)
	{
	case 1:
	{
		std::cout << "a > b" << std::endl;
		break;
	}
	case 0:
	{
		std::cout << "a == b" << std::endl;
		break;
	}
	case -1:
	{
		std::cout << "a < b" << std::endl;
		break;
	}
	default:
	{
		std::cout << "Got some problems" << std::endl;
		break;
	}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	processPrintNumbers(printNumbers(2, 5));
	printNumbers(12, 51);
	printNumbers(21, 15);
	int a = calcSum(5, 2);
	std::cout << a << std::endl;
	return EXIT_SUCCESS;
}