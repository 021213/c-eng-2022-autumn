#include<iostream>

int main(int argc, char* argv[])
{
	int capacity = 10;
	int count = 0;
	int* a = (int*)malloc(sizeof(int) * capacity);
	int in = 0;

	do
	{
		std::cout << "0 - Exit\n";
		std::cout << "1 - Add\n";
		std::cout << "2 - Print\n";
		std::cout << "3 - Delete\n";
		std::cout << "4 - Swap\n";
		std::cin >> in;
		switch (in)
		{
		case 1:
		{
			std::cout << "input element: ";
			if (count == capacity)
			{
				int* t = (int*)malloc(sizeof(int) * (capacity + 5));
				for (int i = 0; i < capacity + 5; ++i)
				{
					*(t + i)= (i < capacity ? *(a + i) : 0);
				}
				free(a);
				a = t;
				capacity += 5;
			}
			std::cin >> *(a + count);
			++count;
			break;
		}
		case 2:
		{
			std::cout << "a = ";
			for (int i = 0; i < count; ++i)
			{
				std::cout << *(a + i) << " ";
			}
			std::cout << std::endl;
			break;
		}
		}
		system("pause");
		system("cls");

	} while (in != 0);

	free(a);
	return EXIT_SUCCESS;
}