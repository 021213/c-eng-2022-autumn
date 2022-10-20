#include<iostream>

int main(int argc, char* argv[])
{
	int a[3];
	std::cout << a + 0 << std::endl;
	std::cout << a + 1 << std::endl;
	std::cout << a + 2 << std::endl;

	int b = 10;
	int* p = &b;
	(*p) = 15;
	std::cout << b << std::endl;

	float f = 1.5f;
	p = (int*)&f;
	std::cout << (*p) << std::endl;
	
	b = (int)f;
	b = ceil(f);
	b = floor(f);
	b = round(f);

	printf("%d + %d = %d\n", 5, 3, 5 + 3); //5 + 3 = 8
	scanf_s("%d", &b); // std::cin >> b;

	return EXIT_SUCCESS;
}