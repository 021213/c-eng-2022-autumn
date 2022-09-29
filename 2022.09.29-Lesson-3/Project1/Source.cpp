#include<iostream>

int main(int argc, char* argv[])
{
	{
		int a = 0;
	loopBeg:
		std::cout << "BANANA " << a << std::endl;
		if (a < 5)
		{
			++a;
			goto loopBeg;
		}
	}

	{
		int a = 0;
		while (a < 5)
		{
			std::cout << "BANANA " << a << std::endl;
			++a;
		}
	}

	{
		int a = 0;
		do
		{
			std::cout << "BANANA " << a << std::endl;
			++a;
		} while (a < 5);
	}

	{
		for (int a = 0; a < 5; ++a)
		{
			std::cout << "BANANA " << a << std::endl;
		}
	}

	{
		for (int a = 0; true; ++a)
		{
			if (a == 3)
			{
				continue;
			}
			if (a == 6)
			{
				break;
			}
			std::cout << "BANANA " << a << std::endl;
		}
	}

	return EXIT_SUCCESS;
}